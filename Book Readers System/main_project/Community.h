#ifndef COMMUNITY_H_INCLUDED
#define COMMUNITY_H_INCLUDED

#include "Set.h"
#include "Reader.h"

class Community : public Set<Reader>
{
public:
	Community(unsigned capacity = 1);

	virtual int getReadingRank() const;

};

#endif // ! COMMUNITY_H_INCLUDED