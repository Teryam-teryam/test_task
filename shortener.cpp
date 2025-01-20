#include "shortener.h"

Shortener::Shortener(const std::string& filename)
{
	saveLoadObj.load_from_file(filename); // Загружаем существующие URL из файла
}

std::string Shortener::generate_random_short_url()
{
	const int len_of_short_url = 10;    	// Длина генерируемого короткого URL
	std::string short_url;
	const std::string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::random_device random_device;   	// Источник энтропии
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, alph.size() - 1); // Равномерное распределение
	for (int i = 0; i < len_of_short_url; i++)
		{
			int x = distribution(generator);
			short_url += alph[x];
		}
	return short_url;
}

std::string Shortener::shorten(const std::string& orign_url)
{
	std::string short_url;
	do{
		short_url = generate_random_short_url();
    }while (saveLoadObj.map_url.find(short_url) != saveLoadObj.map_url.end()); // Проверка на уникальность
	saveLoadObj.map_url[short_url] = orign_url;
	saveLoadObj.save_to_file("urls.txt");	// Сохраняем в файл
	return short_url;
}

std::string Shortener::redirect(const std::string& short_url)
{
	auto it = saveLoadObj.map_url.find(short_url);	//итератор первого вхождения
	if (it != saveLoadObj.map_url.end())
		{
			return it->second; // Возвращаем оригинальный URL
		}
	return ""; // Возвращаем пустую строку, если не найден
}
