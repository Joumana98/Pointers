#include "../../std_lib_facilites.h"

int main()
{
	char* line = new char[1];
	char ch;
	cout << "Enter a string: " << endl;

	int counter = 0;
	while (cin.get(ch) && ch != '\n')
	{
		line[counter] = toupper(ch);
		counter++;
	}

	for (int x = 0; x < counter; x++)
		cout << line[x];

	return 0;
}