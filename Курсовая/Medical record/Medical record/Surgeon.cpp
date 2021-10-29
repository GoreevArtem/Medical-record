#include <string>
#include<iostream>

#include"Doc.h"

#include "Surgeon.h"


using namespace std;

Surgeon::Surgeon() :Doc()
{
}

Surgeon::Surgeon(string namedoc, string namepatient, string gender, double weight, int age, string met) : Doc(namedoc, namepatient, gender, weight, age), Method(met)
{
}

Surgeon::Surgeon(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size, string met) : Doc(namedoc, namepatient, gender, weight, age, NEW, size), Method(met)
{
}

Surgeon::Surgeon(const Surgeon& ref) : Doc(ref)
{
}

void Surgeon::Method_Of_Treatment(int method)
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
		cout << "Отсроченная операция" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата отсроченной операции : " + Method;
		break;
	case(3):
		cout << "Плановая операция" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата плановой операции : " + Method;
		break;
	case(4):
		cout << "Экстренная операция" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата экстренной операции : " + Method;
		break;

	default:
		cout << "Неправильно выбран метод лечения" << endl;
		Method = "Неправильно выбран метод лечения";
	}
}

Surgeon::~Surgeon()
{
}

void Surgeon::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*                                       ХИРУРГ                                       *" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "Выбирите метод лечения" << endl;
	cout << "  1-консультация\n  2-отсроченная операция\n  3-плановая операция\n  4-экстренная операция" << endl;
	cout << "Номер : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
}

void Surgeon::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "ОКАЗАНИЕ ПОМОЩИ\n" << Method << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
}

Surgeon& Surgeon::operator=(const Surgeon& right)
{
	Doc::operator=(right);
	Method = right.Method;
	return *this;
}
