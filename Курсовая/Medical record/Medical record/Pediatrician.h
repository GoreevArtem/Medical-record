#ifndef PEDIATRICIAN_H
#define PEDIATRICIAN_H

using namespace std;

class Pediatrician :public Doc
{
private:
	string Method;
	string NameParent;

public:
	Pediatrician();

	Pediatrician(string namedoc, string namepatient, string nameparent, string gender, double weight, int age);

	Pediatrician(string namedoc, string namepatient, string nameparent, string gender, double weight, int age, string* NEW, int size);

	Pediatrician(const Pediatrician& ref);

	string GetNameParent() const { return NameParent; }
	void SetNameParent(string NameParent) { this->NameParent = NameParent; }

	void Method_Of_Treatment(int method);

	string Get_Method() const { return Method; }

	virtual ~Pediatrician();

	virtual void Patient() override;

	virtual void Print(ostream& out) const override;

	Pediatrician& operator=(const Pediatrician& right);
};

#endif 