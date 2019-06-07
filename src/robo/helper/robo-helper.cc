/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "robo-helper.h"

namespace ns3 {

RoboHelper::RoboHelper ()
{
}

RoboHelper::~RoboHelper ()
{
}

void
RoboHelper::Init (TeamConfig config, uint8_t teamNum = 2)
{
  NS_ASSERT_MSG (!m_hasInit, "Init Twice");
  m_hasInit = true;
  for (int i = 0; i < teamNum; ++i)
    {
      Ptr<RoboTeamHelper> team = Create<RoboTeamHelper> ();
      team->Install (config);
      m_teams.push_back (team);
    }
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
