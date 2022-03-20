#include "pch.h"
#include "Item.h"

CItem::CItem()
	: CObj()
{
}

CItem::CItem(const char* szName, int _iAttack, int _iMaxHp, int _iLevel)
	: CObj(szName, _iAttack, _iMaxHp, _iLevel)
{
}

CItem::CItem(CItem& rItem)
	: CObj(rItem)
	, m_eItemType(rItem.m_eItemType)
	, m_bEquip(rItem.m_bEquip)
{
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
}

void CItem::Render()
{
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "���ݷ� : " << m_tInfo.iAttack << endl;
	cout << "ü�� : " << m_tInfo.iHp << endl;
	cout << "���� : " << m_tInfo.iMoney << endl;
	cout << "==============================" << endl;
}

void CItem::Release()
{
}
