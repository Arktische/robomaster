/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-base.h"
#include "ns3/integer.h"
#include "ns3/double.h"
#include "ns3/enum.h"
#include "ns3/pointer.h"

namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (RoboBase);
NS_LOG_COMPONENT_DEFINE ("RoboBase");
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
          .SetParent<RoboActor> ()
          .SetGroupName ("Robo")
          .AddConstructor<RoboBase> ();
          // .AddAttribute ("Type", "The type of this robot", EnumValue (Follower),
          //                MakeEnumAccessor (&RoboBase::m_type),
          //                MakeEnumChecker (Master, "Master", Follower, "Follower"))
          // .AddAttribute ("Life", "The init life of this robot", IntegerValue (0),
          //                MakeIntegerAccessor (&RoboBase::m_life), MakeIntegerChecker<int> (0))
          // .AddAttribute ("MaxSpeed", "The max speed of this robot", DoubleValue (0),
          //                MakeDoubleAccessor (&RoboBase::m_maxSpeed), MakeDoubleChecker<float> (0));
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
RoboBase::Update (float delta)
{
}
uint8_t
RoboBase::GetUid () const
{
  return m_uid;
}
void
RoboBase::SetUid (uint8_t uid)
{
  m_uid = uid;
}
uint8_t
RoboBase::GetTeam () const
{
  return m_team;
}
void
RoboBase::SetTeam (uint8_t team)
{
  m_team = team;
}
RoboBase::RoboType
RoboBase::GetType () const
{
  return m_type;
}
void
RoboBase::SetType (RoboType type)
{
  m_type = type;
}
float
RoboBase::GetMaxSpeed (void) const
{
  return m_maxSpeed;
}
void
RoboBase::SetMaxSpeed (float speed)
{
  m_maxSpeed = speed;
}
FVector
RoboBase::GetSpeed (void) const
{
  return m_speed;
}
void
RoboBase::SetSpeed (FVector speed)
{
  NS_ASSERT (speed.GetLength () <= m_maxSpeed);
  m_speed = speed;
}
////////////////////////TODO//////////////////////
FVector
RoboBase::GetLocation () const
{
  return FVector ();
}
void
RoboBase::SetLocation (FVector location)
{
}
int
RoboBase::GetLargeAmmoNumber (void) const
{
  return 0;
}
void
RoboBase::SetLargeAmmoNumber (int num)
{
}
bool
RoboBase::IsLargeAmmoCanShoot (void) const
{
  return 0;
}
void
RoboBase::ShootLargeAmmo (FVector speed)
{
}

int
RoboBase::GetSmallAmmoNumber (void) const
{
  return 0;
}
void
RoboBase::SetSmallAmmoNumber (int num)
{
}
bool
RoboBase::IsSmallAmmoCanShoot (void) const
{
  return 0;
}
void
RoboBase::ShootSmallAmmo (FVector speed)
{
}

int
RoboBase::GetLife () const
{
  return m_life;
}
void
RoboBase::SetLife (int life)
{
  m_life = life;
}
} // namespace ns3
