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
uint32_t gBoundaryMask;
uint32_t gBoundaryCollisionMask;
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

  gLargeAmmoRedius = 0.042;
  gSmallAmmoRedius = 0.017;

  gRoboMask = 0x1;
  gRoboCollisionMask = 0x7;

  gAmmoMask = 0x2;
  gAmmoCollisionMask = 0x7;

  gBoundaryMask = 0x4;
  gBoundaryCollisionMask = 0x3;
  return 0;
}
static int common = InitCommonConfig ();
} // namespace ns3
