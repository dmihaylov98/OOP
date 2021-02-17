#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
using namespace std;

class Person
{
public:
	Person(const char* name = "Name", const char* nationality = "Nat", int age = 0);
	Person(const Person&);
	Person& operator=(const Person&);
	virtual ~Person();

	void setName(const char*);
	void setNationality(const char*);
	void setAge(int);

	const char* getName()const { return this->name; }
	const char* getNationality()const { return this->nationality; }
	int getAge()const { return this->age; }

	bool operator<(const Person&)const;
	bool operator>(const Person&) const;
	bool operator<=(const Person&) const;
	bool operator>=(const Person&) const;
	bool operator!=(const Person&) const;
	bool operator==(const Person&) const;

	friend istream& operator>>(istream& is, Person& p);
	friend ostream& operator<<(ostream& os, const Person& p);

	operator bool() const
	{
		return name != "" || nationality != "" || age != 0;
	}
	bool operator!() const
	{
		return !bool(*this);
	}

	virtual void print()const;
	virtual Person* clone() const { return new Person(*this); }
protected:
	char* name;
	char* nationality;
	int age;
};

#endif // ! PERSON_H_INCLUDED
