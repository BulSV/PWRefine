#include <iostream>
#include <vector>
#include <stdlib.h>
#include "include/kuznitsa.h"
#include "include/refine.h"
#include <conio.h>
#include <windows.h>
#include <iomanip>

void inputObjects(std::vector<Kuznitsa> &vk)
{
    int i = 0;
    char cat;
    std::string predmet;
    std::string pro;

    std::cout << "������� �������� ��� �������.\n";

    while(cat != 'q')
    {
        std::cout << "������� � " << i++ << " ��� ����� (q):\n";
        std::cout << "0 - ������, 1 - ����, 2 - �������, 3 - ������, 4 - ������,\n";
        std::cout << "5 - ������, 6 - ����, 7 - ��������, 8 - ����, 9 - ������\n";

        while(1)
        {
            int ch = getch(); // ��������� ������ �� ������, �� �� ������� ��� � �����.
                              // ��� ������ ���� ������ �����
            if( (ch >= '0' && ch <= '9') || ch == 'q')
            {
                cat = ch;
                std::cout << cat;
                std::cin.get();
                break;
            }
        }
        std::cout << std::endl;

        if(cat == 'q') break;

        switch(cat)
        {
        case '0': predmet = "������";
                  break;
        case '1': predmet = "�����";
                  break;
        case '2': predmet = "�������";
                  break;
        case '3': predmet = "�������";
                  break;
        case '4': predmet = "�����";
                  break;
        case '5': predmet = "�������";
                  break;
        case '6': predmet = "�����";
                  break;
        case '7': predmet = "��������";
                  break;
        case '8': predmet = "�����";
                  break;
        case '9': predmet = "������";
                  break;
        default: exit(-7);
        }

        std::cout << "������� �������� " << predmet << ":\n";
        //std::cin.ignore(); // ����������� ����� getline()
        std::getline(std::cin, pro); // ��������� ��� ������ (���� � ���������)
        std::cout << std::endl;

        switch(cat)
        {
        case 'q': break;
        case '0':
            {
                Kuznitsa k(WEAPON, pro);
                vk.push_back(k);
                break;
            }
        case '1':
            {
                Kuznitsa k(SHLEM, pro);
                vk.push_back(k);
                break;
            }
        case '2':
            {
                Kuznitsa k(NAKIDKA, pro);
                vk.push_back(k);
                break;
            }
        case '3':
            {
                Kuznitsa k(BRIDGY, pro);
                vk.push_back(k);
                break;
            }
        case '4':
            {
                Kuznitsa k(SAPOGI, pro);
                vk.push_back(k);
                break;
            }
        case '5':
            {
                Kuznitsa k(NARUCHI, pro);
                vk.push_back(k);
                break;
            }
        case '6':
            {
                Kuznitsa k(PLASCH, pro);
                vk.push_back(k);
                break;
            }
        case '7':
            {
                Kuznitsa k(OZHERELYE, pro);
                vk.push_back(k);
                break;
            }
        case '8':
            {
                Kuznitsa k(POYAS, pro);
                vk.push_back(k);
                break;
            }
        case '9':
            {
                Kuznitsa k(RING, pro);
                vk.push_back(k);
                break;
            }
        default: exit(-8);
        }
    }
}

std::string CATEGORYtoString(CATEGORY cat)
{
    switch(cat)
    {
    case WEAPON: return "������";
                 break;
    case SHLEM: return "����";
                break;
    case NAKIDKA: return "�������";
                  break;
    case BRIDGY: return "������";
                 break;
    case SAPOGI: return "������";
                 break;
    case NARUCHI: return "������";
                  break;
    case PLASCH: return "����";
                 break;
    case OZHERELYE: return "��������";
                    break;
    case POYAS: return "����";
                break;
    case RING: return "������";
               break;
    default: exit(-9);
    }

    return "��� ���������";
}

void refineInfo(TOCHKA t)
{
    switch(t)
    {
    case UDACH: std::cout << "��������� ������ �������!\n";
                break;
    case NEUDACH: std::cout << "��������� �� ������. ������� ������� �������� �� 1 �������.\n";
                  break;
    case NEIZMEN: std::cout << "��������� �� ������. ������� ������� �� ���������.\n";
                  break;
    case RESET: std::cout << "��������� �� ������. ������� ������� �������� �� 0.\n";
                break;
    default: exit(-12);
    }
}

