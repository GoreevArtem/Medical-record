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
		cout << "������������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ������������ : " + Method;
		break;
	case(2):
		cout << "����������� ��������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ����������� �������� : " + Method;
		break;
	case(3):
		cout << "�������� ��������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� �������� �������� : " + Method;
		break;
	case(4):
		cout << "���������� ��������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ���������� �������� : " + Method;
		break;

	default:
		cout << "����������� ������ ����� �������" << endl;
		Method = "����������� ������ ����� �������";
	}
}

Surgeon::~Surgeon()
{
}

void Surgeon::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*                                       ������                                       *" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "�������� ����� �������" << endl;
	cout << "  1-������������\n  2-����������� ��������\n  3-�������� ��������\n  4-���������� ��������" << endl;
	cout << "����� : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
}

void Surgeon::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "�������� ������\n" << Method << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
}

Surgeon& Surgeon::operator=(const Surgeon& right)
{
	Doc::operator=(right);
	Method = right.Method;
	return *this;
}
