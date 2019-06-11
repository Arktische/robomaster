/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 HUST Dian Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Original Author: Pengyu Liu    <eicliupengyu@gmail.com>
 * Modified by:     Zhichao Liu
 */
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
