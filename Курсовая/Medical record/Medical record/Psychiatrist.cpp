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
		cout << "���������� ��������������� ������" << endl;
		cout << "������ ����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "����������� �� ���������� ���������� ��������������� ������ : " + Method;
		break;
	case(2):
		cout << "���������� ��������������� ����������" << endl;
		cout << "������ ����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "����������� �� ���������� ��������������� ���������� : " + Method;
		break;
	case(3):
		cout << "������� � �������� ����� ��������� ���" << endl;
		cout << "������ ����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "������� � �������� ����� ��������� ���. ����������� : " + Method;
		break;
	case(4):
		cout << "������������ �� �������� ��������" << endl;
		cout << "������ ����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "����������� �� ���������� ������������ �� �������� �������� : " + Method;
		break;
	case(5):
		cout << "�������� ������ � ������������ ���������" << endl;
		cout << "������ ����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "����������� �� �������� ������ � ������������ ��������� : " + Method;
		break;
	case(6):
		cout << "��������� ������� ���������� ��������� � �����������" << endl;
		cout << "������ ����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "����������� �� ��������� ������� ���������� ��������� � ����������� : " + Method;
		break;

	default:
		cout << "����������� ������ ����� �������" << endl;
		Method = "����������� ������ ����� �������";
	}
}

Psychiatrist::~Psychiatrist()
{
}

void Psychiatrist::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*                                      ��������                                      *" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "�������� ����� �������" << endl;
	cout << "  1-���������� ��������������� ������\n  2-����������� �� ���������� ���������� ��������������� ������\n  3-������� � �������� ����� ��������� ���\n  4-������������ �� �������� ��������\n  5-�������� ������ � ������������ ���������\n  6-��������� ������� ���������� ��������� � �����������" << endl;
	cout << "����� : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
}

void Psychiatrist::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "�������� ������\n" << Method << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
}

Psychiatrist& Psychiatrist::operator=(const Psychiatrist& right)
{
	Doc::operator=(right);
	Method = right.Method;
	return *this;
}
