#include "Component.h"
#include <iostream>
using namespace std;

void Component::add(IComponent *pItem)
{
    cout << "add item" << endl;
}

void Component::remove(IComponent *pItem)
{
    cout << "remove item" << endl;
}

void Component::operation()
{
    cout << "display item" << endl;
}

