#include "pch.h"
#include "Player.h"

CPlayer::CPlayer()
	: CObj()
{
}

CPlayer::CPlayer(const char* _Name, int _iAttack, int _iMaxHp, int _iLevel)
	: CObj(_Name, _iAttack, _iMaxHp, _iLevel)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	// Temp
}

void CPlayer::Render()
{
	cout << "==========================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "���� : " << m_tInfo.iLevel << endl;
	cout << "���ݷ� : " << m_tInfo.iAttack << endl;
	cout << "ü�� / �ִ� ü�� : " << m_tInfo.iMaxHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "����ġ / �ִ� ����ġ : " << m_tInfo.iExp << " / " << m_tInfo.iMaxExp << endl;
	cout << "������ : " << m_tInfo.iMoney << endl;
	cout << "==========================" << endl;
}

void CPlayer::Release()
{
}

void CPlayer::SelectJob(void)
{
	int iInput = 0;

	cout << "���� ���� : 1. ����  2. ������  3. ����  4. �ҷ�����  5. ���� : " << endl;
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, 32, "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;
		
	case 2:
		strcpy_s(m_tInfo.szName, 32, "������");
		m_tInfo.iAttack = 10;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;
		
	case 3:
		strcpy_s(m_tInfo.szName, 32, "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;
		
	case 4:
		// Load_Date();
		break;
		
	case 5:
		break;

	default:
		break;
	}
}
