#ifndef WRITINGRANKABLE_H_INCLUDED
#define WRITINGRANKABLE_H_INCLUDED

class WritingRankable
{
public:
	virtual ~WritingRankable() { }
	virtual int getWritingRank() const = 0;
};

#endif // ! WRITINGRANKABLE_H_INCLUDED
