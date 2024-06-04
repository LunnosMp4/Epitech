/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** database manager header
*/

#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <thread>
#include <map>
#include <mutex>
#include <chrono>
#include <ctime>
#include <sqlite3.h>

class Database {
    public:
        Database(const std::string& dbPath);
        ~Database();

        static int createTables(const char* s);
        static int insertData(const char* s, const std::string& sqlInsertStatement);
        static int deleteData(const char* s);
        static int updateData(const char* s);
        static int selectData(const char* s);
        bool doesClientExist(int clientID);
        static int callback(void* NotUsed, int argc, char** argv, char** azColName);

    private:
        sqlite3* DB;
};
