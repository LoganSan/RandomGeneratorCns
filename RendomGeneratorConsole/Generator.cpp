#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <cstdlib>

using namespace std;

void newThreadLoading(int count) {
	//Animated \-/-
}


//Now argument is "int", but next time it will be a Class "Data"
//with 4 columns of data
void newThreadGenerator(int iValueOfData) {
	//Generate of data
}


void generator() {
	system("cls");
	int iValueOfData;
	cout << "������� ������ ���������� ��������, ������� ����� �������������: ";
	try {
		cin >> iValueOfData;
		newThreadGenerator(iValueOfData);
	}
	catch (...) {
		cout << "\n��� ������ 4: ������ � ����������";
		Sleep(1000);
		return;
	}
}