/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-actor.h"
#include <unordered_map>

namespace ns3 {
class RoboActor;
class RoboJudge : public Object
{
private:
  std::vector<Ptr<RoboActor>> m_robos;
  std::list<Ptr<RoboActor>> m_smallAmmo;
  std::list<Ptr<RoboActor>> m_largeAmmo;
  std::unordered_map<std::string, Ptr<RoboActor>> m_nameRoboMap;

  float m_updatePeriod;
  float m_visibleDistance;

  bool m_enablePlot;
  float m_plotPeriod;
  std::string m_plotFileName;
  FILE *m_filePtr;
  uint16_t m_bufferSize;
  unsigned char *m_outputBuffer;
  unsigned char *m_outputBufferHead;
  unsigned char *m_outputBufferTail;

public:
  RoboJudge ();
  ~RoboJudge ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void DoInitialize (void);
  virtual void DoDispose (void);

  void Update ();
  void PlotAll ();
  void PlotRobo (Ptr<RoboActor> robo);
  void PlotLargeAmmo (Ptr<RoboActor> ammo);
  void PlotSmallAmmo (Ptr<RoboActor> ammo);

  void AddRobo (Ptr<RoboActor> actor); //添加robo
  void AddSmallAmmo (Ptr<RoboActor> actor); //添加small ammo
  void AddLargeAmmo (Ptr<RoboActor> actor); //添加large ammo
  void FinishAdd (void);

  //计算所有碰撞，通过IndicateCollision告知Actor
  //计算机器人间可见关系，通过IndicateLocation告知RoboBase
  void DoUpdate ();

  void TransLargeAmmo (Ptr<RoboActor> from, std::string to, int num);
  void TransSmallAmmo (Ptr<RoboActor> from, std::string to, int num);

  inline void PutChar (unsigned char ch);
};

} // namespace ns3
