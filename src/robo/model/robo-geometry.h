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
 * Modified by:     Zhichao Liu
 */
#pragma once
#include "fvector2.h"
#include "fangle2.h"
const float EPS = 1e-4;

namespace ns3 {
typedef FVector2 FVector;
typedef FAngle2 FAngle;
class LineSegment
{
public:
  FVector m_start;
  FVector m_end;

  LineSegment (FVector st, FVector ed);
  LineSegment (float x1, float y1, float x2, float y2);
  LineSegment (const LineSegment &oth);
  ~LineSegment ();
};

FVector2 ConvCoordinate (FVector2 centerOfSubcoordinate, FAngle2 directionOfSubcoordinate,
                         FVector2 coordinate);
bool IsCross (FVector2 st1, FVector2 ed1, FVector2 st2, FVector2 ed2);
bool IsCross (const LineSegment l1, const LineSegment l2);
bool PointInTriangle (FVector2 point, FVector2 p1, FVector2 p2, FVector2 p3);
bool CircleCrossLineSegment (FVector2 center, float redius, FVector2 st, FVector2 ed);
} // namespace ns3
