/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once

namespace ns3 {
class Vector3
{
public:
  Vector3 ();
  Vector3 (float x, float y, float z);
  Vector3 (const Vector3 &oth);
  Vector3 (float x, float y);
  Vector3 operator+ (Vector3 &oth);
  Vector3 operator- (Vector3 &oth);
  Vector3 operator* (Vector3 &oth);
  Vector3 operator* (float oth);
  float GetDistance (Vector3 &oth);
  float GetDistance2 (Vector3 &oth);

  float m_x;
  float m_y;
  float m_z;
};
} // namespace ns3
