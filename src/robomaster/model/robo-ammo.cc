#include "ns3/integer.h"
#include "ns3/double.h"
#include "robo-ammo.h"
namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (Ammo);
NS_OBJECT_ENSURE_REGISTERED (LargeAmmo);
NS_OBJECT_ENSURE_REGISTERED (SmallAmmo);
Ammo::Ammo ()
{
}
Ammo::~Ammo ()
{
}
TypeId
Ammo::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::Ammo").SetParent<Object> ().SetGroupName ("Robomaster").AddConstructor<Ammo> ();
  return tid;
}
TypeId
Ammo::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
int
Ammo::GetNumber (void) const
{
  return m_number;
}
void
Ammo::SetNumber (int number)
{
  m_number = number;
}
int
Ammo::AddAmmo (int num)
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
Ammo::UseAmmo (int num = 1)
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
Ammo::GetInjury (void) const
{
  return m_injury;
}
void
Ammo::SetInjury (int injury)
{
  m_injury = injury;
}

Time
Ammo::GetPeriod (void) const
{
  return m_period;
}
void
Ammo::SetPeriod (Time period)
{
  m_period = period;
}

float
Ammo::GetSpeed (void) const
{
  return m_speed;
}

void
Ammo::SetSpeed (float speed)
{
  m_speed = speed;
}

float
Ammo::GetRange (void) const
{
  return m_range;
}

void
Ammo::SetRange (float range)
{
  m_range = range;
}

/////////////////////////////////////////

LargeAmmo::LargeAmmo ()
{
}

LargeAmmo::~LargeAmmo ()
{
}

TypeId
LargeAmmo::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::LargeAmmo")
          .SetParent<Ammo> ()
          .SetGroupName ("Robomaster")
          .AddConstructor<LargeAmmo> ()
          .AddAttribute ("Injury", "The injury of this ammo", IntegerValue (100),
                         MakeIntegerAccessor (&LargeAmmo::m_injury), MakeIntegerChecker<int> (0))
          .AddAttribute ("Number", "The init number of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&LargeAmmo::m_number), MakeIntegerChecker<int> (0))
          .AddAttribute ("Speed", "The max speed of this ammo", DoubleValue (16.5),
                         MakeDoubleAccessor (&LargeAmmo::m_speed), MakeDoubleChecker<float> (0))
          .AddAttribute ("Period", "The min period between ammos", TimeValue (Seconds (1.0 / 3)),
                         MakeTimeAccessor (&LargeAmmo::m_period), MakeTimeChecker (Seconds (0)))
          .AddAttribute ("MaxNumber", "The max number of this ammo", IntegerValue (50),
                         MakeIntegerAccessor (&LargeAmmo::m_maxNumber), MakeIntegerChecker<int> (0))
          .AddAttribute ("Range", "The effective distance of this ammo", DoubleValue (7),
                         MakeDoubleAccessor (&LargeAmmo::m_range), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
LargeAmmo::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
///////////////////////////////////
SmallAmmo::SmallAmmo ()
{
}

SmallAmmo::~SmallAmmo ()
{
}

TypeId
SmallAmmo::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::SmallAmmo")
          .SetParent<Ammo> ()
          .SetGroupName ("Robomaster")
          .AddConstructor<SmallAmmo> ()
          .AddAttribute ("Injury", "The injury of this ammo", IntegerValue (10),
                         MakeIntegerAccessor (&SmallAmmo::m_injury), MakeIntegerChecker<int> (0))
          .AddAttribute ("Number", "The init number of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&SmallAmmo::m_number), MakeIntegerChecker<int> (0))
          .AddAttribute ("Speed", "The max speed of this ammo", DoubleValue (25),
                         MakeDoubleAccessor (&SmallAmmo::m_speed), MakeDoubleChecker<float> (0))
          .AddAttribute ("Period", "The min period between ammos", TimeValue (Seconds (1.0 / 10)),
                         MakeTimeAccessor (&SmallAmmo::m_period), MakeTimeChecker (Seconds (0)))
          .AddAttribute ("MaxNumber", "The max number of this ammo", IntegerValue (200),
                         MakeIntegerAccessor (&SmallAmmo::m_maxNumber), MakeIntegerChecker<int> (0))
          .AddAttribute ("Range", "The effective distance of this ammo", DoubleValue (10),
                         MakeDoubleAccessor (&SmallAmmo::m_range), MakeDoubleChecker<float> (0));
  return tid;
}
TypeId
SmallAmmo::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
} // namespace ns3
