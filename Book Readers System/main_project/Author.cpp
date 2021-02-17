#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

#include "Author.h"

Author::Author(const char* name , const char* nationality, int age)
	: Reader(name, nationality, age)
{}

void Author::writeBook(const Book& book)
{
	writtenBooks.insert(book);
}

int Author::getWrittenBooksCount()const
{
	return writtenBooks.getSize();
}

int Author::getWritingRank() const
{
	int rank = 0;
	for (int i = 0; i < getWrittenBooksCount(); i++)
	{
		rank += writtenBooks[i].getPages();
	}
	return rank;
}

void Author::print() const
{
	Reader::print();
	for (size_t i = 0; i < getWrittenBooksCount(); i++)
	{
		cout << writtenBooks[i].getCaption() << endl;
	}
}