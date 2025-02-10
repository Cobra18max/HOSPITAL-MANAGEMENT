#include "Patient.h"
#include<iostream>
#include<string>


using namespace std;

//IMPLEMENTATION OF PATIENT CLASS
void Patient::display_Patient() const {
	Patient* P = front;
	while (P)
	{
		cout << P->getName() << endl;
		cout << P->getAge() << endl;
		cout << P->getCondition() << endl;
		cout << P->getTurnsRemaining() << endl;
		cout << P->getDoctor() << endl;
		cout << P->getPriority() << endl;
		P = P->getNextPa();
	}
};