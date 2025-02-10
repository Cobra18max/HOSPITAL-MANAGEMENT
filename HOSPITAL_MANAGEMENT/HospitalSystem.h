#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H


#include "HospitalSystem.h"
#include "PatientManager.h"
#include<vector>

class HospitalSystem :public PatientManager
{
private:
	PatientManager patientManager;
	vector<string> doctors;
	int failureCount = 0;
public:
	HospitalSystem(PatientManager* manager, const vector<string> doctors) : patientManager(*manager), doctors(doctors) {};

	PatientManager* addPatient(const Patient& pa, Priority priority) { patientManager.adddPatient(pa, priority);return &patientManager; };
	void processNextPatient(const string& doctor) { patientManager.getNextFor(doctor); };
	void processTurn() { patientManager.addTurns(); };
	void displayState() const { patientManager.displayPatient(); };
	int getFailureCount()const { return failureCount; };
};


#endif

