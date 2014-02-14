#include <iostream>
#include <vector>
#include <stdlib.h>
#include "include/kuznitsa.h"
#include "include/refine.h"
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "include/iochecker.h"
#include <stdlib.h>

void inputObjects(std::vector<Kuznitsa> &vk)
{
    int i = 0;
    char cat;
    std::string predmet;
    std::string pro;

    std::cout << "������ �।���� ��� ���窨.\n";
    std::cout << "�।��� � " << i++ << ":\n";

    while(1)
    {

        std::cout << "0 - ��㦨�, 1 - ����, 2 - �������, 3 - �ਤ��, 4 - ������,\n";
        std::cout << "5 - �����, 6 - ����, 7 - ���५�, 8 - ����, 9 - �����\n";

        std::vector<unsigned char> vInput;
        iochecker ioInput(1, &vInput, "0123456789q");

        ioInput.check(_getch());

        if(iochecker::isDigit(ioInput.charBuffer(iochecker::ALLZEROS)))
        {
            cat = (char)iochecker::stoi(ioInput.charBuffer(iochecker::ALLZEROS));
        }
        else
        {
            cat = ioInput.buffer(iochecker::ALLZEROS).at(0);
        }

        if(cat == 'q')
        {
            std::cout << std::endl;
            std::cin.get();
            break;
        }

        switch(cat)
        {
        case 0: predmet = "��㦨�";
                  break;
        case 1: predmet = "諥��";
                  break;
        case 2: predmet = "�������";
                  break;
        case 3: predmet = "�ਤ���";
                  break;
        case 4: predmet = "ᠯ��";
                  break;
        case 5: predmet = "����祩";
                  break;
        case 6: predmet = "����";
                  break;
        case 7: predmet = "���५��";
                  break;
        case 8: predmet = "����";
                  break;
        case 9: predmet = "�����";
                  break;
        default: exit(-7);
        }

        std::cout << "\n������ �������� " << predmet << ":\n";
        std::cin.ignore(); // ��易⥫쭮 ��। getline()
        std::getline(std::cin, pro); // ���뢠�� ��� ��ப� (���� � �஡�����)
        std::cout << std::endl;

        switch(cat)
        {
        case 0:
            {
                Kuznitsa k(WEAPON, pro);
                vk.push_back(k);
                break;
            }
        case 1:
            {
                Kuznitsa k(SHLEM, pro);
                vk.push_back(k);
                break;
            }
        case 2:
            {
                Kuznitsa k(NAKIDKA, pro);
                vk.push_back(k);
                break;
            }
        case 3:
            {
                Kuznitsa k(BRIDGY, pro);
                vk.push_back(k);
                break;
            }
        case 4:
            {
                Kuznitsa k(SAPOGI, pro);
                vk.push_back(k);
                break;
            }
        case 5:
            {
                Kuznitsa k(NARUCHI, pro);
                vk.push_back(k);
                break;
            }
        case 6:
            {
                Kuznitsa k(PLASCH, pro);
                vk.push_back(k);
                break;
            }
        case 7:
            {
                Kuznitsa k(OZHERELYE, pro);
                vk.push_back(k);
                break;
            }
        case 8:
            {
                Kuznitsa k(POYAS, pro);
                vk.push_back(k);
                break;
            }
        case 9:
            {
                Kuznitsa k(RING, pro);
                vk.push_back(k);
                break;
            }
        default: exit(-8);
        }

        std::cout << "������ �஢��� ���窨:\n";

        std::vector<unsigned char> vTochka;
        iochecker ioTochka(2, &vTochka, "0123456789");

        while(1)
        {
			ioTochka.check(_getch());

            unsigned int tochka = iochecker::stoi(ioTochka.charBuffer(iochecker::ALLZEROS));

            vk[vk.size() - 1].object()->setToch(tochka);
            std::cin.get();
            break;
        }
        std::cout << std::endl;
        std::cout << "�।��� � " << i++ << " ��� ��室 (q):\n";
    }
}

