#pragma once
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "logger.h"
#include "error.h"
namespace po = boost::program_options;
class Interface
{
private:
    int serverPort;
    std::string databaseFile; // Путь к файлу базы данных
    std::string logFile; 			//Путь к файлу журнала
    std::string address; 			//Адрес для доступа к сервису

public:
    Interface() : serverPort(33333), databaseFile("urls.txt"), logFile("log.txt"), address("127.0.0.1") {}
    bool parseArguments(int argc, char* argv[]);
    void displayHelp(const boost::program_options::options_description& options);
		std::string getLogFile() { return logFile; }
		std::string getDatabaseFile() { return databaseFile; }
		int getServerPort() const { return serverPort; }
		std::string getAddress() const { return address; }

};
