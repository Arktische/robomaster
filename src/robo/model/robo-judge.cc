/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "robo-judge.h"
#include "robo-base.h"
namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("RoboJudge");
NS_OBJECT_ENSURE_REGISTERED (RoboJudge);
RoboJudge::RoboJudge ()
{
  NS_LOG_FUNCTION (this);
}

RoboJudge::~RoboJudge ()
{
  NS_LOG_FUNCTION (this);
}
TypeId
RoboJudge::GetTypeId (void)
{
  static TypeId tid =
      TypeId ("ns3::RoboJudge")
          .SetParent<Object> ()
          .SetGroupName ("Robo")
          .AddConstructor<RoboJudge> ()
          .AddAttribute ("Period", "The period between update", DoubleValue (0.001),
                         MakeDoubleAccessor (&RoboJudge::m_updatePeriod),
                         MakeDoubleChecker<float> (0))
          .AddAttribute ("EnablePlot", "Enable plot or not", BooleanValue (true),
                         MakeBooleanAccessor (&RoboJudge::m_enablePlot), MakeBooleanChecker ())
          .AddAttribute ("PlotPeriod", "The period between plot", DoubleValue (1.0 / 24),
                         MakeDoubleAccessor (&RoboJudge::m_plotPeriod),
                         MakeDoubleChecker<float> (0))
          .AddAttribute ("VisibleDistance", "The visible distance between robos", DoubleValue (5.0),
                         MakeDoubleAccessor (&RoboJudge::m_visibleDistance),
                         MakeDoubleChecker<float> (0))
          .AddAttribute ("PlotFileName", "Plot file name", StringValue ("PlotDefault.plt"),
                         MakeStringAccessor (&RoboJudge::m_plotFileName), MakeStringChecker ());
  return tid;
}
TypeId
RoboJudge::GetInstanceTypeId (void) const
{
  NS_LOG_FUNCTION (this);
  return GetTypeId ();
}

void
RoboJudge::DoInitialize (void)
{
  NS_LOG_FUNCTION (this);
  Simulator::Schedule (Seconds (m_updatePeriod) - NanoSeconds (5), &RoboJudge::Update, this);
  if (m_enablePlot)
    {
      Simulator::Schedule (Seconds (m_plotPeriod), &RoboJudge::PlotAll, this);
    }
  m_filePtr = fopen (m_plotFileName.c_str (), "wb");
  NS_ASSERT_MSG (m_filePtr != 0, "Cannot create plot file");
  NS_ASSERT_MSG (m_bufferSize > 0, "Buffer size should larger than zero");
  m_outputBuffer = new unsigned char[m_bufferSize];
  NS_ASSERT_MSG (m_outputBuffer != 0, "Cannot allocate memery");
  m_outputBufferHead = m_outputBuffer;
  m_outputBufferTail = m_outputBuffer + m_bufferSize;
}

void
RoboJudge::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  fclose (m_filePtr);
  fwrite (m_outputBuffer, 1, m_outputBufferHead - m_outputBuffer, m_filePtr);
  delete[] m_outputBuffer;
}
void
RoboJudge::Update ()
{
  DoUpdate ();
  Simulator::Schedule (Seconds (m_updatePeriod), &RoboJudge::Update, this);
}

void
RoboJudge::DoUpdate ()
{
  NS_LOG_FUNCTION (this);
  auto iter = m_smallAmmo.begin ();
  while (iter != m_smallAmmo.end ())
    {
      if ((*iter)->m_isDeleted)
        {
          m_smallAmmo.erase (iter++);
        }
      else
        {
          iter++;
        }
    }
  iter = m_largeAmmo.begin ();
  while (iter != m_largeAmmo.end ())
    {
      if ((*iter)->m_isDeleted)
        {
          m_largeAmmo.erase (iter++);
        }
      else
        {
          iter++;
        }
    }
  // std::cout << "Ammo " << m_largeAmmo.size () << "  " << m_smallAmmo.size () << std::endl;
  // std::cout << (int) m_robos.size () << std::endl;
  for (uint32_t i = 0; i < m_robos.size (); ++i)
    {
      for (uint32_t j = i + 1; j < m_robos.size (); ++j)
        {
          if (m_robos[i]->m_collision->m_globalLocation.GetDistance (
                  m_robos[j]->m_collision->m_globalLocation) < m_visibleDistance)
            {
              DynamicCast<RoboBase> (m_robos[i])->IndicateLocation (m_robos[j]);
              DynamicCast<RoboBase> (m_robos[j])->IndicateLocation (m_robos[i]);
            }
          if (IsCollision (m_robos[i]->m_collision, m_robos[j]->m_collision))
            {
              std::cout << "  " << (int) DynamicCast<RoboBase> (m_robos[i])->m_team
                        << DynamicCast<RoboBase> (m_robos[i])->m_name << "  "
                        << (int) DynamicCast<RoboBase> (m_robos[j])->m_team
                        << DynamicCast<RoboBase> (m_robos[j])->m_name << std::endl;
              m_robos[i]->IndicateCollision (m_robos[j]);
              m_robos[j]->IndicateCollision (m_robos[i]);
            }
        }
      for (auto j : m_smallAmmo)
        {
          if (IsCollision (m_robos[i]->m_collision, j->m_collision))
            {
              m_robos[i]->IndicateCollision (j);
              j->IndicateCollision (m_robos[i]);
            }
        }
      for (auto j : m_largeAmmo)
        {
          if (IsCollision (m_robos[i]->m_collision, j->m_collision))
            {
              m_robos[i]->IndicateCollision (j);
              j->IndicateCollision (m_robos[i]);
            }
        }
    }
}
void
RoboJudge::AddRobo (Ptr<RoboActor> actor)
{
  NS_LOG_FUNCTION (this);
  m_robos.push_back (actor);
  m_nameRoboMap.emplace (DynamicCast<RoboBase> (actor)->m_name, actor);
}

