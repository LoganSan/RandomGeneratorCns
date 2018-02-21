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
		cout << "\nКод ошибки 1: Ошибка при вызове меню:\n";
	}

	return 0;
}