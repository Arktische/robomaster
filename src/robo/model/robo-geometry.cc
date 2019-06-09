/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-geometry.h"
#include <cmath>

namespace ns3 {
LineSegment::LineSegment (FVector st, FVector ed) : m_start (st), m_end (ed)
{
}
LineSegment::LineSegment (const LineSegment &oth) : m_start (oth.m_start), m_end (oth.m_end)
{
}
LineSegment::LineSegment (float x1, float y1, float x2, float y2)
    : m_start (FVector (x1, y1)), m_end (FVector (x2, y2))
{
}
LineSegment::~LineSegment ()
{
}
//////////////////TODO////////////////
bool
LineSegment::isCross (LineSegment &oth)
{
  return ((((oth.m_start - m_start) * (oth.m_end - m_start)) *
           ((m_start - oth.m_start) * (m_end - oth.m_start))) > 0);
}
bool
LineSegment::isParallelism (LineSegment &oth)
{
  return 1;
}
bool
LineSegment::isVertical (LineSegment &oth)
{
  return 1;
}

FVector2
ConvCoordinate (FVector2 centerOfSubcoordinate, FAngle2 directionOfSubcoordinate,
                FVector2 coordinate)
{
  float cosOfAngle = cosf (directionOfSubcoordinate.m_phi);
  float sinOfAngle = sinf (directionOfSubcoordinate.m_phi);
  FVector2 offset (coordinate.m_x * cosOfAngle - coordinate.m_y * sinOfAngle,
                   coordinate.m_x * sinOfAngle + coordinate.m_y * cosOfAngle);
  return centerOfSubcoordinate + offset;
}
} // namespace ns3
