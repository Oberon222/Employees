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

void Read_file();
void Save_in_File();
void AddEmployee();
void EditingInfoEmployee();
void DeleteEmployee();
void Search_by_name();
void Search_by_age();
void Search_by_first_letter_name();
void SearchEmployee();
void ShowEmployees();