/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-collision.h"
namespace ns3 {
RoboCollision::RoboCollision ()
{
}

RoboCollision::~RoboCollision ()
{
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
RoboCollision::AddLineSegment (LineSegment boundary)
{
  m_boundary.push_back (boundary);
}

bool
RoboCollision::IsCollision (RoboCollision &oth)
{
  return (m_globalLocation.GetDistance (oth.m_globalLocation) <= (m_redius + oth.m_redius));
}
} // namespace ns3
