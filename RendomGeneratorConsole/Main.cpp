#include "Headers.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int result = 0;

	try {
		do { 
			result = menu();
		} while (result!=0);
	}

	catch (...) {
		cout << "\n��� ������ 1: ������ ��� ������ ����:\n";
	}

	return 0;
}