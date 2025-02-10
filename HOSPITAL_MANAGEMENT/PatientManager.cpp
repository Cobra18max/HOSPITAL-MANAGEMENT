#include "PatientManager.h"
#include "PatientQueue.h"
#include "Priority.h"
#include "Patient.h"
#include <iostream>
#include <string>
#include<vector>

using namespace std;

//Add a patient to the queue based on their priority...
void PatientManager::adddPatient(Patient pa, Priority priority) {
	PatientQueue* MediumPriorityQ = new PatientQueue();
	PatientQueue* HighPriorityQ = new PatientQueue();
	PatientQueue* LowPriorityQ = new PatientQueue();
	if (!front)
	{
		switch (priority)
		{
		case Priority::LOW:
			LowPriorityQ->enqueue(pa.getName(), pa.getAge(), pa.getCondition(), pa.getTurnsRemaining(), pa.getDoctor());
			LowPriorityQ->setNext(front);
			front = LowPriorityQ;
			break;
		case Priority::MEDIUM:
			MediumPriorityQ->enqueue(pa.getName(), pa.getAge(), pa.getCondition(), pa.getTurnsRemaining(), pa.getDoctor());
			MediumPriorityQ->setNext(front);
			front = MediumPriorityQ;
			break;
		case Priority::HIGH:
			HighPriorityQ->enqueue(pa.getName(), pa.getAge(), pa.getCondition(), pa.getTurnsRemaining(), pa.getDoctor());
			HighPriorityQ->setNext(front);
			front = HighPriorityQ;
			break;
		default:
			break;
		}
	}
	else {//Parcours la liste pour inserer le patient en fonction de sa priorite a la bonne place
		Patient* current = front;
		while (current)
		{
			switch (priority)
			{
			case Priority::LOW:
				LowPriorityQ->enqueue(pa.getName(), pa.getAge(), pa.getCondition(), pa.getTurnsRemaining(), pa.getDoctor());
				LowPriorityQ->setNext(current);
				front = LowPriorityQ;
				break;
			case Priority::MEDIUM:
				MediumPriorityQ->enqueue(pa.getName(), pa.getAge(), pa.getCondition(), pa.getTurnsRemaining(), pa.getDoctor());
				MediumPriorityQ->setNext(current);
				front = MediumPriorityQ;
				break;
			case Priority::HIGH:
				HighPriorityQ->enqueue(pa.getName(), pa.getAge(), pa.getCondition(), pa.getTurnsRemaining(), pa.getDoctor());
				HighPriorityQ->setNext(current);
				front = HighPriorityQ;
				break;
			default:

				break;
			}
		}

	}

};

Patient* PatientManager::getNextFor(const string& doctor) {
	Patient* current = front;
	Patient* previous = nullptr;
	if (!front)return nullptr;

	while (current) {
		if (current->getDoctor() == doctor) {
			if (previous) {
				previous->setNextPa(current->getNextPa());
			}
			else {
				front = current->getNextPa();
			}
			return current;
		}
		previous = current;
		current = current->getNextPa();
	}
	return current;

};
//Returns the number of patients that haven't been treated
int PatientManager::addTurns() {
	int deletedPatients = 0;
	Patient* current = front;
	Patient* previous = nullptr;
	while (current) {
		if (current->getTurnsRemaining() > 0) {
			current->decreaseTurnsRemaining(getNbPatients());
			current = current->getNextPa();
		}
		else {
			Patient* selectedPatient = current;
			if (previous != nullptr) {
				previous->setNextPa(current->getNextPa());
			}
			else {
				front = current->getNextPa();
			}
			delete selectedPatient;
			deletedPatients++;
			current = current->getNextPa();
		}
	}
	return deletedPatients;
}
//Returns the number of patients in the queue
int PatientManager::getNbPatients() const {

	Patient* current = front;
	int count = 0;
	while (current) {
		if (current->getTurnsRemaining() > 0) {
			count++;
			current = current->getNextPa();
		}
	}
	return count;
}
//Display the patients in every single queue
void PatientManager::displayPatient() const {
	Patient* current = front;
	while (current) {
		//display patients in a low priority queue
		if (current->getPriority() == Priority::LOW) {
			current->display_Patient();
			current = current->getNextPa();
		}
		//display patients in a medium priority queue
		if (current->getPriority() == Priority::MEDIUM) {
			current->display_Patient();
			current = current->getNextPa();
		}
		//display patients in a high priority queue
		if (current->getPriority() == Priority::HIGH) {
			current->display_Patient();
			current = current->getNextPa();
		}
	}
}