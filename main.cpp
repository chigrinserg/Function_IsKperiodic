#include <iostream>
#include <string>

void IsKPeriodic(std::string& text, int k)
{
    int count = 0; //переменная счетчика чиста вхождений подстроки в строку
    size_t position = 0;  //позиция вхождения подстроки в строку
    std::string subtext = text.substr(0, k); //извлечние начальной подстроки длиной k символов
    for (unsigned i{}; i <= text.length() - k; ++i) //цикл подсчета числа вхождений подстроки в строку
    {
        size_t position = text.find(subtext, i);
        if (position == std::string::npos) break;
        i = position + 1;
        ++count;
    }
    std::cout << "Заданное целевое число К равно " << k << '\n';
    std::cout << '\n';
    if ((text.length() % count == 0)) //определение кратности
    { std::cout << "Строка " << text << " является кратной заданному целевому числу К " << '\n';   }
    else
    { std::cout << "Строка " << text << " непериодическая и кратной заданному целевому числу не является "<< "\n"; }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::string text{ "cabcabcabс" };
    IsKPeriodic(text, 3);
    return 0;
}