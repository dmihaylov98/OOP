// main_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Author.h"
#include "BooksContainer.h"
#include "Community.h"

int main()
{
	Author a1("Ivan Vazov", "Bulgarian", 80);
	Author a2("Hristo Botev", "Bulgarian", 30);
	Author a3("J.K. Rowling", "British", 50);
	Reader r1("Ivan Dimitrov", "Bulgarian", 25);
	Reader r2("Georgi Popov", "Bulgarian", 30);
	Reader r3("John Parker", "British", 19);
	Book b1("Pod igoto", 400, 1885, &a1, novel, 9.00);
	Book b2("Poeziq", 100, 1870, &a2, poem, 8.50);
	Book b3("Harry Potter and the Philosopher's Stone", 332, 1997, &a3, fantasy, 19.99);
	Book b4("Harry Potter and the Chamber of Secrets", 360, 1998, &a3, fantasy, 21.50);
	Book b5("Nemili-nedragi", 230, 1887, &a1, novel, 11.00);
	r1.readBook(b1);
	r1.readBook(b2);
	r1.readBook(b5);
	r2.readBook(b1);
	r2.readBook(b3);
	r3.readBook(b3);
	r3.readBook(b4);
	a1.readBook(b2);
	a1.writeBook(b1);
	a1.writeBook(b5);
	a2.writeBook(b2);
	a3.writeBook(b3);
	a3.writeBook(b4);
	Community com;
	com.insert(r1);
	com.insert(r3);
	com.insert(a3);
	com.insert(a1);
	cout << "Community Reading Rank: ";
	cout << com.getReadingRank() << endl;
	cout << "Author a3 Writing Rank: ";
	cout << a3.getWritingRank() << endl;
	cout << "Community New Reading Rank: ";
	com.remove(a1);
	cout << com.getReadingRank() << endl;
	system("pause");
    return 0;
}

