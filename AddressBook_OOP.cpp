#include "UserInterface.h"
#include "MyList.h"
#include "header.h"
#include "UserData.h"

int main()
{
	CMyList DB(new CUserData);
	CUserInterface UI(DB);
	UI.Run();

	return 0;
}