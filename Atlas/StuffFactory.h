#ifndef _STUFF_FACTORY_H_
#define _STUFF_FACTORY_H_

class StuffFactory
{
public:
	virtual void* New(void* pParameters) = 0;
	virtual void Delete(void* pObject) = 0;
};

#endif