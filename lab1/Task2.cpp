#include <iostream>
#include <windows.h>


int main()
{
    setlocale(LC_ALL, "Russian"); //����������� ������� ���������
    SetConsoleOutputCP(CP_UTF8);
    int N = 0, i = 0, k = 0;
    bool ist = 0, istDOT = 0;
    std::string N1 = "";
    std::cin >> N1;
    for (i = 0; i < N1.size(); i++) // �������� ��������� �������� �� ������� ����
    {
        if ((N1[i] >= '0') and (N1[i] <= '9') or ((N1[i] == '-') and (i == 0)) or (N1[i] == '.'))
        {
            ist = 0;
            if (N1[i] == '.')
            {
                istDOT = 1; //�������� �� ������� ����� � �������� ��������
            }
        }
        else
            ist = 1; //����, ������������ ������� ����, ��� ��. ������, �� ����������� � ������
        if (ist != 0)
        {
            std::cout << "����� ����� � ���� ������ ���� ������ ������, ���������� ���������";
            exit(0);
        }
    }
    if (istDOT == 1) //�������� ����� �� ������� ����� � �������� ��������
    {
        std::cout << "����� ����� � ���� ������ ���� ������ ����� ������, ���������� ���������";
        exit(0);
    }
    if (N1[0] == '-') //�������� �� ������� ������ ����� ������ � string
        k = 1;
    else
        k = 0;
    for (i = k; i < N1.size(); i++) //����������� ����� �� char � int
    {
        N = int(N1[i]) - '0' + N * 10;
    }
    if (k == 1) //��� ������� ������ � ���� char, ���������� ����� � int ���������� �� -1
        N *= -1;
    if (N <= 0) // �������� �� ������������� �����
    {
        std::cout << "����� ����� ������ ���� ������ ������������� ������, ���������� ���������";
        exit(0);
    }
    if (((N >= 5) and (N <= 20)) or (N % 10 == 0) or (N % 10 == 5) or (N % 10 == 6) or (N % 10 == 7) or (N % 10 == 8) or (N % 10 == 9))
    {
        std::cout << "� ���� " << N << " �����";
        exit(0);
    }
    if ((N % 10 == 2) or (N % 10 == 3) or (N % 10 == 4)) //����� ���������� ������ ������ �� ������� ��������
    {
        std::cout << "� ���� " << N << " ������";
        exit(0);
    }
    if (N % 10 == 1)
    {
        std::cout << "� ���� " << N << " ������";
    }
    return 0;
}