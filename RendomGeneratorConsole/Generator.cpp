#include "Headers.h"

using namespace std;

HANDLE hThr;
int iAllCounts = 0;

class myData {
public:
	//члены данных (пока 1 интовое значение, для удобства)
	int m_iInteger;
	myData(int iInteger);	//Прототип
};

//Определение конструктора
myData::myData(int iInteger) {
	m_iInteger = iInteger;
}


mutex g_lock;

void newThreadLoading(int* piTurnsCount) {
	//Animated \-/-
	iAllCounts = *piTurnsCount;

	char cData[] = "-/-\\";
	for (int q=0;;q++) {
		q %= 4;
		system("cls");
		//g_lock.lock();
		cout << cData[q];
		cout << "\t[";

		//Сколько % сделано? (сколько заполненных ячеек написать)
		if (iAllCounts) {
			int iDoneCounts = (((iAllCounts - (*piTurnsCount)) * 100) / iAllCounts) / 10;
		
		//Сколько пустых полей вывести
		int iClearDots = 10 - iDoneCounts;
		for(;iDoneCounts!=0;iDoneCounts--) cout << "#";
		for(;iClearDots!=0;iClearDots--) cout << "-";
		}
		else {
			cout << "ВВЕДЕНО 0 ЗНАЧЕНИЕ ЧИСЕЛ";
			cout << "]";
			return;
		}
		cout << "]";
		//g_lock.unlock();
		//this_thread::sleep_for(std::chrono::);
		//this_thread::
		//this_thread::sleep_for(chrono::seconds(0));
		Sleep(500);
	}
}


//Now argument is "int", but next time it will be a Class "Data"
//with 4 columns of data
void newThreadGenerator(int* piValueOfData) {
	//Generate of data
	
	
	
	if (DEBUG) {
		cout << "\n[DEBUG] " << *piValueOfData; 
	Sleep(1000); 
}
	//Создаем вектор объектов класса myData с заведомо известным количеством iValueOfData
	//vector<myData> vMyData(*piValueOfData);
	//Заполняем объекты класса случайными значениями через функцию rand();
	thread threadLoading(newThreadLoading, piValueOfData);
	//if (threadLoading.joinable()) {
		//threadLoading.join();
	//}

	for (; (*piValueOfData)!=0; (*piValueOfData)--) {
		int iRand = rand();
		if (DEBUG) {
			cout << iRand;
			//Sleep(1000);
		}
		//myData* md = new myData(iRand);
		//vMyData.push_back(*md);
	}

	//Как только вектор объектов класса будет заполнен полностью, останавливаем процесс анимации загрузки
	threadLoading.detach();
	//Очищаем экран и выводим на экран все сгенерированные значения
}


void generator() {
	system("cls");
	int iValueOfData;
	cout << "Просьба ввести количество значений, которые нужно сгенерировать: ";
	try {
		cin >> iValueOfData;
		int* piValueOfData = &iValueOfData;
		//запуск процесса генерации в параллели
		thread newThread(newThreadGenerator, piValueOfData);
		if(newThread.joinable())
			newThread.join();
		//Необходимо реализовать возможность останова цикла перебора новых значений. Там будет просто 1 detach параллельного потока.
		//Судя по всему какое-то событие должно запуститься, ведь если запрашивать ввод данных от пользователя - консоль заблокируется.
		//А она должна выводить лог загрузки.
		//for(;(newThread.))
	}
	catch (...) {
		cout << "\nКод ошибки 4: Ошибка в генераторе";
		Sleep(1000);
		return;
	}
}