/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-common.h"

namespace ns3 {
std::vector<FVector> gHeroBounds;
std::vector<FVector> gInfBounds;
float gLargeAmmoRedius;
float gSmallAmmoRedius;
uint32_t gRoboMask;
uint32_t gRoboCollisionMask;
uint32_t gAmmoMask;
uint32_t gAmmoCollisionMask;
int
InitCommonConfig (void)
{
  gHeroBounds.push_back (FVector (-0.2, -0.2));
  gHeroBounds.push_back (FVector (0.2, -0.2));
  gHeroBounds.push_back (FVector (0.2, 0.2));
  gHeroBounds.push_back (FVector (-0.2, 0.2));

  gInfBounds.push_back (FVector (-0.1, -0.1));
  gInfBounds.push_back (FVector (0.1, -0.1));
  gInfBounds.push_back (FVector (0.1, 0.1));
  gInfBounds.push_back (FVector (-0.1, 0.1));

  gLargeAmmoRedius = 0.01;
  gSmallAmmoRedius = 0.005;

  gRoboMask = 0x1;
  gRoboCollisionMask = 0x3;
  gAmmoMask = 0x2;
  gAmmoCollisionMask = 0x3;
  return 0;
}
static int common = InitCommonConfig ();
} // namespace ns3