void outputResults(const std::vector<Kuznitsa> &vk)
{
    int mirazh = 0;
    int nebeska = 0;
    int podzemka = 0;
    int mirozdanka = 0;

    //std::cout << "������� �\t���������\t��������\t\t�������\t�������\t�������\t�������� ����������\n";
    std::cout.fill(' ');

    std::cout << std::left << std::setw(10) << "������� �"
    << std::setw(10) << "���������"
    << std::setw(30) << "��������"
    << std::setw(8) << "�������"
    << std::setw(8) << "�������"
    << std::setw(8) << "�������"
    << std::setw(9) << "��������"
    << std::setw(10) << "����������\n";

    std::cout.fill('.');

    for(unsigned int i = 0; i < vk.size(); ++i)
    {
        /*std::cout << i << "\t\t";
        std::cout << CATEGORYtoString(vk.at(i).object()->cat()) << "\t\t";
        std::cout << vk.at(i).object()->pro() << "\t";
        std::cout << vk.at(i).object()->toch() << "\t";
        std::cout << vk.at(i).object()->mirazh() << "\t";
        std::cout << vk.at(i).object()->nebeska() << "\t";
        std::cout << vk.at(i).object()->podzemka() << "\t ";
        std::cout << vk.at(i).object()->mirozdanka() << "\n";*/
        std::cout << std::left << std::setw(9) << i << " ";
        std::cout << std::left << std::setw(9) << CATEGORYtoString(vk.at(i).object()->cat()) << " ";
        std::cout << std::left << std::setw(29) << vk.at(i).object()->pro() << " ";
        std::cout << std::left << std::setw(7) << vk.at(i).object()->toch() << " ";
        std::cout << std::left << std::setw(7) << vk.at(i).object()->mirazh() << " ";
        std::cout << std::left << std::setw(7) << vk.at(i).object()->nebeska() << " ";
        std::cout << std::left << std::setw(8) << vk.at(i).object()->podzemka() << " ";
        std::cout << std::left << std::setw(10) << vk.at(i).object()->mirozdanka();
        std::cout << std::endl;

        mirazh += vk.at(i).object()->mirazh();
        nebeska += vk.at(i).object()->nebeska();
        podzemka += vk.at(i).object()->podzemka();
        mirozdanka += vk.at(i).object()->mirozdanka();
    }

    std::cout << std::setw(57) << "�����:" << " "
    << std::setw(7)<< mirazh << " "
    << std::setw(7) << nebeska << " "
    << std::setw(8) << podzemka << " "
    << std::setw(10) << mirozdanka
    << std::endl << std::endl;
}

void inputNumber(unsigned int &c)
{
    std::cout << c - '0' << '\r';
    char *cNum = new char;
    unsigned int num = 0;

    cNum[0] = c;
    num = c - '0';
    c = getch();

    if(c >= '0' && c <= '9')
    {
        cNum[1] = c;
        num = cNum[0] - '0';
        num *= 10;
        num += cNum[1] - '0';
    }
    else
    {
        std::cin.putback(c);
    }

    c = num;
    cNum = 0;
    delete cNum;
}

