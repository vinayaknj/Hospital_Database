#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "HospitalDatabase.h"
#include "saveandloadDB.h"
#include "inputData.h"

using namespace std;

HospitalDatabase database;

int main() {
    // Load database from file 
    SaveAndLoadDB::loadDatabaseFromFile(database);
    int choice;
    do {
        cout << "========== Hospital Database ==========" << endl;
        cout << "1. Add a new patient" << endl;
        cout << "2. Add a new doctor" << endl;
        cout << "3. Assign a doctor to a patient" << endl;
        cout << "4. Display patients assigned to a specific doctor" << endl;
        cout << "5. Display doctors assigned to a specific patient" << endl;
        cout << "6. Remove a patient from the database" << endl;
        cout << "7. Remove a doctor from the database" << endl;
        cout << "8. Display all the doctors from the database" << endl;
        cout << "9. Display all the patients from the database" << endl;
        cout << "10. Export data to CSV" << endl;
        cout << "11. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        inputData input;
        switch (choice) {
            case 1: {
                input.addPatient(database);
                break;
            }
            case 2: {
                input.addDoctor(database);
                break;
            }
            case 3: {
                int patientID, doctorID;
                cout << "Enter patient ID: ";
                cin >> patientID;
                cout << "Enter doctor ID: ";
                cin >> doctorID;
                bool success = database.assignDoctorToPatient(patientID, doctorID);
                if (success) {
                    cout << "Doctor assigned to patient successfully!" << endl;
                }
                break;
            }
            case 4: {
                int doctorID;
                cout << "Enter doctor ID: ";
                cin >> doctorID;

                vector<Patient> patientsByDoctor = database.getPatientsByDoctor(doctorID);
                if (patientsByDoctor.empty()) {
                    cout << "No patients assigned to the specified doctor." << endl;
                } else {
                    cout << "Patients assigned to Doctor " << doctorID << ":" << endl;
                    for (const auto& patient : patientsByDoctor) {
                        cout << "Patient ID: " << patient.getPatientID() << ", Name: " << patient.getName() << endl;
                    }
                }
                break;
            }
            case 5: {
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;

                vector<Doctor> doctorsByPatient = database.getDoctorsByPatient(patientID);
                if (doctorsByPatient.empty()) {
                    cout << "No doctors assigned to the specified patient." << endl;
                } else {
                    cout << "Doctors assigned to Patient " << patientID << ":" << endl;
                    for (const auto& doctor : doctorsByPatient) {
                        cout << "Doctor ID: " << doctor.getDoctorID() << ", Name: " << doctor.getName() << endl;
                    }
                }
                break;
            }
            case 6: {
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;

                database.removePatient(patientID);
                cout << "Patient removed successfully!" << endl;
                break;
            }
            case 7: {
                int doctorID;
                cout << "Enter doctor ID: ";
                cin >> doctorID;

                database.removeDoctor(doctorID);
                cout << "Doctor removed successfully!" << endl;
                break;
            }
            case 8: {
                database.displayAllDoctors();
                break;
            }
            case 9: {
                database.displayAllPatients();
                break;
            }
            case 10: {
                database.exportToCSV("database.csv");
                break;
            }
            case 11:
                // Save database
                database.exportToCSV("database.csv");
                SaveAndLoadDB::saveDatabaseToFile(database);
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 11);

    return 0;
}
