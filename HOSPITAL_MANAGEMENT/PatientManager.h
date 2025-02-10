#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

#include "PatientQueue.h"
#include "Priority.h"
#include "Patient.h"


class PatientManager :public PatientQueue
{
private:
	PatientQueue* LowPriorityQ;
	PatientQueue* HighPriorityQ;
	PatientQueue* MediumPriorityQ;
	PatientQueue* frontQ;

public:


	PatientManager() :LowPriorityQ(nullptr), MediumPriorityQ(nullptr), HighPriorityQ(nullptr), frontQ(nullptr) {};
	void adddPatient(Patient pa, Priority priority);
	Patient* getNextFor(const string& doctor);
	int addTurns();
	void displayPatient() const;
	int getNbPatients()const;
};

#endif