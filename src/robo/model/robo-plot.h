/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-actor.h"
namespace ns3 {

class RoboPlot
{
public:
  std::string m_plotFileName;
  RoboPlot ();
  ~RoboPlot ();
  //Format: "TimeInSeconds#roboTeam#roboName#roboLife#boundaryVertex1|boundaryVertex2|boundaryVertex3|...\n"
  void Plot (Ptr<RoboActor> obj, std::string roboName);
};

} // namespace ns3
