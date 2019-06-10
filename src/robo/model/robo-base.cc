/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-base.h"
#include "robo-common.h"
#include "ns3/integer.h"
#include "ns3/double.h"
#include "ns3/enum.h"
#include "ns3/pointer.h"

namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (RoboBase);
NS_LOG_COMPONENT_DEFINE ("RoboBase");
RoboBase::RoboBase ()
{
  NS_LOG_FUNCTION (this);
  m_uid = AllocUid ();
  m_largeAmmo = CreateObject<LargeWeapon> ();
  m_smallAmmo = CreateObject<SmallWeapon> ();
  m_lastShootLarge = Seconds (-1);
  m_lastShootSmall = Seconds (-1);
  AddCollisionCallback (MakeCallback (&RoboBase::HandleCollision, this));
}
RoboBase::~RoboBase ()
{
  NS_LOG_FUNCTION (this);
}
TypeId
RoboBase::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::RoboBase")
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
  return m_collision->GetGlobalLocation ();
}
void
RoboBase::SetLocation (FVector location)
{
  m_collision->SetGlobalLocation (location);
}
int
RoboBase::GetLargeAmmoNumber (void) const
{
  return m_largeAmmo->GetNumber ();
}
void
RoboBase::SetLargeAmmoNumber (int num)
{
  m_largeAmmo->SetNumber (num);
}
bool
RoboBase::IsLargeAmmoCanShoot (void) const
{
  bool numberJudge = m_largeAmmo->GetNumber () >= 1;
  bool timeJudge = Simulator::Now () > m_lastShootLarge + m_largeAmmo->GetPeriod ();
  // std::cout << numberJudge << " & " << timeJudge << std::endl;
  return numberJudge && timeJudge;
}
void
RoboBase::ShootLargeAmmo (FVector speed)
{
  NS_LOG_FUNCTION (this);
  if (!IsLargeAmmoCanShoot ())
    {
      return;
    }
  if (speed.GetLength () <= m_largeAmmo->GetSpeed ())
    {
      // puts ("Speed OK");
      Ptr<RoboAmmo> Ammo = CreateObject<RoboAmmo> ();
      if (m_largeAmmo->UseAmmo (1))
        {
          std::cout << "Shoot Ammo at " << m_collision->GetGlobalLocation () << " with speed "
                    << speed << " and range " << m_largeAmmo->GetRange () << std::endl;
          Ammo->SetSpeed (speed);
          Ammo->SetShooterUid (m_uid);
          Ammo->SetInjury (m_largeAmmo->GetInjury ());
          Ammo->SetRange (m_largeAmmo->GetRange ());
          Ammo->SetInitValue (m_collision->GetGlobalLocation (), gLargeAmmoRedius);
          Ammo->Initialize ();
          m_judge->AddLargeAmmo (Ammo);
          m_lastShootLarge = Simulator::Now ();
        }
    }
}

int
RoboBase::GetSmallAmmoNumber (void) const
{
  return m_smallAmmo->GetNumber ();
}
void
RoboBase::SetSmallAmmoNumber (int num)
{
  m_smallAmmo->SetNumber (num);
}
bool
RoboBase::IsSmallAmmoCanShoot (void) const
{
  bool numberJudge = m_smallAmmo->GetNumber () >= 1;
  bool timeJudge = Simulator::Now () > m_lastShootSmall + m_smallAmmo->GetPeriod ();
  return numberJudge && timeJudge;
}
void
RoboBase::ShootSmallAmmo (FVector speed)
{
  NS_LOG_FUNCTION (this);
  if (!IsSmallAmmoCanShoot ())
    {
      return;
    }
  if (speed.GetLength () <= m_smallAmmo->GetSpeed ())
    {
      Ptr<RoboAmmo> Ammo = CreateObject<RoboAmmo> ();
      if (m_smallAmmo->UseAmmo (1))
        {
          Ammo->SetSpeed (speed);
          Ammo->SetShooterUid (m_uid);
          Ammo->SetInjury (m_smallAmmo->GetInjury ());
          Ammo->SetRange (m_smallAmmo->GetRange ());
          Ammo->SetInitValue (m_collision->GetGlobalLocation (), gSmallAmmoRedius);
          Ammo->Initialize ();
          m_judge->AddSmallAmmo (Ammo);
          m_lastShootSmall = Simulator::Now ();
        }
    }
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
void
RoboBase::IndicateLocation (Ptr<RoboActor> oth)
{
  NS_LOG_FUNCTION (this);
  Ptr<RoboBase> othRobo = DynamicCast<RoboBase> (oth);
  m_knownLocation[othRobo->GetUid ()] =
      (LocationInfo){othRobo->GetUid (), othRobo->GetLocation (), Simulator::Now ()};
}

LocationInfo
RoboBase::GetKnownLocation (uint8_t uid)
{
  auto iter = m_knownLocation.find (uid);
  if (iter != m_knownLocation.end ())
    {
      return iter->second;
    }
  else
    {
      return (LocationInfo){255, FVector (), Seconds (0)};
    }
}

void
RoboBase::HandleCollision (Ptr<RoboActor> oth)
{
  NS_LOG_FUNCTION (this);
  // std::cout << "Collision" << m_name << " at " << m_collision->GetGlobalLocation () << std::endl;
  Ptr<RoboAmmo> ammo = DynamicCast<RoboAmmo> (oth);
  if (ammo != 0)
    {
      // std::cout << (int) m_uid << " Collision Ammo " << (int) ammo->GetShooterUid () << std::endl;
      if (ammo->GetShooterUid () == m_uid)
        {
          return;
        }
      // puts ("OK1");
      if (ammo->GetRange () <= 0)
        {
          return;
        }
      // std::cout << ammo->GetRange () << std::endl;
      // puts ("OK2");
      if (m_isDestroy)
        {
          return;
        }
      // puts ("OK3");
      m_life -= ammo->GetInjury ();
      if (m_life <= 0)
        {
          Disable ();
        }
      ammo->Disable ();
      std::cout << "Be shot at " << Simulator::Now ().GetSeconds () << std::endl;
      return;
    }
  Ptr<RoboBase> robo = DynamicCast<RoboBase> (oth);
  if (robo != 0)
    {
      FVector oldLocation = GetLocation ();
      SetLocation (oldLocation - m_speed * m_updatePeriod);
      m_speed = -m_speed;
      std::cout << "Collision robot at " << Simulator::Now ().GetSeconds () << std::endl;
      return;
    }
}

void
RoboBase::SetName (std::string name)
{
  m_name = name;
}

std::string
RoboBase::GetName () const
{
  return m_name;
}

void
RoboBase::ReceiveLargeAmmo (uint32_t num)
{
  NS_LOG_FUNCTION (this);
  m_largeAmmo->AddAmmo (num);
}

void
RoboBase::ReceiveSmallAmmo (uint32_t num)
{
  NS_LOG_FUNCTION (this);
  m_smallAmmo->AddAmmo (num);
}

void
RoboBase::GaveLargeAmmoTo (std::string roboName, uint32_t num)
{
  NS_LOG_FUNCTION (this);
  m_judge->TransLargeAmmo (this, roboName, num);
}

void
RoboBase::GaveSmallAmmoTo (std::string RoboName, uint32_t num)
{
  NS_LOG_FUNCTION (this);
  m_judge->TransSmallAmmo (this, RoboName, num);
}
} // namespace ns3
