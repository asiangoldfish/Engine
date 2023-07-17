#ifndef IOBSERVER_H
#define IOBSERVER_H

class ISubject;

class IObserver
{
public:
	IObserver() {}
	virtual ~IObserver() {}

	virtual void onNotify(ISubject *subject) = 0;
};

#endif