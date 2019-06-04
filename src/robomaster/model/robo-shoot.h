/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/nstime.h"
#include "vector2.h"
namespace ns3 {
struct ShootParam
{
  int m_injury; //伤害值
  double m_range; //有效范围
  Time m_shootTime; //射击的时刻
  Vector2 m_shootLocation; //射击时的位置
  Vector2 m_shootSpeed; //射击的速度
};

} // namespace ns3
