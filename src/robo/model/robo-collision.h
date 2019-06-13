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
 * Modified by:     Zhichao Liu
 */
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"
namespace ns3 {
/*
*枚举类型，用于表示不同的类型，分别为圆，多边形和边界
*/
enum CollisionType {
  Collision_Type_Circle,
  Collision_Type_Polygon,
  Collision_Type_Boundary,
};
  /**
 * \brief 这个类用于描述碰撞
 * 
 *
 *   
 * 
 */ 
class RoboCollision : public SimpleRefCount<RoboCollision>
{
  friend class RoboJudge; //友元类RoboJudge
  friend class RoboTeamHelper; //友元类RoboTeamHelper

private:
  CollisionType m_type{Collision_Type_Circle}; //碰撞类型
  FVector m_globalLocation; //全局坐标系坐标
  FAngle m_globalRotation; //全局坐标系坐标
  float m_redius{0}; //包围圆半径
  std::vector<FVector> m_boundaryPoint; //局部坐标系下边界点
  uint32_t m_collisionMask; //决定是否计算碰撞
  uint32_t m_selfMask; //决定是否计算碰撞

public:
  /**
 * \brief 默认构造函数
 *  
 *
 * \param None 
 * \returns RoboCollision实例
 */
  RoboCollision ();
  /**
 * \brief 默认析构函数
 *  
 *
 * \param None
 * \returns None
 */
  ~RoboCollision ();

  /**
 * \brief 设置碰撞类型
 *  
 *
 * \param type 碰撞类型
 * \returns None
 */
  void SetType (CollisionType type);
  /**
 * \brief 返回碰撞类型
 * 
 *
 * \param None  
 * \returns 碰撞类型
 */
  CollisionType GetType (void) const;

  /**
 * \brief 设置全局坐标系坐标
 *  
 *
 * \param globallocation 全局坐标系坐标
 * \returns None
 */
  void SetGlobalLocation (FVector globallocation);
  /**
 * \brief 返回全局坐标系坐标
 * 
 *
 * \param None  
 * \returns 全局坐标系坐标
 */
  FVector GetGlobalLocation (void) const;

  /**
 * \brief 设置全局坐标系旋转角
 *  
 *
 * \param globalrotation 全局坐标系旋转角
 * \returns None
 */
  void SetGlobalRotation (FAngle globalrotation);
  /**
 * \brief 返回全局坐标系旋转角
 * 
 *
 * \param None  
 * \returns 全局坐标系旋转角
 */
  FAngle GetGlobalRotation (void) const;

  /**
 * \brief 设置碰撞标志位，即决定是否计算碰撞
 *  
 *
 * \param collisionMask 碰撞标志位
 * \returns None
 */
  void SetCollisionMask (uint32_t collisionMask);
  /**
 * \brief 返回碰撞标志位
 * 
 *
 * \param None  
 * \returns 碰撞标志位
 */
  uint32_t GetCollisionMask (void) const;

  /**
 * \brief 返回碰撞标志位
 * 
 *
 * \param None  
 * \returns 碰撞标志位
 */
  uint32_t GetSelfMask (void) const;
  /**
 * \brief 设置碰撞标志位，即决定是否计算碰撞
 *  
 *
 * \param selfMask 碰撞标志位
 * \returns None
 */
  void SetSelfMask (uint32_t selfMask);

  /**
 * \brief 设置包围圆半径
 *  
 *
 * \param redius 包围圆半径
 * \returns None
 */
  void SetRedius (float redius);
  /**
 * \brief 返回包围圆半径
 * 
 *
 * \param None  
 * \returns 包围圆半径
 */
  float GetRedius (void) const;

  /**
 * \brief 增加局部坐标系下边界点
 * 
 *
 * \param boundaryPoint 局部坐标系下边界点 
 * \returns None
 */
  void AddBoundaryPoint (FVector boundaryPoint);
  /**
 * \brief 增加一堆局部坐标系下边界点
 * 
 *
 * \param boundaryPoint 包含一堆局部坐标系下边界点的vector 
 * \returns None
 */
  void AddBoundaryPoint (std::vector<FVector> boundaryPoints);

  /**
 * \brief 判断两碰撞体是否碰撞
 * 
 *
 * \param obj1 碰撞体1
 *        obj2 碰撞体2
 * \returns 1代表碰撞
 *          0代表未碰撞
 */
  friend bool IsCollision (Ptr<RoboCollision> obj1, Ptr<RoboCollision> obj2);
};

} // namespace ns3
