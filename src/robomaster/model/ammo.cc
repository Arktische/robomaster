#include "ammo.h"
namespace ns3 {
OBJECT_ENSURE_REGISTERED (Ammo);
OBJECT_ENSURE_REGISTERED (LargeAmmo);

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
      TypeId ("ns3::Ammo")
          .SetParent<Object> ()
          .SetGroupName ("Robomaster")
          .AddConstructor<Ammo> ()
          .AddAttribute ("Injury", "The injury of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&Ammo::m_injury), MakeIntegerChecker<int> (0))
          .AddAttribute ("Number", "The number of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&Ammo::m_number), MakeIntegerChecker<int> (0));
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
Ammo::AddAmmo (int num)
{
  NS_ASSERT (num > 0);
  m_number += num;
}
bool
Ammo::UseAmmo (int num)
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
          .AddAttribute ("Injury", "The injury of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&LargeAmmo::m_injury), MakeIntegerChecker<int> (0))
          .AddAttribute ("Number", "The number of this ammo", IntegerValue (0),
                         MakeIntegerAccessor (&LargeAmmo::m_number), MakeIntegerChecker<int> (0));
}
TypeId
LargeAmmo::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
} // namespace ns3
