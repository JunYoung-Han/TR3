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

		cout << "1. �ʱ�  2. �߱�  3. ���  4. �� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("�ʱ�", 10, 50, 1);
			m_pMonster->Initialize();
			break;

		case 2:
			m_pMonster = new CMonster("�߱�", 20, 70, 2);
			m_pMonster->Initialize();
			break;

		case 3:
			m_pMonster = new CMonster("���", 30, 90, 3);
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

		cout << "1. ����  2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster->Set_Damage(m_pPlayer->Get_Info().iAttack);
			m_pPlayer->Set_Damage(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "�¸�" << endl;
				return COMBAT::COMBAT_WIN;
			}
			if (0 >= m_pPlayer->Get_Info().iHp)
			{
				cout << "�÷��̾� ���" << endl;
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
