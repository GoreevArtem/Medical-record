#ifndef PSYCHIATRIST_H
#define PSYCHIATRIST_H

using namespace std;

class Psychiatrist :public Doc
{
private:

	string Method;

public:
	Psychiatrist();

	Psychiatrist(string namedoc, string namepatient, string gender, double weight, int age, string met);

	Psychiatrist(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size, string met);

	Psychiatrist(const Psychiatrist& ref);

	void Method_Of_Treatment(int method);

	string Get_Method() const { return Method; }

	virtual ~Psychiatrist();

	virtual void Patient() override;

	virtual void Print(ostream& out) const override;

	Psychiatrist& operator =(const Psychiatrist& right);
};

#endif 