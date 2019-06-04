/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-geometry.h"

namespace ns3 {
LineSegment::LineSegment (Vector2 st, Vector2 ed) : m_start (st), m_end (ed)
{
}
LineSegment::LineSegment (const LineSegment &oth) : m_start (oth.m_start), m_end (oth.m_end)
{
}
LineSegment::LineSegment (float x1, float y1, float x2, float y2)
    : m_start (Vector2 (x1, y1)), m_end (Vector2 (x2, y2))
{
}
LineSegment::~LineSegment ()
{
}
bool
LineSegment::isCross (LineSegment &oth)
{
  return 1;
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
} // namespace ns3
