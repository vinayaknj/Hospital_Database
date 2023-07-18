#include "inputData.h"
#include <iostream>
#include <limits>
#include <regex>

using namespace std;

void inputData::addPatient(HospitalDatabase& database){
    int patientID, age;
    string name, contactNumber;
    bool validInput = true;
    bool enteredPatientID = false;
    bool enteredName = false;
    bool enteredAge = false;
    bool enteredContactNumber = false;

    do {
        if (!enteredPatientID) {
            cout << "Enter patient ID: ";
            if (!(cin >> patientID)) {
                cout << "Invalid input. Patient ID must be a valid integer." << endl;
                validInput = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;  // Return to the start of the loop
            } else {
                enteredPatientID = true;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if(!enteredName){
            cout << "Enter patient name: ";
            getline(cin, name);
            std::regex pattern("^[a-zA-Z]+$");

            // Validate patient name
            bool isValid = std::regex_match(name, pattern);

            if (!isValid) {
                std::cout << "Invalid input. Patient name must contain only alphabetical characters." << std::endl;
                validInput = false;
                continue;
            } else {
                enteredName = true;
            }
        }

        if (!enteredAge) {
            cout << "Enter patient age: ";
            if (!(cin >> age)) {
                cout << "Invalid input. Age must be a valid integer." << endl;
                validInput = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;  // Return to the start of the loop
            } else {
                enteredAge = true;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (!enteredContactNumber) {
            cout << "Enter patient contact number: ";
            getline(cin, contactNumber);

            if (contactNumber.size() < 7) {
                cout << "Invalid input. Contact number must have at least 7 digits." << endl;
                validInput = false;
                continue;  // Return to the start of the loop
            } else {
                enteredContactNumber = true;
            }
        }

        validInput = true;
    } while (!validInput);

    Patient patient(patientID, name, age, contactNumber, 0);
    database.addPatient(patient);
    cout << "Patient added successfully!" << endl;
}

void inputData::addDoctor(HospitalDatabase& database){
    int doctorID;
    string name, specialization;
    bool validInput = true;
    bool enteredDoctorID = false;
    bool enteredName = false;
    bool enteredSpecialization = false;

    do{
        if (!enteredDoctorID) {
            cout << "Enter doctor ID: ";
            if (!(cin >> doctorID)) {
                cout << "Invalid input. Patient ID must be a valid integer." << endl;
                validInput = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;  // Return to the start of the loop
            } else {
                enteredDoctorID = true;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if(!enteredName){
            cout << "Enter doctor name: ";
            getline(cin, name);
            std::regex pattern("^[a-zA-Z]+$");

            bool isValid = std::regex_match(name, pattern);

            if (!isValid) {
                std::cout << "Invalid input. Doctor name must contain only alphabetical characters." << std::endl;
                validInput = false;
                continue;
            } else {
                enteredName = true;
            }
        }

        if(!enteredSpecialization){
            cout << "Enter doctor specialization: ";
            getline(cin, specialization);
            std::regex pattern("^[a-zA-Z]+$");

            bool isValid = std::regex_match(specialization, pattern);

            if (!isValid) {
                std::cout << "Invalid input. Doctor specialization must contain only alphabetical characters." << std::endl;
                validInput = false;
                continue;
            } else {
                enteredSpecialization = true;
            }
        }
        
        validInput = true;
    } while (!validInput);

    Doctor doctor(doctorID, name, specialization);
    database.addDoctor(doctor);
    cout << "Doctor added successfully!" << endl;
}