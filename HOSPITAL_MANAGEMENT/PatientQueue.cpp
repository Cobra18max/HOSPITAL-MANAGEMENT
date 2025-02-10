#include "PatientQueue.h"
#include "Patient.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Enqueue a patient into the queue...
void PatientQueue::enqueue(const string& name_P, int age_P, const string& condition_P, int turnsRemaining_P, const string& requiredSpeciality_P) {

	Patient* newPatient = new Patient(name_P, age_P, condition_P, turnsRemaining_P, requiredSpeciality_P);
	if (!front)
	{
		front = rear = newPatient;
	}
	else
	{
		rear->setNextPa(newPatient);
		rear = newPatient;
	}
};

// Dequeue a patient from the queue...
Patient* PatientQueue::dequeue() {
	if (!front)
	{
		return nullptr;
	}
	Patient* P = front;
	front = front->getNextPa();

	if (!front)
	{
		rear = nullptr;
	}
	return P;
};

// Display the patient queue...
