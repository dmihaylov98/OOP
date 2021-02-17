#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

#include "Book.h"
#include "Author.h"

void printGenre(Genre genre)
{
	switch (genre)
	{
	case novel: cout << "novel"; break;
	case drama: cout << "drama"; break;
	case fiction: cout << "fiction"; break;
	case fantasy: cout << "fantasy"; break;
	case story: cout << "story"; break;
	case poem: cout << "poem"; break;
	default: "other";
	}
}

Book::Book()
	: author(NULL), caption(NULL)
{
	this->setCaption("Name");
	this->setPages(0);
	this->setYear(0);
	this->setPrice(0.0);
	this->setGenre(other);
}

Book::Book(const char* theCaption, int thePages, int theYear, const Author* theAuthor, const Genre& theGenre, double thePrice)
	: caption(NULL), pages(0), year(0), genre(theGenre), price(0.0), author(NULL)
{
	this->setCaption(theCaption);
	this->setPages(thePages);
	this->setYear(theYear);
	this->setPrice(thePrice);
	this->setAuthor(theAuthor);
}

Book::Book(const Book& other)
{
	this->setCaption(other.caption);
	this->setPages(other.pages);
	this->setYear(other.year);
	this->setAuthor(other.author);
	this->setGenre(other.genre);
	this->setPrice(other.price);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		this->setCaption(other.caption);
		this->setPages(other.pages);
		this->setYear(other.year);
		this->setAuthor(other.author);
		this->setGenre(other.genre);
		this->setPrice(other.price);
	}
	return *this;
}

Book::~Book()
{
	delete[] this->caption;
}

void Book::setCaption(const char* caption)
{
	if (!caption)caption = "";
	size_t len = strlen(caption);
	delete[] this->caption;
	this->caption = new char[len + 1];
	strcpy_s(this->caption, len + 1, caption);
}

void Book::setPages(int pages)
{
	if (pages>0)
		this->pages = pages;
}

void Book::setYear(int year)
{
	if (year>0)
		this->year = year;
}

void Book::setAuthor(const Author* author)
{
	this->author = author;
}

void Book::setGenre(const Genre& genre)
{
	this->genre = genre;
}

void Book::setPrice(double price)
{
	if (price>0)
		this->price = price;
}

const char* Book::getCaption()const
{
	return this->caption;
}

int Book::getPages()const
{
	return this->pages;
}

int Book::getYear()const
{
	return this->year;
}

const Author* Book::getAuthor()const
{
	return this->author;
}

Genre Book::getGenre()const
{
	return this->genre;
}

double Book::getPrice()const
{
	return this->price;
}

void Book::print()const
{
	cout << "Caption: " << this->caption << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Year: " << this->year << endl;
	cout << "Author: " << this->author->getName() << endl;
	cout << "Genre: "; printGenre(this->genre); cout << endl;
	cout << "Price: " << this->price << endl;
}

bool Book::operator==(const Book& other)const
{
	if (strcmp(this->caption, other.caption) != 0)return false;
	if (this->pages != other.pages)return false;
	if (this->year != other.year)return false;
	if (this->author != other.author)return false;
	if (this->genre != other.genre)return false;
	if (this->price != other.price)return false;
	return true;
}

istream& operator>>(istream& is, Book& b)
{
	char buffer[100];
	is >> buffer;
	b.setCaption(buffer);
	is >> b.pages >> b.year;
	b.setAuthor(NULL);
	int genr;
	is >> genr;
	switch (genr)
	{
	case novel: b.genre = novel; break;
	case drama: b.genre = drama; break;
	case fiction: b.genre = fiction; break;
	case fantasy: b.genre = fantasy; break;
	case story: b.genre = story; break;
	case poem: b.genre = poem; break;
	default: b.genre = other;
	}
	is >> b.price;
	return is;
}

ostream& operator<<(ostream& os, const Book& b)
{
	os << b.caption << " " << b.pages << " " << b.year << " " << b.author;
	printGenre(b.genre);
	os << " " << b.price << endl;
	return os;
}