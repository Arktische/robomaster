/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "robo-actor.h"
#include "robo-weapon.h"
#include "robo-ammo.h"

namespace ns3 {
struct LocationInfo
{
  uint8_t m_uid;
  FVector m_location;
  Time m_indicateTime;
};
class RoboBase : public RoboActor
{
  friend class RoboTeamHelper;

public:
  RoboBase ();
  virtual ~RoboBase ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  virtual uint8_t GetUid () const;

  virtual uint8_t GetTeam () const;

  enum RoboType { Master, Follower };
  virtual RoboType GetType () const;

  virtual float GetMaxSpeed (void) const;

  virtual FVector GetSpeed (void) const;

  virtual FVector GetLocation () const;

  virtual int GetLargeAmmoNumber (void) const;
  virtual bool IsLargeAmmoCanShoot (void) const;
  virtual void ShootLargeAmmo (FVector speed);

  virtual int GetSmallAmmoNumber (void) const;
  virtual bool IsSmallAmmoCanShoot (void) const;
  virtual void ShootSmallAmmo (FVector speed);

  virtual int GetLife () const;

  uint8_t AllocUid (void);
  virtual void Update (float delta);

  virtual void IndicateLocation (Ptr<RoboActor> oth);

  virtual LocationInfo GetKnownLocation (uint8_t uid);
  std::map<uint8_t, LocationInfo> m_knownLocation;

protected:
  uint8_t m_uid; //标识符
  uint8_t m_team; //所属的队伍
  RoboType m_type; //机器人类型
  float m_maxSpeed; //最大移动速度大小
  LargeWeapon m_largeAmmo; //大弹药情况
  Time m_lastShootLarge; //上次大号弹药射击时刻
  SmallWeapon m_smallAmmo; //小弹药情况
  Time m_lastShootSmall; //上次小号弹药射击时刻
  int m_life; //生命值

  virtual void SetUid (uint8_t uid);
  virtual void SetTeam (uint8_t team);
  virtual void SetType (RoboType type);
  virtual void SetMaxSpeed (float speed);
  virtual void SetSpeed (FVector speed);
  virtual void SetLocation (FVector location);
  virtual void SetLargeAmmoNumber (int num);
  virtual void SetSmallAmmoNumber (int num);
  virtual void SetLife (int life);
};
} // namespace ns3
