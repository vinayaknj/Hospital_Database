#include "saveandloadDB.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string SaveAndLoadDB::DATABASE_FILE = "hospital_database.txt";

void SaveAndLoadDB::saveDatabaseToFile(const HospitalDatabase& database) {
    ofstream file(DATABASE_FILE);

    if (file.is_open()) {
        // Save patient details
        file << "PATIENTS\n";
        const vector<Patient>& patients = database.getPatients();
        for (const auto& patient : patients) {
            file << patient.getPatientID() << "," << patient.getName() << "," << patient.getAge() << "," << patient.getContactNumber() << "," << patient.getAssignedDoctorID() << "\n";
        }

        // Save doctor details
        file << "DOCTORS\n";
        const vector<Doctor>& doctors = database.getDoctors();
        for (const auto& doctor : doctors) {
            file << doctor.getDoctorID() << "," << doctor.getName() << "," << doctor.getSpecialization() << "\n";
        }

        file.close();
    } else {
        cout << "Error: Unable to open the database file for saving." << endl;
    }
}

void SaveAndLoadDB::loadDatabaseFromFile(HospitalDatabase& database) {
    ifstream file(DATABASE_FILE);

    if (file.is_open()) {
        // Clear existing patient and doctor data
        database.clear();

        // Load patient and doctor details from the file
        string line;
        string section;
        while (getline(file, line)) {
            if (line == "PATIENTS") {
                section = "PATIENTS";
                continue;
            } else if (line == "DOCTORS") {
                section = "DOCTORS";
                continue;
            }

            if (section == "PATIENTS") {
                stringstream ss(line);
                string patientID, name, age, contactNumber, assignedDoctorID;
                getline(ss, patientID, ',');
                getline(ss, name, ',');
                getline(ss, age, ',');
                getline(ss, contactNumber, ',');
                getline(ss, assignedDoctorID, ',');

                int patientIDInt = stoi(patientID);
                int ageInt = stoi(age);
                int assignedDoctorIDInt = stoi(assignedDoctorID);

                Patient patient(patientIDInt, name, ageInt, contactNumber, assignedDoctorIDInt);
                database.addPatient(patient);
            } else if (section == "DOCTORS") {
                stringstream ss(line);
                string doctorID, name, specialization;
                getline(ss, doctorID, ',');
                getline(ss, name, ',');
                getline(ss, specialization, ',');

                int doctorIDInt = stoi(doctorID);

                Doctor doctor(doctorIDInt, name, specialization);
                database.addDoctor(doctor);
            }
        }

        file.close();
    } else {
        cout << "Error: Unable to open the database file for loading." << endl;
    }
}
