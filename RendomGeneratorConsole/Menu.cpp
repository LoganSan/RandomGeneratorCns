#include "Headers.h"

using namespace std;


int menu() {
	//int resultInMenu = 1;
	int iData;
	try { 
		system("cls");
		cout << "Данная программа выводит указанное Вами количество случайных значений\n\n";
		cout << "\nПросьба выбрать пункт меню:\n";
		cout << "1. Сгенерировать случаные числа\n";
		cout << "2. Загрузить случайные числа из файла для просмотра\n";
		cout << "3. Выйти\n\nВведите пункт меню:";
		cin >> iData;
		if (iData == 1) {
			try { generator(); }
			catch (...) {
				cout << "\nКод ошибки 2: Ошибка при вызове меню генератора:\n";
				return 1;
			}
		}
		else if (iData == 2) try { loadingFromFile(); }
		catch (...) {
			cout << "\nКод ошибки 3: Ошибка при вызове меню загрузки файла";
			return 1;
		}
		else if (iData == 3) return 0;
	}
	catch (...) {
		cout << "\nКод ошибки 5: Ошибка в меню";
		return 1;
	}

	return 1;
}