/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "robo-ammo.h"
#include "robo-geometry.h"
#include "robo-shoot.h"
#include "robo-config-common.h"

namespace ns3 {
class RoboBase : public Object
{
public:
  RoboBase ();
  virtual ~RoboBase ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  Vector2 GetSpeed (void) const;
  void SetSpeed (Vector2 newSpeed);

  int GetLargeAmmoNumber (void) const;
  void ShootLargeAmmo (Vector2 speed);

  int GetSmallAmmoNumber (void) const;
  void ShootSmallAmmo (Vector2 speed);

  enum RoboType { Master, Follower };

private:
  uint8_t m_uid;

  Vector2 m_location; //当前位置
  Vector2 m_speed; //当前速度
  LargeAmmo m_largeAmmo; //大弹药情况
  SmallAmmo m_smallAmmo; //小弹药情况

  Time m_lastShootLarge; //上次大号弹药射击时刻
  Time m_lastShootSmall; //上次小号弹药射击时刻

  Ptr<RoboMasterConfigCommon> m_config; //公有配置

  uint8_t AllocUid (void);
  void Update ();
  void SetLocation (Vector2 newLocation);
  void SetLargeAmmoNumber (int num);
  void SetSmallAmmoNumber (int num);

protected:
  RoboType m_type;
  
  int m_life; //生命值
  float m_maxSpeed; //最大移动速度
};
} // namespace ns3
