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
	char szName[32];    // 이름
	char szPhone[32];   // 전화번호

	CUserData* pNext;

	//static int nUserDataCounter;
};