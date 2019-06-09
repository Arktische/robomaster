/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-ammo.h"

namespace ns3 {
RoboAmmo::RoboAmmo ()
{
  AddUpdateCallback (MakeCallback (&RoboAmmo::UpdateRange, this));
  AddCollisionCallback (MakeCallback (&RoboAmmo::HandleCollision, this));
}

RoboAmmo::~RoboAmmo ()
{
}
void
RoboAmmo::SetInjury (int injury)
{
  m_injury = injury;
}
int
RoboAmmo::GetInjury () const
{
  return m_injury;
}
void
RoboAmmo::SetRange (float range)
{
  m_range = range;
}
float
RoboAmmo::GetRange () const
{
  return m_range;
}
void
RoboAmmo::Disable (void)
{
  m_range = -1;
  RoboActor::Disable ();
  RoboActor::Delete ();
}
void
RoboAmmo::UpdateRange (float delta)
{
  m_range -= m_speed.GetLength () * delta;
  if (m_range < 0)
    {
      Disable ();
    }
}
void
RoboAmmo::HandleCollision (Ptr<RoboActor> oth)
{
  Disable ();
}
} // namespace ns3
