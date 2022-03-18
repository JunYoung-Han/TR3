#pragma once

class CObj
{
public:
	CObj();
	CObj(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel);
	CObj(CObj& rCObj);
	virtual ~CObj();

public:
	const INFO& Get_Info(void) const { return m_tInfo; }
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }
	void		But_Item(int _iPrice) { m_tInfo.iMoney -= _iPrice; }

public:
	virtual void	Initialize(void)	PURE;
	virtual void	Render(void)		PURE;
	virtual void	Release(void)		PURE;

protected:
	INFO m_tInfo;
};