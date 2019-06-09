/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
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
