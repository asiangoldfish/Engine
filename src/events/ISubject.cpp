#include "shared/Logger.h"

#include "ISubject.h"
#include "IObserver.h"

void ISubject::notify(ISubject *subject)
{
	for (auto o : observers)
	{
		o->onNotify(subject);
	}
}

void ISubject::addObserver(IObserver* observer)
{
	observers.push_back(observer);
}

void ISubject::removeObserver(IObserver* observer)
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		if (observers[i] == observer)
		{
			observers.erase(observers.begin() + i);
		}
	}
}
