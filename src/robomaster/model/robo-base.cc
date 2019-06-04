/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-base.h"
#include "ns3/integer.h"
#include "ns3/double.h"
#include "ns3/enum.h"
#include "ns3/pointer.h"

namespace ns3 {
RoboBase::RoboBase ()
{
  m_uid = AllocUid ();
}
RoboBase::~RoboBase ()
{
}
TypeId
RoboBase::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboBase")
          .SetParent<Object> ()
          .SetGroupName ("Robomaster")
          .AddConstructor<RoboBase> ()
          .AddAttribute ("Type", "The type of this robot", EnumValue (Follower),
                         MakeEnumAccessor (&RoboBase::m_type),
                         MakeEnumChecker (Master, "Master", Follower, "Follower"))
          .AddAttribute ("Life", "The init life of this robot", IntegerValue (0),
                         MakeIntegerAccessor (&RoboBase::m_life), MakeIntegerChecker<int> (0))
          .AddAttribute ("MaxSpeed", "The max speed of this robot", DoubleValue (0),
                         MakeDoubleAccessor (&RoboBase::m_maxSpeed), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
RoboBase::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
uint8_t
RoboBase::AllocUid (void)
{
  static uint8_t uidIndex = 0;
  return uidIndex++;
}
void
RoboBase::Update ()
{
}
void
RoboBase::SetLocation (Vector2 newLocation)
{
}
void
RoboBase::SetLargeAmmoNumber (int num)
{
}
void
RoboBase::SetSmallAmmoNumber (int num)
{
}

} // namespace ns3
