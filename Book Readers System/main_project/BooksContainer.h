#ifndef BOOKSCONTAINER_H_INCLUDED
#define BOOKSCONTAINER_H_INCLUDED

#include "Set.h"
#include "Book.h"

class BooksContainer : public Set<Book>
{
public:
	BooksContainer(unsigned capacity = 1);

	void sort(bool(*compareBooks)(const Book& book1, const Book& book2));
	BooksContainer booksByAuthor(const Author& author);
};

#endif // ! BOOKSCONTAINER_H_INCLUDED
