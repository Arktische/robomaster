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
 * Modified by:     Yuxing Tu
 */
#pragma once
#include "ns3/core-module.h"
#include "robo-actor.h"
#include <unordered_map>

namespace ns3 {
class RoboActor;
  /**
 * \brief 实现全局裁判类
 *  
 *
 *
 *
 */
class RoboJudge : public Object
{
private:
  std::vector<Ptr<RoboActor>> m_robos;//记录全场robots
  std::list<Ptr<RoboActor>> m_smallAmmo;//记录全场小子弹
  std::list<Ptr<RoboActor>> m_largeAmmo;//记录全场大子弹
  std::vector<Ptr<RoboActor>> m_othCollision;//记录全场障碍物
  std::unordered_map<std::string, Ptr<RoboActor>> m_nameRoboMap;//记录全场robots名字与Actor对应关系

  float m_updatePeriod;//更新周期
  float m_visibleDistance;//可视距离

  bool m_enablePlot;//开启输出运行记录
  float m_plotPeriod;//输出频率
  std::string m_plotFileName;//输出文件名
  FILE *m_filePtr;//输出文件指针
  uint16_t m_bufferSize;//缓冲区大小
  unsigned char *m_outputBuffer;//buffer指针
  unsigned char *m_outputBufferHead;//buffer头
  unsigned char *m_outputBufferTail;//buffer尾
  float m_boundaryX;//x边界
  float m_boundaryY;//y边界

public:
  RoboJudge ();
  ~RoboJudge ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void DoInitialize (void);
  virtual void DoDispose (void);
  /**
 * \brief 更新全场
 *  
 *
 * \param None 
 * \returns None
 */
  void Update ();
  /**
 * \brief 输出全场各机器人情况
 *  
 *
 * \param None 
 * \returns None
 */
  void PlotAll ();
  /**
 * \brief 输出指定机器人情况
 *  
 *
 * \param robot 对应的Actor指针
 * \returns None
 */
  void PlotRobo (Ptr<RoboActor> robo);
  /**
 * \brief 输出指定大子弹情况
 *  
 *
 * \param 大子弹对应的Actor指针 
 * \returns None
 */
  void PlotLargeAmmo (Ptr<RoboActor> ammo);
  /**
 * \brief 输出指定小子弹情况
 *  
 *
 * \param 小子弹对应的Actor指针 
 * \returns None
 */  
  void PlotSmallAmmo (Ptr<RoboActor> ammo);

  /**
 * \brief 增加robot
 *  
 *
 * \param robot对应Actor指针
 * \returns None
 */
  void AddRobo (Ptr<RoboActor> actor);
  /**
 * \brief 增加小子弹到场景
 *  
 *
 * \param robot对应的Actor指针
 * \returns None
 */
  void AddSmallAmmo (Ptr<RoboActor> actor);
  /**
 * \brief 增加大子弹到场景
 *  
 *
 * \param robot对应的Actor指针 
 * \returns None
 */
  void AddLargeAmmo (Ptr<RoboActor> actor);
  /**
 * \brief 增加碰撞体积到场景
 *  
 *
 * \param 碰撞判定类指针
 * \returns None
 */
  void AddCollision(Ptr<RoboCollision> col);
  /**
 * \brief 完成机器人添加
 *  
 *
 * \param None 
 * \returns None
 */
  void FinishAdd (void);
  /**
 * \brief 计算所有碰撞，通过IndicateCollision告知Actor，计算机器人间可见关系，通过IndicateLocation告知RoboBase
 *  
 *
 * \param None 
 * \returns None
 */
  
  void DoUpdate ();
  /**
 * \brief 转移大子弹
 *  
 *
 * \param from: 供给方Actor指针, to 接收方roboName, num 转移数量
 * \returns None
 */
  void TransLargeAmmo (Ptr<RoboActor> from, std::string to, int num);
  /**
 * \brief 转移小子弹
 *  
 *
 * \param from: 供给方Actor指针, to 接收方roboName, num 转移数量 
 * \returns None
 */
  void TransSmallAmmo (Ptr<RoboActor> from, std::string to, int num);

  inline void PutChar (unsigned char ch);
};

} // namespace ns3
