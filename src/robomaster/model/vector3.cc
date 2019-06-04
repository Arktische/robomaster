/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "vector3.h"

namespace ns3 {
Vector3::Vector3 () : m_x (0), m_y (0), m_z (0)
{
}
Vector3::Vector3 (float x, float y, float z) : m_x (x), m_y (y), m_z (z)
{
}
Vector3::Vector3 (const Vector3 &oth) : m_x (oth.m_x), m_y (oth.m_y), m_z (oth.m_z)
{
}
Vector3::Vector3 (float x, float y) : m_x (x), m_y (y)
{
}
Vector3
Vector3::operator+ (Vector3 &oth)
{
  return Vector3 (m_x + oth.m_x, m_y + oth.m_y, m_z + oth.m_z);
}
Vector3
Vector3::operator- (Vector3 &oth)
{
  return Vector3 (m_x - oth.m_x, m_y - oth.m_y, m_z - oth.m_z);
}
Vector3 Vector3::operator* (Vector3 &oth)
{
  return Vector3 ();
}
Vector3 Vector3::operator* (float oth)
{
}
} // namespace ns3
