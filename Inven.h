#pragma once
#include "Player.h"

class CInven
{
public:
	CInven();
	~CInven();

public:
	void	Initialize();
	void	Update();

private:
	void	Release();

public:
	void	Equip_Item();
	void	Unequip_Item();
	void	Render_All();
	void	Render_Selective(bool _isEquipped);
	bool	Is_BuyItem(CObj* _pItem);
	bool	Is_SellItem(int _iSelect, int& _iMoney);

public:
	void	Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }

private:
	CObj* m_pPlayer;
	// 인벤토리 역할 벡터
	vector<CObj*> m_vecInven;
	const size_t m_iInvenSize;
};