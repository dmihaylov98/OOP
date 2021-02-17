#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

#include "BooksContainer.h"
#include "Author.h"

BooksContainer::BooksContainer(unsigned capacity)
	: Set<Book>(capacity)
{ }

void BooksContainer::sort(bool(*compareBooks)(const Book& book1, const Book& book2))
{
	for (unsigned i = 0; i<getSize() - 1; i++)
		for (unsigned j = 0; j<getSize() - i - 1; j++)
			if (compareBooks(*objects[j], *objects[j + 1]))
			{
				Book* swap = objects[j];
			    objects[j] = objects[j + 1];
				objects[j + 1] = swap;
			}
}

BooksContainer BooksContainer::booksByAuthor(const Author& author)
{
	BooksContainer books;
	for (unsigned i = 0; i<getSize(); i++)
	{
		if (strcmp(objects[i]->getAuthor()->getName(), author.getName()) == 0) { books.insert(*objects[i]);  }
	}
	return books;
}