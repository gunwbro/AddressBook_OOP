#include "UserInterface.h"
#include "MyList.h"
#include "header.h"

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

	m_List.AddNewNode(szName, szPhone);
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
	CUserData* pNode = nullptr;

	cout << "Input name : ";
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = m_List.FindNode(szName);
	if (pNode != nullptr)
	{
		printf("[%p] %s\t%s [%p]\n",
			pNode,
			pNode->getName(), pNode->getPhone(),
			pNode->getNext());
	}
	else
		cout << "ERROR: �����͸� ã�� �� �����ϴ�.";

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

	//���� �̺�Ʈ �ݺ���
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