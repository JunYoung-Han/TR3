#pragma once
// Store Ŭ����.
// �÷��̾ �������� ��� ��.
// ���ο��� �÷��̾�� �κ��丮�� �ּҸ� �޾ƿ�.

#include "Player.h"
#include "Inven.h"

class CStore
{
public:
	CStore();
	~CStore();

public:
	void	Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	void	Set_Inven(CInven* _pInven) { m_pInven = _pInven; }

public:
	void	Initialize();
	void	Update();

private:
	void	Release();
	void	Render(ITEMTYPE _eType);
	void	Buy_Item(CObj* pItem);
	void	Sell_Item(void);

private:
	CObj* m_pPlayer;
	CInven* m_pInven;
	// ������ Item Type (arr) ���� Vector�� �����ȴ�.
	// ������ �������� �������� �����Ϸ��� �뵵.
	vector<CObj*> m_vecItem[(int)ITEMTYPE::ITEM_END];
};