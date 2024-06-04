/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** database manager
*/

#include "Database.hpp"

Database::Database(const std::string& dbPath) {
    sqlite3* db;
    int exit = sqlite3_open(dbPath.c_str(), &db);

    if (exit != SQLITE_OK) {
        std::cerr << "Error creating database" << std::endl;
        sqlite3_close(db);
        return;
    } else
        std::cout << "Database created Successfully!" << std::endl;

    sqlite3_close(db);
}

Database::~Database() {
}

int Database::createTables(const char* s) {
    sqlite3* DB;
    char* messageError;
    int exit = 0;

    // SQL command to create the RTYPE table
    std::string sqlRTYPE = "CREATE TABLE IF NOT EXISTS RTYPE("
                           "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                           "NAME TEXT NOT NULL,"
                           "SCORE INTEGER NOT NULL);";

    // SQL command to create the Clients table
    std::string sqlClients = "CREATE TABLE IF NOT EXISTS Clients ("
                             "ClientID INTEGER PRIMARY KEY AUTOINCREMENT,"
                             "Name TEXT NOT NULL,"
                             "LastConnected TEXT);";

    try {
        // Open the database
        exit = sqlite3_open(s, &DB);
        if (exit != SQLITE_OK) {
            std::cerr << "Error opening database" << std::endl;
            return exit;
        }

        // Execute the command to create the RTYPE table
        exit = sqlite3_exec(DB, sqlRTYPE.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            std::cerr << "Error creating RTYPE table: " << messageError << std::endl;
            sqlite3_free(messageError);
        } else {
            std::cout << "RTYPE table created successfully" << std::endl;
        }

        // Execute the command to create the Clients table
        exit = sqlite3_exec(DB, sqlClients.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            std::cerr << "Error creating Clients table: " << messageError << std::endl;
            sqlite3_free(messageError);
        } else {
            std::cout << "Clients table created successfully" << std::endl;
        }

        // Close the database
        sqlite3_close(DB);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}

int Database::insertData(const char* s, const std::string& sqlInsertStatement) {
    sqlite3* DB;
    char* messageError = nullptr;

    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_close(DB);
        return exit;
    }

    exit = sqlite3_exec(DB, sqlInsertStatement.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert: " << messageError << std::endl;
        sqlite3_free(messageError);
    } else {
        std::cout << "Records created Successfully!" << std::endl;
    }
    sqlite3_close(DB);
    return exit;
}


int Database::deleteData(const char* s) {
    sqlite3* DB;

    std::string sql = "DELETE FROM RTYPE WHERE ID = 1;";

    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Delete" << std::endl;
            sqlite3_free(messageError);
        } else
            std::cout << "Records deleted Successfully!" << std::endl;
        sqlite3_close(DB);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
int Database::updateData(const char* s) {
    sqlite3* DB;

    std::string sql = "UPDATE RTYPE SET SCORE = 1000 WHERE ID = 1;";

    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Update" << std::endl;
            sqlite3_free(messageError);
        } else
            std::cout << "Records updated Successfully!" << std::endl;
        sqlite3_close(DB);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

int Database::selectData(const char* s) {
    sqlite3* DB;

    std::string sql = "SELECT * FROM RTYPE";

    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Select" << std::endl;
            sqlite3_free(messageError);
        } else
            std::cout << "Operation done Successfully!" << std::endl;
        sqlite3_close(DB);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

bool Database::doesClientExist(int clientID) {
    sqlite3* DB;
    char* messageError;
    int exit = 0;

    // SQL command to check if a client exists
    std::string sql = "SELECT * FROM Clients WHERE ClientID = " + std::to_string(clientID) + ";";

    try {
        // Open the database
        exit = sqlite3_open("./databases/database.db", &DB);
        if (exit != SQLITE_OK) {
            std::cerr << "Error opening database" << std::endl;
            return false;
        }

        // Execute the command to check if a client exists
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            std::cerr << "Error checking if client exists: " << messageError << std::endl;
            sqlite3_free(messageError);
            return false;
        }

        // Close the database
        sqlite3_close(DB);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

int Database::callback(void* NotUsed, int argc, char** argv, char** azColName) {
    NotUsed = 0;

    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << argv[i] << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
