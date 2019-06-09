/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"
namespace ns3 {
enum CollisionType {
  Collision_Type_Circle,
  Collision_Type_Polygon,
  Collision_Type_Boundary,
};
class RoboCollision : public SimpleRefCount<RoboCollision>
{
  friend class RoboJudge;

private:
  CollisionType m_type{Collision_Type_Circle};
  FVector m_globalLocation; //全局坐标系坐标
  FAngle m_globalRotation; //全局坐标系坐标
  float m_redius; //包围圆半径
  std::vector<FVector> m_boundaryPoint; //局部坐标系下边界点
  uint32_t m_collisionMask; //决定是否计算碰撞
  uint32_t m_selfMask; //决定是否计算碰撞

public:
  RoboCollision ();
  ~RoboCollision ();

  void SetType (CollisionType type);
  CollisionType GetType (void) const;

  void SetGlobalLocation (FVector globallocation);
  FVector GetGlobalLocation (void) const;

  void SetGlobalRotation (FAngle globalrotation);
  FAngle GetGlobalRotation (void) const;

  void SetCollisionMask (uint32_t collisionMask);
  uint32_t GetSelfMask (void) const;

  void SetSelfMask (uint32_t selfMask);
  uint32_t GetCollisionMask (void) const;

  void SetRedius (float redius);
  float GetRedius (void) const;

  void AddBoundaryPoint (FVector boundaryPoint);
  friend bool IsCollision (Ptr<RoboCollision> obj1, Ptr<RoboCollision> obj2);
};

} // namespace ns3
