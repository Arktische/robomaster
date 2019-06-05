/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-actor.h"
#include "robo-weapon.h"

namespace ns3 {
class RoboBase : public RoboActor
{
public:
  RoboBase ();
  virtual ~RoboBase ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  uint8_t m_uid; //标识符
  virtual uint8_t GetUid () const;
  virtual void SetUid (uint8_t uid);

  uint8_t m_team; //所属的队伍
  virtual uint8_t GetTeam () const;
  virtual void SetTeam (uint8_t team);

  enum RoboType { Master, Follower };
  RoboType m_type; //机器人类型
  virtual RoboType GetType () const;
  virtual void SetType (RoboType type);

  float m_maxSpeed; //最大移动速度大小
  virtual float GetMaxSpeed (void) const;
  virtual void SetMaxSpeed (float speed);

  virtual FVector GetSpeed (void) const;
  virtual void SetSpeed (FVector speed);

  virtual FVector GetLocation () const;
  virtual void SetLocation (FVector location);

  LargeWeapon m_largeAmmo; //大弹药情况
  Time m_lastShootLarge; //上次大号弹药射击时刻
  virtual int GetLargeAmmoNumber (void) const;
  virtual void SetLargeAmmoNumber (int num);
  virtual bool IsLargeAmmoCanShoot (void) const;
  virtual void ShootLargeAmmo (FVector speed);

  SmallWeapon m_smallAmmo; //小弹药情况
  Time m_lastShootSmall; //上次小号弹药射击时刻
  virtual int GetSmallAmmoNumber (void) const;
  virtual void SetSmallAmmoNumber (int num);
  virtual bool IsSmallAmmoCanShoot (void) const;
  virtual void ShootSmallAmmo (FVector speed);

  int m_life; //生命值
  virtual int GetLife () const;
  virtual void SetLife (int life);

  uint8_t AllocUid (void);
  virtual void Update (float delta);

  virtual void IndicateLocation (uint8_t uid);
};
} // namespace ns3
