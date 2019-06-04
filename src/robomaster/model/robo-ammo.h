/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#pragma once
#include "ns3/object.h"
#include "ns3/nstime.h"
namespace ns3 {
class Ammo : public Object
{
public:
  Ammo ();
  virtual ~Ammo ();
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
class LargeAmmo : public Ammo
{
public:
  LargeAmmo ();
  ~LargeAmmo ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};
class SmallAmmo : public Ammo
{
public:
  SmallAmmo ();
  ~SmallAmmo ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};
} // namespace ns3
