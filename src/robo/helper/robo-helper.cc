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

#include "robo-helper.h"

namespace ns3 {

RoboHelper::RoboHelper ()
{
  m_judge = CreateObject<RoboJudge> ();
  NS_ASSERT_MSG (m_judge != 0, "Cannot create RoboJudge");
  m_judge->Initialize ();
}

RoboHelper::~RoboHelper ()
{
}

void
RoboHelper::AddTeam (TeamConfig config, FVector location, FAngle rotation)
{
  Ptr<RoboTeamHelper> team = Create<RoboTeamHelper> ();
  team->SetJudge (m_judge);
  team->SetInitLocation (location);
  team->SetInitRotation (rotation);
  team->Install (config);
  m_teams.push_back (team);
}

void
RoboHelper::FinishAdd (void)
{
  m_judge->FinishAdd ();
}

Ptr<RoboTeamHelper>
RoboHelper::GetTeam (uint8_t teamId)
{
  NS_ASSERT_MSG (teamId < m_teams.size (), "Team Id Error");
  return m_teams[teamId];
}

NodeContainer
RoboHelper::GetAllNodes (void)
{
  NodeContainer ret;
  for (auto &tm : m_teams)
    {
      ret.Add (tm->m_nodes);
    }
  return ret;
}

Ptr<RoboBase>
RoboHelper::GetRoboOfTeam (std::string roboName, uint8_t team)
{
  return GetTeam (team)->GetRobotByName (roboName);
}
} // namespace ns3
