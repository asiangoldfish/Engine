#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "shared/pch.h"
#include "IObserver.h"

class ISubject
{
public:
	virtual ~ISubject() {}

	virtual void notify();
	virtual void addObserver(IObserver* observer);
	virtual void removeObserver(IObserver* observer);

protected:
	std::vector<IObserver*> observers;
};

#endif