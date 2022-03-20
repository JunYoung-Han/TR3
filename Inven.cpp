#include "pch.h"
#include "Inven.h"

CInven::CInven()
    : m_pPlayer(nullptr)
    , m_iInvenSize(5)
{
}

CInven::~CInven()
{
    Release();
}

void CInven::Initialize()
{
    // ���� ���� �̸� �Ҵ�
    m_vecInven.reserve(m_iInvenSize);
}

void CInven::Update()
{
    // ������ ���� & ����
    int iInput = 0;

    while (true)
    {
        system("cls");
        m_pPlayer->Render();

        cout << "1. ����  2. ����  3. �� �ܰ� : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Equip_Item();
            break;
            
        case 2:
            Unequip_Item();
            break;
            
        case 3:
            return;

        default:
            continue;
        }
    }
}

void CInven::Release()
{
    for_each(m_vecInven.begin(), m_vecInven.end(), CDeleteObj());
    m_vecInven.clear();
    vector<CObj*>().swap(m_vecInven);
}

void CInven::Equip_Item()
{
    int iInput = 0;
    while (iInput)
    {
        system("cls");
        m_pPlayer->Render();
        Render_All();

        cout << "0. ������ : ";
        cin >> iInput;
        --iInput;
        if (0 > iInput)
            return;

        if ((size_t)iInput >= m_vecInven.size())
            continue;

        dynamic_cast<CPlayer*>(m_pPlayer)->Equip_Item(m_vecInven[iInput]);
    }
}

void CInven::Unequip_Item()
{
    int iInput = 0;
    while (iInput)
    {
        system("cls");
        m_pPlayer->Render();
        Render_Equipped();

        cout << "0. ������ : ";
        cin >> iInput;
        --iInput;
        if (0 > iInput)
            return;

        if ((size_t)iInput >= m_vecInven.size())
            continue;

        dynamic_cast<CPlayer*>(m_pPlayer)->Unequip_Item(m_vecInven[iInput]);
    }
}

void CInven::Render_All()
{
    for (size_t i = 0; i < m_vecInven.size(); ++i)
    {
        cout << i + 1 << ". ";
        m_vecInven[i]->Render();
    }
}

void CInven::Render_Equipped()
{
    for (size_t i = 0; i < m_vecInven.size(); ++i)
    {
        if (dynamic_cast<CItem*>(m_vecInven[i])->Get_Equip())
        {
            cout << i + 1 << ". ";
            m_vecInven[i]->Render();
        }
    }

}

bool CInven::Is_BuyItem(CObj* _pItem)
{
    return false;
}

bool CInven::Is_SellItem(int _iSelect, int& _iMoney)
{
    return false;
}
