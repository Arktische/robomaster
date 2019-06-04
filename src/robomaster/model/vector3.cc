/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "vector3.h"
#include "math.h"

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
Vector3::Vector3 (float x, float y) : m_x (x), m_y (y), m_z (0)
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
  return Vector3 (m_y * oth.m_z - m_z * oth.m_y, m_z * oth.m_x - m_x * oth.m_z,
                  m_x * oth.m_y - m_y * oth.m_x);
}
Vector3 Vector3::operator* (float oth)
{
  return Vector3 (m_x * oth, m_y * oth, m_z * oth);
}
float
Vector3::GetDistance (Vector3 &oth)
{
  return sqrtf ((m_x - oth.m_x) * (m_x - oth.m_x) + (m_y - oth.m_y) * (m_y - oth.m_y) +
                (m_z - oth.m_z) * (m_z - oth.m_z));
}
float
Vector3::GetDistance2 (Vector3 &oth)
{
  return (m_x - oth.m_x) * (m_x - oth.m_x) + (m_y - oth.m_y) * (m_y - oth.m_y) +
         (m_z - oth.m_z) * (m_z - oth.m_z);
}
} // namespace ns3
