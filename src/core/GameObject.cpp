#include "core/GameObject.h"

#include "shared/pch.h"
#include "GameObject.h"

void GameObject::onNotify(ISubject *subject)
{
    std::cout << "I have been notified!\n";
}
