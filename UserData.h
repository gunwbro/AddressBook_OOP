#pragma once

class CUserData
{
	friend class CMyList;

public:
	CUserData();
	~CUserData();

	const char* getName() const { return szName; }
	const char* getPhone() const { return szPhone; }
	const CUserData* getNext(void) const { return pNext; }

	//static int getUserDataCounter() { return nUserDataCounter; }

protected:
	char szName[32];    // �̸�
	char szPhone[32];   // ��ȭ��ȣ

	CUserData* pNext;

	//static int nUserDataCounter;
};