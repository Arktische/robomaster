/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
#include "robo-geometry.h"
#include "robo-collision.h"
#include "robo-judge.h"

namespace ns3 {
class RoboJudge;
class RoboActor : public Object
{
  friend class RoboJudge;

protected:
  Ptr<RoboCollision> m_collision;
  FVector m_speed;

  float m_updatePeriod;
  Ptr<RoboJudge> m_judge; //全局裁判

  bool m_isDestroy{false};
  bool m_isDeleted{false};

private:
  typedef Callback<void, float> UpdateCallback;
  typedef Callback<void, Ptr<RoboActor>> CollisionCallback;

  std::vector<UpdateCallback> m_beforeUpdateCallbackList; //每轮更新前调用
  std::vector<UpdateCallback> m_updateCallbackList; //每轮更新时调用
  std::vector<UpdateCallback> m_afterUpdateCallbackList; //每轮更新后调用
  std::vector<CollisionCallback> m_collisionCallbackList; //检测到碰撞时调用

public:
  RoboActor ();
  ~RoboActor ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void DoInitialize (void);

  virtual FVector GetSpeed () const;
  virtual void SetSpeed (FVector speed);

private:
  void BeforeUpdate (); //每轮更新前调用
  void Update (); //每轮更新时调用
  void AfterUpdate (); //每轮更新后调用
  void IndicateCollision (Ptr<RoboActor> oth); //由judge告知被碰撞

protected:
  void AddBeforeUpdateCallback (UpdateCallback cb);
  void AddUpdateCallback (UpdateCallback cb);
  void AddAfterUpdateCallback (UpdateCallback cb);
  void AddCollisionCallback (CollisionCallback cb);

  virtual void SetJudge (Ptr<RoboJudge> judge);
  virtual Ptr<RoboJudge> GetJudge (void) const;

  virtual void Disable ();
  virtual void Enable ();
  virtual void Delete ();
};

} // namespace ns3
