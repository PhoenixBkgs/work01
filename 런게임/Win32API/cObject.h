#pragma once
#include "cImage.h"

#define ObjStart_X (WINSIZEX)
#define ObjStart_Y (WINSIZEY)

class cObject
{
private:
	cImage*			m_pObjectImage;
	int				m_fObjMove;
	int				m_fIncSpeed;

public:
	cObject();
	~cObject();

	void Setup();
	void Update();
	void Render();
};

