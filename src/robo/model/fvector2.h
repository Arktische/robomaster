/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include <ostream>
namespace ns3 {
class FVector2
{
public:
  FVector2 (void);
  FVector2 (float x, float y);
  FVector2 (const FVector2 &oth);
  FVector2 operator+ (FVector2 oth);
  FVector2 operator+= (FVector2 oth);
  FVector2 operator- (FVector2 oth);
  FVector2 operator- (void);
  FVector2 operator-= (FVector2 oth);
  float operator* (FVector2 oth);
  FVector2 operator* (float oth);
  float GetDistance (FVector2 oth) const;
  float GetDistance2 (FVector2 oth) const;
  float GetLength (void) const;

  friend std::ostream &operator<< (std::ostream &os, const FVector2 &vector);

  float m_x;
  float m_y;
};
float Dot (FVector2 v1, FVector2 v2);
} // namespace ns3
