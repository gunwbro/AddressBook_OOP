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
	char szName[32];    // 이름
	char szPhone[32];   // 전화번호

	static int nUserDataCounter;

public:
	// 순수 가상 함수들 정의
	virtual const char* getKey();
	virtual void PrintNode();
};