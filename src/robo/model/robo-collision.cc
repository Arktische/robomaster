/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-collision.h"
namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("RoboCollision");
RoboCollision::RoboCollision ()
{
  NS_LOG_FUNCTION (this);
}

RoboCollision::~RoboCollision ()
{
  NS_LOG_FUNCTION (this);
}

void
RoboCollision::SetGlobalLocation (FVector globallocation)
{
  m_globalLocation = globallocation;
}
FVector
RoboCollision::GetGlobalLocation (void) const
{
  return m_globalLocation;
}

void
RoboCollision::SetGlobalRotation (FAngle globalrotation)
{
  m_globalRotation = globalrotation;
}
FAngle
RoboCollision::GetGlobalRotation (void) const
{
  return m_globalRotation;
}

void
RoboCollision::SetCollisionMask (uint32_t collisionMask)
{
  m_collisionMask = collisionMask;
}
uint32_t
RoboCollision::GetCollisionMask (void) const
{
  return m_collisionMask;
}

void
RoboCollision::SetRedius (float redius)
{
  NS_ASSERT_MSG (redius > 0.0, "The redius of a circle must be bigger than 0.");
  m_redius = redius;
}
float
RoboCollision::GetRedius (void) const
{
  return m_redius;
}

void
RoboCollision::AddBoundaryPoint (FVector boundaryPoint)
{
  m_boundaryPoint.push_back (boundaryPoint);
}

bool
IsCollision (Ptr<RoboCollision> obj1, Ptr<RoboCollision> obj2)
{
  if (!(obj1->m_globalLocation.GetDistance (obj2->m_globalLocation) <=
        (obj1->m_redius + obj2->m_redius)))
    {
      return false;
    }
}
} // namespace ns3
