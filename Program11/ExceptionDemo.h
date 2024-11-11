#ifndef EXCEPTION_DEMO_H
#define EXCEPTION_DEMO_H

#include <iostream>
#include <exception>
#include <new>

using namespace std;

void divisionByZero();
void rethrowException();
void stackUnwinding();
void badAllocException();
void setNewHandlerException();
void myNewHandler();

#endif // EXCEPTION_DEMO_H
