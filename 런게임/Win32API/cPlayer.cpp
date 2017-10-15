#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pPlayerImage = new cImage;
	m_pPlayerImage->Setup("images/Rockman.bmp", 320, 235, 4, 3,
		128, MAP1_Y, true, RGB(255, 0, 255));
}


cPlayer::~cPlayer()
{
}

void cPlayer::Setup()
{
	m_nMapYPos = MAP1_Y;
	m_fJumpDefault = -7.0f;
	m_fJumpPower = m_fJumpDefault;

	SetLanding();
}

void cPlayer::Update()
{
	m_isSlide = false;
	if (!m_isJumpping && !m_is2ndJump && g_pKeyManager->isOnceKeyDown(VK_SPACE))
	{
		m_fJumpPower = m_fJumpDefault;
		m_isJumpping = true;
	}

	if (m_isJumpping)
	{		//���� �ִϸ��̼�
		
		m_fGravity += GRAVITY;
		m_fJumpPower += GRAVITY;
		m_pPlayerImage->SetPosY(m_pPlayerImage->GetPosY() + m_fJumpPower);
		m_pPlayerImage->FrameRender(g_hDC,
			(int)(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
			(int)(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
			0, 0, 0, 0, 0); //FrameRender(HDC hdc, int ��������X, ��������Y, ��������X, ��������Y, �ƽ�������X, �ƽ�������Y, ������)
		
		//m_fGravity += GRAVITY;//�������°�
	}
	if (!m_is2ndJump && m_isJumpping && g_pKeyManager->isOnceKeyDown(VK_SPACE))//2������
	{
		m_fJumpPower = m_fJumpDefault;
		m_isJumpping = false;
		m_is2ndJump = true;
	}
	if (m_is2ndJump)//2�� ���� �۵�
	{
		m_fGravity += GRAVITY;
		m_fJumpPower += GRAVITY;
		m_pPlayerImage->SetPosY(m_pPlayerImage->GetPosY() + m_fJumpPower); //��°� + �ϰ���
		//2�� ���� �ִϸ��̼�
		m_pPlayerImage->FrameRender(g_hDC,
			(int)(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
			(int)(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
			1, 0, 3, 0, 4); //FrameRender(HDC hdc, int ��������X, ��������Y, ��������X, ��������Y, �ƽ�������X, �ƽ�������Y, ������)
		
	}
	if (!m_isJumpping && !m_is2ndJump && g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		m_isSlide = true;
	}
	if (m_isSlide)
	{
		//�����̵� �ִϸ��̼�
		m_pPlayerImage->FrameRender(g_hDC,
			(int)(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
			(int)(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
			0, 2, 3, 2, 2); //FrameRender(HDC hdc, int ��������X, ��������Y, ��������X, ��������Y, �ƽ�������X, �ƽ�������Y, ������)
	}
	if (m_fGravity > m_fJumpPower &&
		m_pPlayerImage->GetPosY() > m_nMapYPos - m_pPlayerImage->GetFrameHeight() / 2)
	{
		SetLanding();
	}


}

void cPlayer::Render()
{
	HPEN hPen = (HPEN)CreatePen(0, 3, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	//RectangleMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5));
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).top,
		m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).top);
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).top,
		m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom);
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom,
		m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom);
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom,
		m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).top);

	DeleteObject(hSelectPen);
	DeleteObject(hPen);



	//�ȱ� �ִϸ��̼�

	m_pPlayerImage->FrameRender(g_hDC,
		(int)(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
		(int)(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
		0, 1, 3, 1, 10); //FrameRender(HDC hdc, int ��������X, ��������Y, ��������X, ��������Y, �ƽ�������X, �ƽ�������Y, ������)
	
}

void cPlayer::SetLanding()
{
	m_pPlayerImage->SetCenterY(m_nMapYPos);
	m_fGravity = 0.0f;
	m_isJumpping = false;
	m_is2ndJump = false;
}