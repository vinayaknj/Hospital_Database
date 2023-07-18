#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "HospitalDatabase.h"
#include "Patient.h"
#include "Doctor.h"

class inputData {
public:
    void addPatient(HospitalDatabase& database);
    void addDoctor(HospitalDatabase& database);
};

#endif // INPUTDATA_H