/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-actor.h"
namespace ns3 {
class RoboAmmo : public RoboActor
{
  friend class RoboJudge;

private:
  int m_injury; //伤害值
  float m_range; //有效范围剩余值
  uint8_t m_shooterUid;

public:
  RoboAmmo ();
  virtual ~RoboAmmo ();
  //TODO Getter & Setter of attributes
  virtual void SetInjury (int injury);
  virtual int GetInjury () const;
  virtual void SetRange (float range);
  virtual float GetRange () const;
  virtual void SetShooterUid (uint8_t uid);
  virtual uint8_t GetShooterUid () const;
  virtual void SetInitValue (FVector location, float redius);

  void UpdateRange (float delta);
  void HandleCollision (Ptr<RoboActor> oth);

  virtual void Disable (void);

  virtual void ShowTrace (float delta);
};

} // namespace ns3
