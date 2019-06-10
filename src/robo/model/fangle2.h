/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#define PI 3.14159265f
#include <ostream>
namespace ns3 {
class FAngle2
{
public:
  float m_phi;
  FAngle2 ();
  FAngle2 (float phi);
  ~FAngle2 ();
  void SetAngle (float angle);
  float GetAngle (void) const;
  FAngle2 operator+ (FAngle2 oth);
  FAngle2 operator+= (FAngle2 oth);
  FAngle2 operator- (FAngle2 oth);
  FAngle2 operator- (void);
  FAngle2 operator-= (FAngle2 oth);

  //角度转换为弧度
  friend float AngleToRadian (float angle);
  //弧度转换为角度
  friend float RadianToAngle (float radian);
  friend std::ostream &operator<< (std::ostream &os, const FAngle2 &angle);
};

} // namespace ns3
