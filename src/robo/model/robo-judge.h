/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-actor.h"

namespace ns3 {
class RoboActor;
class RoboJudge : public Object
{
private:
  std::vector<Ptr<RoboActor>> m_robos;
  std::list<Ptr<RoboActor>> m_smallAmmo;
  std::list<Ptr<RoboActor>> m_largeAmmo;

  float m_updatePeriod;
  float m_visibleDistance;

public:
  RoboJudge ();
  ~RoboJudge ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  void Update ();

  void AddRobo (Ptr<RoboActor> actor); //添加robo
  void AddSmallAmmo (Ptr<RoboActor> actor); //添加small ammo
  void AddLargeAmmo (Ptr<RoboActor> actor); //添加large ammo

  //计算所有碰撞，通过IndicateCollision告知Actor
  //计算机器人间可见关系，通过IndicateLocation告知RoboBase
  void DoUpdate ();
};

} // namespace ns3
