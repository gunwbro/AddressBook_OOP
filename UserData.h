#pragma once
#include "MyNode.h"

class CUserData : public CMyNode
{
	friend class CMyList;

public:
	CUserData();
	CUserData(const char* pszName, const char* pszPhone);
	~CUserData();

	const char* getName() const { return szName; }
	const char* getPhone() const { return szPhone; }
	static int getUserDataCounter() { return nUserDataCounter; }

protected:
	char szName[32];    // �̸�
	char szPhone[32];   // ��ȭ��ȣ

	static int nUserDataCounter;

public:
	// ���� ���� �Լ��� ����
	virtual const char* getKey();
	virtual void PrintNode();
};