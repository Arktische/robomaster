/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-team-helper.h"
namespace ns3 {

RoboTeamHelper::RoboTeamHelper ()
{
  m_teamId = AllocateTeamId ();
}

RoboTeamHelper::~RoboTeamHelper ()
{
}
Ptr<RoboBase>
RoboTeamHelper::CreateRobot (MemberType type)
{
  switch (type)
    {
    case Member_Type_Hero:
      return CreateObject<RoboHero> ();
    case Member_Type_Infantry:
      return CreateObject<RoboInfantry> ();
    case Member_Type_Sentry:
    case Member_Type_AeroRobot:
    case Member_Type_Engineer:
      NS_ABORT_MSG ("Unsupported Type");
    case Member_Type_Tower:
      return CreateObject<RoboTower> ();
    default:
      NS_ABORT_MSG ("Unknown Type");
    }
}
void
RoboTeamHelper::Install (TeamConfig config)
{
  if (m_hasInstalled)
    {
      NS_ABORT_MSG ("Init a team twice");
    }
  m_hasInstalled = true;
  for (unsigned i = 0; i < config.size (); ++i)
    {
      auto &cfg = config[i];
      NS_ASSERT_MSG (m_nameRoboMap.find (cfg.m_name) == m_nameRoboMap.end (), "Name Conflice");
      Ptr<RoboBase> robo = CreateRobot (cfg.m_type);
      robo->SetTeam (m_teamId);
      m_nameRoboMap.emplace (cfg.m_name, robo);
      m_uidNameMap.emplace (robo->GetUid (), cfg.m_name);
    }
}
Ptr<RoboBase>
RoboTeamHelper::GetRobotByName (std::string roboName)
{
  auto iter = m_nameRoboMap.find (roboName);
  NS_ASSERT_MSG (iter != m_nameRoboMap.end (), "Cannot find this robot");
  return iter->second;
}

Ptr<Node>
RoboTeamHelper::GetNodeByRoboName (std::string roboName)
{
  auto iter = m_nameRoboMap.find (roboName);
  NS_ASSERT_MSG (iter != m_nameRoboMap.end (), "Cannot find this robot");
  return iter->second->GetObject<Node> ();
}

uint8_t
RoboTeamHelper::AllocateTeamId (void)
{
  static uint8_t teamId = 0;
  return teamId++;
}

} // namespace ns3
