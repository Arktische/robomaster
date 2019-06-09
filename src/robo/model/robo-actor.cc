/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-actor.h"
namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("RoboActor");
NS_OBJECT_ENSURE_REGISTERED (RoboActor);

RoboActor::RoboActor ()
{
  NS_LOG_FUNCTION (this);
  m_collision = Create<RoboCollision> ();
}

RoboActor::~RoboActor ()
{
  NS_LOG_FUNCTION (this);
}
TypeId
RoboActor::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboActor")
          .SetParent<Object> ()
          .SetGroupName ("Robo")
          .AddConstructor<RoboActor> ()
          .AddAttribute ("Period", "The period between location update", DoubleValue (0.01),
                         MakeDoubleAccessor (&RoboActor::m_updatePeriod),
                         MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboActor::GetInstanceTypeId (void) const
{
  NS_LOG_FUNCTION (this);
  return GetTypeId ();
}

void
RoboActor::DoInitialize (void)
{
  NS_LOG_FUNCTION (this << m_updatePeriod);
  Simulator::Schedule (Seconds (m_updatePeriod) - NanoSeconds (10), &RoboActor::BeforeUpdate, this);
  Simulator::Schedule (Seconds (m_updatePeriod), &RoboActor::Update, this);
  Simulator::Schedule (Seconds (m_updatePeriod) + NanoSeconds (10), &RoboActor::AfterUpdate, this);
}

void
RoboActor::BeforeUpdate ()
{
  NS_LOG_FUNCTION (this << static_cast<double> (Simulator::Now ().GetSeconds ()));
  if (!m_isDestroy)
    {
      FVector oldLocation = m_collision->GetGlobalLocation ();
      m_collision->SetGlobalLocation (oldLocation + m_speed * m_updatePeriod);
    }
  for (auto &cb : m_beforeUpdateCallbackList)
    {
      cb (m_updatePeriod);
    }
}
void
RoboActor::Update ()
{
  NS_LOG_FUNCTION (this << static_cast<double> (Simulator::Now ().GetSeconds ()));
  NS_LOG_INFO (m_collision->GetGlobalLocation ());
  if (!m_isDestroy)
    {
      for (auto &cb : m_updateCallbackList)
        {
          cb (m_updatePeriod);
        }
    }
  Simulator::Schedule (Seconds (m_updatePeriod) - NanoSeconds (10), &RoboActor::BeforeUpdate, this);
  Simulator::Schedule (Seconds (m_updatePeriod), &RoboActor::Update, this);
  Simulator::Schedule (Seconds (m_updatePeriod) + NanoSeconds (10), &RoboActor::AfterUpdate, this);
}
void
RoboActor::AfterUpdate ()
{
  NS_LOG_FUNCTION (this << static_cast<double> (Simulator::Now ().GetSeconds ()));
  if (!m_isDestroy)
    {
      for (auto &cb : m_afterUpdateCallbackList)
        {
          cb (m_updatePeriod);
        }
    }
}
void
RoboActor::IndicateCollision (Ptr<RoboActor> oth)
{
  NS_LOG_FUNCTION (this << static_cast<double> (Simulator::Now ().GetSeconds ()));
  //TODO
  //根据oth类型决定回退上次位置更新(即不能移动的情况)
  if (!m_isDestroy)
    {
      for (auto &cb : m_collisionCallbackList)
        {
          cb (oth); //处理减血等
        }
    }
}

void
RoboActor::AddBeforeUpdateCallback (UpdateCallback cb)
{
  NS_LOG_FUNCTION (this);
  NS_ASSERT (!cb.IsNull ());
  m_beforeUpdateCallbackList.push_back (cb);
}
void
RoboActor::AddUpdateCallback (UpdateCallback cb)
{
  NS_LOG_FUNCTION (this);
  NS_ASSERT (!cb.IsNull ());
  m_updateCallbackList.push_back (cb);
}
void
RoboActor::AddAfterUpdateCallback (UpdateCallback cb)
{
  NS_LOG_FUNCTION (this);
  NS_ASSERT (!cb.IsNull ());
  m_afterUpdateCallbackList.push_back (cb);
}
void
RoboActor::AddCollisionCallback (CollisionCallback cb)
{
  NS_LOG_FUNCTION (this);
  NS_ASSERT (!cb.IsNull ());
  m_collisionCallbackList.push_back (cb);
}

void
RoboActor::SetSpeed (FVector speed)
{
  m_speed = speed;
}
FVector
RoboActor::GetSpeed () const
{
  return m_speed;
}

void
RoboActor::SetJudge (Ptr<RoboJudge> judge)
{
  m_judge = judge;
}
Ptr<RoboJudge>
RoboActor::GetJudge (void) const
{
  return m_judge;
}

void
RoboActor::Disable ()
{
  NS_LOG_FUNCTION (this);
  m_isDestroy = true;
}
void
RoboActor::Enable ()
{
  NS_LOG_FUNCTION (this);
  m_isDestroy = false;
}
void
RoboActor::Delete ()
{
  NS_LOG_FUNCTION (this);
  m_isDeleted = true;
}
} // namespace ns3
