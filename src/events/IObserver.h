#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
	IObserver() {}
	virtual ~IObserver() {}

	virtual void onNotify() = 0;
};

#endif