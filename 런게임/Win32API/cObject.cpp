#include "stdafx.h"
#include "cObject.h"


cObject::cObject()
{
	m_pObjectImage = new cImage;
	m_pObjectImage->Setup("images/Bullet.bmp", 47, 34);
	//m_pObjectImage->Setup("images/Bullet.bmp", 472, 342);

}


cObject::~cObject()
{
}


void cObject::Setup()
{

	//m_nSourX = 0;
	//m_nMoveSpeed = 5;
	m_fObjMove = 0;// WINSIZEX - 100;
	m_fIncSpeed = 8;

}

void cObject::Update()
{
	m_fObjMove += m_fIncSpeed;

	if (m_fObjMove >= 1071)
		m_fObjMove = 0;

	//m_fObjMove += m_fIncSpeed;
	//
	//if (m_fObjMove >= 0)
	//	m_fObjMove = WINSIZEX;
	//
	//m_pObjectImage->SetPosX(m_pObjectImage->GetPosX() + 5.0f);
}

void cObject::Render()
{
	//m_pBgImage->Render(g_hDC, 0, 0, m_nSourX, 0, WINSIZEX, WINSIZEY);
	//m_pObjectImage->Render(g_hDC, WINSIZEX, WINSIZEY - 100, m_fObjMove, WINSIZEY - 100, 472, 342);
	m_pObjectImage->Render(g_hDC, WINSIZEX, 495, m_fObjMove, 0, -WINSIZEX, WINSIZEY);
}
