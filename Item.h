#pragma once
#include "Obj.h"
class CItem :
	public CObj
{
public:
	CItem();
	CItem(const char* szName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	CItem(CItem& rItem);
	virtual ~CItem();

public:
	virtual void    Initialize() override;
	virtual void    Render() override;
	virtual void    Release() override;

public:
	const ITEMTYPE& Get_ItemType(void) const { return m_eItemType; }
	void			Set_Equip(bool _bEquip) { m_bEquip = _bEquip; }
	bool			Get_Equip(void) { return m_bEquip; }
	void			Set_ItemType(ITEMTYPE _eItemType) { m_eItemType = _eItemType; }
	void			Set_Price(int _iPrice) { m_tInfo.iMoney = _iPrice; }

private:
	ITEMTYPE    m_eItemType = ITEMTYPE::ITEM_END;
	bool        m_bEquip = false;
};

