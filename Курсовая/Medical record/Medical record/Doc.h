#ifndef DOC_H
#define DOC_H

using namespace std;

class Doc {
private:
	string NameDoc;
	string NamePatient;

	int Age;
	string* Diagnosis;
	int Size;
	int MaxSize;
	double Weight;

	string Gender;
public:

	Doc();

	Doc(string namedoc, string namepatient, string gender, double weight, int age);

	string GetNameDoc() const { return NameDoc; }
	void SetNameDoc(string NameDoc) { this->NameDoc = NameDoc; }

	string GetNamePatient() const { return NamePatient; }
	void SetNamePatient(string NamePatient) { this->NamePatient = NamePatient; }

	double GetWeight() const { return Weight; }
	void SetWeight(double Weight) { this->Weight = Weight; }

	int GetAgePatient() const { return Age; }
	void SetAgePatient(int Age) { this->Age = Age; }

	string GetGender() { return Gender; }
	void SetGender(string Gender) { this->Gender = Gender; }

	Doc(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size);

	virtual ~Doc();

	Doc(const Doc& ref);

	void Add_Diagnosis(string diagnosis);


	virtual void Patient();

	virtual void Print(ostream& out) const;

	Doc& operator=(const Doc& right);
	Doc& operator +=(string NEW);
	Doc& operator++();
	Doc& operator++(int);
	bool operator==(const Doc& right) const;

	bool operator==(string namepatient);

	bool operator!=(const Doc& right) const;

	bool operator!=(string namepatient);

	string operator [](int index)const;
	string& operator[](int index);

};

ostream& operator<<(ostream& out, const Doc& H);

istream& operator>>(istream& in, Doc& H);
#endif