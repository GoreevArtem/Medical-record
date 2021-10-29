#ifndef THERAPIST_H
#define THERAPIST_H

using namespace std;

class Therapist :public Doc
{
private:

	string* Medicines;
	int Count;
	int MaxCount;
	string Method;
public:
	Therapist();

	Therapist(string namedoc, string namepatient, string gender, double weight, int age, string met);

	Therapist(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size, string* med, int count, string met);

	Therapist(const Therapist& ref);

	void Add_Medicines(string medicines);

	virtual ~Therapist();

	virtual void Patient() override;

	virtual void Print(ostream& out) const override;

	void Method_Of_Treatment(int method);

	string Get_Method() const { return Method; }

	Therapist& operator=(const Therapist& right);
};

#endif 