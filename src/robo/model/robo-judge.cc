/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-judge.h"
#include "robo-base.h"
namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("RoboJudge");
NS_OBJECT_ENSURE_REGISTERED (RoboJudge);
RoboJudge::RoboJudge ()
{
  NS_LOG_FUNCTION (this);
}

RoboJudge::~RoboJudge ()
{
  NS_LOG_FUNCTION (this);
}
TypeId
RoboJudge::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboJudge")
          .SetParent<Object> ()
          .SetGroupName ("Robo")
          .AddConstructor<RoboJudge> ()
          .AddAttribute ("Period", "The period between update", DoubleValue (0.01),
                         MakeDoubleAccessor (&RoboJudge::m_updatePeriod),
                         MakeDoubleChecker<float> (0))
          .AddAttribute ("VisibleDistance", "The visible distance between robos", DoubleValue (5.0),
                         MakeDoubleAccessor (&RoboJudge::m_visibleDistance),
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
RoboJudge::DoInitialize (void)
{
  NS_LOG_FUNCTION (this);
  Simulator::Schedule (Seconds (m_updatePeriod) - NanoSeconds (5), &RoboJudge::Update, this);
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
  NS_LOG_FUNCTION (this);
  for (uint32_t i = 0; i < m_robos.size (); ++i)
    {
      for (uint32_t j = i + 1; j < m_robos.size (); ++j)
        {
          if (m_robos[i]->m_collision->m_globalLocation.GetDistance (
                  m_robos[j]->m_collision->m_globalLocation) < m_visibleDistance)
            {
              DynamicCast<RoboBase> (m_robos[i])->IndicateLocation (m_robos[j]);
              DynamicCast<RoboBase> (m_robos[j])->IndicateLocation (m_robos[i]);
            }
          if (IsCollision (m_robos[i]->m_collision, m_robos[j]->m_collision))
            {
              m_robos[i]->IndicateCollision (m_robos[j]);
              m_robos[j]->IndicateCollision (m_robos[i]);
            }
        }
      for (auto j : m_smallAmmo)
        {
          if (IsCollision (m_robos[i]->m_collision, j->m_collision))
            {
              m_robos[i]->IndicateCollision (j);
              j->IndicateCollision (m_robos[i]);
            }
        }
      for (auto j : m_largeAmmo)
        {
          if (IsCollision (m_robos[i]->m_collision, j->m_collision))
            {
              m_robos[i]->IndicateCollision (j);
              j->IndicateCollision (m_robos[i]);
            }
        }
    }
}
void
RoboJudge::AddRobo (Ptr<RoboActor> actor)
{
  NS_LOG_FUNCTION (this);
  m_robos.push_back (actor);
}

void
RoboJudge::AddSmallAmmo (Ptr<RoboActor> actor)
{
  NS_LOG_FUNCTION (this);
  m_smallAmmo.push_back (actor);
}

void
RoboJudge::AddLargeAmmo (Ptr<RoboActor> actor)
{
  NS_LOG_FUNCTION (this);
  m_largeAmmo.push_back (actor);
}
} // namespace ns3
