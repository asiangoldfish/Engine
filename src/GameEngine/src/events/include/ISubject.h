#pragma once

#include <pch.h>
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