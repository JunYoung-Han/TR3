#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	CMonster(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel);
	virtual ~CMonster();

public:
	virtual void	Initialize(void);
	virtual void	Render(void);
	virtual void	Release(void);
};

