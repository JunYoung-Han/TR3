#pragma once
// Store 클래스.
// 플레이어가 아이템을 사는 씬.
// 메인에서 플레이어와 인벤토리의 주소를 받아옴.

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
	// 각각의 Item Type (arr) 별로 Vector가 생성된다.
	// 아이템 종류별로 아이템을 저장하려는 용도.
	vector<CObj*> m_vecItem[(int)ITEMTYPE::ITEM_END];
};