/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "fvector2.h"
#include "math.h"

namespace ns3 {
FVector2::FVector2 (void) : m_x (0), m_y (0)
{
}
FVector2::FVector2 (float x, float y) : m_x (x), m_y (y)
{
}
FVector2::FVector2 (const FVector2 &oth) : m_x (oth.m_x), m_y (oth.m_y)
{
}
FVector2
FVector2::operator+ (FVector2 oth)
{
  return FVector2 (m_x + oth.m_x, m_y + oth.m_y);
}
FVector2
FVector2::operator+= (FVector2 oth)
{
  m_x += oth.m_x;
  m_y += oth.m_y;
  return *this;
}
FVector2
FVector2::operator- (FVector2 oth)
{
  return FVector2 (m_x - oth.m_x, m_y - oth.m_y);
}
FVector2
FVector2::operator- (void)
{
  return FVector2 (-m_x, -m_y);
}
FVector2
FVector2::operator-= (FVector2 oth)
{
  m_x -= oth.m_x;
  m_y -= oth.m_y;
  return *this;
}
float FVector2::operator* (FVector2 oth)
{
  return (m_x * oth.m_y - m_y * oth.m_x);
}
FVector2 FVector2::operator* (float oth)
{
  return FVector2 (m_x * oth, m_y * oth);
}
float
FVector2::GetDistance (FVector2 oth) const
{
  return sqrtf ((m_x - oth.m_x) * (m_x - oth.m_x) + (m_y - oth.m_y) * (m_y - oth.m_y));
}
float
FVector2::GetDistance2 (FVector2 oth) const
{
  return (m_x - oth.m_x) * (m_x - oth.m_x) + (m_y - oth.m_y) * (m_y - oth.m_y);
}
float
FVector2::GetLength (void) const
{
  return sqrt (m_x * m_x + m_y * m_y);
}
std::ostream &
operator<< (std::ostream &os, const FVector2 &vector)
{
  os << vector.m_x << ":" << vector.m_y;
  return os;
}

} // namespace ns3
