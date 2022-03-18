#include "pch.h"
#include "MainGame.h"

CMainGame::CMainGame()
	: m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	if (nullptr == m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
	dynamic_cast<CPlayer*>(m_pPlayer)->SelectJob();

}

void CMainGame::Update(void)
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. 사냥터  2. 상점  3. 인벤토리  4. 저장  5. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{

		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:
			break;

		case 5:
			return;

		default:
			continue;
		}
	}
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);
}