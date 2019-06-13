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
#include <ostream>
namespace ns3 {
  /**
 * \brief 这个类用于描述点的坐标向量
 * 
 *
 *   
 * 
 */  
class FVector2
{
public:
  /**
 * \brief 默认构造函数
 *  
 *
 * \param None 
 * \returns FVector2实例
 */
  FVector2 (void);
  /**
 * \brief 构造函数
 *  
 *
 * \param x 横坐标
 *        y 纵坐标
 * \returns FVector2实例
 */
  FVector2 (float x, float y);
  /**
 * \brief 构造函数
 *  
 *
 * \param oth 用来初始化的另一个实例
 * \returns FVector2实例
 */
  FVector2 (const FVector2 &oth);

  /**
 * \brief 重载操作符"+"
 * 
 *
 * \param oth 需要进行加运算的另一个坐标  
 * \returns 坐标等于坐标和的新实例 
 */  
  FVector2 operator+ (FVector2 oth);
  /**
 * \brief 重载操作符"+="
 * 
 *
 * \param oth 需要进行"+="运算的另一个坐标  
 * \returns 调用此方法的实例
 */    
  FVector2 operator+= (FVector2 oth);
  /**
 * \brief 重载操作符"-"
 * 
 *
 * \param oth 需要进行"-"运算的另一个坐标  
 * \returns 坐标等于坐标差的新实例
 */  
  FVector2 operator- (FVector2 oth);
  /**
 * \brief 重载单目操作符"-"
 * 
 *
 * \param None  
 * \returns 坐标与原坐标关于原点对称的新实例
 */  
  FVector2 operator- (void);
  /**
 * \brief 重载操作符"-="
 * 
 *
 * \param oth 需要进行"-="运算的另一个坐标 
 * \returns 调用此方法的实例 
 */
  FVector2 operator-= (FVector2 oth);
  /**
 * \brief 重载操作符"*"
 * 
 *
 * \param oth 进行叉乘的另一个坐标  
 * \returns 坐标与原坐标叉乘得到的浮点数
 */  
  float operator* (FVector2 oth);
  /**
 * \brief 重载操作符"*"
 * 
 *
 * \param oth 将横纵坐标扩大的倍数 
 * \returns 坐标扩大相应倍数的新实例
 */ 
  FVector2 operator* (float oth);
  
  /**
 * \brief 计算两点之间的距离
 * 
 *
 * \param oth 计算距离的另一个坐标
 * \returns 两点距离
 */ 
  float GetDistance (FVector2 oth) const;
  /**
 * \brief 计算两点之间的距离的平方
 * 
 *
 * \param oth 计算距离平方的另一个坐标
 * \returns 两点距离的平方
 */ 
  float GetDistance2 (FVector2 oth) const;
  /**
 * \brief 计算向量的模
 * 
 *
 * \param None
 * \returns 模值
 */
  float GetLength (void) const;
  /**
 * \brief 重载操作符"<<"
 * 
 *
 * \param os 标准输出流
 *        vector 要输出的实例  
 * \returns 标准输出流
 */  
  friend std::ostream &operator<< (std::ostream &os, const FVector2 &vector);

  float m_x; //横坐标
  float m_y; //纵坐标
};
  /**
 * \brief 两向量点乘
 * 
 *
 * \param oth 计算点乘的另一个向量
 * \returns 点乘结果
 */ 
float Dot (FVector2 v1, FVector2 v2);
} // namespace ns3
