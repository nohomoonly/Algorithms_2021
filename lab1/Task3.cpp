#include <iostream>
#include <cmath>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Russian"); //����������� ������� ���������
    SetConsoleOutputCP(CP_UTF8);
    int N = 0, i = 0, k = 0, a = 0, b = 0, c = 0, cmax = 0, amin = 0, bsr = 0;
    bool ist = 0, istDOT = 0;
    std::string A1 = "", B1 = "", C1 = ""; //������� � ���� string
    std::cin >> A1 >> B1 >> C1;
    for (i = 0; i < A1.size(); i++) // �������� ��������� �������� �� ������� ����
    {
        if ((A1[i] >= '0') and (A1[i] <= '9') or ((A1[i] == '-') and (i == 0)) or (A1[i] == '.'))
        {
            ist = 0;
            if (A1[i] == '.')
            {
                istDOT = 1; //�������� �� ������� ����� � �������� ��������
            }
        }
        else
            ist = 1; //����, ������������ ������� ����, ��� ��. ������, �� ����������� � ������
        if (ist != 0)
        {
            std::cout << "������� ������������ ������ ���� ������ �������, ���������� ���������";
            exit(0);
        }
    }
    if (istDOT == 1) //�������� ����� �� ������� ����� � �������� ��������
    {
        std::cout << "������� ������������ ������ ���� ������ ����� �������, ���������� ���������";
        exit(0);
    }
    for (i = 0; i < B1.size(); i++) // �������� ��������� �������� �� ������� ����
    {
        if ((B1[i] >= '0') and (B1[i] <= '9') or ((B1[i] == '-') and (i == 0)) or (B1[i] == '.'))
        {
            ist = 0;
            if (B1[i] == '.')
            {
                istDOT = 1; //�������� �� ������� ����� � �������� ��������
            }
        }
        else
            ist = 1; //����, ������������ ������� ����, ��� ��. ������, �� ����������� � ������
        if (ist != 0)
        {
            std::cout << "������� ������������ ������ ���� ������ �������, ���������� ���������";
            exit(0);
        }
    }
    if (istDOT == 1) //�������� ����� �� ������� ����� � �������� ��������
    {
        std::cout << "������� ������������ ������ ���� ������ ����� �������, ���������� ���������";
        exit(0);
    }
    for (i = 0; i < C1.size(); i++) // �������� ��������� �������� �� ������� ����
    {
        if ((C1[i] >= '0') and (C1[i] <= '9') or ((C1[i] == '-') and (i == 0)) or (C1[i] == '.'))
        {
            ist = 0;
            if (C1[i] == '.')
            {
                istDOT = 1; //�������� �� ������� ����� � �������� ��������
            }
        }
        else
            ist = 1; //����, ������������ ������� ����, ��� ��. ������, �� ����������� � ������
        if (ist != 0)
        {
            std::cout << "������� ������������ ������ ���� ������ �������, ���������� ���������";
            exit(0);
        }
    }
    if (istDOT == 1) //�������� ����� �� ������� ����� � �������� ��������
    {
        std::cout << "������� ������������ ������ ���� ������ ����� �������, ���������� ���������";
        exit(0);
    }
    if (A1[0] == '-') //�������� �� ������� ������ ����� ������
        k = 1;
    else
        k = 0;
    for (i = k; i < A1.size(); i++) //����������� ����� �� char � int
    {
        a = int(A1[i]) - '0' + a * 10;
    }
    if (k == 1) //��� ������� ������ � ���� char, ���������� ����� � int ���������� �� -1
        a *= -1;
    if (a <= 0) // �������� �� ������������� ������� ������������
    {
        std::cout << "������� ������������ ������ ���� ������ �������������� �������, ���������� ���������";
        exit(0);
    }
    if (B1[0] == '-')
        k = 1;
    else
        k = 0;
    for (i = k; i < B1.size(); i++)
    {
        b = int(B1[i]) - '0' + b * 10;
    }
    if (k == 1)
        b *= -1;
    if (b <= 0)
    {
        std::cout << "������� ������������ ������ ���� ������ �������������� �������, ���������� ���������";
        exit(0);
    }
    if (C1[0] == '-')
        k = 1;
    else
        k = 0;
    for (i = k; i < C1.size(); i++)
    {
        c = int(C1[i]) - '0' + c * 10;
    }
    if (k == 1)
        c *= -1;
    if (c <= 0)
    {
        std::cout << "������� ������������ ������ ���� ������ �������������� �������, ���������� ���������";
        exit(0);
    }
    cmax = max(c, max(a, b)); //������� � ������������ �������
    amin = min(c, min(a, b)); //������� � ����������� �������
    bsr = a + b + c - cmax - amin; //������� �� ������� �������
    if (bsr + amin <= cmax) //�������� �� ������������� ������������
    {
        std::cout << "����������� c ������ ��������� �������� ������, ���������� ���������";
        exit(0);
    }
    else
        if (pow(cmax, 2) == pow(amin, 2) + pow(bsr, 2)) // �������� �� ������������� ����������� �.�.�
            std::cout << "����������� �������������";
        else
            if (pow(cmax, 2) > pow(amin, 2) + pow(bsr, 2))
                std::cout << "����������� ������������";
            else
                if (pow(cmax, 2) < pow(amin, 2) + pow(bsr, 2))
                    std::cout << "����������� �������������";
    if ((cmax == amin) and (amin == bsr))
        std::cout << " � ��������������";
    else
        if ((cmax == amin) or (amin == bsr) or (cmax == bsr))
            std::cout << " � ��������������";
    return 0;
}