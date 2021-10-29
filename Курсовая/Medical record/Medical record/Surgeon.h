#ifndef SURGEON_H
#define SURGEON_H

using namespace std;

class Surgeon :public Doc
{
private:

	string Method;

public:
	Surgeon();

	Surgeon(string namedoc, string namepatient, string gender, double weight, int age, string met);

	Surgeon(string namedoc, string namepatient, string gender, double weight, int age, string* NEW, int size, string met);

	Surgeon(const Surgeon& ref);

	string Get_Method() const { return Method; }

	void Method_Of_Treatment(int method);

	virtual ~Surgeon();

	virtual void Patient() override;

	virtual void Print(ostream& out) const override;

	Surgeon& operator=(const Surgeon& right);
};

#endif 