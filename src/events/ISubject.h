#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "shared/pch.h"

class IObserver;

class ISubject
{
protected:

public:
	virtual ~ISubject() {}

	/**
	 * @brief Notifies all observers about an event
	 * @param subject The subject that published the event
	 */
	virtual void notify(ISubject *subject);
	virtual void addObserver(IObserver* observer);
	virtual void removeObserver(IObserver* observer);

protected:
	std::vector<IObserver*> observers;
};

#endif