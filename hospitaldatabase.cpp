#include "HospitalDatabase.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void HospitalDatabase::exportToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << "Patient ID,Name,Age,Contact Number,Assigned Doctor ID" << std::endl;
    for (const auto& patient : patients) {
        file << patient.getPatientID() << ","
             << patient.getName() << ","
             << patient.getAge() << ","
             << patient.getContactNumber() << ","
             << patient.getAssignedDoctorID() << std::endl;
    }

    file << std::endl;
    
    file << "Doctor ID,Name,Specialization" << std::endl;
    for (const auto& doctor : doctors) {
        file << doctor.getDoctorID() << ","
             << doctor.getName() << ","
             << doctor.getSpecialization() << std::endl;
    }

    file.close();
    std::cout << "Data exported to CSV: " << filename << std::endl;
}

void HospitalDatabase::addPatient(const Patient& patient) {
    patients.push_back(patient);
}

void HospitalDatabase::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}

bool HospitalDatabase::assignDoctorToPatient(int patientID, int doctorID) {
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
