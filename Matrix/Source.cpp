#include <iostream>
#include <windows.h>
#include "Queue.h"
#include <vector>
#include <string>
#include "BusStop.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	vector<string> times_of_day = { "����","����","�����" };
	for (int i{}; i < 3; ++i)
	{
		cout << times_of_day[i] << endl;
		vector<int> parametrs;
		int temp{};
		cout << "������� ����������� ���������: ";
		cin >> temp;
		parametrs.push_back(temp);
		cout << "������� ����� ��������� ����������: ";
		cin >> temp;
		parametrs.push_back(temp);
		cout << "������� ����� ��������� ���������: ";
		cin >> temp;
		parametrs.push_back(temp);
		cout << "��������� ��������?(1 - ��, 0 - ���): ";
		cin >> temp;
		parametrs.push_back(temp);
		BusStop test1(parametrs[0], parametrs[1], parametrs[2], parametrs[3]);
		test1.Start();
		cout << "\n\n";
		parametrs.clear();
	}

	
	return 0;
}
