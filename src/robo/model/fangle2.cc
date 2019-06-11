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
#include "fangle2.h"
namespace ns3 {
FAngle2::FAngle2 () : m_phi (0)
{
}
FAngle2::FAngle2 (float phi) : m_phi (phi)
{
}

FAngle2::~FAngle2 ()
{
}

void
FAngle2::SetAngle (float angle)
{
  m_phi = angle;
}

float
FAngle2::GetAngle (void) const
{
  return m_phi;
}

FAngle2
FAngle2::operator+ (FAngle2 oth)
{
  return FAngle2 (m_phi + oth.m_phi);
}

FAngle2
FAngle2::operator+= (FAngle2 oth)
{
  m_phi += oth.m_phi;
  return *this;
}

FAngle2
FAngle2::operator- (FAngle2 oth)
{
  return FAngle2 (m_phi - oth.m_phi);
}

FAngle2
FAngle2::operator- (void)
{
  return FAngle2 (-m_phi);
}

FAngle2
FAngle2::operator-= (FAngle2 oth)
{
  m_phi -= oth.m_phi;
  return *this;
}

float
AngleToRadian (float angle)
{
  return angle / 180 * PI;
}

float
RadianToAngle (float radian)
{
  return radian / PI * 180;
}

std::ostream &
operator<< (std::ostream &os, const FAngle2 &angle)
{
  os << angle.GetAngle ();
  return os;
}

} // namespace ns3
