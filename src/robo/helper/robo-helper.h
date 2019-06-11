/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 HUST Dian Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Original Author: Pengyu Liu <eicliupengyu@gmail.com>
 */
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
  Ptr<RoboJudge> m_judge;

public:
  RoboHelper ();
  ~RoboHelper ();

  void AddTeam (TeamConfig config, FVector location, FAngle rotation);
  void FinishAdd (void);
  Ptr<RoboTeamHelper> GetTeam (uint8_t teamId);
  NodeContainer GetAllNodes (void);

  Ptr<RoboBase> GetRoboOfTeam (std::string roboName, uint8_t team);
};

} // namespace ns3
