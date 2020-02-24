#pragma once
#include "MyNode.h"

class CMyNode;

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	~CMyList();

protected:
	void ReleaseList();
	CMyNode* m_pHead;

public:
	CMyNode* FindNode(const char* pszKey);
	int AddNewNode(CMyNode *pNewNode);
	void PrintAll();
	int RemoveNode(const char* pszKey);
};