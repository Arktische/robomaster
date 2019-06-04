/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/object.h"
#include "ammo.h"

namespace ns3 {
class RoboBase : public : Object
{
public:
  RoboBase ();
  virtual ~RoboBase ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  void Dispose (void);

private:
  int m_life;
  
};
} // namespace ns3
