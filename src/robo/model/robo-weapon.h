/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/core-module.h"
namespace ns3 {
class Weapon : public Object
{
public:
  Weapon ();
  virtual ~Weapon ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual int GetInjury (void) const;
  virtual void SetInjury (int injury);

  virtual int GetNumber (void) const;
  virtual void SetNumber (int number);

  virtual int AddAmmo (int num);
  virtual bool UseAmmo (int num);

  virtual Time GetPeriod (void) const;
  virtual void SetPeriod (Time period);

  virtual float GetSpeed (void) const;
  virtual void SetSpeed (float speed);

  virtual float GetRange (void) const;
  virtual void SetRange (float range);

protected:
  int m_injury; //弹药伤害值
  int m_number; //弹药数
  float m_speed; //最大发射速度
  Time m_period; //最小发射间隔
  int m_maxNumber; //最大弹药数
  float m_range; //弹药有效距离
};
class LargeWeapon : public Weapon
{
public:
  LargeWeapon ();
  ~LargeWeapon ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};
class SmallWeapon : public Weapon
{
public:
  SmallWeapon ();
  ~SmallWeapon ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};
} // namespace ns3
