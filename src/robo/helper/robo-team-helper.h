/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once

// #include "ns3/robo.h"
#include "ns3/core-module.h"
#include "ns3/node.h"
#include "ns3/robo-actor.h"
#include "ns3/robo-base.h"
#include "ns3/robo-hero.h"
#include "ns3/robo-infantry.h"
#include "ns3/robo-tower.h"
#include <unordered_map>

namespace ns3 {

enum MemberType {
  Member_Type_Hero, //英雄机器人
  Member_Type_Infantry, //步兵机器人
  Member_Type_Sentry, //哨兵机器人
  Member_Type_AeroRobot, //空中机器人
  Member_Type_Engineer, //工程机器人
  Member_Type_Tower, //基地
};
struct MemberConfig
{
  MemberType m_type;
  std::string m_name;
};
typedef std::vector<MemberConfig> TeamConfig;

class RoboTeamHelper
{
private:
  std::unordered_map<std::string, Ptr<RoboBase>> m_nameRoboMap;
  std::unordered_map<uint8_t, std::string> m_uidNameMap;
  Ptr<RoboBase> CreateRobot (MemberType type);
  bool m_hasInstalled{false};
  uint8_t m_teamId;
  uint8_t AllocateTeamId (void);

public:
  RoboTeamHelper ();
  ~RoboTeamHelper ();

  void Install (TeamConfig config);

  Ptr<RoboBase> GetRobotByName (std::string roboName);
  Ptr<Node> GetNodeByRoboName (std::string roboName);
};

} // namespace ns3
