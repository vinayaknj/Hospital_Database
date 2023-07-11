#ifndef SAVEANDLOADDB_H
#define SAVEANDLOADDB_H

#include "HospitalDatabase.h"

class SaveAndLoadDB {
public:
    static const std::string DATABASE_FILE;

    static void saveDatabaseToFile(const HospitalDatabase& database);
    static void loadDatabaseFromFile(HospitalDatabase& database);
};

#endif // SAVEANDLOADDB_H
