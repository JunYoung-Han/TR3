#include "pch.h"
#include "Player.h"

CPlayer::CPlayer()
	: CObj()
{
	memset(m_pEquip_slot, 0, sizeof(m_pEquip_slot));
}

CPlayer::CPlayer(const char* _Name, int _iAttack, int _iMaxHp, int _iLevel)
	: CObj(_Name, _iAttack, _iMaxHp, _iLevel)
{
	memset(m_pEquip_slot, 0, sizeof(m_pEquip_slot));
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
	cout << "ü�� / �ִ� ü�� : " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
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
		Load_Data();
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

void CPlayer::Equip_Item(CObj* _pItem)
{
	// ���� �������� Ÿ�� �޾ƿ� ��,
	// ���� ������ ���� ���� Ȯ�� �� 
	// �� ) ���� �� ����
	// - �ش� �������� �ɷ�ġ ���� ��ġ ����
	// - �ش� ���� ���� 
	// �� ) ����
	//

	// �Ű����� �������� ������ Ÿ�� �޾ƿ�.
	ITEMTYPE	eItemType = dynamic_cast<CItem*>(_pItem)->Get_ItemType();

	// ������ �����Ǿ��ִ� �������� ���� ���, ���� �� ������ ������.
	// ������ ������ �ƴ� ���������̱� ������ �������� Delete �� �ʿ�� ����.
	if (nullptr != m_pEquip_slot[(int)eItemType])
	{
		// ������ �ɷ�ġ ����
		Adjust_ItemAbility(m_pEquip_slot[(int)eItemType], false);
		// ���� ������ ���� ���� ����
		dynamic_cast<CItem*>(m_pEquip_slot[(int)eItemType])->Set_Equip(false);
		// �ش� ��� ���� ����
		m_pEquip_slot[(int)eItemType] = nullptr;
	}

	// ������ ����
	// ������ �ɷ�ġ ����
	Adjust_ItemAbility(_pItem, true);
	// �ش� ��� ���� ä���
	m_pEquip_slot[(int)eItemType] = _pItem;
	// �ش� ������ ���� ���� ����
	dynamic_cast<CItem*>(m_pEquip_slot[(int)eItemType])->Set_Equip(true);
}

void CPlayer::Unequip_Item(CObj* _pItem)
{
	ITEMTYPE	eItemType = dynamic_cast<CItem*>(_pItem)->Get_ItemType();
	if (nullptr != m_pEquip_slot[(int)eItemType])
	{
		// ������ �ɷ�ġ ����
		Adjust_ItemAbility(m_pEquip_slot[(int)eItemType], false);
		// ���� ������ ���� ���� ����
		dynamic_cast<CItem*>(m_pEquip_slot[(int)eItemType])->Set_Equip(false);
		// �ش� ��� ���� ����
		m_pEquip_slot[(int)eItemType] = nullptr;
	}
}

void CPlayer::Adjust_ItemAbility(CObj* _pItem, bool _bEquipStatus)
{
	int iAddorSub = _bEquipStatus ? 1 : -1;
	m_tInfo.iAttack += (iAddorSub)*_pItem->Get_Info().iAttack;
	m_tInfo.iMaxHp += (iAddorSub)*_pItem->Get_Info().iHp;
	m_tInfo.iHp = m_tInfo.iMaxHp;
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

		cout << "ĳ���� ���� �ҷ����� ����" << endl;
		fclose(fp);
	}
	else
		cout << "ĳ���� ���� �ҷ����� ����" << endl;

	system("pause");
}
