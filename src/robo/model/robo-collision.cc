/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-collision.h"
namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("RoboCollision");
RoboCollision::RoboCollision ()
{
  NS_LOG_FUNCTION (this);
}

RoboCollision::~RoboCollision ()
{
  NS_LOG_FUNCTION (this);
}

void
RoboCollision::SetType (CollisionType type)
{
  m_type = type;
}
CollisionType
RoboCollision::GetType (void) const
{
  return m_type;
}

void
RoboCollision::SetGlobalLocation (FVector globallocation)
{
  m_globalLocation = globallocation;
}
FVector
RoboCollision::GetGlobalLocation (void) const
{
  return m_globalLocation;
}

void
RoboCollision::SetGlobalRotation (FAngle globalrotation)
{
  m_globalRotation = globalrotation;
}
FAngle
RoboCollision::GetGlobalRotation (void) const
{
  return m_globalRotation;
}

void
RoboCollision::SetCollisionMask (uint32_t collisionMask)
{
  m_collisionMask = collisionMask;
}
uint32_t
RoboCollision::GetCollisionMask (void) const
{
  return m_collisionMask;
}

uint32_t
RoboCollision::GetSelfMask (void) const
{
  return m_selfMask;
}
void
RoboCollision::SetSelfMask (uint32_t selfMask)
{
  m_selfMask = selfMask;
}

void
RoboCollision::SetRedius (float redius)
{
  NS_ASSERT_MSG (redius > 0.0, "The redius of a circle must be bigger than 0.");
  m_redius = redius;
}
float
RoboCollision::GetRedius (void) const
{
  return m_redius;
}

void
RoboCollision::AddBoundaryPoint (FVector boundaryPoint)
{
  m_boundaryPoint.push_back (boundaryPoint);
}

