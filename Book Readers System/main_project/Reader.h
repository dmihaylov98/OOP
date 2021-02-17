#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED

#include "Person.h"
#include "ReadingRankable.h"
#include "BooksContainer.h"

class Reader : public Person, public ReadingRankable
{
public:
	Reader(const char* name = "Name", const char* nationality = "Nat", int age = 0);
	virtual ~Reader() {}

	void readBook(const Book&);
	 
	int getReadBooksCount()const;

	virtual int getReadingRank() const;

	virtual void print()const;

	virtual Reader* clone() const { return new Reader(*this); }

private:
	BooksContainer readBooks;
};

#endif // ! READER_H_INCLUDED

