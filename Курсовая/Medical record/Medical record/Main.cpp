#include <string>
#include <iostream>
#include <Windows.h>
#include<fstream>
#include "Doc.h"
#include"Surgeon.h"
#include "Pediatrician.h"
#include"Psychiatrist.h"
#include "Therapist.h"
using namespace std;


template <typename T>
void WriteFile(ofstream& fout, T Human) {

	cin >> Human;
	cout << Human;
	Human.Print(fout);
	fout << "\n\n**************************************************************************************";
	fout << "\n���� ����� ����� ��� ��������� �����";
	fout << "\n���� �������� ������� ��� ����� ���������� ��������� ������� �� ������ 8800553535";
	fout << "\n**************************************************************************************";
	cout << "\n���� ����������� ��� ������ �����\n" << endl;
}

int main(int argc, char* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc < 2)
	{
		cout << "Wrong format" << endl;
		return -1;
	}

	ofstream fout(argv[1]);

	if (!fout) {
		cout << "Error writing file" << endl;
		return -3;
	}

	cout << "�������� �����������\n 1-������\n 2-�������\n 3-��������\n 4-��������\n 5-�����" << endl;

	int number;
	cout << "��������� ����� : ";
	cin >> number;

	Surgeon S;
	Pediatrician P;
	Psychiatrist PS;
	Therapist T;
	switch (number) {

	case(1):
		WriteFile(fout, S);
		break;
	case(2):
		WriteFile(fout, P);
		break;
	case(3):
		WriteFile(fout, PS);
		break;
	case(4):
		WriteFile(fout, T);
		break;
	}

	fout.close();

	system("pause");

	return 0;
}