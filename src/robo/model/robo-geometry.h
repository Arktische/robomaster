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
 * Modified by:     Zhichao Liu
 */
#pragma once
#include "fvector2.h"
#include "fangle2.h"
const float EPS = 1e-4;

namespace ns3 {
typedef FVector2 FVector; //FVector2ȡһ������FVector
typedef FAngle2 FAngle; //FAngle2ȡһ������FAngle
  /**
 * \brief ��������������߶�
 * 
 *
 *   
 * 
 */ 
class LineSegment
{
public:
  FVector m_start; //��ʼ��
  FVector m_end; //�յ�

  /**
 * \brief ���캯��
 *  
 *
 * \param st ��ʼ��
 *        ed �յ�
 * \returns LineSegmentʵ��
 */
  LineSegment (FVector st, FVector ed);
  /**
 * \brief ���캯��
 *  
 *
 * \param x1 y1 ��ʼ���������
 *        x2 y2 �յ��������
 * \returns LineSegmentʵ��
 */  
  LineSegment (float x1, float y1, float x2, float y2);
  /**
 * \brief ���캯��
 *  
 *
 * \param oth ���ڳ�ʼ����ʵ��
 * \returns LineSegmentʵ��
 */
  LineSegment (const LineSegment &oth);
  /**
 * \brief Ĭ����������
 *  
 *
 * \param None
 * \returns None
 */
  ~LineSegment ();
};

  /**
 * \brief ���ֲ�����תΪȫ������
 *  
 *
 * \param centerOfSubcoordinate �ֲ���������(ԭ��)
 *        directionOfSubcoordinate �ֲ����귽��(�����˳���)
 *        coordinate �ֲ�����ϵ����
 * \returns �ֲ�����ϵ��������ȫ������ϵ����Ӧ������
 */
FVector2 ConvCoordinate (FVector2 centerOfSubcoordinate, FAngle2 directionOfSubcoordinate,
                         FVector2 coordinate);
  /**
 * \brief �ж����߶��Ƿ��ཻ
 *  
 *
 * \param st1 ed1 �߶�1����ʼ�����յ�
 *        st2 ed2 �߶�2����ʼ�����յ�
 * \returns 1��ʾ�ཻ
 *          0��ʾ���ཻ
 */
bool IsCross (FVector2 st1, FVector2 ed1, FVector2 st2, FVector2 ed2);
  /**
 * \brief �ж����߶��Ƿ��ཻ
 *  
 *
 * \param l1 �߶�1
 *        l2 �߶�2
 * \returns 1��ʾ�ཻ
 *          0��ʾ���ཻ
 */
bool IsCross (const LineSegment l1, const LineSegment l2);
  /**
 * \brief �жϵ��Ƿ�����������
 *  
 *
 * \param point ��
 *        p1 p2 p3 ���������߶���
 * \returns 1��ʾ���ڲ�
 *          0��ʾ�����ڲ�
 */
bool PointInTriangle (FVector2 point, FVector2 p1, FVector2 p2, FVector2 p3);
  /**
 * \brief �ж��߶���Բ�Ƿ��ཻ
 *  
 *
 * \param center Բ��
 *        redius �뾶
 *        st ed �߶���ʼ�����յ�
 * \returns 1��ʾ�ཻ
 *          0��ʾ���ཻ
 */
bool CircleCrossLineSegment (FVector2 center, float redius, FVector2 st, FVector2 ed);
} // namespace ns3
