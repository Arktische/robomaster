/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-infantry.h"
namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (RoboInfantry);
NS_LOG_COMPONENT_DEFINE ("RoboInfantry");
RoboInfantry::RoboInfantry ()
{
}

RoboInfantry::~RoboInfantry ()
{
}
TypeId
RoboInfantry::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboInfantry")
          .SetParent<RoboBase> ()
          .SetGroupName ("Robo")
          .AddConstructor<RoboInfantry> ()
          .AddAttribute ("Type", "The type of this robot", EnumValue (Master),
                         MakeEnumAccessor (&RoboInfantry::m_type),
                         MakeEnumChecker (Master, "Master", Follower, "Follower"))
          .AddAttribute ("Life", "The init life of this robot", IntegerValue (200),
                         MakeIntegerAccessor (&RoboInfantry::m_life), MakeIntegerChecker<int> (0))
          .AddAttribute ("MaxSpeed", "The max speed of this robot", DoubleValue (3),
                         MakeDoubleAccessor (&RoboInfantry::m_maxSpeed),
                         MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboInfantry::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

} // namespace ns3
