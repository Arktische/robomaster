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
 * \brief 这个类用于描述隶属节点
 * 
 *
 *   
 * 
 */   
class RoboInfantry : public RoboBase
{
public:
  /**
 * \brief 默认构造函数
 *  
 *
 * \param None 
 * \returns RoboInfantry类实例
 */
  RoboInfantry ();
  /**
 * \brief 默认虚析构函数
 *  
 *
 * \param None
 * \returns None
 */
  virtual ~RoboInfantry ();
  /**
 * \brief 返回Infantry的TypeId
 * 
 *
 * \param None  
 * \returns TypeId tid
 */
  static TypeId GetTypeId (void);
  /**
 * \brief 返回Infantry实例的TypeId
 * 
 *
 * \param None  
 * \returns TypeId tid
 */
  virtual TypeId GetInstanceTypeId (void) const;
  /**
 * \brief 初始化相关操作
 * 
 *
 * \param None  
 * \returns None 
 */
  virtual void Init();
};

} // namespace ns3
