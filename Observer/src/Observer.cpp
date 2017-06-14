//============================================================================
// Name        : Observer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <string>
using namespace std;

Observer::Observer ()
{
  _st = '\0';
}

Observer::~Observer ()
{
}
ConcreteObserverA::ConcreteObserverA (Subject* sub)
{
  _sub = sub;
  _sub->Attach (this);
}
ConcreteObserverA::~ConcreteObserverA ()
{
  _sub->Detach (this);
  if (_sub)
    {
      delete _sub;
      _sub = NULL;
    }
}
Subject*
ConcreteObserverA::GetSubject ()
{
  return _sub;
}
void
ConcreteObserverA::PrintInfo ()
{
  cout << "ConcreteObserverA observer.." << _sub->GetState () << endl;
}
void
ConcreteObserverA::Update (Subject* sub)
{
  _st = sub->GetState ();
  PrintInfo ();
}
ConcreteObserverB::ConcreteObserverB (Subject* sub)
{
  _sub = sub;
  _sub->Attach (this);
}

ConcreteObserverB::~ConcreteObserverB ()
{
  _sub->Detach (this);
  if (_sub)
    {
      delete _sub;
      _sub = NULL;
    }
}

Subject*
ConcreteObserverB::GetSubject ()
{
  return _sub;
}
void
ConcreteObserverB::PrintInfo ()
{
  cout << "ConcreteObserverB observer.." << _sub->GetState () << endl;
}
void
ConcreteObserverB::Update (Subject* sub)
{
  _st = sub->GetState ();
  PrintInfo ();
}