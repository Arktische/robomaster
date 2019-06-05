/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-base.h"
namespace ns3 {
class RoboTower : public RoboBase
{
private:
public:
  RoboTower ();
  virtual ~RoboTower ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};

} // namespace ns3
