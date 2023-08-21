#include <iostream>
#include <string>
#include <algorithm>

void IsKPeriodic(std::string& text, int k)
{
    int count = 0; //переменная счетчика чиста вхождений подстроки в строку
    size_t position = 0;  //позиция вхождения подстроки в строку
    if (text.length() == 0) //проверка на пустую строку
    {
        std::cout << "Пустая строка проверке на кратность не подлежит "<< '\n';
        return;
    }
    std::string subtext = text.substr(0, k); //извлечние начальной подстроки длиной k символов
    std::cout << "Подстрока: " << subtext << '\n';
    for (std::string::size_type i = 0; i < text.length(); ++i) //поиск числа вхождений подстроки в строку:
        if (text[i] == subtext[0])
        {
            if (text.substr(i, subtext.length()) == subtext)
            {
                ++count;
                i += subtext.length() - 1;
            }
        }
    std::cout << '\n';
    std::cout << "Длина строки: " << text.length() << '\n';
    std::cout << "Длина подстроки: " << subtext.length() << '\n';
    std::cout << "Число вхождений подстроки в строку: " << count << '\n';
    std::cout << "Заданное целевое число К равно " << k << '\n';
    std::cout << '\n';
    if ((subtext.length() * count)== text.length()) 
    {
        std::cout << "Строка " << text << " является кратной заданному целевому числу К " << '\n';
    }
    else
    {
        std::cout << "Строка " << text << " непериодическая и кратной заданному целевому числу не является "<< "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::string text{ "qwertyqwerty" };
    IsKPeriodic(text, 3);
	return 0;
}

