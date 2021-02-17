#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

#include "Community.h"

Community::Community(unsigned capacity)
	: Set<Reader>(capacity)
{ }

int Community::getReadingRank()const
{
	int rank = 0;
	for (unsigned i = 0; i < getSize(); i++)
	{
		rank += objects[i]->getReadingRank();
	}
	return rank;
}