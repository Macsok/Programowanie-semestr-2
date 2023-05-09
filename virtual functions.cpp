#include <iostream>
#include <string>

using namespace std;

//	Klasa bazowa
class Osoba {
private:

	const string name;
public:
	//	wykluczenie mo¿liwoœci niejawnej konwersji typu
	explicit Osoba(string n) : name(n) {}
	//	wirtualizacja funkcji - przy wywolywaniu funkcji bedzie brany pod uwage typ wskaznika/referencji
	virtual void getInfo() {
		cout << this->name << endl;
	}
};

//-------------------------------------
//	Klasa pochodna osoby
class Student : public Osoba {
private:
	const int index;

public:
	Student(string n, int idx) : Osoba(n), index(idx) {}

	void getInfo() {
		Osoba::getInfo();
		cout << index << endl;
	}
};
	
int main() {
	Osoba o("Ala");
	Student s("Piotrek", 123456);

	Osoba* optr = &o;

	optr->getInfo();

	//	Ustawienie wskaznika typu Osoba na typ Student
	optr = &s;

	optr->getInfo();
	return 0;
}