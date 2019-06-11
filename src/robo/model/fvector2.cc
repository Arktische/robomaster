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
  return sqrtf (m_x * m_x + m_y * m_y);
}
std::ostream &
operator<< (std::ostream &os, const FVector2 &vector)
{
  os << vector.m_x << ":" << vector.m_y;
  return os;
}

float
Dot (FVector2 v1, FVector2 v2)
{
  return v1.m_x * v2.m_x + v1.m_y * v2.m_y;
}

} // namespace ns3
