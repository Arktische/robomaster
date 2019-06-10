/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

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
