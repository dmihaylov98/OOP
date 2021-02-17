#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

template <typename T>
class Set
{
public:
	Set(unsigned capacity = 1);
	Set(const Set&);
	Set<T>& operator=(const Set&);
	~Set();

	unsigned getCapacity()const { return this->capacity; }
	unsigned getSize()const { return this->size; }

	bool has(const T&)const;

	void insert(const T&);
	void remove(const T&);
	bool isEmpty()const;

	void print()const;

	T& operator[](unsigned index);
	const T& operator[](unsigned index)const;
	
protected:
	T** objects;
	unsigned capacity;
	unsigned size;

private:
	void copy(const Set<T>& other);
	void destroy();
	void resizeUp();
	void resizeDown();
	int find(const T&)const;
};

#include "Set.hpp"

#endif // ! SET_H_INCLUDED