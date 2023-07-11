#include "HospitalDatabase.h"
#include <algorithm>  // Include the <algorithm> header for remove_if
#include <iostream>

using namespace std;

void HospitalDatabase::addPatient(const Patient& patient) {
    patients.push_back(patient);
}

void HospitalDatabase::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}

bool HospitalDatabase::assignDoctorToPatient(int patientID, int doctorID) {
    // Check doctor ID valid
    bool validDoctor = false;
    for (const auto& doctor : doctors) {
        if (doctor.getDoctorID() == doctorID) {
            validDoctor = true;
            break;
        }
    }
    if(!validDoctor){
        cout << "Invalid doctor ID." << endl;
        return false;
    }
    if (validDoctor) {
        for (auto& patient : patients) {
            if (patient.getPatientID() == patientID) {
                patient.setAssignedDoctorID(doctorID);
                return true;
            }
        }
    }
    cout << "Invalid patient ID" << endl;
    return false;
}

vector<Patient> HospitalDatabase::getPatientsByDoctor(int doctorID) const {
    vector<Patient> patientsByDoctor;
    for (const auto& patient : patients) {
        if (patient.getAssignedDoctorID() == doctorID) {
            patientsByDoctor.push_back(patient);
        }
    }
    return patientsByDoctor;
}

vector<Doctor> HospitalDatabase::getDoctorsByPatient(int patientID) const {
    vector<Doctor> doctorsByPatient;
    for (const auto& doctor : doctors) {
        for (const auto& patient : patients) {
            if (patient.getPatientID() == patientID && patient.getAssignedDoctorID() == doctor.getDoctorID()) {
                doctorsByPatient.push_back(doctor);
                break;
            }
        }
    }
    return doctorsByPatient;
}

void HospitalDatabase::removePatient(int patientID) {
    patients.erase(remove_if(patients.begin(), patients.end(),
                                  [patientID](const Patient& patient) { return patient.getPatientID() == patientID; }),
                   patients.end());
}

void HospitalDatabase::removeDoctor(int doctorID) {
    doctors.erase(remove_if(doctors.begin(), doctors.end(),
                                 [doctorID](const Doctor& doctor) { return doctor.getDoctorID() == doctorID; }),
                  doctors.end());
}

void HospitalDatabase::displayAllDoctors() const {
    cout << "========== List of Doctors ==========" << endl;
    for (const auto& doctor : doctors) {
        cout << "Doctor ID: " << doctor.getDoctorID() << ", Name: " << doctor.getName() << ", Specialization: " << doctor.getSpecialization() << std::endl;
    }
    cout << "======================================" << endl;
}

void HospitalDatabase::displayAllPatients() const {
    cout << "========== List of Patients ==========" << endl;
    for (const auto& patient : patients) {
        cout << "Patient ID: " << patient.getPatientID() << ", Name: " << patient.getName() << ", Age: " << patient.getAge() << ", Contact Number: " << patient.getContactNumber() << std::endl;
    }
    cout << "======================================" << endl;
}

vector<Patient> HospitalDatabase::getPatients() const {
    return patients;
}

vector<Doctor> HospitalDatabase::getDoctors() const {
    return doctors;
}

void HospitalDatabase::clear() {
    patients.clear();
    doctors.clear();
}
