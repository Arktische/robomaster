/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "ns3/integer.h"
#include "ns3/double.h"
#include "robo-weapon.h"
namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (Weapon);
NS_OBJECT_ENSURE_REGISTERED (LargeWeapon);
NS_OBJECT_ENSURE_REGISTERED (SmallWeapon);
NS_LOG_COMPONENT_DEFINE ("Weapon");
Weapon::Weapon ()
{
}
Weapon::~Weapon ()
{
}
TypeId
Weapon::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::Weapon").SetParent<Object> ().SetGroupName ("Robo").AddConstructor<Weapon> ();
  return tid;
}
TypeId
Weapon::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
int
Weapon::GetNumber (void) const
{
  return m_number;
}
void
Weapon::SetNumber (int number)
{
  NS_ASSERT (number <= m_maxNumber);
  m_number = number;
}
int
Weapon::AddAmmo (int num)
{
  NS_ASSERT (num > 0);
  int realAdd = num;
  if (m_number + num > m_maxNumber)
    {
      realAdd = m_maxNumber - num;
    }
  m_number += realAdd;
  return realAdd;
}
bool
Weapon::UseAmmo (int num = 1)
{
  if (m_number < num)
    {
      return false;
    }
  else
    {
      m_number -= num;
      return true;
    }
}

int
Weapon::GetInjury (void) const
{
  return m_injury;
}
void
Weapon::SetInjury (int injury)
{
  m_injury = injury;
}

Time
Weapon::GetPeriod (void) const
{
  return m_period;
}
void
Weapon::SetPeriod (Time period)
{
  m_period = period;
}

float
Weapon::GetSpeed (void) const
{
  return m_speed;
}

void
Weapon::SetSpeed (float speed)
{
  m_speed = speed;
}

float
Weapon::GetRange (void) const
{
  return m_range;
}

void
Weapon::SetRange (float range)
{
  m_range = range;
}

/////////////////////////////////////////

LargeWeapon::LargeWeapon ()
{
}

LargeWeapon::~LargeWeapon ()
{
}

TypeId
LargeWeapon::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::LargeWeapon")
          .SetParent<Weapon> ()
          .SetGroupName ("Robo")
          .AddConstructor<LargeWeapon> ()
          .AddAttribute ("Injury", "The injury of this ammo", IntegerValue (100),
                         MakeIntegerAccessor (&LargeWeapon::m_injury), MakeIntegerChecker<int> (0))
          .AddAttribute ("Number", "The init number of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&LargeWeapon::m_number), MakeIntegerChecker<int> (0))
          .AddAttribute ("Speed", "The max speed of this ammo", DoubleValue (16.5),
                         MakeDoubleAccessor (&LargeWeapon::m_speed), MakeDoubleChecker<float> (0))
          .AddAttribute ("Period", "The min period between ammos", TimeValue (Seconds (1.0 / 3)),
                         MakeTimeAccessor (&LargeWeapon::m_period), MakeTimeChecker (Seconds (0)))
          .AddAttribute ("MaxNumber", "The max number of this ammo", IntegerValue (50),
                         MakeIntegerAccessor (&LargeWeapon::m_maxNumber),
                         MakeIntegerChecker<int> (0))
          .AddAttribute ("Range", "The effective distance of this ammo", DoubleValue (7),
                         MakeDoubleAccessor (&LargeWeapon::m_range), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
LargeWeapon::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
///////////////////////////////////
SmallWeapon::SmallWeapon ()
{
}

SmallWeapon::~SmallWeapon ()
{
}

TypeId
SmallWeapon::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::SmallWeapon")
          .SetParent<Weapon> ()
          .SetGroupName ("Robo")
          .AddConstructor<SmallWeapon> ()
          .AddAttribute ("Injury", "The injury of this ammo", IntegerValue (10),
                         MakeIntegerAccessor (&SmallWeapon::m_injury), MakeIntegerChecker<int> (0))
          .AddAttribute ("Number", "The init number of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&SmallWeapon::m_number), MakeIntegerChecker<int> (0))
          .AddAttribute ("Speed", "The max speed of this ammo", DoubleValue (25),
                         MakeDoubleAccessor (&SmallWeapon::m_speed), MakeDoubleChecker<float> (0))
          .AddAttribute ("Period", "The min period between ammos", TimeValue (Seconds (1.0 / 10)),
                         MakeTimeAccessor (&SmallWeapon::m_period), MakeTimeChecker (Seconds (0)))
          .AddAttribute ("MaxNumber", "The max number of this ammo", IntegerValue (200),
                         MakeIntegerAccessor (&SmallWeapon::m_maxNumber),
                         MakeIntegerChecker<int> (0))
          .AddAttribute ("Range", "The effective distance of this ammo", DoubleValue (10),
                         MakeDoubleAccessor (&SmallWeapon::m_range), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
SmallWeapon::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
} // namespace ns3
