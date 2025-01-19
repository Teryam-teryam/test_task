#include "shortener.h"


std::string Shortener::generate_random_short_url()
{
	const int len_of_short_url = 10;	//длина генерируемого короткого url
	std::string short_url;
	const std::string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::random_device random_device;	//источник энтропии
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, alph.size()-1 ); //равномерное распределение (вероятности равновозможны)
	for(int i = 0; i < len_of_short_url; i++)
		{
			int x = distribution(generator);
			short_url += alph[x];
		}
	return short_url;
}

std::string Shortener::shorten(const std::string& orign_url, SaveLoad& SaveLoad_obj, const std::string& filename)
{
	std::string short_url;
	do{
		short_url = generate_random_short_url();
	}while(SaveLoad_obj.map_url.find(short_url) != SaveLoad_obj.map_url.end());		//проверка на уникальность
	
	SaveLoad_obj.map_url[short_url] = orign_url;
	SaveLoad_obj.save_to_file(filename);
	return short_url;
}
