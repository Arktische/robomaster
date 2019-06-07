/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-judge.h"
namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("RoboJudge");
NS_OBJECT_ENSURE_REGISTERED (RoboJudge);
RoboJudge::RoboJudge ()
{
  NS_LOG_FUNCTION (this);
  Simulator::Schedule (Seconds (m_updatePeriod) - NanoSeconds (5), &RoboJudge::Update, this);
}

RoboJudge::~RoboJudge ()
{
  NS_LOG_FUNCTION (this);
}
TypeId
RoboJudge::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::RoboJudge")
                          .SetParent<Object> ()
                          .SetGroupName ("Robo")
                          .AddConstructor<RoboJudge> ()
                          .AddAttribute ("Period", "The period between update", DoubleValue (0.01),
                                         MakeDoubleAccessor (&RoboJudge::m_updatePeriod),
                                         MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboJudge::GetInstanceTypeId (void) const
{
  NS_LOG_FUNCTION (this);
  return GetTypeId ();
}
void
RoboJudge::Update ()
{
  DoUpdate ();
  Simulator::Schedule (Seconds (m_updatePeriod), &RoboJudge::Update, this);
}

void
RoboJudge::DoUpdate ()
{
  // for (auto iter = m_robos.begin (); iter != m_robos.end (); ++iter)
  //   {
  //     for (auto subiter = ++iter; subiter != m_robos.end (); ++subiter)
  //       {
  //         if (*iter->m_collision->m_globalLocation.GetDistance (
  //                 *subiter->m_collision->m_globalLocation) < *iter->m_visibleDistance)
  //           // fix me! : IndicateLocation belong to class RoboBase
  //           *iter->IndicateLocation (*subiter);
  //         else if (*subiter->m_collision->m_globalLocation.GetDistance (
  //                      *iter->m_collision->m_globalLocation) < *subiter->m_visibleDistance)
  //           *subiter->IndicateLocation (*iter);
  //         else
  //           continue;
  //         if (*iter->m_collision->IsCollision (*subiter->m_collision))
  //           {
  //             *iter->IndicateCollision (*subiter);
  //             *subiter->IndicateCollision (*iter);
  //           }
  //       }
  //     for (auto subiter = m_smallAmmo.begin (); subiter != m_smallAmmo.end (); ++subiter)
  //       {
  //         if (*iter->m_collision->IsCollision (*subiter->m_collision))
  //           {
  //             *iter->IndicateCollision (*subiter);
  //             *subiter->IndicateCollision (*iter);
  //           }
  //       }
  //     for (auto subiter = m_largeAmmo.begin (); subiter != m_largeAmmo.end (); ++subiter)
  //       {
  //         if (*iter->m_collision->IsCollision (*subiter->m_collision))
  //           {
  //             *iter->IndicateCollision (*subiter);
  //             *subiter->IndicateCollision (*iter);
  //           }
  //       }
  //   }
}
void
RoboJudge::AddRobo (Ptr<RoboActor> actor)
{
  m_robos.push_back (actor);
  return;
}

void
RoboJudge::AddSmallAmmo (Ptr<RoboActor> actor)
{
  m_smallAmmo.push_back (actor);
  return;
}

void
RoboJudge::AddLargeAmmo (Ptr<RoboActor> actor)
{
  m_largeAmmo.push_back (actor);
  return;
}
} // namespace ns3
