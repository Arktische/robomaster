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

FVector2 ConvCoordinate (FVector2 centerOfSubcoordinate, FAngle2 directionOfSubcoordinate,
                         FVector2 coordinate);
bool IsCross (FVector2 st1, FVector2 ed1, FVector2 st2, FVector2 ed2);
bool IsCross (const LineSegment l1, const LineSegment l2);
bool PointInTriangle (FVector2 point, FVector2 p1, FVector2 p2, FVector2 p3);
bool CircleCrossLineSegment (FVector2 center, float redius, FVector2 st, FVector2 ed);
} // namespace ns3
