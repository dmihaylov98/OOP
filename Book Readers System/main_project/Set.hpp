#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <new>
using namespace std;

#include "Set.h"

template <typename T>
Set<T>::Set(unsigned capacity)
	: capacity(capacity), size(0), objects(NULL)
{
	this->objects = new T*[this->capacity]{ NULL };
}

template <typename T>
Set<T>::Set(const Set<T>& other)
	: objects(NULL), size(other.size), capacity(other.capacity)
{
	copy(other);
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

template <typename T>
Set<T>::~Set()
{
	this->destroy();
}

template <typename T>
void Set<T>::copy(const Set<T>& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->objects = new T*[this->capacity]{ NULL };
	for (int i = 0; i < this->size; i++)
	{
		this->objects[i] = other.objects[i]->clone();
	}
}


template <typename T>
void Set<T>::destroy()
{
	for (unsigned i = 0; i < this->size; i++)
	{
		delete objects[i];
	}
	delete[] objects;
}

/*template <typename T>
void Set<T>::resizeUp()
{
	T** temp = this->objects;
	this->objects = new (nothrow) T*[this->capacity];
	assert(temp != nullptr);

	for (int i = 0; i < this->capacity; i++)
	{
		temp[i] = this->objects[i];
	}
	delete[] this->objects;
	this->objects = temp;
	this->capacity *= 2;

}*/

template <typename T>
void Set<T>::resizeUp()
{
	this->capacity *= 2;
	T** temp = new (nothrow) T*[this->capacity];
	assert(temp != nullptr);

	for (int i = 0; i < this->size; i++)
	{
		temp[i]=this->objects[i];
	}
	delete[] this->objects;
	this->objects = temp;
	
}

template <typename T>
void Set<T>::resizeDown()
{
	this->capacity /= 2;
	T** temp = new (nothrow) T*[this->capacity];
	assert(temp != nullptr);

	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->objects[i];
	}

	delete[] this->objects;

	this->objects = temp;
}

template <typename T>
int Set<T>::find(const T& obj)const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (*objects[i] == obj)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
bool Set<T>::has(const T& obj)const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (obj == *objects[i])
		{
			return true;
		}
	}
	return false;
}

template <typename T>
void Set<T>::insert(const T& other)
{
	if (has(other) == 0)
	{
		if (this->size + 1 >= this->capacity)
		{
			resizeUp();
		}
		this->objects[this->size] = other.clone();
		this->size++;
	}
}

template <typename T>
void Set<T>::remove(const T& other)
{
	if (has(other) == 1)
	{
		size_t position = find(other);
		
		delete this->objects[position];

		this->objects[position] = this->objects[this->size - 1];
		this->objects[this->size - 1] = NULL;
	
		--this->size;

		if (this->size <= this->capacity / 2)
		{
			resizeDown();
		}
	}
}

template <typename T>
bool Set<T>::isEmpty()const
{
	return this->size == 0;
}

template <typename T>
void Set<T>::print()const
{
	for (size_t i = 0; i < this->size; i++)
	{
		objects[i]->print();
		cout << endl;
	}
}

template <typename T>
T& Set<T>::operator[](unsigned index)
{
	assert(index < this->size);
	return *this->objects[index];
}

template <typename T>
const T& Set<T>::operator[](unsigned index)const
{
	assert(index < this->size);
	return *this->objects[index];
}

