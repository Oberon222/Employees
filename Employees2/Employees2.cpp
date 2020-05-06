#include "Employees2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Employee* list;
const string fileName= "EmployeesList.txt";
int countEmployees = 0;

void Insert(Employee data)
{
	Employee* tmp = new Employee[countEmployees + 1];
	for (int i = 0; i < countEmployees; i++) {
		tmp[i] = list[i];
	}
	tmp[countEmployees] = data;
	countEmployees++;
	list = new Employee[countEmployees];
	for (int i = 0; i < countEmployees; i++) {
		list[i] = tmp[i];
	}
	delete[]tmp;

}

void Init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (!isOpen) {
		cout << "Error" << endl;
	}
	while (!fin.eof()) {
		Employee tmp;
		getline(fin, tmp.name);
		if (tmp.name != "") {
			fin >> tmp.name;
			fin >> tmp.age;
			fin >> tmp.email;
			fin >> tmp.phonNumb;
			Insert(tmp);
		}
		else {
			break;
		}
	}
	fin.close();
}
	

void AddEmployee()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (!isOpen) {
		cout << "Error" << endl;
	}
	Employee newEmployee;
	cout << "Enter name employee: ";
	cin >> newEmployee.name;
	cout << "Enter age employee: ";
	cin >> newEmployee.age;
	cout << "Enter e-mail employee: ";
	cin >> newEmployee.email;
	cout << "Enter phon number employee: ";
	cin >> newEmployee.phonNumb;

	Insert(newEmployee);
	fout << "Name: "<<newEmployee.name << endl;
	fout <<"Age: "<< newEmployee.age << endl;
	fout << "E-mail: "<<newEmployee.email << endl;
	fout << "Phone number: "<< newEmployee.phonNumb << endl;
	fout << "------------------" << endl;
	fout.close();
}




void EditingInfoEmployee()
{

}

void DeleteEmployee()
{
	string employeeName;
	cout << "Enter the name of the employee whose information you want to delete: ";
	cin >> employeeName;
	int numbPosition;
	for (int i = 0; i < countEmployees;i++) {
		if(list->name== employeeName)
			numbPosition = i;
	}

	cout <<"position number in the staff list"<< numbPosition << endl;
	for (int i = numbPosition; i < countEmployees; i++) {
		list[i] = list[i + 1];
	}
	countEmployees--;

	for (int i = 0; i < countEmployees; i++) {
		cout << list[i].name;
	}
	cout << endl;

}

void SearchEmployee()
{
	string Name;
	cout << "Enter name employee or first letter of the name ";
	cin >> Name;
	for (int i = 0; i < countEmployees; i++) {
		if (list[i].name.find(Name) != string::npos) {
			cout << list[i].name << endl;
			cout << list[i].age << endl;
			cout << list[i].email << endl;
			cout << list[i].phonNumb << endl;
		}
	}
}

void ShowEmployee()
{
	Init();
	for (int i = 0; i < countEmployees; i++) {
		cout << i+1<<" " << list[i].name << endl;
		
	}
	
}
