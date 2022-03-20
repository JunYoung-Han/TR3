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
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "공격력 : " << m_tInfo.iAttack << endl;
	cout << "체력 : " << m_tInfo.iHp << endl;
	cout << "가격 : " << m_tInfo.iMoney << endl;
	cout << "==============================" << endl;
}

void CItem::Release()
{
}
