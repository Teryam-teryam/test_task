#pragma once
#include <string>
#include <chrono>
#include <random>
#include "saveload.h"

class Shortener
{
private:
    SaveLoad saveLoadObj; 										// Объект для сохранения и загрузки
    std::string generate_random_short_url(); 	// Генерация случайного короткого URL
public:
    Shortener(const std::string& filename); 	// Конструктор для инициализации SaveLoad
    std::string shorten(const std::string& orign_url); 		// Метод для сокращения URL
    std::string redirect(const std::string& short_url); 	// Метод для получения оригинального URL
};
