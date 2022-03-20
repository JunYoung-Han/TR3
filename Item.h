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

private:
	ITEMTYPE    m_eItemType = ITEMTYPE::ITEM_END;
	bool        m_bEquip = false;
};

