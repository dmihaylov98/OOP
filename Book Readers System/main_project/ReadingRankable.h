#ifndef READINGRANKABLE_H_INCLUDED
#define READINGRANKABLE_H_INCLUDED

class ReadingRankable
{
public:
	virtual ~ReadingRankable() { }
	virtual int getReadingRank() const = 0;
};

#endif // ! READINGRANKABLE_H_INCLUDED
