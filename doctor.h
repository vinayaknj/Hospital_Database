#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

using namespace std;

class Doctor {
private:
    int doctorID;
    string name;
    string specialization;

public:
    Doctor(int doctorID, string name, string specialization);
    int getDoctorID() const;
    string getName() const;
    string getSpecialization() const;
};

#endif  // DOCTOR_H