void
RoboJudge::AddSmallAmmo (Ptr<RoboActor> actor)
{
  NS_LOG_FUNCTION (this);
  m_smallAmmo.push_back (actor);
}

void
RoboJudge::AddLargeAmmo (Ptr<RoboActor> actor)
{
  NS_LOG_FUNCTION (this);
  m_largeAmmo.push_back (actor);
}

void
RoboJudge::TransLargeAmmo (Ptr<RoboActor> from, std::string to, int num)
{
  NS_LOG_FUNCTION (this);
  // Ptr to ammo giver
  Ptr<RoboBase> giver = DynamicCast<RoboBase> (from);
  if (giver->m_largeAmmo->GetNumber () < num)
    {
      return;
    }
  auto iter = m_nameRoboMap.find (to);
  if (iter == m_nameRoboMap.end ())
    {
      return;
    }
  Ptr<RoboBase> receiver = DynamicCast<RoboBase> (iter->second);
  if (receiver->m_largeAmmo->GetNumber () + num > receiver->m_largeAmmo->m_maxNumber)
    {
      return;
    }
  giver->m_largeAmmo->UseAmmo (num);
  receiver->ReceiveLargeAmmo (num);
  return;
}

void
RoboJudge::TransSmallAmmo (Ptr<RoboActor> from, std::string to, int num)
{
  NS_LOG_FUNCTION (this);
  // Ptr to ammo giver
  Ptr<RoboBase> giver = DynamicCast<RoboBase> (from);
  if (giver->m_smallAmmo->GetNumber () < num)
    {
      return;
    }
  auto iter = m_nameRoboMap.find (to);
  if (iter == m_nameRoboMap.end ())
    {
      return;
    }
  Ptr<RoboBase> receiver = DynamicCast<RoboBase> (iter->second);
  if (receiver->m_smallAmmo->GetNumber () + num > receiver->m_smallAmmo->m_maxNumber)
    {
      return;
    }
  giver->m_smallAmmo->UseAmmo (num);
  receiver->ReceiveSmallAmmo (num);
  return;
}

void
RoboJudge::PutChar (unsigned char ch)
{
  if (m_outputBufferHead == m_outputBufferTail)
    {
      fwrite (m_outputBuffer, 1, m_bufferSize, m_filePtr);
      m_outputBufferHead = m_outputBuffer;
    }
  *m_outputBufferHead++ = ch;
}

void
RoboJudge::PlotAll ()
{
  for (auto &robo : m_robos)
    {
      PlotRobo (DynamicCast<RoboBase> (robo));
    }
  for (auto &ammo : m_smallAmmo)
    {
      if (ammo->m_isDeleted)
        {
          continue;
        }
      PlotSmallAmmo (ammo);
    }
  for (auto &ammo : m_largeAmmo)
    {
      if (ammo->m_isDeleted)
        {
          continue;
        }
      PlotLargeAmmo (ammo);
    }
  Simulator::Schedule (Seconds (m_plotPeriod), &RoboJudge::PlotAll, this);
}
void
RoboJudge::PlotRobo (Ptr<RoboActor> robo)
{
  auto cast = DynamicCast<RoboBase> (robo);
  // Simulator::Now ().GetSeconds ();
  // cast->m_uid;
  // cast->m_collision->m_globalLocation;
  // cast->m_collision->m_globalRotation;
  fprintf (m_filePtr, "%.4f$%u$%.4f:%.4f$%.4f\n", Simulator::Now ().GetSeconds (), cast->m_uid,
           cast->m_collision->m_globalLocation.m_x, cast->m_collision->m_globalLocation.m_y,
           cast->m_collision->m_globalRotation.m_phi);
}
void
RoboJudge::PlotLargeAmmo (Ptr<RoboActor> ammo)
{
  fprintf (m_filePtr, "%.4f&0&%.4f:%.4f\n", Simulator::Now ().GetSeconds (),
           ammo->m_collision->m_globalLocation.m_x, ammo->m_collision->m_globalLocation.m_y);
}
void
RoboJudge::PlotSmallAmmo (Ptr<RoboActor> ammo)
{
  fprintf (m_filePtr, "%.4f&1&%.4f:%.4f\n", Simulator::Now ().GetSeconds (),
           ammo->m_collision->m_globalLocation.m_x, ammo->m_collision->m_globalLocation.m_y);
}
} // namespace ns3
