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
  friend class RoboJudge;

public:
  RoboBase ();
  virtual ~RoboBase ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  virtual uint8_t GetUid () const;

  virtual uint8_t GetTeam () const;
  virtual std::string GetName () const;

  enum RoboType { Master, Follower };
  virtual RoboType GetType () const;

  virtual float GetMaxSpeed (void) const;

  virtual void SetSpeed (FVector speed);
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

  virtual void GaveLargeAmmoTo (std::string roboName, uint32_t num);
  virtual void GaveSmallAmmoTo (std::string roboName, uint32_t num);

protected:
  uint8_t m_uid; //标识符
  uint8_t m_team; //所属的队伍
  std::string m_name;
  RoboType m_type; //机器人类型
  float m_maxSpeed; //最大移动速度大小
  Ptr<LargeWeapon> m_largeAmmo; //大弹药情况
  Time m_lastShootLarge; //上次大号弹药射击时刻
  Ptr<SmallWeapon> m_smallAmmo; //小弹药情况
  Time m_lastShootSmall; //上次小号弹药射击时刻
  int m_life; //生命值

  Ptr<UniformRandomVariable> m_random;

  virtual void SetUid (uint8_t uid);
  virtual void SetTeam (uint8_t team);
  virtual void SetName (std::string name);
  virtual void SetType (RoboType type);
  virtual void SetMaxSpeed (float speed);
  virtual void SetLocation (FVector location);
  virtual void SetLargeAmmoNumber (int num);
  virtual void SetSmallAmmoNumber (int num);
  virtual void SetLife (int life);
  virtual void HandleCollision (Ptr<RoboActor> oth);
  virtual void ReceiveLargeAmmo (uint32_t num);
  virtual void ReceiveSmallAmmo (uint32_t num);
};
} // namespace ns3
