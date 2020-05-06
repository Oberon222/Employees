#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Employee
{
	string name;
	string age;
	string email;
	string phonNumb;
};

void Insert(Employee data);
void Init();
void AddEmployee();

void EditingInfoEmployee();
void DeleteEmployee();
void SearchEmployee();
void ShowEmployee();