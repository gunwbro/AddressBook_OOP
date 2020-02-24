#pragma once

class CMyNode
{
	friend class CMyList;
public:
	CMyNode();
	virtual ~CMyNode();

	CMyNode* getNext() const { return pNext; }

	// 관리를 위해 꼭 필요한 인터페이스 함수들을 순수 가상 함수로 선언
	virtual const char* getKey() = 0;
	virtual void PrintNode() = 0;

private:
	// 연결 리스트 자체를 위한 멤버
	CMyNode* pNext;
};

