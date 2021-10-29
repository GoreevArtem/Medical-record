#include <string>
#include<iostream>

#include"Doc.h"

#include"Psychiatrist.h"

using namespace std;

Psychiatrist::Psychiatrist() :Doc()
{
}

Psychiatrist::Psychiatrist(string namedoc, string namepatient, string gender, double weight, int age, string met) : Doc(namedoc, namepatient, gender, weight, age), Method(met)
{
}

Psychiatrist::Psychiatrist(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size, string met) : Doc(namedoc, namepatient, gender, weight, age, NEW, size), Method(met)
{
}

Psychiatrist::Psychiatrist(const Psychiatrist& ref) : Doc(ref)
{
}

void Psychiatrist::Method_Of_Treatment(int method)
{
	switch (method) {
	case(1):
		cout << "Неотложная психиатрическая помощь" << endl;
		cout << "Выдать направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Направление на проведение неотложной психиатрической помощи : " + Method;
		break;
	case(2):
		cout << "Проведение психиатрической экспертизы" << endl;
		cout << "Выдать направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Направление на проведение психиатрической экспертизы : " + Method;
		break;
	case(3):
		cout << "Участие в вопросах опеки указанных лиц" << endl;
		cout << "Выдать направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Участие в вопросах опеки указанных лиц. Направление : " + Method;
		break;
	case(4):
		cout << "Консультации по правовым вопросам" << endl;
		cout << "Выдать направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Направление на проведение консультации по правовым вопросам : " + Method;
		break;
	case(5):
		cout << "Оказание помощи в стационарных условаиях" << endl;
		cout << "Выдать направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Направление на оказание помощи в стационарных условаиях : " + Method;
		break;
	case(6):
		cout << "Социально бытовое устройство инвалидов и престарелых" << endl;
		cout << "Выдать направление : ";
		cin.ignore();
		getline(cin, Method);
		Method = "Направление на социально бытовое устройство инвалидов и престарелых : " + Method;
		break;

	default:
		cout << "Неправильно выбран метод лечения" << endl;
		Method = "Неправильно выбран метод лечения";
	}
}

Psychiatrist::~Psychiatrist()
{
}

void Psychiatrist::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*                                      ПСИХИАТР                                      *" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "Выбирите метод лечения" << endl;
	cout << "  1-Неотложная психиатрическая помощь\n  2-Направление на проведение неотложной психиатрической помощи\n  3-Участие в вопросах опеки указанных лиц\n  4-Консультации по правовым вопросам\n  5-Оказание помощи в стационарных условаиях\n  6-Социально бытовое устройство инвалидов и престарелых" << endl;
	cout << "Номер : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
}

void Psychiatrist::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "ОКАЗАНИЕ ПОМОЩИ\n" << Method << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
}

Psychiatrist& Psychiatrist::operator=(const Psychiatrist& right)
{
	Doc::operator=(right);
	Method = right.Method;
	return *this;
}
