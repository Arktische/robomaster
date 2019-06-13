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
 * Original Author: Pengyu Liu    <eicliupengyu@gmail.com>
 * Modified by:     Zhichao Liu
 */
#pragma once
#define PI 3.14159265f
#include <ostream>
namespace ns3 {
  /**
 * \brief 这个类用于描述机器人头部所指方向与x轴正方向夹角
 * 
 *
 *   
 * 
 */  
class FAngle2
{
public:

  float m_phi; //机器人头部所指方向与x轴正方向夹角
  /**
 * \brief 默认构造函数
 *  
 *
 * \param None 
 * \returns FAngle2类实例
 */
  FAngle2 ();
  /**
 * \brief 重载构造函数
 *  
 *
 * \param phi 机器人头部所指方向与x轴正方向夹角
 * \returns FAngle2类实例
 */
  FAngle2 (float phi);
  /**
 * \brief 默认析构函数
 *  
 *
 * \param None
 * \returns None
 */
  ~FAngle2 ();

  /**
 * \brief 设置机器人头部所指方向与x轴正方向夹角
 *  
 *
 * \param angle 夹角大小 
 * \returns None
 */
  void SetAngle (float angle);
  /**
 * \brief 返回机器人头部所指方向与x轴正方向夹角
 * 
 *
 * \param None  
 * \returns 夹角大小 
 */
  float GetAngle (void) const;
  
  /**
 * \brief 重载操作符"+"
 * 
 *
 * \param oth 需要进行加运算的另一个角度  
 * \returns 夹角等于夹角和的新实例 
 */  
  FAngle2 operator+ (FAngle2 oth);
  /**
 * \brief 重载操作符"+="
 * 
 *
 * \param oth 需要进行"+="运算的另一个角度  
 * \returns 调用此方法的实例
 */    
  FAngle2 operator+= (FAngle2 oth);
  /**
 * \brief 重载操作符"-"
 * 
 *
 * \param oth 需要进行"-"运算的另一个角度  
 * \returns 夹角等于夹角差的新实例
 */  
  FAngle2 operator- (FAngle2 oth);
  /**
 * \brief 重载单目操作符"-"
 * 
 *
 * \param None  
 * \returns 夹角为原夹角负值的新实例
 */  
  FAngle2 operator- (void);
  /**
 * \brief 重载操作符"-="
 * 
 *
 * \param oth 需要进行"-="运算的另一个角度  
 * \returns 调用此方法的实例 
 */  
  FAngle2 operator-= (FAngle2 oth);

  /**
 * \brief 把角度转换为弧度
 * 
 *
 * \param angle 要转换的角度
 * \returns 转换得到的弧度
 */  
  friend float AngleToRadian (float angle);
  /**
 * \brief 把弧度转换为角度
 * 
 *
 * \param radian 要转换的弧度
 * \returns 转换得到的角度
 */   
  friend float RadianToAngle (float radian);
  /**
 * \brief 重载操作符"<<"
 * 
 *
 * \param os 标准输出流
 *        angle 要输出的实例  
 * \returns 标准输出流
 */  
  friend std::ostream &operator<< (std::ostream &os, const FAngle2 &angle);
};

} // namespace ns3
