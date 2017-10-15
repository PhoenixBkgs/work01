#include "stdafx.h"
#include "cMap.h"


cMap::cMap()
{
	m_pBgImage = new cImage;
	m_pBgImage->Setup("images/bg2.bmp", 2400 , 675);
}


cMap::~cMap()
{
}

void cMap::Setup()
{
	m_nSourX = 0;
	m_nMoveSpeed = 5;
}

void cMap::Update()
{
	m_nSourX += m_nMoveSpeed;

	if (m_nSourX >= 800)
		m_nSourX = 0;
}

void cMap::Render()
{
	m_pBgImage->Render(g_hDC, 0, 0, m_nSourX, 0, WINSIZEX, WINSIZEY);

	// string ���ڿ� Ŭ���� : ���ڿ��� ���� ������ ����� �����ϴ� ex) +=
	string str("�� X ��ǥ : ");
	char szStr[128];
	//str += "asdfasdfsadf";
	str += itoa(m_nSourX, szStr, 10); // itoa => ��Ʈ���� ���ڿ��� ��ȯ (��ȯ �ҽ�, �ӽ� �����, ������ ����)
	TextOutA(g_hDC, 100, 100, str.c_str(), str.length());
}