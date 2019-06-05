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
  //TODO
}
} // namespace ns3
