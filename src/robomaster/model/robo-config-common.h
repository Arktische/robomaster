#pragma once
#include "ns3/simple-ref-count.h"
namespace ns3 {
class RoboMasterConfigCommon : public SimpleRefCount<RoboMasterConfigCommon>
{
public:
  RoboMasterConfigCommon ();
  virtual ~RoboMasterConfigCommon ();
  float m_updatePeriod;
};
} // namespace ns3
