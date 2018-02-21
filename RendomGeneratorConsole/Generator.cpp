#include "Headers.h"

using namespace std;

HANDLE hThr;
int iAllCounts = 0;

class myData {
public:
	//����� ������ (���� 1 ������� ��������, ��� ��������)
	int m_iInteger;
	myData(int iInteger);	//��������
};

//����������� ������������
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

		//������� % �������? (������� ����������� ����� ��������)
		if (iAllCounts) {
			int iDoneCounts = (((iAllCounts - (*piTurnsCount)) * 100) / iAllCounts) / 10;
		
		//������� ������ ����� �������
		int iClearDots = 10 - iDoneCounts;
		for(;iDoneCounts!=0;iDoneCounts--) cout << "#";
		for(;iClearDots!=0;iClearDots--) cout << "-";
		}
		else {
			cout << "������� 0 �������� �����";
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
	//������� ������ �������� ������ myData � �������� ��������� ����������� iValueOfData
	//vector<myData> vMyData(*piValueOfData);
	//��������� ������� ������ ���������� ���������� ����� ������� rand();
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

	//��� ������ ������ �������� ������ ����� �������� ���������, ������������� ������� �������� ��������
	threadLoading.detach();
	//������� ����� � ������� �� ����� ��� ��������������� ��������
}


void generator() {
	system("cls");
	int iValueOfData;
	cout << "������� ������ ���������� ��������, ������� ����� �������������: ";
	try {
		cin >> iValueOfData;
		int* piValueOfData = &iValueOfData;
		//������ �������� ��������� � ���������
		thread newThread(newThreadGenerator, piValueOfData);
		if(newThread.joinable())
			newThread.join();
		//���������� ����������� ����������� �������� ����� �������� ����� ��������. ��� ����� ������ 1 detach ������������� ������.
		//���� �� ����� �����-�� ������� ������ �����������, ���� ���� ����������� ���� ������ �� ������������ - ������� �������������.
		//� ��� ������ �������� ��� ��������.
		//for(;(newThread.))
	}
	catch (...) {
		cout << "\n��� ������ 4: ������ � ����������";
		Sleep(1000);
		return;
	}
}