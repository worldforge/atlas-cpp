// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#ifndef ATLAS_FACTORY_H
#define ATLAS_FACTORY_H

#include <string>
#include <list>
#include <algorithm>
#include "StuffFactory.h"
namespace Atlas {

/** Class factory

Factory is a template class for automatic registration, construction and
destruction of particular classes. It is used by creating a static instance
for each class that requires it. Each registered class specifies a name and
Metrics (can be any class) that is used when enumerating the classes for the
purposes of negotiation. Each class also declares a Parameters structure,
which is passed to the constructor of the class at creation time by the
factory.

Both Codec and Filter specialise Factory and use it for class registration.

@see Codec
@see Filter
@see Negotiate
*/

class Factory
{
    public:
	struct sClassInfo
	{
		std::string classname;
		std::list<Factory*> aImpFactories;
	};

	static std::list<sClassInfo> aClassFactories;

	StuffFactory* m_pFactory;
    Factory(StuffFactory* pFact, const std::string& classname, const std::string& name)
     : m_pFactory(pFact), name(name)
    {
		FactoriesCheckAdd(classname, this);
    }
    
    virtual ~Factory()
    {
		/*std::list<Factory*>::iterator i;
		i = std::find(Factories().begin(), Factories().end(), this);
		Factories().erase(i);*/
    }
    
	void* New(void* pParameters)
	{
		return m_pFactory->New(pParameters);
	}

	void Delete(void* filter)
	{
		m_pFactory->Delete(filter);
	}

    std::string GetName()
    {
		return name;
    }
       
    static std::list<Factory*> Factories(const std::string & classname)
    {	
		std::list<sClassInfo>::iterator i;
	    for (i = aClassFactories.begin(); i != aClassFactories.end(); ++i)
	    {
			if ((*i).classname == classname)
				return (*i).aImpFactories;
		}
		std::list<Factory*> dummy;
		return 	dummy;
    }

    void FactoriesCheckAdd(std::string classname, Factory* pNewFact)
    {	
		std::list<sClassInfo>::iterator i;
		
		std::list<Factory*>* pImps = NULL;
	    for (i = aClassFactories.begin(); i != aClassFactories.end(); ++i)
	    {
			if ((*i).classname == classname)
			{
				pImps = &(*i).aImpFactories;
				break;
			};
		}
		if (!pImps)
		{
			sClassInfo ci;
			ci.classname = classname;
			ci.aImpFactories.push_back(pNewFact);
			aClassFactories.push_back(ci);
			return;
		}
		
		std::list<Factory*>::iterator j;

		for (j = pImps->begin(); j != pImps->end(); ++j)
	    {
			if ((*j)->name == pNewFact->name)
				return;
		}
		pImps->push_back(pNewFact);
		
		return ;
    }
    public:

    std::string name;
};

} // Atlas namespace

#endif
