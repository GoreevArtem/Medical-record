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
	cout << "*                                      ��������                                      *" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
	Doc::Patient();

	cout << "--------------------------------------------------------------------------------------" << endl;
	int k;
	cout << "�������� ����� �������" << endl;
	cout << "  1-������������\n  2-������ �� ������\n  3-������ ������� �����\n  4-������" << endl;
	cout << "����� : ";
	cin >> k;
	cout << "--------------------------------------------------------------------------------------" << endl;
	Method_Of_Treatment(k);
	cout << "--------------------------------------------------------------------------------------" << endl;

	//cin.ignore();

	cout << "�������� ������������� ��������� : " << endl;
	cout << "����� ������� � ���������� ������� ������� 0" << endl;
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
	out << "�������� ������\n" << Method << endl;
	if (Count - 1 > 0) {
		out << "--------------------------------------------------------------------------------------" << endl;
		out << " ���������� ��������� : " << endl;
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
		cout << "������������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ������������ : " + Method;
		break;
	case(2):
		cout << "�������� �� ������" << endl;
		cout << "��������� ���� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "���� ������� : " + Method;
		break;
	case(3):
		cout << "������ ����������� ������� �����" << endl;
		cout << "����������� : ";
		cin.ignore();
		getline(cin, Method);
		Method = "����������� ������� ����� : " + Method;
		break;
	case(4):
		cout << "������ " << endl;
		cout << "������ : ";
		cin.ignore();
		getline(cin, Method);
		Method = "������ : " + Method;
		break;
	default:
		cout << "����������� ������ ����� �������" << endl;
		Method = "����������� ������ ����� �������";
	}
}

Therapist& Therapist::operator=(const Therapist& right)
{
	Doc::operator=(right);
	Method = right.Method;
	return *this;
}