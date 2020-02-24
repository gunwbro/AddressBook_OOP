#pragma once

class CMyNode
{
	friend class CMyList;
public:
	CMyNode();
	virtual ~CMyNode();

	CMyNode* getNext() const { return pNext; }

	// ������ ���� �� �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const char* getKey() = 0;
	virtual void PrintNode() = 0;

private:
	// ���� ����Ʈ ��ü�� ���� ���
	CMyNode* pNext;
};

