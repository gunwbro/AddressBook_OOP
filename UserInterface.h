#pragma once

// 클래스 전방 선언
class CMyList;

class CUserInterface
{
public:
	CUserInterface(CMyList& rList);
	~CUserInterface();

protected:
	CMyList& m_List;

public:
	void Add();
	void Search();
	void Remove();
	int PrintUI();
	int Run();
};