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
#include "ns3/node-container.h"
#include "ns3/robo-actor.h"
#include "ns3/robo-base.h"
#include "ns3/robo-hero.h"
#include "ns3/robo-infantry.h"
#include "ns3/robo-tower.h"
#include "ns3/robo-air.h"
#include "ns3/robo-sentinel.h"
#include "ns3/robo-judge.h"
#include <unordered_map>

namespace ns3 {

enum MemberType {
  Member_Type_Hero, //英雄机器人
  Member_Type_Infantry, //步兵机器人
  Member_Type_Sentry, //哨兵机器人
  Member_Type_AeroRobot, //空中机器人
  Member_Type_Engineer, //工程机器人
  Member_Type_Tower, //基地
  // Member_Type_LargeAmmo,
  // Member_Type_SmallAmmo,
};
struct MemberConfig
{
  MemberType m_type; //类型
  std::string m_name; //名称
  FVector m_initLocation; //初始局部坐标
  FAngle m_initRotation; //初始局部坐标
  std::vector<FVector> m_boundary;
};
typedef std::vector<MemberConfig> TeamConfig;

class RoboTeamHelper : public SimpleRefCount<RoboTeamHelper>
{
  friend class RoboHelper;

private:
  std::unordered_map<std::string, Ptr<RoboBase>> m_nameRoboMap;
  std::unordered_map<uint8_t, std::string> m_uidNameMap;
  Ptr<RoboBase> CreateRobot (MemberType type);
  bool m_hasInstalled{false};
  uint8_t m_teamId;
  NodeContainer m_nodes;
  Ptr<RoboJudge> m_judge;
  FVector m_teamInitLocation;
  FAngle m_teamInitRotation;

  uint8_t AllocateTeamId (void);

public:
  RoboTeamHelper ();
  ~RoboTeamHelper ();

  void Install (TeamConfig config);

  Ptr<RoboBase> GetRobotByName (std::string roboName);
  Ptr<Node> GetNodeByRoboName (std::string roboName);

  void SetJudge (Ptr<RoboJudge> judge);
  void SetInitLocation (FVector location);
  void SetInitRotation (FAngle rotation);
};

} // namespace ns3
