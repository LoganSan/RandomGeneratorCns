#include "Headers.h"

using namespace std;


int menu() {
	//int resultInMenu = 1;
	int iData;
	try { 
		system("cls");
		cout << "������ ��������� ������� ��������� ���� ���������� ��������� ��������\n\n";
		cout << "\n������� ������� ����� ����:\n";
		cout << "1. ������������� �������� �����\n";
		cout << "2. ��������� ��������� ����� �� ����� ��� ���������\n";
		cout << "3. �����\n\n������� ����� ����:";
		cin >> iData;
		if (iData == 1) {
			try { generator(); }
			catch (...) {
				cout << "\n��� ������ 2: ������ ��� ������ ���� ����������:\n";
				return 1;
			}
		}
		else if (iData == 2) try { loadingFromFile(); }
		catch (...) {
			cout << "\n��� ������ 3: ������ ��� ������ ���� �������� �����";
			return 1;
		}
		else if (iData == 3) return 0;
	}
	catch (...) {
		cout << "\n��� ������ 5: ������ � ����";
		return 1;
	}

	return 1;
}