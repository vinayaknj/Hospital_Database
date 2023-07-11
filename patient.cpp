#include "Patient.h"

Patient::Patient(int patientID, string name, int age, string contactNumber, int assignedDoctorID)
    : patientID(patientID), name(move(name)), age(age), contactNumber(move(contactNumber)),
      assignedDoctorID(assignedDoctorID) {
}

int Patient::getPatientID() const {
    return patientID;
}

string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

string Patient::getContactNumber() const {
    return contactNumber;
}

int Patient::getAssignedDoctorID() const {
    return assignedDoctorID;
}

void Patient::setAssignedDoctorID(int doctorID) {
    assignedDoctorID = doctorID;
}
