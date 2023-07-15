#include "shared/Logger.h"

#include "ISubject.h"

void ISubject::notify()
{
	for (auto o : observers)
	{
		o->onNotify();
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
