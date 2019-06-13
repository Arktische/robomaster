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
 */
#pragma once
#include <ostream>
namespace ns3 {
  /**
 * \brief ������������������������
 * 
 *
 *   
 * 
 */  
class FVector2
{
public:
  /**
 * \brief Ĭ�Ϲ��캯��
 *  
 *
 * \param None 
 * \returns FVector2ʵ��
 */
  FVector2 (void);
  /**
 * \brief ���캯��
 *  
 *
 * \param x ������
 *        y ������
 * \returns FVector2ʵ��
 */
  FVector2 (float x, float y);
  /**
 * \brief ���캯��
 *  
 *
 * \param oth ������ʼ������һ��ʵ��
 * \returns FVector2ʵ��
 */
  FVector2 (const FVector2 &oth);

  /**
 * \brief ���ز�����"+"
 * 
 *
 * \param oth ��Ҫ���м��������һ������  
 * \returns �����������͵���ʵ�� 
 */  
  FVector2 operator+ (FVector2 oth);
  /**
 * \brief ���ز�����"+="
 * 
 *
 * \param oth ��Ҫ����"+="�������һ������  
 * \returns ���ô˷�����ʵ��
 */    
  FVector2 operator+= (FVector2 oth);
  /**
 * \brief ���ز�����"-"
 * 
 *
 * \param oth ��Ҫ����"-"�������һ������  
 * \returns ���������������ʵ��
 */  
  FVector2 operator- (FVector2 oth);
  /**
 * \brief ���ص�Ŀ������"-"
 * 
 *
 * \param None  
 * \returns ������ԭ�������ԭ��ԳƵ���ʵ��
 */  
  FVector2 operator- (void);
  /**
 * \brief ���ز�����"-="
 * 
 *
 * \param oth ��Ҫ����"-="�������һ������ 
 * \returns ���ô˷�����ʵ�� 
 */
  FVector2 operator-= (FVector2 oth);
  /**
 * \brief ���ز�����"*"
 * 
 *
 * \param oth ���в�˵���һ������  
 * \returns ������ԭ�����˵õ��ĸ�����
 */  
  float operator* (FVector2 oth);
  /**
 * \brief ���ز�����"*"
 * 
 *
 * \param oth ��������������ı��� 
 * \returns ����������Ӧ��������ʵ��
 */ 
  FVector2 operator* (float oth);
  
  /**
 * \brief ��������֮��ľ���
 * 
 *
 * \param oth ����������һ������
 * \returns �������
 */ 
  float GetDistance (FVector2 oth) const;
  /**
 * \brief ��������֮��ľ����ƽ��
 * 
 *
 * \param oth �������ƽ������һ������
 * \returns ��������ƽ��
 */ 
  float GetDistance2 (FVector2 oth) const;
  /**
 * \brief ����������ģ
 * 
 *
 * \param None
 * \returns ģֵ
 */
  float GetLength (void) const;
  /**
 * \brief ���ز�����"<<"
 * 
 *
 * \param os ��׼�����
 *        vector Ҫ�����ʵ��  
 * \returns ��׼�����
 */  
  friend std::ostream &operator<< (std::ostream &os, const FVector2 &vector);

  float m_x; //������
  float m_y; //������
};
  /**
 * \brief ���������
 * 
 *
 * \param oth �����˵���һ������
 * \returns ��˽��
 */ 
float Dot (FVector2 v1, FVector2 v2);
} // namespace ns3
