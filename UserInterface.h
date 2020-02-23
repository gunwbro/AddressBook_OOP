#pragma once

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