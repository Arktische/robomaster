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
 */
#include "robo-tower.h"
namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (RoboTower);
NS_LOG_COMPONENT_DEFINE ("RoboTower");
RoboTower::RoboTower ()
{
}

RoboTower::~RoboTower ()
{
}
TypeId
RoboTower::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboTower")
          .SetParent<RoboBase> ()
          .SetGroupName ("Robo")
          .AddConstructor<RoboTower> ()
          .AddAttribute ("Type", "The type of this robot", EnumValue (Follower),
                         MakeEnumAccessor (&RoboTower::m_type),
                         MakeEnumChecker (Master, "Master", Follower, "Follower"))
          .AddAttribute ("Life", "The init life of this robot", IntegerValue (1000),
                         MakeIntegerAccessor (&RoboTower::m_life), MakeIntegerChecker<int> (0))
          .AddAttribute ("MaxSpeed", "The max speed of this robot", DoubleValue (0),
                         MakeDoubleAccessor (&RoboTower::m_maxSpeed), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboTower::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
void
RoboTower::Init ()
{
  m_largeAmmo->m_maxNumber = 0;
  m_smallAmmo->m_maxNumber = 0;
}
} // namespace ns3
