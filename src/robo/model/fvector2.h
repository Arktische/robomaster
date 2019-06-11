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
 * Original Author: Pengyu Liu <eicliupengyu@gmail.com>
 */
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
