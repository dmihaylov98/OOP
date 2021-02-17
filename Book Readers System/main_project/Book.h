#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

class Author;

enum Genre { novel, drama, fiction, fantasy, story, poem, other };

class Book
{
public:
	Book();
	Book(const char* caption, int pages , int year , const Author* author, const Genre& genre, double price );
	Book(const Book&);
	Book& operator=(const Book&);
	virtual ~Book();

	void setCaption(const char*);
	void setPages(int);
	void setYear(int);
	void setAuthor(const Author*);
	void setGenre(const Genre&);
	void setPrice(double);

	const char* getCaption()const;
	int getPages()const;
	int getYear()const;
	const Author* getAuthor()const;
	Genre getGenre()const;
	double getPrice()const;

	void print()const;

	bool operator==(const Book&) const;

	virtual Book* clone() const { return new Book(*this); }

	friend istream& operator>>(istream& is, Book& b);
	friend ostream& operator<<(ostream& os, const Book& b);

protected:
	char* caption;
	int pages;
	int year;
	const Author* author;
	Genre genre;
	double price;
};

#endif // ! BOOK_H_INCLUDED
