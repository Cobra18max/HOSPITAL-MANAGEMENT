#ifndef PATIENTQUEUE_H
#define PATIENTQUEUE_H
#include <string>
#include "Patient.h"

using namespace std;

class PatientQueue : public Patient
{
protected:
	Patient* front;
	Patient* rear;
	Patient* next;
public:
	PatientQueue() :next(nullptr), front(nullptr), rear(nullptr) {};
	void enqueue(const string& name_P, int age_P, const string& condition_P, int turnsRemaining_P, const string& requiredSpeciality_P);
	Patient* dequeue();

	void setNext(Patient* pa) { this->next = next; };


};

#endif
