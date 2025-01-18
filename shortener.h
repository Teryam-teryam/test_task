#pragma once
#include <string>
#include <chrono>
#include <random>
class Shortener
{
private:
	std::string generate_random_short_url();
	//добавить пользовательскую настройку имени
public:
	std::string shorten(const std::string& orign_url);
}
