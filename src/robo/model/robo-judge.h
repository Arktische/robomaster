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

public:
  RoboJudge ();
  ~RoboJudge ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  void Update ();

  void AddRobo (Ptr<RoboActor> actor); //添加robo
  void AddSmallAmmo (Ptr<RoboActor> actor); //添加small ammo
  void AddLargeAmmo (Ptr<RoboActor> actor); //添加large ammo

  void DoUpdate (); //计算所有碰撞，通过IndicateCollision告知Actor
};

} // namespace ns3
