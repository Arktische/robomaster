/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"
namespace ns3 {
class RoboCollision : public SimpleRefCount<RoboCollision>
{
private:
  FVector m_globalLocation; //全局坐标系坐标
  FAngle m_globalRotation; //全局坐标系坐标
  float m_redius; //包围圆半径
  std::vector<LineSegment> m_boundary; //局部坐标系下边界
  uint32_t m_collisionMask; //决定是否计算碰撞

public:
  RoboCollision ();
  //含参数构造函数及拷贝构造函数
  ~RoboCollision ();
  //Setter & Getter of m_globalLocation m_globalRotation m_collisionMask m_redius
  //TODO

  //Function Add LineSegment to m_boundary
  //TODO

  //全局-局部坐标变换
  //TODO

  //是否碰撞判断,m_collisionMask & oth.m_collisionMask时才计算
  //当前版本将所有碰撞体视为圆形，圆心距离-两半径判断
  //之后版本先圆形判断后边界碰撞判断，即边界相交判断和顶点包围判断
  bool IsCollision (RoboCollision &oth);
};

} // namespace ns3
