#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "Priority.h"


using namespace std;

class Patient
{
private:

	string name;
	int age;
	string condition;
	int turnsRemaining;
	string requiredSpeciality;
	Patient* nextPa;
	Patient* front;

public:
	Patient(const string& name_P, int age_P, const string& condition_P, int turnsRemaining_P, const string& requiredSpeciality_P) : name(name_P), age(age_P), condition(condition_P), turnsRemaining(turnsRemaining_P), requiredSpeciality(requiredSpeciality_P), nextPa(nullptr), front(nullptr) {};
	Patient* getNextPa() const { return nextPa; }
	string getName()const { return name; }
	string getDoctor()const { return requiredSpeciality; }
	int getAge()const { return age; }
	string getCondition()const { return condition; }
	int  getTurnsRemaining() { return turnsRemaining; }

	//Methode de mutateur
	void setNextPa(Patient* pa) { this->nextPa = pa; }
	void decreaseTurnsRemaining(int turns) { this->turnsRemaining = turns - 1; }

	Priority getPriority()const { if (condition == "Crise cardiaque") return Priority::HIGH; if (condition == "M ralgie") return Priority::MEDIUM; return Priority::LOW; }

	void display_Patient()const;
	Patient():name(""), age(0), condition(""), turnsRemaining(0), requiredSpeciality(""), nextPa(nullptr), front(nullptr){};

};

#endif