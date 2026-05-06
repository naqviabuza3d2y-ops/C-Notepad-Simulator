#include <iostream>
#include "Q1.h"
using namespace std;

int main()
{
	DoublyList<char> l1;
	char c; 
	l1.print();

	do
	{
		c = _getch();
		
		if (c == 8)
		{
			l1.remove();
		}
		else if (c == -32)
		{
			int code = _getch();
			if (code == 75)
				l1.moveLeft();
			else if (code == 77)
				l1.moveRight();
		}
		else if (c == 26)
		{
			l1.redo();
		}
		else if (c == 13)
		{
			l1.enter();
		}
		else
		{
			l1.insert(c);
		}
		system("cls");
		l1.print();
	} while (c != 27);

	return 0;
}
