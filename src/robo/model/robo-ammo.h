/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-actor.h"
namespace ns3 {
class RoboAmmo : public RoboActor
{
private:
  int m_injury; //伤害值
  double m_range; //有效范围剩余值
public:
  RoboAmmo ();
  virtual ~RoboAmmo ();
  //TODO Getter & Setter of attributes
  //TODO impl these functions
  virtual void SetSpeed (FVector speed);
  virtual FVector GetSpeed () const;
};

} // namespace ns3
