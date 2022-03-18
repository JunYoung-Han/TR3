#include "pch.h"
#include "Obj.h"

CObj::CObj()
{
}

CObj::CObj(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel)
	: m_tInfo(_szName, _iAttack, _iMaxHp, _iLevel)
{
}

CObj::CObj(CObj& rCObj)
	: m_tInfo(rCObj.m_tInfo)
{
}

CObj::~CObj()
{
}