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
#include "robo-base.h"
namespace ns3 {
  /**
 * \brief 基地类
 *  
 *
 * 
 *
 */
class RoboTower : public RoboBase
{
public:
  RoboTower ();
  virtual ~RoboTower ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  /**
 * \brief 初始化
 *  
 *
 * \param None 
 * \returns None
 */
  virtual void Init();
};

} // namespace ns3
