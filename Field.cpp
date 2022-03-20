#include "pch.h"
#include "Field.h"

CField::CField()
	: m_pPlayer(nullptr)
{
}

CField::~CField()
{
	Release();
}

void CField::Initialize()
{
}

void CField::Update()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. 초급  2. 중급  3. 고급  4. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("초급", 10, 50, 1);
			m_pMonster->Initialize();
			break;

		case 2:
			m_pMonster = new CMonster("중급", 20, 70, 2);
			m_pMonster->Initialize();
			break;

		case 3:
			m_pMonster = new CMonster("고급", 30, 90, 3);
			m_pMonster->Initialize();
			break;

		case 4:
			return;

		default:
			continue;
		}

		switch (Fight())
		{
		case COMBAT::COMBAT_WIN:
			dynamic_cast<CPlayer*>(m_pPlayer)->COMBAT_WIN(m_pMonster->Get_Info().iExp, m_pMonster->Get_Info().iMoney);
			break;
			
		case COMBAT::COMBAT_LOSE:
			dynamic_cast<CPlayer*>(m_pPlayer)->COMBAT_LOSE();
			break;
			
		case COMBAT::COMBAT_RUN:
			dynamic_cast<CPlayer*>(m_pPlayer)->COMBAT_RUN();
			break;

		default:
			break;
		}
	}
}

void CField::Release()
{
	Safe_Delete<CObj*>(m_pMonster);
}

COMBAT CField::Fight()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();

		cout << "1. 공격  2. 도망 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster->Set_Damage(m_pPlayer->Get_Info().iAttack);
			m_pPlayer->Set_Damage(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "승리" << endl;
				return COMBAT::COMBAT_WIN;
			}
			if (0 >= m_pPlayer->Get_Info().iHp)
			{
				cout << "플레이어 사망" << endl;
				return COMBAT::COMBAT_LOSE;
			}
			break;

		case 2:
			return COMBAT::COMBAT_RUN;

		default:
			continue;
		}
	}
}
