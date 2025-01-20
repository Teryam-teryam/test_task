cmake_minimum_required(VERSION 3.10)
project(URLShortener)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system filesystem program_options)
find_package(nlohmann_json 3.2.0 REQUIRED) # Добавляем зависимость от nlohmann/json


include_directories(${Boost_INCLUDE_DIRS})

add_executable(url_shortener main.cpp shortener.cpp saveload.cpp interface.cpp logger.cpp)

target_link_libraries(url_shortener ${Boost_LIBRARIES} nlohmann_json::nlohmann_json) # Линкуем библиотеку JSON
