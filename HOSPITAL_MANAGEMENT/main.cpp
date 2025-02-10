#include <iostream>
#include <vector>
#include "HospitalSystem.h"
#include "PatientManager.h"
#include "Priority.h"

static Priority categorizeCondition(const std::string& condition) {
    if (condition == "Crise cardiaque") {
        return Priority::HIGH;
    }
    if (condition == "M�ralgie") {
        return Priority::MEDIUM;
    }
    return Priority::LOW;
}

int main() {
    // Create a list of doctors
    cout << "Creating a list of doctors..." << std::endl;
    std::vector<std::string> doctors = { "Cardiologue", "G�n�raliste",
       "Pneumologue", "Orthop�diste" };
    PatientManager manager{};
    HospitalSystem hospital(&manager, doctors);
    cout << "Creating a list of doctors..." << std::endl;
    std::vector<Patient> patients = {
     Patient("Manon Dupont", 19, "M�ralgie", 3, "G�n�raliste"),
     Patient("Jean Lambert", 25, "Crise cardiaque", 1, "Cardiologue"),
     Patient("Julie Marchand", 41, "Hypertension", 2, "Cardiologue"),
     Patient("Lucie Lefevre", 32, "Asthme", 2, "Pneumologue"),
    };
    cout << "Creating a list of doctors..." << std::endl;

    // Add patients to the hospital
    for (const Patient& patient : patients) {
        hospital.addPatient(patient, categorizeCondition(patient.getCondition()));
    }
    cout << "Creating a list of doctors..." << std::endl;

    for (int nbTour = 1; manager.getNbPatients() > 0; nbTour++) {
        std::cout << "Tour " << nbTour << ":" << std::endl;
        hospital.displayState();
        hospital.processTurn();
        std::cout << "--------------------------------" << std::endl;
    }
    std::cout << "Nombre de patients non trait�s: " << hospital.getFailureCount()
        << std::endl;
    std::cout << "Pourcentage trait� : " << (1 -
        (float)hospital.getFailureCount() / patients.size()) * 100 << "%" << std::endl;

    return 0;
}
