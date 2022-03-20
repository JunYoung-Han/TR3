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
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "레벨 : " << m_tInfo.iLevel << endl;
	cout << "공격력 : " << m_tInfo.iAttack << endl;
	cout << "체력 / 최대 체력 : " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "경험치 / 최대 경험치 : " << m_tInfo.iExp << " / " << m_tInfo.iMaxExp << endl;
	cout << "소지금 : " << m_tInfo.iMoney << endl;
	cout << "==========================" << endl;
}

void CPlayer::Release()
{
}

void CPlayer::SelectJob(void)
{
	int iInput = 0;

	cout << "직업 선택 : 1. 전사  2. 마법사  3. 도적  4. 불러오기  5. 종료 : " << endl;
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, 32, "전사");
		m_tInfo.iAttack = 10;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;
		
	case 2:
		strcpy_s(m_tInfo.szName, 32, "마법사");
		m_tInfo.iAttack = 10;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;
		
	case 3:
		strcpy_s(m_tInfo.szName, 32, "도적");
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

void CPlayer::COMBAT_WIN(int _iExp, int _iMoney)
{
	m_tInfo.iExp += _iExp;
	m_tInfo.iMoney += _iMoney;

	if (m_tInfo.iExp >= m_tInfo.iMaxExp)
	{
		++m_tInfo.iLevel;
		m_tInfo.iMaxExp *= 1.1;
		m_tInfo.iMaxHp *= 1.1;
		m_tInfo.iAttack *= 1.1;
		m_tInfo.iHp = m_tInfo.iMaxHp;
	}
}

void CPlayer::COMBAT_LOSE(void)
{
	m_tInfo.iExp = 0;
	m_tInfo.iHp = m_tInfo.iMaxHp;
	m_tInfo.iMoney >> 1;
}

void CPlayer::COMBAT_RUN(void)
{
	m_tInfo.iMoney >> 1;
}

void CPlayer::Load_Data(void)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/Save_Player.dat", "rb");

	if (0 == err)
	{
		INFO tInfo = {};

		fread(&tInfo, sizeof(INFO), 1, fp);

		m_tInfo = tInfo;

		cout << "캐릭터 정보 불러오기 성공" << endl;
		fclose(fp);
	}
	else
		cout << "캐릭터 정보 불러오기 실패" << endl;
	system("pause");
}
