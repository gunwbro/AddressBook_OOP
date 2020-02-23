#include "UserInterface.h"
#include "MyList.h"
#include "header.h"

int main()
{
	CMyList DB;
	CUserInterface UI(DB);
	UI.Run();

	return 0;
}