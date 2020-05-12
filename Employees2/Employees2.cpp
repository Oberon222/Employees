#include "Employees2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Employee* list;
const string fileName= "EmployeesList.txt";
int countEmployees = 0;



void Read_file()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (!isOpen) {
		cout << "Read error." << endl;
	}
	int counter_string = 0;
	string data;

	Employee info_from_file;

	while (!fin.eof())
	{
		counter_string++;
		getline(fin, data);
		if (counter_string == 1) {
			info_from_file.name = data;
		}
		else if (counter_string == 2) {
			info_from_file.age = data;
		}
		else if (counter_string == 3) {
			info_from_file.email = data;
		}
		else if (counter_string == 4) {
			info_from_file.phonNumb = data;
			counter_string = 0;

			Employee* tmp = new Employee[countEmployees + 1];
			for (int i = 0; i < countEmployees; i++) {
				tmp[i] = list[i];
			}

			tmp[countEmployees] = info_from_file;
			countEmployees++;

			list = new Employee[countEmployees];
			for (int i = 0; i < countEmployees; i++) {
				list[i] = tmp[i];
			}

			delete[] tmp;
		}
	}
}

void Save_in_File() {
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (!isOpen) {
		cout << "Error" << endl;
	}

	for (int i = 0; i < countEmployees; i++) {
		fout << list[i].name<<endl;
		fout << list[i].age << endl;
		fout << list[i].email << endl;
		fout << list[i].phonNumb << endl;
	}
	fout.close();
	cout << "Writing to file is complete." << endl;
}
	
void AddEmployee()
{
	
	Employee* tmp = new Employee[countEmployees + 1];
	for (int i = 0; i < countEmployees; i++) {
		tmp[i] = list[i];
	}
	cout << "Enter name employee: ";
	cin >> tmp[countEmployees].name;
	cout << "Enter age employee: ";
	cin >> tmp[countEmployees].age;
	cout << "Enter e-mail employee: ";
	cin >> tmp[countEmployees].email;
	cout << "Enter phone number employee: ";
	cin >> tmp[countEmployees].phonNumb;

	list = new Employee[countEmployees + 1];
	for (int i = 0; i < countEmployees + 1; i++) {
		list[i] = tmp[i];
	}
	countEmployees++;
	delete[]tmp;
}

void EditingInfoEmployee()
{
	int numb_Position_Edit;
	cout << "Enter number posetion employee for edition: ";
	cin >> numb_Position_Edit;
	for (int i = 0; i < countEmployees; i++) {
		if ((numb_Position_Edit - 1) == i) {
			cout << "Enter a new employee name: ";
			cin >> list[i].name;
			cout << "Enter the new age of the employee: ";
			cin >> list[i].age;
			cout << "Enter a new e-mail employee: ";
			cin >> list[i].email;
			cout << "Enter the new employee phone number: ";
			cin >> list[i].phonNumb;
		}
	}
}

void DeleteEmployee()
{
	
	int numbPosition;
	cout << "Enter number employee: ";
	cin >> numbPosition;
	
	for (int i = numbPosition-1; i < countEmployees-1; i++) {
		list[i] = list[i + 1];
	}
	countEmployees--;

		cout << "The deletion of employee data was successful." << endl;
}

void Search_by_name() {
	string Name;
	cout << "Enter the employee's name: ";
	cin >> Name;
	for (int i = 0; i < countEmployees; i++) {
		if (list[i].name == Name) {
			cout << list[i].name << endl;
			cout << list[i].age << endl;
			cout << list[i].email << endl;
			cout << list[i].phonNumb << endl;
		}
	}
}

void Search_by_age() {
	string Age;
	cout << "Enter the age of the employee: ";
	cin >> Age;
	for (int i = 0; i < countEmployees; i++) {
		if (list[i].age == Age) {
			cout << list[i].name << endl;
			cout << list[i].age << endl;
			cout << list[i].email << endl;
			cout << list[i].phonNumb << endl;
		}
	}
}

void Search_by_first_letter_name() {
	char symb;
	cout << "Enter the first letter of the employee's name : ";
	cin >> symb;
	for (int i = 0; i < countEmployees; i++) {
		if (list[i].name[0] == symb) {
			cout << "Name: " << list[i].name << endl;
			cout << "Age: " << list[i].age << endl;
			cout << "E-mail: " << list[i].email << endl;
			cout << "Phon number: " << list[i].phonNumb << endl;
		}
		
	}

}

void SearchEmployee()
{
	int action2;
	do
	{
		cout << "1) Search for an employee by name." << endl;
		cout << "2) Search for an employee by age." << endl;
		cout << "3) Search for an employee by name." << endl;
		cout << "4) Exit " << endl;

		cin >> action2;
		switch (action2)
		{
			case 1: {Search_by_name(); } break;

			case 2: { Search_by_age(); } break;

			case 3: { Search_by_first_letter_name(); } break;

			case 4: {cout << "Exit to the main menu" << endl; } break;
		}

	} while (action2 !=4);
	
}

void ShowEmployees()
{
	for (int i = 0; i < countEmployees; i++) {
		cout << i+1<<" " << list[i].name << endl;
	}
}
