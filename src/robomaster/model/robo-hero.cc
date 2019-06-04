/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-hero.h"
#include "ns3/integer.h"
#include "ns3/double.h"
#include "ns3/enum.h"
#include "ns3/pointer.h"

namespace ns3 {
RoboHero::RoboHero ()
{
}

RoboHero::~RoboHero ()
{
}
TypeId
RoboHero::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboHero")
          .SetParent<RoboBase> ()
          .SetGroupName ("Robomaster")
          .AddConstructor<RoboHero> ()
          .AddAttribute ("Type", "The type of this robot", EnumValue (Master),
                         MakeEnumAccessor (&RoboHero::m_type),
                         MakeEnumChecker (Master, "Master", Follower, "Follower"))
          .AddAttribute ("Life", "The init life of this robot", IntegerValue (0),
                         MakeIntegerAccessor (&RoboHero::m_life), MakeIntegerChecker<int> (0))
          .AddAttribute ("MaxSpeed", "The max speed of this robot", DoubleValue (0),
                         MakeDoubleAccessor (&RoboHero::m_maxSpeed), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboHero::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
} // namespace ns3
