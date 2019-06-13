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
#include "fvector2.h"
#include "fangle2.h"
const float EPS = 1e-4;

namespace ns3 {
typedef FVector2 FVector; //FVector2取一个别名FVector
typedef FAngle2 FAngle; //FAngle2取一个别名FAngle
  /**
 * \brief 这个类用于描述线段
 * 
 *
 *   
 * 
 */ 
class LineSegment
{
public:
  FVector m_start; //起始点
  FVector m_end; //终点

  /**
 * \brief 构造函数
 *  
 *
 * \param st 起始点
 *        ed 终点
 * \returns LineSegment实例
 */
  LineSegment (FVector st, FVector ed);
  /**
 * \brief 构造函数
 *  
 *
 * \param x1 y1 起始点横纵坐标
 *        x2 y2 终点横纵坐标
 * \returns LineSegment实例
 */  
  LineSegment (float x1, float y1, float x2, float y2);
  /**
 * \brief 构造函数
 *  
 *
 * \param oth 用于初始化的实例
 * \returns LineSegment实例
 */
  LineSegment (const LineSegment &oth);
  /**
 * \brief 默认析构函数
 *  
 *
 * \param None
 * \returns None
 */
  ~LineSegment ();
};

  /**
 * \brief 将局部坐标转为全局坐标
 *  
 *
 * \param centerOfSubcoordinate 局部坐标中心(原点)
 *        directionOfSubcoordinate 局部坐标方向(机器人朝向)
 *        coordinate 局部坐标系坐标
 * \returns 局部坐标系的坐标在全局坐标系中相应的坐标
 */
FVector2 ConvCoordinate (FVector2 centerOfSubcoordinate, FAngle2 directionOfSubcoordinate,
                         FVector2 coordinate);
  /**
 * \brief 判断两线段是否相交
 *  
 *
 * \param st1 ed1 线段1的起始点与终点
 *        st2 ed2 线段2的起始点与终点
 * \returns 1表示相交
 *          0表示不相交
 */
bool IsCross (FVector2 st1, FVector2 ed1, FVector2 st2, FVector2 ed2);
  /**
 * \brief 判断两线段是否相交
 *  
 *
 * \param l1 线段1
 *        l2 线段2
 * \returns 1表示相交
 *          0表示不相交
 */
bool IsCross (const LineSegment l1, const LineSegment l2);
  /**
 * \brief 判断点是否在三角形内
 *  
 *
 * \param point 点
 *        p1 p2 p3 三角形三边顶点
 * \returns 1表示在内部
 *          0表示不在内部
 */
bool PointInTriangle (FVector2 point, FVector2 p1, FVector2 p2, FVector2 p3);
  /**
 * \brief 判断线段与圆是否相交
 *  
 *
 * \param center 圆心
 *        redius 半径
 *        st ed 线段起始点与终点
 * \returns 1表示相交
 *          0表示不相交
 */
bool CircleCrossLineSegment (FVector2 center, float redius, FVector2 st, FVector2 ed);
} // namespace ns3
