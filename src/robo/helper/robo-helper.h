/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once

// #include "ns3/robo.h"
#include "ns3/core-module.h"
#include "ns3/robo-actor.h"
#include "ns3/robo-team-helper.h"
#include "ns3/robo-judge.h"

namespace ns3 {

class RoboHelper
{
private:
  std::vector<Ptr<RoboTeamHelper>> m_teams;
  bool m_hasInit{false};
  Ptr<RoboJudge> m_judge;

public:
  RoboHelper ();
  ~RoboHelper ();

  void Init (TeamConfig config, uint8_t teamNum);
  Ptr<RoboTeamHelper> GetTeam (uint8_t teamId);
  NodeContainer GetAllNodes (void);

  Ptr<RoboBase> GetRoboOfTeam (std::string roboName, uint8_t team);
};

} // namespace ns3
