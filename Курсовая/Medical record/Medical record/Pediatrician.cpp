#include <string>
#include<iostream>

#include"Doc.h"

#include "Pediatrician.h"

using namespace std;

Pediatrician::Pediatrician() :Doc()
{
}

Pediatrician::Pediatrician(string namedoc, string namepatient, string nameparent, string gender, double weight, int age) : Doc(namedoc, namepatient, gender, weight, age), NameParent(nameparent)
{
}

Pediatrician::Pediatrician(string namedoc, string namepatient, string nameparent, string gender, double weight, int age, string* NEW, int size) : Doc(namedoc, namepatient, gender, weight, age, NEW, size), NameParent(nameparent)
{
}

Pediatrician::Pediatrician(const Pediatrician& ref) : Doc(ref), NameParent(ref.NameParent)
{
}

void Pediatrician::Method_Of_Treatment(int method)
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
		cout << "Осмотр" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата проведения осмотра : " + Method;
		break;
	case(3):
		cout << "Профилактика" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата проведения профилактики : " + Method;
		break;
	case(4):
		cout << "Вакцинация" << endl;
		cout << "Назначить дату : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Дата проведения вакцинации : " + Method;
		break;

	default:
		cout << "Неправильно выбран метод лечения" << endl;
		Method = "Вы неправильно заполнили это поле";
	}
}

Pediatrician::~Pediatrician()
{
}

void Pediatrician::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "                                                                                      " << endl;
	cout << "                                       ПЕДИАТР                                        " << endl;
	cout << "                                                                                      " << endl;
	cout << "**************************************************************************************" << endl;

	cout << "ФИО родителя ";
	cin.ignore();
	string nr;
	getline(cin, nr);
	SetNameParent(nr);

	cout << "--------------------------------------------------------------------------------------" << endl;

	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "Выбирите метод лечения" << endl;
	cout << "  1-консультация\n  2-осмотр\n  3-профилактика\n  4-вакцинаия" << endl;
	cout << "Номер : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
}

void Pediatrician::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "РОДИТЕЛЬ (ФИО) : " << NameParent << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "ОКАЗАНИЕ ПОМОЩИ\n" << Method << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
}

Pediatrician& Pediatrician::operator=(const Pediatrician& right)
{
	Doc::operator=(right);
	Method = right.Method;
	NameParent = right.NameParent;
	return *this;
}
