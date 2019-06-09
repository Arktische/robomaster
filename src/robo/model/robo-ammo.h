/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-actor.h"
namespace ns3 {
class RoboAmmo : public RoboActor
{
private:
  int m_injury; //伤害值
  float m_range; //有效范围剩余值
public:
  RoboAmmo ();
  virtual ~RoboAmmo ();
  //TODO Getter & Setter of attributes
  virtual void SetInjury (int injury);
  virtual int GetInjury () const;
  virtual void SetRange (float range);
  virtual float GetRange () const;

  void UpdateRange(float delta);
  void HandleCollision(Ptr<RoboActor> oth);

  virtual void Disable (void);
};

} // namespace ns3
