/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once

// #include "ns3/robo.h"
#include "ns3/core-module.h"
#include "ns3/robo-actor.h"

namespace ns3 {

class RoboHelper
{
private:
  std::vector<Ptr<RoboActor> > m_robots;
  std::list<Ptr<RoboActor> > m_smallAmmos;
  std::list<Ptr<RoboActor> > m_largeAmmos;
public:
  RoboHelper ();
  ~RoboHelper ();
};

} // namespace ns3
