#include "UserInterface.h"
#include "MyList.h"
#include "header.h"
#include "UserData.h"
CUserInterface::CUserInterface(CMyList& rList) : m_List(rList)
{
}

CUserInterface::~CUserInterface()
{
}

void CUserInterface::Add()
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	cout << "input name : ";
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	cout << "Input phone number : ";
	fflush(stdin);
	gets_s(szPhone, sizeof(szPhone));

	int result = m_List.AddNewNode(new CUserData(szName, szPhone));

	if (result == 0)
		cout << "이미 존재하는 데이터 입니다." << endl;
}

int CUserInterface::PrintUI()
{
	int nInput = 0;

	system("cls");
	cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:";

	scanf_s("%d", &nInput);

	while (getchar() != '\n');
	return nInput;
}

void CUserInterface::Search()
{
	char szName[32] = { 0 };
	CMyNode* pNode = nullptr;

	cout << "Input name : ";
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = m_List.FindNode(szName);
	if (pNode != nullptr)
	{
		pNode->PrintNode();
	}
	else
		cout << "ERROR: 데이터를 찾을 수 없습니다.";

	_getch();
}

void CUserInterface::Remove()
{
	char szName[32] = { 0 };

	cout << "Input name : ";
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	m_List.RemoveNode(szName);
}

int CUserInterface::Run()
{
	int nMenu = 0;

	//메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:  // Add
			Add();
			break;
			
		case 2:
			Search();
			break;
			
		case 3:
			m_List.PrintAll();
			break;

		case 4:
			Remove();
			break;
		}

	}

	return nMenu;
}