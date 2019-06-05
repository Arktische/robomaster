/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once

// #include "ns3/robo.h"
#include "ns3/core-module.h"
#include "ns3/robo-module.h"

namespace ns3 {

class RoboTeamHelper
{
private:
  std::unordered_map<std::string, Ptr<RoboActor>> m_robos;

public:
  RoboTeamHelper ();
  ~RoboTeamHelper ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  void AddRobot (std::string roboName, Ptr<RoboActor> robot);
  void GetSmallAmmoNumber (std::string roboName);
  void GetLargeAmmoNumber (std::string roboName);
  void GetRoboLocation (std::string roboName);
  void GetRoboSpeed (std::string roboName);
};


} // namespace ns3
