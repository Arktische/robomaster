/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "vector2.h"

namespace ns3 {
Vector2::Vector2 () : m_x (0), m_y (0)
{
}
Vector2::Vector2 (float x, float y) : m_x (x), m_y (y)
{
}
Vector2::Vector2 (const Vector2 &oth) : m_x (oth.m_x), m_y (oth.m_y)
{
}
Vector2
Vector2::operator+ (Vector2 &oth)
{
  return Vector2 (m_x + oth.m_x, m_y + oth.m_y);
}
Vector2
Vector2::operator- (Vector2 &oth)
{
  return Vector2 (m_x - oth.m_x, m_y - oth.m_y);
}
float Vector2::operator* (Vector2 &oth)
{
  return (m_x * oth.m_y - m_y * oth.m_x);
}
Vector2 Vector2::operator* (float oth)
{
  return Vector2 (m_x * oth, m_y * oth);
}
float
Vector2::GetDistance (Vector2 &oth)
{
  return (m_x - oth.m_x) * (m_x - oth.m_x) + (m_y - oth.m_y) * (m_y - oth.m_y);
}
} // namespace ns3
