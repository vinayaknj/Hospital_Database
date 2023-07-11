#ifndef HOSPITALDATABASE_H
#define HOSPITALDATABASE_H

#include "Patient.h"
#include "Doctor.h"
#include <vector>

class HospitalDatabase {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;

public:
    void addPatient(const Patient& patient);
    void addDoctor(const Doctor& doctor);
    bool assignDoctorToPatient(int patientID, int doctorID);
    vector<Patient> getPatientsByDoctor(int doctorID) const;
    vector<Doctor> getDoctorsByPatient(int patientID) const;
    void removePatient(int patientID);
    void removeDoctor(int doctorID);
    void displayAllPatients() const;
    void displayAllDoctors() const;
    vector<Patient> getPatients() const;
    vector<Doctor> getDoctors() const;
    void clear();
};

#endif  // HOSPITALDATABASE_H
