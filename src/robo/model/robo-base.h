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
 * Modified by:     Xinyu Li
 */
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

  uint8_t GetUid () const;

  uint8_t GetTeam () const;
  std::string GetName () const;

  enum RoboType { Master, Follower };
  RoboType GetType () const;

  float GetMaxSpeed (void) const;

  void SetSpeed (FVector speed);
  FVector GetSpeed (void) const;

  FVector GetLocation () const;

  int GetLargeAmmoNumber (void) const;
  bool IsLargeAmmoCanShoot (void) const;
  void ShootLargeAmmo (FVector speed);

  int GetSmallAmmoNumber (void) const;
  bool IsSmallAmmoCanShoot (void) const;
  void ShootSmallAmmo (FVector speed);

  int GetLife () const;

  uint8_t AllocUid (void);
  virtual void Update (float delta);

  void IndicateLocation (Ptr<RoboActor> oth);

  LocationInfo GetKnownLocation (uint8_t uid);
  std::map<uint8_t, LocationInfo> m_knownLocation;

  void GaveLargeAmmoTo (std::string roboName, uint32_t num);
  void GaveSmallAmmoTo (std::string roboName, uint32_t num);

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
