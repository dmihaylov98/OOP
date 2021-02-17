#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

#include "Reader.h"

Reader::Reader(const char* name, const char* nationality, int age )
	: Person(name, nationality, age)
{}

void Reader::readBook(const Book& book)
{
	readBooks.insert(book);
}

int Reader::getReadBooksCount()const
{
	return readBooks.getSize();
}

int Reader::getReadingRank() const
{
	int rank = 0;
	for (int i = 0; i < getReadBooksCount(); i++)
	{
		rank += readBooks[i].getPages();
	}
	return rank;
}

void Reader::print()const
{
	Person::print();
	for (size_t i = 0; i < getReadBooksCount(); i++)
	{
		cout << readBooks[i].getCaption() << endl;
	}
}

