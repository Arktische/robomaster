/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-ammo.h"

namespace ns3 {
RoboAmmo::RoboAmmo ()
{
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
}
} // namespace ns3
