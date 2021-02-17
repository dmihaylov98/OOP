#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

#include "Person.h"

void Person::setName(const char* name)
{
	if (!name)name = "";

	size_t len = strlen(name);

	delete[] this->name;
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}

void Person::setAge(int age)
{
	if (age > 0)
		this->age = age;
}

void Person::setNationality(const char* nationality)
{
	if (!nationality)nationality = "";

	size_t len = strlen(nationality);

	delete[] this->nationality;
	this->nationality = new char[len + 1];
	strcpy_s(this->nationality, len + 1, nationality);
}

Person::Person(const char* theName, const char* theNationality, int theAge)
	: name(NULL), nationality(NULL), age(theAge)
{
	this->setName(theName);
	this->setNationality(theNationality);
	this->setAge(theAge);
}

Person::Person(const Person& other)
	: Person(other.name, other.nationality, other.age)
{ }

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->setNationality(other.nationality);
		this->setAge(other.age);
	}
	return *this;
}

Person::~Person()
{
	delete[] this->name;
	delete[] this->nationality;
}

bool Person::operator<(const Person& other)const
{
	if (strcmp(this->name, other.name) != -1)return false;
	if (strcmp(this->nationality, other.nationality) != -1)return false;
	if (this->age >= other.age)return false;
	return true;
}

bool Person::operator==(const Person& other)const
{
	if (strcmp(this->name, other.name) != 0)return false;
	if (strcmp(this->nationality, other.nationality) != 0)return false;
	if (this->age != other.age)return false;
	return true;
}

bool Person::operator>(const Person& other)const
{
	if (strcmp(this->name, other.name) != 1)return false;
	if (strcmp(this->nationality, other.nationality) != 1)return false;
	if (this->age <= other.age)return false;
	return true;
	//return !operator<(other)&&!operator==(other);
}

bool Person::operator<=(const Person& other)const
{
	if (strcmp(this->name, other.name) > 0)return false;
	if (strcmp(this->nationality, other.nationality) > 0)return false;
	if (this->age > other.age)return false;
	return true;
	//return operator<(other)&&operator==(other);
}

bool Person::operator>=(const Person& other)const
{
	if (strcmp(this->name, other.name) < 0)return false;
	if (strcmp(this->nationality, other.nationality) < 0)return false;
	if (this->age < other.age)return false;
	return true;
	//return !operator<(other);
}

bool Person::operator!=(const Person& other)const
{
	if (strcmp(this->name, other.name) == 0)return false;
	if (strcmp(this->nationality, other.nationality) == 0)return false;
	if (this->age == other.age)return false;
	return true;
	//return !operator==(other);
}


istream& operator>>(istream& is, Person& p)
{

	char buffer[100];
	is >> buffer;
	p.setName(buffer);
	is >> p.nationality >> p.age;
	return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << p.name << " " << p.nationality << " " << p.age << " ";
	return os;
}

void Person::print()const
{
	cout << "Name: " << this->name << endl;
	cout << "Nationality: " << this->nationality << endl;
	cout << "Age: " << this->age << endl;
}