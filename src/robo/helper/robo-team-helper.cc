/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-team-helper.h"
#include "ns3/robo-common.h"
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
  m_nodes.Create (config.size ());
  for (unsigned i = 0; i < config.size (); ++i)
    {
      auto &cfg = config[i];
      NS_ASSERT_MSG (m_nameRoboMap.find (cfg.m_name) == m_nameRoboMap.end (), "Name Conflice");
      Ptr<RoboBase> robo = CreateRobot (cfg.m_type);
      robo->SetTeam (m_teamId);
      robo->SetJudge (m_judge);
      robo->SetName (cfg.m_name);
      //TODO局部坐标转换全局设置初始坐标
      robo->m_collision->m_type = Collision_Type_Polygon;
      robo->m_collision->m_selfMask = gRoboMask;
      robo->m_collision->m_collisionMask = gRoboCollisionMask;
      robo->m_collision->m_globalLocation =
          ConvCoordinate (m_teamInitLocation, m_teamInitRotation, cfg.m_initLocation);
      robo->m_collision->m_globalRotation = m_teamInitRotation + cfg.m_initRotation;
      robo->m_collision->AddBoundaryPoint (cfg.m_boundary);
      robo->m_speed = FVector ();
      ////DEBUG
      if (cfg.m_type == Member_Type_Hero)
        {
          robo->SetLargeAmmoNumber (25);
        }
      robo->SetSmallAmmoNumber (100);
      ////DEBUG
      m_judge->AddRobo (robo);
      m_nameRoboMap.emplace (cfg.m_name, robo);
      m_uidNameMap.emplace (robo->GetUid (), cfg.m_name);
      m_nodes.Get (i)->AggregateObject (robo);
      // std::cout << (int)robo->m_uid << std::endl;
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

void
RoboTeamHelper::SetJudge (Ptr<RoboJudge> judge)
{
  m_judge = judge;
}

void
RoboTeamHelper::SetInitLocation (FVector location)
{
  m_teamInitLocation = location;
}

void
RoboTeamHelper::SetInitRotation (FAngle rotation)
{
  m_teamInitRotation = rotation;
}
} // namespace ns3
