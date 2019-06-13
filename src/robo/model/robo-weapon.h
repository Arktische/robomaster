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
namespace ns3 {
  /**
 * \brief 该类描述实体的武器
 * 
 *
 *   
 * 
 */ 
class Weapon : public Object
{
  friend class RoboBase;
  friend class RoboHero;
  friend class RoboInfantry;
  friend class RoboTower;
  friend class RoboAir;
  friend class RoboSentry;
  friend class RoboJudge;

public:
  Weapon ();
  virtual ~Weapon ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  /**
 * \brief 获取伤害值
 *  
 *
 * \param None 
 * \returns 伤害值
 */  
  virtual int GetInjury (void) const;
  /**
 * \brief 设置伤害值
 *  
 *
 * \param 伤害值
 * \returns RoboCollision实例
 */
  virtual void SetInjury (int injury);
  /**
 * \brief 获取弹药数量
 *  
 *
 * \param None 
 * \returns 弹药数量
 */
  virtual int GetNumber (void) const;
  /**
 * \brief 设置弹药数量
 *  
 *
 * \param 弹药数量
 * \returns None
 */
  virtual void SetNumber (int number);
  /**
 * \brief 增加弹药
 *  
 *
 * \param 增加弹药量
 * \returns 成功增加的弹药量
 */
  virtual int AddAmmo (int num);
  /**
 * \brief 使用弹药
 *  
 *
 * \param 使用弹药数
 * \returns 是否成功
 */
  virtual bool UseAmmo (int num);
  /**
 * \brief 获取冷却时间
 *  
 *
 * \param None 
 * \returns 冷却时间
 */
  virtual Time GetPeriod (void) const;
  /**
 * \brief 设置冷却时间
 *  
 *
 * \param 冷却时间
 * \returns None
 */
  virtual void SetPeriod (Time period);
  /**
 * \brief 获取弹药速度
 *  
 *
 * \param None 
 * \returns 弹药速度
 */
  virtual float GetSpeed (void) const;
  /**
 * \brief 设置弹药速度
 *  
 *
 * \param 弹药速度
 * \returns None
 */
  virtual void SetSpeed (float speed);
  /**
 * \brief 获取有效射程
 *  
 *
 * \param None 
 * \returns 有效射程
 */
  virtual float GetRange (void) const;
  /**
 * \brief 设置有效射程
 *  
 *
 * \param 射程
 * \returns None
 */  
  virtual void SetRange (float range);

protected:
  int m_injury; //弹药伤害值
  int m_number; //弹药数
  float m_speed; //最大发射速度
  Time m_period; //最小发射间隔
  int m_maxNumber; //最大弹药数
  float m_range; //弹药有效距离
};
  /**
 * \brief 从Weapon类继承，用于大型子弹
 * 
 *
 *   
 * 
 */ 
class LargeWeapon : public Weapon
{
public:
  LargeWeapon ();
  ~LargeWeapon ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};
  /**
 * \brief 从Weapon类继承，用于小型子弹
 * 
 *
 *   
 * 
 */ 
class SmallWeapon : public Weapon
{
public:
  SmallWeapon ();
  ~SmallWeapon ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};
} // namespace ns3
