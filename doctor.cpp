#include "Doctor.h"

Doctor::Doctor(int doctorID, string name, string specialization)
    : doctorID(doctorID), name(move(name)), specialization(move(specialization)) {
}

int Doctor::getDoctorID() const {
    return doctorID;
}

string Doctor::getName() const {
    return name;
}

string Doctor::getSpecialization() const {
    return specialization;
}
