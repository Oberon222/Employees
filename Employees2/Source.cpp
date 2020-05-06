#include <iostream>
#include <string>
#include <fstream>
#include "Employees2.h"

using namespace std;

int main() {
	int action;

	do
	{
		cout << "1) Add new employee" << endl;
		cout << "2) Edit info employee" << endl;
		cout << "3) Delete employee" << endl;
		cout << "4) Serch employee" << endl;
		cout << "5) Show employees" << endl;
		cout << "6) Exit" << endl;
		cin >> action;

		switch (action)
		{
		case 1:{AddEmployee();}break;
		case 2: {}break;
		case 3: {DeleteEmployee();}break;
		case 4: {SearchEmployee();}break;
		case 5: {ShowEmployee();}break;
		case 6: {cout << "Goodbye :)" << endl;}break;

		}
	} while (action !=6);

	system("pause");
	return 0;
}