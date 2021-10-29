#include <string>
#include<iostream>
#include"Doc.h"
#include "Therapist.h"


using namespace std;

Therapist::Therapist() :Doc(), Count(0), MaxCount(0), Medicines(0)
{
}

Therapist::Therapist(string namedoc, string namepatient, string gender, double weight, int age, string met) : Doc(namedoc, namepatient, gender, weight, age), Count(0), MaxCount(0), Medicines(0), Method(met)
{
}

Therapist::Therapist(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size, string* med, int count, string met) : Doc(namedoc, namepatient, gender, weight, age, NEW, size), Count(count), Method(met)
{
	MaxCount = Count * 2;
	Medicines = new string[MaxCount];
	for (int i = 0; i < Count; i++) {
		Medicines[i] = med[i];
	}
}

Therapist::Therapist(const Therapist& ref) :Doc(ref), Count(ref.Count), MaxCount(ref.MaxCount)
{
	Medicines = new string[MaxCount];
	for (int i = 0; i < Count; i++) {
		Medicines[i] = ref.Medicines[i];
	}
}

void Therapist::Add_Medicines(string medicines)
{
	if (Count == MaxCount) {
		MaxCount = Count * 2 + 1;
		string* NEW = new string[MaxCount];
		for (int i = 0; i < Count; i++)
			NEW[i] = Medicines[i];
		delete[]Medicines;
		Medicines = NEW;
	}

	Medicines[Count++] = medicines;
}

Therapist::~Therapist()
{
	if (Count - 1 > 0) {
		delete[] Medicines;
		cout << "Memory cleaned (med)" << endl;
	}
}


void Therapist::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*                                      ТЕРАПЕВТ                                      *" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "Выбирите метод лечения" << endl;
	cout << "  1-консультация\n  2-Запись на осмотр\n  3-запись другому врачу\n  4-другое" << endl;
	cout << "Номер : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
	cout << "--------------------------------------------------------------------------------------" << endl;

	//cin.ignore();

	cout << "Выписать лекарственные препараты : " << endl;
	cout << "Чтобы перейти к следующему разделу нажмите 0" << endl;
	string M;

	int num = 0;
	do {

		cout << num + 1 << ") ";

		getline(cin, M);
		num++;
		Add_Medicines(M);

	} while (M != "0");

}

void Therapist::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "ОКАЗАНИЕ ПОМОЩИ\n" << Method << endl;
	if (Count - 1 > 0) {
		out << "--------------------------------------------------------------------------------------" << endl;
		out << " Выписанные лекарства : " << endl;
		for (int i = 0; i < Count - 1; i++)
		{
			out << i + 1 << ") " << Medicines[i] << endl;
		}
		out << "--------------------------------------------------------------------------------------" << endl;
	}
}

void Therapist::Method_Of_Treatment(int method)
{
	switch (method) {
	case(1):
		cout << "Консультация" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата консультации : " + Method;
		break;
	case(2):
		cout << "Записать на осмотр" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата осмотра : " + Method;
		break;
	case(3):
		cout << "Выдать направление другому врачу" << endl;
		cout << "Направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Направление другому врачу : " + Method;
		break;
	case(4):
		cout << "Другое " << endl;
		cout << "Другое : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Другое : " + Method;
		break;
	default:
		cout << "Неправильно выбран метод лечения" << endl;
		Method = "Неправильно выбран метод лечения";
	}
}

Therapist& Therapist::operator=(const Therapist& right)
{
	Doc::operator=(right);
	Method = right.Method;
	return *this;
}