std::string CATEGORYtoString(CATEGORY cat)
{
    switch(cat)
    {
    case WEAPON: return "��㦨�";
                 break;
    case SHLEM: return "����";
                break;
    case NAKIDKA: return "�������";
                  break;
    case BRIDGY: return "�ਤ��";
                 break;
    case SAPOGI: return "������";
                 break;
    case NARUCHI: return "�����";
                  break;
    case PLASCH: return "����";
                 break;
    case OZHERELYE: return "���५�";
                    break;
    case POYAS: return "����";
                break;
    case RING: return "�����";
               break;
    default: exit(-9);
    }

    return "��� ��⥣�ਨ";
}

void refineInfo(TOCHKA t)
{
    switch(t)
    {
    case UDACH: std::cout << "����襭�� ��諮 �ᯥ譮!\n";
                break;
    case NEUDACH: std::cout << "����襭�� �� ��諮. �஢��� ���窨 ᭨����� �� 1 �஢���.\n";
                  break;
    case NEIZMEN: std::cout << "����襭�� �� ��諮. �஢��� ���窨 �� ���������.\n";
                  break;
    case RESET: std::cout << "����襭�� �� ��諮. �஢��� ���窨 ᭨����� �� 0.\n";
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

    std::cout.fill(' ');

    std::cout << std::left << std::setw(10) << "�।��� �"
    << std::setw(10) << "��⥣���"
    << std::setw(30) << "���ᠭ��"
    << std::setw(8) << "���窠"
    << std::setw(8) << "��ࠦ��"
    << std::setw(8) << "����᮪"
    << std::setw(9) << "��������"
    << std::setw(10) << "��஧�����\n";

    std::cout.fill('.');

    for(unsigned int i = 0; i < vk.size(); ++i)
    {
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

    std::cout << std::setw(57) << "�ᥣ�:" << " "
    << std::setw(7)<< mirazh << " "
    << std::setw(7) << nebeska << " "
    << std::setw(8) << podzemka << " "
    << std::setw(10) << mirozdanka
    << std::endl << std::endl;
}

void zatochka(std::vector<Kuznitsa> &vk)
{
    unsigned int i = 0;
    char choice;

    while(1)
    {
        std::cout << "������ ���浪��� ����� �।��� ��� ���窨 ��� �뢥�� ᯨ᮪ ��� �।��⮢ (p):\n";

        while(1)
        {
            std::vector<unsigned char> vRN;
            iochecker ioRN(2, &vRN, "0123456789pp");

            ioRN.check(_getch());

            if(iochecker::isDigit(ioRN.charBuffer(iochecker::ALLZEROS)))
            {
                i = iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS));

                std::cin.get();
                break;
            }
            else
            {
                std::cin.get();
                std::cout << std::endl;
                outputResults(vk);
                std::cout << "������ ���浪��� ����� �।��� ��� ���窨 ��� �뢥�� ᯨ᮪ ��� �।��⮢ (p):\n";
            }
        }

        std::cout << std::endl;

        if(i >= 0 && i < vk.size())
        {
            int stone = 0;
            Refine r;

            std::cout << "�ᯮ�짮���� �����?\n\t0 - ��祣�, 1 - ������, 2 - ��������, 3 - ��஧�����\n";

            while(1)
            {
                std::vector<unsigned char> vStones;
                iochecker ioStones(1, &vStones, "0123");

                ioStones.check(_getch());

                int ch = iochecker::stoi(ioStones.charBuffer(iochecker::ALLZEROS));

                stone = ch;
                std::cin.get();
                break;
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

        std::cout << "�������� ᯨ᮪ ��� �।��⮢ (p), �த������ ����� (r) ��� �������� �ணࠬ�� (q)?\n";

        while(1)
        {
            std::vector<unsigned char> vPRQ;
            iochecker ioPRQ(1, &vPRQ, "prq");

            ioPRQ.check(_getch());

            int ch = ioPRQ.buffer(iochecker::ALLZEROS).at(0);

            if( ch == 'r' || ch == 'q')
            {
                choice = ch;
                std::cin.get();
                std::cout << std::endl;
                break;
            }
            if(ch == 'p')
            {
                choice = ch;
                std::cin.get();
                std::cout << std::endl;
                outputResults(vk);
                std::cout << "�������� ᯨ᮪ ��� �।��⮢ (p), �த������ ����� (r) ��� �������� �ணࠬ�� (q)?\n";
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
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    std::vector<Kuznitsa> vk;
    char choice;

    inputObjects(vk);

    while(1)
    {
        std::cout << "�� �।���� �������. �������� ᯨ᮪ ��� �।��⮢ (p) ��� ����� ����� (r)?\n";
        while(1)
        {
            int ch = _getch(); // ���뢠�� ᨬ��� �� ��⮪�, �� �� �뢮��� ��� � ��⮪.
                              // �� ᢮��� த� ���� �����
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

/* ������ �।���� ��� ���窨.
�।��� � 1 ��� ��室 (q):
    //0 - WEAPON, 1 - SHLEM, 2 - NAKIDKA, 3 - BRIDGY, 4 - SAPOGI, 5 - PLASCH, 6 - OZHERELYE, 7 - POYAS, 8 - RING
    0 - ��㦨�, 1 - ����, 2 - �������, 3 - �ਤ��, 4 - ������, 5 - ����, 6 - ���५�, 7 - ����, 8 - �����
0
������ �������� ��㦨�:
������ � �����ﬨ

�।��� � 2 ��� ��室 (q):
    //0 - WEAPON, 1 - SHLEM, 2 - NAKIDKA, 3 - BRIDGY, 4 - SAPOGI, 5 - PLASCH, 6 - OZHERELYE, 7 - POYAS, 8 - RING
    0 - ��㦨�, 1 - ����, 2 - �������, 3 - �ਤ��, 4 - ������, 5 - ����, 6 - ���५�, 7 - ����, 8 - �����
0
������ �������� ��㦨�:
������ � �����ﬨ

...

�।��� � N ��� ��室 (q):
q

�� �।���� �������. �������� ᯨ᮪ ��� �।��⮢ (p) ��� ����� ����� (r).
p
�।��� �   ��⥣���   ���ᠭ��            ���窠     ��ࠦ��     ����᮪     ��������    ��஧�����
0           ��㦨�      ������ � �������   +0          0           0           0           0
1           ��㦨�      ������ � �������   +0          0           0           0           0

�� �।���� �������. �������� ᯨ᮪ ��� �।��⮢ (p) ��� ����� ����� (r).
r

������ ���浪��� ����� �।��� ��� ���窨 ��� �뢥�� ᯨ᮪ ��� �।��⮢ (p):
0

�ᯮ�짮����:
    0 - ��祣�, 1 - ������, 2 - ��������, 3 - ��஧�����
0

����襭�� ��諮 �ᯥ譮!
�।��� �   ��⥣���   ���ᠭ��            ���窠     ��ࠦ��     ����᮪     ��������    ��஧�����
0           ��㦨�      ������ � �������   +1          2           0           0           0

�த������ ����� (r) ��� ��室 (q)?
r

������ ���浪��� ����� �।��� ��� ���窨 ��� �뢥�� ᯨ᮪ ��� �।��⮢ (p):
1

�ᯮ�짮����:
    0 - ��祣�, 1 - ������, 2 - ��������, 3 - ��஧�����
1

����襭�� ��諮 �ᯥ譮!
�।��� �   ��⥣���   ���ᠭ��            ���窠     ��ࠦ��     ����᮪     ��������    ��஧�����
1           ��㦨�      ������ � �������   +1          2           1           0           0

�த������ ����� (r) ��� ��室 (q)?
q

�������� ���窨.
�।��� �   ��⥣���   ���ᠭ��            ���窠     ��ࠦ��     ����᮪     ��������    ��஧�����
0           ��㦨�      ������ � �������   +1          2           0           0           0
1           ��㦨�      ������ � �������   +1          2           1           0           0

�ᥣ�                                                   4           1           0           0
*/