void zatochka(std::vector<Kuznitsa> &vk)
{
    unsigned int i = 0;
    char choice;

    while(1)
    {
        std::cout << "������� ���������� ����� �������� ��� ������� ��� ������� ������ ���� ��������� (p):\n";
        while(1)
        {
            unsigned int ch = getch(); // ��������� ������ �� ������, �� �� ������� ��� � �����.
                                       // ��� ������ ���� ������ �����
            if( ch >= '0' && ch <= '9' )
            {
                inputNumber(ch);
                i = ch;
                std::cout << i;
                std::cin.get();
                break;
            }
            if(ch == 'p')
            {
                choice = ch;
                std::cout << choice;
                std::cin.get();
                outputResults(vk);
                std::cout << "������� ���������� ����� �������� ��� ������� ��� ������� ������ ���� ��������� (p):\n";
            }
        }

        std::cout << std::endl;

        if(i >= 0 && i < vk.size())
        {
            int stone = 0;
            Refine r;

            std::cout << "������������ �����?\n\t0 - ������, 1 - �������, 2 - ��������, 3 - ����������\n";

            while(1)
            {
                int ch = getch(); // ��������� ������ �� ������, �� �� ������� ��� � �����.
                                  // ��� ������ ���� ������ �����
                if( ch >= '0' && ch <= '3')
                {
                    stone = ch - '0';
                    std::cout << stone;
                    std::cin.get();
                    break;
                }
            }
            std::cout << std::endl;

            switch(stone)
            {
            case 0:
                {
                    r.goRefining(vk[i].object(), NOSTONE);
                    break;
                }
            case 1:
                {
                    r.goRefining(vk[i].object(), NEBESKA);
                    break;
                }
            case 2:
                {
                    r.goRefining(vk[i].object(), PODZEMKA);
                    break;
                }
            case 3:
                {
                    r.goRefining(vk[i].object(), MIROZDANKA);
                    break;
                }
            default: exit(-11);
            }

            refineInfo(r.refineResult());
        }

        std::cout << "�������� ������ ���� ��������� (p), ���������� ������� (r) ��� ��������� ��������� (q)?\n";

        while(1)
        {
            int ch = getch(); // ��������� ������ �� ������, �� �� ������� ��� � �����.
                              // ��� ������ ���� ������ �����
            if( ch == 'r' || ch == 'q')
            {
                choice = ch;
                std::cout << choice;
                std::cin.get();
                break;
            }
            if(ch == 'p')
            {
                choice = ch;
                std::cout << choice;
                std::cin.get();
                outputResults(vk);
                std::cout << "�������� ������ ���� ��������� (p), ���������� ������� (r) ��� ��������� ��������� (q)?\n";
            }
        }

        if(choice == 'q')
        {
            exit(0);
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Kuznitsa> vk;
    char choice;

    inputObjects(vk);

    while(1)
    {
        std::cout << "��� �������� �������. �������� ������ ���� ��������� (p) ��� ������ ������� (r)?\n";
        while(1)
        {
            int ch = getch(); // ��������� ������ �� ������, �� �� ������� ��� � �����.
                              // ��� ������ ���� ������ �����
            if( ch == 'p' || ch == 'r')
            {
                choice = ch;
                std::cout << choice;
                std::cin.get();
                break;
            }
        }
        std::cout << std::endl;

        switch(choice)
        {
        case 'p': outputResults(vk);
                  break;
        case 'r': zatochka(vk);
                  break;
        default: exit(-10);
        }
    }

    return 0;
}

/* ������� �������� ��� �������.
������� � 1 ��� ����� (q):
    //0 - WEAPON, 1 - SHLEM, 2 - NAKIDKA, 3 - BRIDGY, 4 - SAPOGI, 5 - PLASCH, 6 - OZHERELYE, 7 - POYAS, 8 - RING
    0 - ������, 1 - ����, 2 - �������, 3 - ������, 4 - ������, 5 - ����, 6 - ��������, 7 - ����, 8 - ������
0
������� �������� ������:
������� � ��������

������� � 2 ��� ����� (q):
    //0 - WEAPON, 1 - SHLEM, 2 - NAKIDKA, 3 - BRIDGY, 4 - SAPOGI, 5 - PLASCH, 6 - OZHERELYE, 7 - POYAS, 8 - RING
    0 - ������, 1 - ����, 2 - �������, 3 - ������, 4 - ������, 5 - ����, 6 - ��������, 7 - ����, 8 - ������
0
������� �������� ������:
������� � ��������

...

������� � N ��� ����� (q):
q

��� �������� �������. �������� ������ ���� ��������� (p) ��� ������ ������� (r).
p
������� �   ���������   ��������            �������     �������     �������     ��������    ����������
0           ������      ������� � �������   +0          0           0           0           0
1           ������      ������� � �������   +0          0           0           0           0

��� �������� �������. �������� ������ ���� ��������� (p) ��� ������ ������� (r).
r

������� ���������� ����� �������� ��� ������� ��� ������� ������ ���� ��������� (p):
0

������������:
    0 - ������, 1 - �������, 2 - ��������, 3 - ����������
0

��������� ������ �������!
������� �   ���������   ��������            �������     �������     �������     ��������    ����������
0           ������      ������� � �������   +1          2           0           0           0

���������� ������� (r) ��� ����� (q)?
r

������� ���������� ����� �������� ��� ������� ��� ������� ������ ���� ��������� (p):
1

������������:
    0 - ������, 1 - �������, 2 - ��������, 3 - ����������
1

��������� ������ �������!
������� �   ���������   ��������            �������     �������     �������     ��������    ����������
1           ������      ������� � �������   +1          2           1           0           0

���������� ������� (r) ��� ����� (q)?
q

���������� �������.
������� �   ���������   ��������            �������     �������     �������     ��������    ����������
0           ������      ������� � �������   +1          2           0           0           0
1           ������      ������� � �������   +1          2           1           0           0

�����                                                   4           1           0           0
*/
