#include "MyList.h"
#include "header.h"
#include "UserData.h"

CMyList::CMyList(CMyNode* pHead)
{
	m_pHead = pHead;
}

CMyList::~CMyList()
{
	ReleaseList();
}

int CMyList::AddNewNode(CMyNode* pNewNode)
{
	if (FindNode(pNewNode->getKey()) != nullptr)
	{
		delete pNewNode;

		return 0;
	}

	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;

	return 1;
}

void CMyList::PrintAll()
{
	CMyNode* pTmp = m_pHead->pNext;

	while (pTmp != nullptr)
	{
		pTmp->PrintNode();
		pTmp = pTmp->pNext;
	}

	printf("CUserData Counter : %d\n", CUserData::getUserDataCounter());
	_getch();
} 

CMyNode* CMyList::FindNode(const char* pszKey)
{
	CMyNode* pTmp = m_pHead->pNext;
	while (pTmp != nullptr)
	{
		if (strcmp(pTmp->getKey(), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return nullptr;
}

int CMyList::RemoveNode(const char* pszKey)
{
	CMyNode* pPrevNode = m_pHead;
	CMyNode* pDelete = nullptr;

	while (pPrevNode->pNext != nullptr)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->getKey(), pszKey) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

void CMyList::ReleaseList()
{
	CMyNode* pTmp = m_pHead->pNext;
	CMyNode* pDelete = nullptr;

	while (pTmp != nullptr)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_pHead = nullptr;
}