#include "UserData.h"

CUserData::CUserData()
	: pNext(nullptr), szName{0}, szPhone{0}
{
	//nUserDataCounter++;
}

CUserData::~CUserData()
{
	//nUserDataCounter--;
}