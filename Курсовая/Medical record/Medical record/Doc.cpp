#include <string>
#include<iostream>
#include "Doc.h"

using namespace std;

Doc::Doc(string namedoc, string nemepatient, string gender, double weight, int age) :
	NameDoc(namedoc), NamePatient(nemepatient), Gender(gender), Weight(weight), Age(age), MaxSize(0),
	Size(0), Diagnosis(0)
{
}


Doc::Doc() :Weight(0), Age(0), MaxSize(0), Size(0), Diagnosis(0)
{}

Doc::~Doc()
{
	if (Size - 1 > 0) {
		delete[] Diagnosis;
		cout << "Memory cleaned" << endl;
	}
}

Doc::Doc(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size) :
	NameDoc(namedoc), NamePatient(namepatient), Gender(gender), Weight(weight), Age(age), Size(size)
{
	MaxSize = Size * 2;
	Diagnosis = new string[MaxSize];
	for (int i = 0; i < Size; i++) {
		Diagnosis[i] = NEW[i];
	}
}

Doc::Doc(const Doc& ref) :
	NameDoc(ref.NameDoc), NamePatient(ref.NamePatient), Gender(ref.Gender), Weight(ref.Weight), Age(ref.Age), MaxSize(ref.MaxSize),
	Size(ref.Size)
{
	Diagnosis = new string[MaxSize];
	for (int i = 0; i < Size; i++) {
		Diagnosis[i] = ref.Diagnosis[i];
	}
}

void Doc::Add_Diagnosis(string diagnosis) {
	if (Size == MaxSize) {
		MaxSize = Size * 2 + 1;
		string* NEW = new string[MaxSize];
		for (int i = 0; i < Size; i++)
			NEW[i] = Diagnosis[i];
		delete[]Diagnosis;
		Diagnosis = NEW;
	}

	Diagnosis[Size++] = diagnosis;
}



void Doc::Print(ostream& out) const
{

	out << "\n\n**************************************************************************************" << endl;
	out << "*                                                                                    *" << endl;
	out << "*                              ����������� ����� ��������                            *" << endl;
	out << "*                                                                                    *" << endl;
	out << "**************************************************************************************" << endl;

	out << "���� : " __DATE__ << "\n����� : " << __TIME__ << "\n" << endl;

	out << " ��� ����� : " << NameDoc << "\n ��� �������� : " << NamePatient << "\n ��� : " << Gender << "\n ������� : " << Age << "\n ��� " << (int)Weight << " ��������� " << (int)((Weight - (int)Weight) * 100) << " �����" << endl;
	if (Size - 1 > 0) {
		out << "\n ������ �� �������� : " << endl;
		for (int i = 0; i < Size - 1; i++)
		{
			out << i + 1 << ") " << Diagnosis[i] << endl;
		}
	}
}

Doc& Doc::operator=(const Doc& right)
{
	if (this != &right) {
		NameDoc = right.NameDoc;
		NamePatient = right.NamePatient;
		Size = right.Size;
		MaxSize = right.MaxSize;
		delete[]Diagnosis;
		Diagnosis = new string[MaxSize];
		for (int i = 0; i < Size; i++)
		{
			Diagnosis[i] = right.Diagnosis[i];
		}

	}
	return *this;
}

Doc& Doc::operator+=(string NEW)
{
	Add_Diagnosis(NEW);
	return *this;
}

Doc& Doc::operator++()
{
	Age++;
	return *this;
}

Doc& Doc::operator++(int)
{
	Doc tmp(*this);
	++* this;
	return tmp;
}

bool Doc::operator==(const Doc& right) const
{
	return NamePatient == right.NamePatient;
}

bool Doc::operator==(string namepatient)
{
	return NamePatient == namepatient;
}

bool Doc::operator!=(const Doc& right) const
{
	return !(*this == right);
}

bool Doc::operator!=(string namepatient)
{
	return !(*this == namepatient);
}

string Doc::operator[](int index) const
{
	if (index >= 0 && index < Size)
		return Diagnosis[index];
	else "";
}

string& Doc::operator[](int index)
{
	if (index >= 0 && index < Size)
		return Diagnosis[index];
}

ostream& operator<<(ostream& out, const Doc& H)
{
	H.Print(out);
	return out;
}

istream& operator>>(istream& in, Doc& H)
{
	H.Patient();
	return in;
}

void Doc::Patient() {

	cout << "��� �������� �����  ";
	string nd;
	cin.ignore();
	getline(cin, nd);
	SetNameDoc(nd);

	cout << "--------------------------------------------------------------------------------------" << endl;

	cout << "��� ��������  ";
	string np;
	getline(cin, np);
	SetNamePatient(np);

	cout << "--------------------------------------------------------------------------------------" << endl;

	cout << "��� : " << endl;
	cout << " 1-�������\n 0-�������" << endl;
	int p;

	while ((!(cin >> p) || (cin.peek() != '\n')) || (p != 1 && p != 0))
	{

		cin >> p;
		cin.clear();
		while (cin.get() != '\n');
		cout << "������������ ���� ������, ���������� �����" << endl;
	}

	if (p == 1) { SetGender("�������"); }
	else { SetGender("�������"); }

	cout << "--------------------------------------------------------------------------------------" << endl;

	cin.ignore();
	cout << "��� ";
	double W;
	while (!(cin >> W) || (cin.peek() != '\n'))
	{
		cin >> W;
		cin.clear();
		while (cin.get() != '\n');
		cout << "�� ����������� ������� ��� ��������, ���������� ������ ������ �����" << endl;
	}
	SetWeight(W);

	cout << "--------------------------------------------------------------------------------------" << endl;

	cout << "������� ";
	int A;
	cin.ignore();

	while (!(cin >> A) || (cin.peek() != '\n'))
	{
		cin >> A;
		cin.clear();
		while (cin.get() != '\n');
		cout << "�� ����������� ������� ������� ��������, ���������� ������ ������ �����" << endl;
	}
	SetAgePatient(A);

	cout << "--------------------------------------------------------------------------------------" << endl;

	cout << "�������� : " << endl;
	cout << "����� ������� � ���������� ������� ������� 0" << endl;
	string a;
	int i = 0;
	cin.ignore();
	do {

		cout << i + 1 << ") ";

		getline(cin, a);
		i++;
		Add_Diagnosis(a);

	} while (a != "0");
}