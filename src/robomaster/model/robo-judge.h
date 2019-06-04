/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-base.h"

namespace ns3 {
class RoboJudge
{
private:
  std::vector<Ptr<RoboBase>> m_robos;
  std::list<ShootParam> m_shoots;

public:
  RoboJudge ();
  ~RoboJudge ();
};

} // namespace ns3
