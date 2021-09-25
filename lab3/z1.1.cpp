#include <iostream>
#include <windows.h>

void disc(int a,int b,int c);

int sqrt(int in);

const char* ERROR_INVALID_COF = "Ошибка: коэффициенты должны быть заданы целыми числами, завершение программы.";

const char* ERROR_INVALID_FIRST_COF = "Ошибка: коэффициент x^2 не может быть равен нулю, завершение программы.";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    try {
        int a = 0, b = 0, c = 0; // Инициализация переменных
        std::cout << "Введите коэффициенты уравнения: ";
        std::cin >> a >> b >> c;
        if (std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
        {
            throw ERROR_INVALID_COF; // Если ввод неверный
        } else {
            if (a == 0) {
                throw ERROR_INVALID_FIRST_COF;
            } else {
                disc(a, b, c); // Запуск функции, если ввод верен
            }
        }
        return 0;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

void disc(int a, int b, int c)
{
    int d = sqrt(b * b - 4 * a * c); // Вычисление корня дискриминанта в отдельной функции
    if(d == -1) // Если дискриминант равен нулю
    {
        std::cout << "Дискриминант меньше нуля, уравнение не имеет корней";
    }
    else if(d == -2) // Удалось ли нахождения целого корня
    {
        std::cout << "Дискриминант - иррациональное число, корни не могут быть вычислены, завершение программы.";
    }
    else
    {
        double x1 = (-b + d) * 1.0 / 2 / a;
        double x2 =  (-b - d) *  1.0 / 2 / a;
        std::cout << "Корни уравнения: " << x1;
        if(x1 != x2) // Проверка на случай, если корни равны, и вывод второго не нужен
        {
            std::cout << " " << x2;
        }
    }
}

int sqrt(int in) // Функция вычисления корня (Только если корень - целое число) c помощью подобия бинарного поиска
{
    if(in < 0) //  Проверка на то, больше ли дискриминант чем ноль
    {
        return -1;
    }
    int left = 1;
    int right = in / 2 + 1;
    int mid = 0;
    int c = 0; // Переменная, которая должна не допустить бесконечной работы цикл при условии того, что корень - дробное число
    while(mid*mid != in && c < right + 5)
    {
        mid = (left + right) / 2;
        if(mid*mid > in)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
        c++;
    }
    if(c > right) // Проверка на то, был ли вычислен корень
    {
        return -2;
    }
    return mid;
}
