# test_task
Тестовое задание для стажера на направление «Разработчик C++»

Чтобы собрать всё в один исполняемый файл:
	g++ -std=c++17 -o name main.cpp saveload.cpp shortener.cpp -lboost_system

Чтобы сократить ссылку, необходимо в первом терминале запустить ./name и во втором ввести:
	curl -X POST http://localhost:8080/shorten -H "Content-Type: application/json" -d '{"url": "https://exemple.com"}'
Где https://exemple.com - это пример, который необходимо заменить на вашу ссылку

Чтобы перейти по сокращённой сслыке, необходимо ввести в терминале:
	 firefox http://localhost:8080/short_url
Где short_url - это сокращённая ссылка, которую вывела программа
