/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-base.h"
namespace ns3 {
class RoboHero : public RoboBase
{
public:
  RoboHero ();
  virtual ~RoboHero ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void Init();
};

} // namespace ns3
