#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>

// Enum�ration des priorit�s pour les patients
enum class Priority {
    HIGH,
    MEDIUM,
    LOW
};

// Surcharge de l'op�rateur << pour afficher Priority
inline std::ostream& operator<<(std::ostream& os, Priority p) {
    switch (p) {
    case Priority::HIGH: os << "HIGH"; break;
    case Priority::MEDIUM: os << "MEDIUM"; break;
    case Priority::LOW: os << "LOW"; break;
    }
    return os;
}

#endif // PRIORITY_H
