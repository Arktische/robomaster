#pragma once
#include "ns3/object.h"
namespace ns3 {
class Ammo : public Object
{
public:
  Ammo ();
  virtual ~Ammo ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual int GetNumber (void) const;
  virtual void AddAmmo(int num);
  virtual bool UseAmmo(int num);

  int m_injury;
  int m_number;
};
class LargeAmmo : public Ammo
{
public:
  LargeAmmo ();
  ~LargeAmmo ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
};

} // namespace ns3
