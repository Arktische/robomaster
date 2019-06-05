/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-hero.h"
namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (RoboHero);
NS_LOG_COMPONENT_DEFINE ("RoboHero");
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
          .SetGroupName ("Robo")
          .AddConstructor<RoboHero> ()
          .AddAttribute ("Type", "The type of this robot", EnumValue (Master),
                         MakeEnumAccessor (&RoboHero::m_type),
                         MakeEnumChecker (Master, "Master", Follower, "Follower"))
          .AddAttribute ("Life", "The init life of this robot", IntegerValue (400),
                         MakeIntegerAccessor (&RoboHero::m_life), MakeIntegerChecker<int> (0))
          .AddAttribute ("MaxSpeed", "The max speed of this robot", DoubleValue (2.5),
                         MakeDoubleAccessor (&RoboHero::m_maxSpeed), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboHero::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

} // namespace ns3
