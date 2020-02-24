#include "UserData.h"
#include "header.h"

int CUserData::nUserDataCounter = -1;

CUserData::CUserData()
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	strcpy_s(szName, sizeof(szName), pszName);
	strcpy_s(szPhone, sizeof(szPhone), pszPhone);

	nUserDataCounter++;
}

const char* CUserData::getKey()
{
	return szName;
}

void CUserData::PrintNode()
{
	printf("[%p] %s\t%s [%p]\n",
		this,
		szName, szPhone,
		getNext());
}
CUserData::~CUserData()
{
	nUserDataCounter--;
}