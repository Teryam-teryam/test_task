#pragma once
#include <string>
#include <chrono>
#include <random>
#include "saveload.h"
class Shortener
{
private:
	std::string generate_random_short_url();
	//добавить пользовательскую настройку имени
public:
	std::string shorten(const std::string& orign_url, SaveLoad& SaveLoad_obj, const std::string& filename);
}
