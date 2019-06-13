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
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"

namespace ns3 {
extern std::vector<FVector> gHeroBounds; //Hero�����˱߽��
extern std::vector<FVector> gInfBounds; //Infantry�����˱߽��
extern float gLargeAmmoRedius;          //���ӵ��뾶
extern float gSmallAmmoRedius;          //С�ӵ��뾶
extern uint32_t gRoboMask;              //Robo��־
extern uint32_t gRoboCollisionMask;     //Robo��ײ��־λ
extern uint32_t gAmmoMask;              //�ӵ���־
extern uint32_t gAmmoCollisionMask;     //�ӵ���ײ��־λ
extern uint32_t gBoundaryMask;          //�߽��־
extern uint32_t gBoundaryCollisionMask; //�߽���ײ��־λ

  /**
 * \brief ��ʼ����ز���
 *  
 *
 * \param None
 * \returns 
 */
int InitCommonConfig (void);

} // namespace ns3