bool
IsCollision (Ptr<RoboCollision> obj1, Ptr<RoboCollision> obj2)
{
  if (!(obj1->m_selfMask & obj2->m_collisionMask))
    {
      return false;
    }
  puts ("LOG1");
  if (!(obj1->m_globalLocation.GetDistance (obj2->m_globalLocation) <=
        (obj1->m_redius + obj2->m_redius)))
    {
      return false; //快速排斥
    }
  puts ("LOG2");
  if (obj1->m_type == Collision_Type_Circle && obj2->m_type == Collision_Type_Circle)
    {
      return true;
    }
  std::vector<FVector> globalBound1;
  for (auto &i : obj1->m_boundaryPoint)
    {
      globalBound1.push_back (ConvCoordinate (obj1->m_globalLocation, obj1->m_globalRotation, i));
    }
  std::vector<FVector> globalBound2;
  for (auto &i : obj2->m_boundaryPoint)
    {
      globalBound2.push_back (ConvCoordinate (obj2->m_globalLocation, obj2->m_globalRotation, i));
    }
  auto len1 = globalBound1.size ();
  auto len2 = globalBound2.size ();
  puts ("LOG3");
  for (auto i : globalBound1)
    {
      std::cout << i << " ";
    }
  puts ("");
  for (auto i : globalBound2)
    {
      std::cout << i << " ";
    }
  if (obj1->m_type == Collision_Type_Circle && obj2->m_type == Collision_Type_Polygon)
    {
      puts ("LOG4");
      for (uint32_t i = 1; i < len2; ++i)
        {
          std::cout << i;
          if (CircleCrossLineSegment (obj1->m_globalLocation, obj1->m_redius, globalBound2[i - 1],
                                      globalBound2[i]))
            {
              return true;
            }
        }
      if (CircleCrossLineSegment (obj1->m_globalLocation, obj1->m_redius, globalBound2[len2 - 1],
                                  globalBound2[0]))
        {
          return true;
        }
      puts ("LOG6");
      for (uint32_t i = 2; i < len2; ++i)
        {
          std::cout << i;
          if (PointInTriangle (obj1->m_globalLocation, globalBound2[0], globalBound2[1],
                               globalBound2[i]))
            {
              return true;
            }
        }
      return false;
    }
  if (obj2->m_type == Collision_Type_Circle && obj1->m_type == Collision_Type_Polygon)
    {
      puts ("LOG5");
      for (uint32_t i = 1; i < len1; ++i)
        {
          if (CircleCrossLineSegment (obj2->m_globalLocation, obj2->m_redius, globalBound1[i - 1],
                                      globalBound1[i]))
            {
              return true;
            }
        }
      if (CircleCrossLineSegment (obj2->m_globalLocation, obj2->m_redius, globalBound1[len1 - 1],
                                  globalBound1[0]))
        {
          return true;
        }
      for (uint32_t i = 2; i < len1; ++i)
        {
          if (PointInTriangle (obj2->m_globalLocation, globalBound1[0], globalBound1[1],
                               globalBound1[i]))
            {
              return true;
            }
        }
      return false;
    }

  if (obj1->m_type == Collision_Type_Polygon && obj2->m_type == Collision_Type_Polygon)
    {
      NS_ASSERT_MSG (len1 > 1 && len2 > 1, "Boundary is empty");
      if (len1 == 2 && len2 == 2)
        {
          return IsCross (globalBound1[0], globalBound1[1], globalBound2[0], globalBound2[1]);
        }
      if (len1 == 2)
        {
          for (uint32_t i = 1; i < len2; ++i)
            {
              if (IsCross (globalBound1[0], globalBound1[1], globalBound2[i - 1], globalBound2[i]))
                {
                  return true;
                }
            }
          if (IsCross (globalBound1[0], globalBound1[1], globalBound2[len2 - 1], globalBound2[0]))
            {
              return true;
            }
          for (uint32_t i = 2; i < len2; ++i)
            {
              if (PointInTriangle (globalBound1[0], globalBound2[0], globalBound2[1],
                                   globalBound2[i]))
                {
                  return true;
                }
            }
          return false;
        }
      if (len2 == 2)
        {
          for (uint32_t i = 1; i < len1; ++i)
            {
              if (IsCross (globalBound2[0], globalBound2[1], globalBound1[i - 1], globalBound1[i]))
                {
                  return true;
                }
            }
          if (IsCross (globalBound2[0], globalBound2[1], globalBound1[len1 - 1], globalBound1[0]))
            {
              return true;
            }
          for (uint32_t i = 2; i < len1; ++i)
            {
              if (PointInTriangle (globalBound2[0], globalBound1[0], globalBound1[1],
                                   globalBound1[i]))
                {
                  return true;
                }
            }
          return false;
        }
      for (uint32_t i = 0; i < len1; ++i)
        {
          for (uint32_t j = 0; j < len2; ++j)
            {
              if (IsCross (globalBound1[(i - 1 < 0 ? len1 : i) - 1], globalBound1[i],
                           globalBound2[(j - 1 < 0 ? len2 : j) - 1], globalBound2[j]))
                {
                  return true;
                }
            }
        }
      for (uint32_t i = 2; i < len1; ++i)
        {
          for (uint32_t j = 0; j < len2; ++j)
            {
              if (PointInTriangle (globalBound2[j], globalBound1[0], globalBound1[1],
                                   globalBound1[i]))
                {
                  return true;
                }
            }
        }
      return false;
    }
  if (obj1->m_type == Collision_Type_Boundary)
    {
      return (obj2->m_globalLocation.m_x > globalBound1[0].m_x &&
              obj2->m_globalLocation.m_y > globalBound1[0].m_y &&
              obj2->m_globalLocation.m_x < globalBound1[1].m_x &&
              obj2->m_globalLocation.m_y < globalBound1[1].m_y);
    }
  if (obj2->m_type == Collision_Type_Boundary)
    {
      return (obj1->m_globalLocation.m_x > globalBound2[0].m_x &&
              obj1->m_globalLocation.m_y > globalBound2[0].m_y &&
              obj1->m_globalLocation.m_x < globalBound2[1].m_x &&
              obj1->m_globalLocation.m_y < globalBound2[1].m_y);
    }
  return false;
}
} // namespace ns3
