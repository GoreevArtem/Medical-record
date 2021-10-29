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
	fout << "\nЭТОТ ТАЛОН НУЖЕН ДЛЯ ПОСЕЩЕНИЯ ВРАЧА";
	fout << "\nЕсли возникли вопросы или нужна необходима медпомощь звоните по номеру 8800553535";
	fout << "\n**************************************************************************************";
	cout << "\nФайл перезаписан или создан новый\n" << endl;
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

	cout << "Выбирите направление\n 1-хирург\n 2-педиатр\n 3-психолог\n 4-терапевт\n 5-выход" << endl;

	int number;
	cout << "Выбранный номер : ";
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