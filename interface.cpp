#include "interface.h"

void Interface::displayHelp(const po::options_description& options)
{
    std::cout << options << std::endl;
}

bool Interface::parseArguments(int argc, char* argv[])
{
    po::options_description options("Options");
    options.add_options()
        ("help,h", "Display help")
        ("databaseFile,b", po::value<std::string>()->default_value("urls.txt"), "Path to the URL database")
        ("logFile,l", po::value<std::string>()->default_value("log.txt"), "Path to the log file")
        ("address,a", po::value<std::string>()->default_value("127.0.0.1"), "Address for accessing the service")
        ("port,p", po::value<int>(&serverPort)->default_value(33333), "port");
   
    po::variables_map variableMap;
    try
    {
        po::store(po::parse_command_line(argc, argv, options), variableMap);
        po::notify(variableMap);
        if (serverPort < 1024 || serverPort > 65535)
        {
            throw CritError("Invalid port: " + std::to_string(serverPort) + " Critical error");
        }
    }
    catch (const CritError& e)
    {
        std::cerr << e.what() << std::endl; // Вывод ошибки в консоль
        return false; 											// Завершаем выполнение метода
    }
    catch (const po::unknown_option& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        displayHelp(options);
        return false;
    }

    if (variableMap.count("help"))
    {
        displayHelp(options);
        return true; 
    }

    // Получаем и выводим пути к файлам
    databaseFile = variableMap["databaseFile"].as<std::string>();
    logFile = variableMap["logFile"].as<std::string>();
    address = variableMap["address"].as<std::string>();
    
    std::cout << "Database file path: " << databaseFile << std::endl;
    std::cout << "Log file path: " << logFile << std::endl;
    std::cout << "Address for accessing the service: " << address << std::endl;
    return true;
}
