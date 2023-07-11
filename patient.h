#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient {
private:
    int patientID;
    string name;
    int age;
    string contactNumber;
    int assignedDoctorID;

public:
    Patient(int patientID, string name, int age, string contactNumber, int assignedDoctorID);
    int getPatientID() const;
    string getName() const;
    int getAge() const;
    string getContactNumber() const;
    int getAssignedDoctorID() const;
    void setAssignedDoctorID(int doctorID);
};

#endif  // PATIENT_H
