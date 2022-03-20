#pragma once
#include "Obj.h"
#include "Item.h"
#include "Inven.h"

class CPlayer :
    public CObj
{
public:
    CPlayer();
    CPlayer(const char* _Name, int _iAttack, int _iMaxHp, int _iLevel);
    virtual ~CPlayer();

public:
    virtual void Initialize()   override;
    virtual void Render()       override;
    virtual void Release()      override;

public:
    void    SelectJob(void);
    void    COMBAT_WIN(int _iExp, int _iMoney);
    void    COMBAT_LOSE(void);
    void    COMBAT_RUN(void);

public:
    void    Equip_Item(CObj* _pItem);
    void    Unequip_Item(CObj* _pItem);
    void    Adjust_ItemAbility(CObj* _pItem, bool _bEquipStatus);

private:
    void    Load_Data(void);

private:
    // ITEM_TYPE에 따른 장비 슬롯
    CObj* m_pEquip_slot[(int)ITEMTYPE::ITEM_END];
    // // 인벤토리
    // CInven* m_pInven;
};