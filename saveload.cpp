#include "saveload.h"

void SaveLoad::load_from_file(const std::string& filename)
{
	std::ifstream file_for_load(filename);	//открывает файл для чтения
	//добавить проверку на правильное открытие
	std::string line;
	while (std::getline(file_for_load, line))
		{
			size_t position = line.find(' ');		//позиция символа-разделителя
			std::string short_url = line.substr(0,position);
			std::string orign_url = line.substr(position+1);
			map_url[short_url] = origin_url;
		}
	file_for_load.close();
}
void SaveLoad::save_to_file(const std::string& filename)
{
	std::ofstream file_for_save(filename);
	//добавить проверку на правильное открытие
	for (const std::pair<std::string, std::string>& short_orign_pair : url_map)
		{
			file_for_save << short_orign_pair.first << " " << short_orign_pair.second << "\n";
		}
	file_for_save.close();
}
