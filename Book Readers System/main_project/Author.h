#ifndef AUTHOR_H_INCLUDED
#define AUTHOR_H_INCLUDED

#include "Reader.h"
#include "WritingRankable.h"

class Author : public Reader, public WritingRankable
{
public:
	Author(const char* name = "Name", const char* nationality = "Nat", int age = 0);
	virtual ~Author() {}

	void writeBook(const Book&);

	int getWrittenBooksCount()const;

	virtual int getWritingRank() const;

	virtual void print()const;

	virtual Author* clone() const { return new Author(*this); }

private:
	BooksContainer writtenBooks;
};

#endif // ! AUTHOR_H_INCLUDED