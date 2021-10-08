#include <iostream>
#include <windows.h>

bool Ist(int a) //�������� �� ��, ��� �������� �������� ��������� �� ��������� �����
{
    if ((a > 0) and (a < 9))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int X1 = 0, Y1 = 0, i = 0;
    std::cout << "Vvedite gde stoit slon: ";
    std::cin >> X1 >> Y1;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    if (!(Ist(X1) and Ist(Y1)))
    {
        std::cout << "Vvedenie znachenia ne dolgni vihodit za predeli igralnoi doski ili bit otrocatelnimi";
        exit(0);
    }
    std::cout << "Figura budet siedena na sleduyshih tochkah:\n";
    for (i = 1; i < 9; i++)
    {
        if (Ist(X1 - i) and Ist(Y1 - i) and (X1 - i != X1 + i) and (Y1 - i != Y1 + i))
        {
            std::cout << X1 - i << " " << Y1 - i << std::endl;
        }
        if (Ist(X1 + i) and Ist(Y1 + i))
        {
            std::cout << X1 + i << " " << Y1 + i << std::endl;
        }
    }
    return 0;
}