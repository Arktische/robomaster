/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"
namespace ns3 {
class RoboCollision : public SimpleRefCount<RoboCollision>
{
  friend class RoboJudge;

private:
  FVector m_globalLocation; //全局坐标系坐标
  FAngle m_globalRotation; //全局坐标系坐标
  float m_redius; //包围圆半径
  std::vector<FVector> m_boundaryPoint; //局部坐标系下边界点
  uint32_t m_collisionMask; //决定是否计算碰撞

public:
  RoboCollision ();
  //含参数构造函数及拷贝构造函数
  ~RoboCollision ();
  /**
 * \brief Set the GlobalLocation of a collision body
 * on this condition, it's the center of a circle  
 *
 * \param globallocation The center of a circle 
 * \returns None
 
 */
  void SetGlobalLocation (FVector globallocation);
  /**
 * \brief Get the GlobalLocation of a collision body
 * Namely, it's the center of a circle  
 *
 * \param None 
 * \returns The center of a circle
 
 */
  FVector GetGlobalLocation (void) const;

  /**
 * \brief Set the GlobalRotation of a collision body
 * on this condition, it's the angle of a circle  
 *
 * \param globalrotation The angle of a circle 
 * \returns None
 
 */
  void SetGlobalRotation (FAngle globalrotation);
  /**
 * \brief Get the GlobalRotation of a collision body
 * Namely, it's the angle of a circle  
 *
 * \param None 
 * \returns The angle of a circle
 
 */
  FAngle GetGlobalRotation (void) const;

  /**
 * \brief Set the CollisionMask of a collision body
 *   
 *
 * \param collisionMask The mask to determine whether two collsion bodies have encountered 
 * \returns None
 
 */
  void SetCollisionMask (uint32_t collisionMask);
  /**
 * \brief Get the CollisionMask of a collision body
 *  
 *
 * \param None 
 * \returns The mask of a collision body
 
 */
  uint32_t GetCollisionMask (void) const;

  /**
 * \brief Set the Redius of a collision body
 * on this condition, it's the redius of a circle  
 *
 * \param redius The redius of a circle 
 * \returns None
 
 */
  void SetRedius (float redius);
  /**
 * \brief Get the Redius of a collision body
 * Namely, it's the redius of a circle  
 *
 * \param None 
 * \returns The redius of a circle
 
 */
  float GetRedius (void) const;

  //Function Add boundaryPoint to m_boundary
  void AddBoundaryPoint (FVector boundaryPoint);
  //TODO

  //全局-局部坐标变换
  //TODO

  //是否碰撞判断,m_collisionMask & oth.m_collisionMask时才计算
  //当前版本将所有碰撞体视为圆形，圆心距离-两半径判断
  //之后版本先圆形判断后边界碰撞判断，即边界相交判断和顶点包围判断
  /**
 * \brief Determine whether two collision bodies have encountered
 * on this condition, it's whether two circles have crossed  
 *
 * \param oth1,oth2 Two collision bodies needed to be determined  
 * \returns 1 :Two circles are crossed
 *          0: Two circles are not crossed
 
 */
  friend bool IsCollision (Ptr<RoboCollision> obj1, Ptr<RoboCollision> obj2);
};

} // namespace ns3
