/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"

namespace ns3 {
extern std::vector<FVector> gHeroBounds;
extern std::vector<FVector> gInfBounds;
extern float gLargeAmmoRedius;
extern float gSmallAmmoRedius;
extern uint32_t gRoboMask;
extern uint32_t gRoboCollisionMask;
extern uint32_t gAmmoMask;
extern uint32_t gAmmoCollisionMask;

int InitCommonConfig (void);

} // namespace ns3
