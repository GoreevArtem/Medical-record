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
		cout << "������������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ������������ : " + Method;
		break;
	case(2):
		cout << "������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ���������� ������� : " + Method;
		break;
	case(3):
		cout << "������������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ���������� ������������ : " + Method;
		break;
	case(4):
		cout << "����������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ���������� ���������� : " + Method;
		break;

	default:
		cout << "����������� ������ ����� �������" << endl;
		Method = "�� ����������� ��������� ��� ����";
	}
}

Pediatrician::~Pediatrician()
{
}

void Pediatrician::Patient()
{
	cout << "\n\n**************************************************************************************" << endl;
	cout << "                                                                                      " << endl;
	cout << "                                       �������                                        " << endl;
	cout << "                                                                                      " << endl;
	cout << "**************************************************************************************" << endl;

	cout << "��� �������� ";
	cin.ignore();
	string nr;
	getline(cin, nr);
	SetNameParent(nr);

	cout << "--------------------------------------------------------------------------------------" << endl;

	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "�������� ����� �������" << endl;
	cout << "  1-������������\n  2-������\n  3-������������\n  4-���������" << endl;
	cout << "����� : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
}

void Pediatrician::Print(ostream& out) const
{
	Doc::Print(out);
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "�������� (���) : " << NameParent << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
	out << "�������� ������\n" << Method << endl;
	out << "--------------------------------------------------------------------------------------" << endl;
}

Pediatrician& Pediatrician::operator=(const Pediatrician& right)
{
	Doc::operator=(right);
	Method = right.Method;
	NameParent = right.NameParent;
	return *this;
}
