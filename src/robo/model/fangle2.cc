/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "fangle2.h"
namespace ns3 {
FAngle2::FAngle2 () : m_phi (0)
{
}
FAngle2::FAngle2 (float phi) : m_phi (phi)
{
}

FAngle2::~FAngle2 ()
{
}

void
FAngle2::SetAngle (float angle)
{
  m_phi = angle;
}

float
FAngle2::GetAngle (void) const
{
  return m_phi;
}

FAngle2
FAngle2::operator+ (FAngle2 oth)
{
  return FAngle2 (m_phi + oth.m_phi);
}

FAngle2
FAngle2::operator+= (FAngle2 oth)
{
  m_phi += oth.m_phi;
  return *this;
}

FAngle2
FAngle2::operator- (FAngle2 oth)
{
  return FAngle2 (m_phi - oth.m_phi);
}

FAngle2
FAngle2::operator- (void)
{
  return FAngle2 (-m_phi);
}

FAngle2
FAngle2::operator-= (FAngle2 oth)
{
  m_phi -= oth.m_phi;
  return *this;
}

float
AngleToRadian (float angle)
{
  return angle / 180 * PI;
}

float
RadianToAngle (float radian)
{
  return radian / PI * 180;
}

std::ostream &
operator<< (std::ostream &os, const FAngle2 &angle)
{
  os << angle.GetAngle ();
  return os;
}

} // namespace ns3
