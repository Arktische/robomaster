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
namespace ns3 {
class RoboAmmo : public RoboActor
{
  friend class RoboJudge;

private:
  int m_injury; //伤害值
  float m_range; //有效范围剩余值
  uint8_t m_shooterUid;

public:
  RoboAmmo ();
  virtual ~RoboAmmo ();
  //TODO Getter & Setter of attributes
  virtual void SetInjury (int injury);
  virtual int GetInjury () const;
  virtual void SetRange (float range);
  virtual float GetRange () const;
  virtual void SetShooterUid (uint8_t uid);
  virtual uint8_t GetShooterUid () const;
  virtual void SetInitValue (FVector location, float redius);

  void UpdateRange (float delta);
  void HandleCollision (Ptr<RoboActor> oth);

  virtual void Disable (void);

  virtual void ShowTrace (float delta);
};

} // namespace ns3
