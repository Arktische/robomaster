/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 HUST Dian Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Original Author: Pengyu Liu <eicliupengyu@gmail.com>
 * Modified by:     Xinyu Li
 */
#include "robo-ammo.h"
#include "robo-base.h"
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
  // auto cast = DynamicCast<RoboBase> (oth);
  // if (cast)
  //   {
  //     if (cast->GetUid () != m_shooterUid)
  //       {
  //         Disable ();
  //       }
  //   }
  // Disable ();
}

void
RoboAmmo::ShowTrace (float delta)
{
  // std::cout << m_collision->GetGlobalLocation () << std::endl;
}
} // namespace ns3
