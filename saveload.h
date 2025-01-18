#pragma once
#include <string>
#include <map>
#include <fstream>
class SaveLoad
{
public:
	std::map<std::string, std::string> map_url; // пары ключ:значение дял хранения сокращённого и полного URL
	void save_to_file(const std::string& filename);
	void load_from_file(const std::string& filename);
}
