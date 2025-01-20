#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "shortener.h"
#include "interface.h" // Подключаем интерфейс
#include <nlohmann/json.hpp> // Подключаем библиотеку JSON

namespace beast = boost::beast;
namespace http = beast::http; // Для HTTP
namespace net = boost::asio; // Для сетевого ввода-вывода
using tcp = boost::asio::ip::tcp; // Для TCP
using json = nlohmann::json; // Упрощаем доступ к json

// Функция обработки HTTP запросов
void handle_request(Shortener& url_shortener, http::request<http::string_body>& req, http::response<http::string_body>& res)
{
    if (req.method() == http::verb::post && req.target() == "/shorten")
    {
        try {
            // Парсим JSON из тела запроса
            auto body = req.body();
            json j = json::parse(body);
            std::string original_url = j.at("url").get<std::string>(); // Извлекаем URL
            std::string short_url = url_shortener.shorten(original_url); // Сокращаем URL
            res.result(http::status::ok);
            res.set(http::field::content_type, "application/json");
            res.body() = json{{"short_url", short_url}}.dump() + "\n"; // Формируем ответ в формате JSON с новой строкой
            res.prepare_payload();
        }
        catch (const std::exception& e)
        {
            res.result(http::status::bad_request);
            res.body() = "Неверный формат JSON";
            res.prepare_payload();
        }
    }
    else if (req.method() == http::verb::get)
    {
        std::string short_url = std::string(req.target().data(), req.target().size()).substr(1); // Извлекаем короткий URL
        std::string original_url = url_shortener.redirect(short_url); // Получаем оригинальный URL
        if (!original_url.empty())
        {
            res.result(http::status::found);
            res.set(http::field::location, original_url); // Устанавливаем заголовок перенаправления
        }
        else
        {
            res.result(http::status::not_found);
            res.body() = "URL не найден"; // Обработка ошибки
        }
        res.prepare_payload();
    }
    else
    {
        res.result(http::status::bad_request);
        res.body() = "Неверный запрос"; // Обработка неверного запроса
        res.prepare_payload();
    }
}

int main(int argc, char* argv[])
{
    Interface interface; // Создаем объект интерфейса
    
    // Парсим аргументы командной строки
    if (!interface.parseArguments(argc, argv)) {
        return EXIT_FAILURE; // Завершение программы в случае ошибки
    }

    // Получаем параметры
    unsigned short port = static_cast<unsigned short>(interface.getServerPort());
    std::string filename = interface.getDatabaseFile();
    std::string logFile = interface.getLogFile();
    std::string address = interface.getAddress(); // Получаем адрес из интерфейса

    try {
        net::io_context ioc; // Контекст ввода-вывода
        tcp::endpoint endpoint(boost::asio::ip::make_address(address), port); // Создаем конечную точку с указанным адресом и портом
        tcp::acceptor acceptor(ioc, endpoint); // Создаем сокет для прослушивания
        Shortener url_shortener(filename); // Инициализация сервиса

        while (true)
        {
            // Ожидаем подключения
            tcp::socket socket(ioc);
            acceptor.accept(socket);

            // Читаем запрос
            beast::flat_buffer buffer;
            http::request<http::string_body> req;
            http::read(socket, buffer, req);

            // Обрабатываем запрос
            http::response<http::string_body> res;
            handle_request(url_shortener, req, res);

            // Отправляем ответ
            http::write(socket, res);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl; // Обработка исключений
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS; // Завершение программы
}
