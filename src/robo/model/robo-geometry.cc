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

bool
IsCross (FVector2 st1, FVector2 ed1, FVector2 st2, FVector2 ed2)
{
  //快速排斥实验
  if ((st1.m_x > ed1.m_x ? st1.m_x : ed1.m_x) < (st2.m_x < ed2.m_x ? st2.m_x : ed2.m_x) ||
      (st1.m_y > ed1.m_y ? st1.m_y : ed1.m_y) < (st2.m_y < ed2.m_y ? st2.m_y : ed2.m_y) ||
      (st2.m_x > ed2.m_x ? st2.m_x : ed2.m_x) < (st1.m_x < ed1.m_x ? st1.m_x : ed1.m_x) ||
      (st2.m_y > ed2.m_y ? st2.m_y : ed2.m_y) < (st1.m_y < ed1.m_y ? st1.m_y : ed1.m_y))
    {
      return false;
    }
  //跨立实验
  if ((((st1.m_x - st2.m_x) * (ed2.m_y - st2.m_y) - (st1.m_y - st2.m_y) * (ed2.m_x - st2.m_x)) *
       ((ed1.m_x - st2.m_x) * (ed2.m_y - st2.m_y) - (ed1.m_y - st2.m_y) * (ed2.m_x - st2.m_x))) >
          0 ||
      (((st2.m_x - st1.m_x) * (ed1.m_y - st1.m_y) - (st2.m_y - st1.m_y) * (ed1.m_x - st1.m_x)) *
       ((ed2.m_x - st1.m_x) * (ed1.m_y - st1.m_y) - (ed2.m_y - st1.m_y) * (ed1.m_x - st1.m_x))) > 0)
    {
      return false;
    }
  return true;
}

bool
IsCross (const LineSegment l1, const LineSegment l2)
{
  //快速排斥实验
  if ((l1.m_start.m_x > l1.m_end.m_x ? l1.m_start.m_x : l1.m_end.m_x) <
          (l2.m_start.m_x < l2.m_end.m_x ? l2.m_start.m_x : l2.m_end.m_x) ||
      (l1.m_start.m_y > l1.m_end.m_y ? l1.m_start.m_y : l1.m_end.m_y) <
          (l2.m_start.m_y < l2.m_end.m_y ? l2.m_start.m_y : l2.m_end.m_y) ||
      (l2.m_start.m_x > l2.m_end.m_x ? l2.m_start.m_x : l2.m_end.m_x) <
          (l1.m_start.m_x < l1.m_end.m_x ? l1.m_start.m_x : l1.m_end.m_x) ||
      (l2.m_start.m_y > l2.m_end.m_y ? l2.m_start.m_y : l2.m_end.m_y) <
          (l1.m_start.m_y < l1.m_end.m_y ? l1.m_start.m_y : l1.m_end.m_y))
    {
      return false;
    }
  //跨立实验
  if ((((l1.m_start.m_x - l2.m_start.m_x) * (l2.m_end.m_y - l2.m_start.m_y) -
        (l1.m_start.m_y - l2.m_start.m_y) * (l2.m_end.m_x - l2.m_start.m_x)) *
       ((l1.m_end.m_x - l2.m_start.m_x) * (l2.m_end.m_y - l2.m_start.m_y) -
        (l1.m_end.m_y - l2.m_start.m_y) * (l2.m_end.m_x - l2.m_start.m_x))) > 0 ||
      (((l2.m_start.m_x - l1.m_start.m_x) * (l1.m_end.m_y - l1.m_start.m_y) -
        (l2.m_start.m_y - l1.m_start.m_y) * (l1.m_end.m_x - l1.m_start.m_x)) *
       ((l2.m_end.m_x - l1.m_start.m_x) * (l1.m_end.m_y - l1.m_start.m_y) -
        (l2.m_end.m_y - l1.m_start.m_y) * (l1.m_end.m_x - l1.m_start.m_x))) > 0)
    {
      return false;
    }
  return true;
}

bool
PointInTriangle (FVector2 point, FVector2 p1, FVector2 p2, FVector2 p3)
{
  FVector2 lineSeg1 = p1 - point;
  FVector2 lineSeg2 = p2 - point;
  FVector2 lineSeg3 = p3 - point;
  float cross12 = lineSeg1 * lineSeg2;
  float cross23 = lineSeg2 * lineSeg3;
  float cross31 = lineSeg3 * lineSeg1;
  return !(cross12 * cross23 < 0 || cross23 * cross31 < 0 || cross31 * cross12 < 0);
}

bool
CircleCrossLineSegment (FVector2 center, float redius, FVector2 st, FVector2 ed)
{
  if (center.GetDistance (st) <= redius || center.GetDistance (ed) <= redius)
    {
      return true;
    }
  float cos1 = Dot (center - st, ed - st) / (center.GetDistance (st) * ed.GetDistance (st));
  float cos2 = Dot (center - ed, st - ed) / (center.GetDistance (ed) * ed.GetDistance (st));

  if (cos1 <= 0 || cos2 <= 0)
    {
      return false;
    }
  return center.GetDistance (st) * sqrtf (1 - cos1 * cos1) <= redius;
}
} // namespace ns3
