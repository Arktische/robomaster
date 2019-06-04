/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "vector2.h"
namespace ns3 {
class LineSegment
{
public:
  Vector2 m_start;
  Vector2 m_end;

  LineSegment (Vector2 st, Vector2 ed);
  LineSegment (float x1, float y1, float x2, float y2);
  LineSegment (const LineSegment &oth);
  ~LineSegment ();

  bool isCross (LineSegment &oth);
  bool isParallelism (LineSegment &oth);
  bool isVertical (LineSegment &oth);
};

} // namespace ns3
