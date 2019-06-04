/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once

namespace ns3 {
class Vector2
{
public:
  Vector2 ();
  Vector2 (float x, float y);
  Vector2 (const Vector2 &oth);
  Vector2 operator+ (Vector2 &oth);
  Vector2 operator- (Vector2 &oth);
  float operator* (Vector2 &oth);
  Vector2 operator* (float oth);
  float GetDistance (Vector2 &oth);

  float m_x;
  float m_y;
};
} // namespace ns3
