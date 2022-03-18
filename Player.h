#pragma once
#include "Obj.h"
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


private:
};