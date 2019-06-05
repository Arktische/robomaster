/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "fvector2.h"
#include "fangle2.h"
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

  bool isCross (LineSegment &oth);
  bool isParallelism (LineSegment &oth);
  bool isVertical (LineSegment &oth);
};

} // namespace ns3
