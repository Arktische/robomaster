/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-ammo.h"
#include "robo-common.h"

namespace ns3 {
RoboAmmo::RoboAmmo ()
{
  AddUpdateCallback (MakeCallback (&RoboAmmo::UpdateRange, this));
  AddUpdateCallback (MakeCallback (&RoboAmmo::ShowTrace, this));
  AddCollisionCallback (MakeCallback (&RoboAmmo::HandleCollision, this));
  m_collision->SetSelfMask (gAmmoMask);
  m_collision->SetCollisionMask (gAmmoCollisionMask);
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
RoboAmmo::SetShooterUid (uint8_t uid)
{
  m_shooterUid = uid;
}
uint8_t
RoboAmmo::GetShooterUid () const
{
  return m_shooterUid;
}
void
RoboAmmo::SetInitValue (FVector location, float redius)
{
  m_collision->SetGlobalLocation (location);
  m_collision->SetRedius (redius);
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
  // Disable ();
}

void
RoboAmmo::ShowTrace (float delta)
{
  // std::cout << m_collision->GetGlobalLocation () << std::endl;
}
} // namespace ns3
