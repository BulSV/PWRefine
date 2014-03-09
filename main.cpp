#include <iostream>
#include <vector>
#include <stdlib.h>
#include "include/kuznitsa.h"
#include "include/kuznitsabridgey.h"
#include "include/kuznitsakolets.h"
#include "include/kuznitsanakidok.h"
#include "include/kuznitsanaruchey.h"
#include "include/kuznitsaoruzhiya.h"
#include "include/kuznitsaozherelyev.h"
#include "include/kuznitsaplaschey.h"
#include "include/kuznitsapoyasov.h"
#include "include/kuznitsasapog.h"
#include "include/kuznitsashlemov.h"
#include "include/refine.h"
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "include/iochecker.h"
#include <stdlib.h>

//==============================================================================
char* cp1251to866(char *c)
{
	int i = 0;

	while(*c)
	{
		if(*c >= -16 && *c <= -1)
		{
			*c -= 16;
		}
		else if(*c <= -17 && *c >= -64)
		{
			*c -= 64;
		}
		c++;
		i++;
	}

	while(i--)
	{
		c--;
	}

	return c;
}
//==============================================================================
char* cp866to1251(char *c)
{
    int i = 0;
    while(*c)
    {
        if(*c > -33 && *c < -16)
        {
            *c += 16;
        }
        else if(*c < -80 && *c > -129)
        {
            *c += 64;
        }
        c++;
        i++;
    }

    while(i--)
    {
        c--;
    }

    return c;
}
//==============================================================================

void inputDospehs(std::vector<Dospeh*> &vd)
{
    int i = 0;
    char cat;
    std::string predmet;
    std::string pro;
    std::vector<Kuznitsa*> vk;

    std::string messages = "������� �������� ��� �������.";
    std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
    messages = "������� � ";
    std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << i++ << ":\n";

    while(1)
    {

        messages = "0 - ������, 1 - ����, 2 - �������, 3 - ������, 4 - ������,";
    	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
    	messages = "5 - ������, 6 - ����, 7 - ��������, 8 - ����, 9 - ������";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";

        std::vector<char> vInput;
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
        case 0:
        {
        	messages = "������";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 1:
        {
        	messages = "�����";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 2:
        {
        	messages = "�������";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 3:
        {
        	messages = "�������";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 4:
        {
        	messages = "�����";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 5:
        {
        	messages = "�������";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 6:
        {
        	messages = "�����";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 7:
        {
        	messages = "��������";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 8:
        {
        	messages = "�����";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 9:
        {
        	messages = "������";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        default: exit(-7);
        }

        messages = "������� �������� ";
        std::cout << "\n" << cp1251to866(const_cast<char*>(messages.c_str())) << predmet;
        messages = " (��� ENTER):\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
        std::cin.ignore(); // ����������� ����� getline()
        /*std::getline(std::cin, pro); // ��������� ��� ������ (���� � ���������)
        std::cout << std::endl;*/
        int t2 = _getch();
        if(t2 != 13)
        {
            std::vector<char> vPro;
            messages = "�������������������������������������Ũ�������������������������� ";
            const char *c = cp1251to866(const_cast<char*>(messages.c_str()));

            iochecker ioPro(29, &vPro, c);
            ioPro.check(t2);
            std::cout << std::endl;
            pro = ioPro.stringBuffer(iochecker::ALLZEROS);
        }
        else
        {
            std::cin.putback(t2);
        }
        std::cin.ignore();
        Kuznitsa *k = 0;

        switch(cat)
        {
        case 0:
        {
            k = KuznitsaOruzhiya::getInstance();
            break;
        }
        case 1:
        {
            k = KuznitsaShlemov::getInstance();
            break;
        }
        case 2:
        {
            k = KuznitsaNakidok::getInstance();
            break;
        }
        case 3:
        {
            k = KuznitsaBridgey::getInstance();
            break;
        }
        case 4:
        {
            k = KuznitsaSapog::getInstance();
            break;
        }
        case 5:
        {
            k = KuznitsaNaruchey::getInstance();
            break;
        }
        case 6:
        {
            k = KuznitsaPlaschey::getInstance();
            break;
        }
        case 7:
        {
            k = KuznitsaOzherelyev::getInstance();
            break;
        }
        case 8:
        {
            k = KuznitsaPoyasov::getInstance();
            break;
        }
        case 9:
        {
            k = KuznitsaKolets::getInstance();
            break;
        }
        default: exit(-8);
        }

        vk.push_back(k);

        messages = "������� ������� ������� (��� ENTER):\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

        int t = _getch();
        int tochka = 0;
        if(t != 13)
        {
            std::vector<char> vTochka;
            iochecker ioTochka(2, &vTochka, "0123456789");

            ioTochka.check(t);
            tochka = iochecker::stoi(ioTochka.charBuffer(iochecker::ALLZEROS));
        }
        else
        {
            std::cin.putback(t);
        }        

        Dospeh *d = vk[vk.size() - 1]->createDospeh(pro);
        d->setToch(tochka);
        vd.push_back(d);
        std::cin.get();

        std::cout << std::endl;
        messages = "������� � ";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << i++;
        messages = " ��� ����� (q):\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
    }
}

std::string CATEGORYtoString(CATEGORY cat)
{
	std::string messages;

	switch(cat)
	{
	case WEAPON:
	{
		messages = "������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case SHLEM:
	{
		messages = "����";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NAKIDKA:
	{
		messages = "�������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case BRIDGY:
	{
		messages = "������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case SAPOGI:
	{
		messages = "������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NARUCHI:
	{
		messages = "������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case PLASCH:
	{
		messages = "����";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case OZHERELYE:
	{
		messages = "��������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case POYAS:
	{
		messages = "����";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case RING:
	{
		messages = "������";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	default: exit(-9);
	}

	messages = "��� ���������";
	return cp1251to866(const_cast<char*>(messages.c_str()));
}

void refineInfo(TOCHKA t)
{
	std::string messages;

	switch(t)
	{
	case UDACH:
	{
		messages = "��������� ������ �������!\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NEUDACH:
	{
		messages = "��������� �� ������. ������� ������� �������� �� 1 �������.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NEIZMEN:
	{
		messages = "��������� �� ������. ������� ������� �� ���������.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case RESET:
	{
		messages = "��������� �� ������. ������� ������� �������� �� 0.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	default: exit(-12);
	}
}

void outputResults(const std::vector<Dospeh*> &vk)
{
    int mirazh = 0;
    int nebeska = 0;
    int podzemka = 0;
    int mirozdanka = 0;

    std::string messages;

    std::cout.fill(' ');

    messages = "������� �";
    std::cout << std::left << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "���������";
    std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "��������";
    std::cout << std::setw(30) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "�������";
    std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "�������";
    std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "�������";
    std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "��������";
    std::cout << std::setw(9) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "����������\n";
    std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));

    std::cout.fill('.');

    for(unsigned int i = 0; i < vk.size(); ++i)
    {
        std::cout << std::left << std::setw(9) << i << " ";
        std::cout << std::left << std::setw(9) << CATEGORYtoString(vk.at(i)->cat()) << " ";
        std::cout << std::left << std::setw(29) << vk.at(i)->pro() << " ";
        std::cout << std::left << std::setw(7) << vk.at(i)->toch() << " ";
        std::cout << std::left << std::setw(7) << vk.at(i)->mirazh() << " ";
        std::cout << std::left << std::setw(7) << vk.at(i)->nebeska() << " ";
        std::cout << std::left << std::setw(8) << vk.at(i)->podzemka() << " ";
        std::cout << std::left << std::setw(10) << vk.at(i)->mirozdanka();
        std::cout << std::endl;

        mirazh += vk.at(i)->mirazh();
        nebeska += vk.at(i)->nebeska();
        podzemka += vk.at(i)->podzemka();
        mirozdanka += vk.at(i)->mirozdanka();
    }

    messages = "�����:";
    std::cout << std::setw(57) << cp1251to866(const_cast<char*>(messages.c_str())) << " "
              << std::setw(7)<< mirazh << " "
              << std::setw(7) << nebeska << " "
              << std::setw(8) << podzemka << " "
              << std::setw(10) << mirozdanka
              << std::endl << std::endl;
}

void outputResults(const std::vector<Dospeh*> &vk, int i)
{
    std::cout.fill(' ');

    std::string messages;

    messages = "������� �";
    std::cout << std::left << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "���������";
    std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "��������";
    std::cout << std::setw(30) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "�������";
    std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "�������";
    std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "�������";
    std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "��������";
    std::cout << std::setw(9) << cp1251to866(const_cast<char*>(messages.c_str()));
    messages = "����������\n";
    std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));

    std::cout.fill('.');

    std::cout << std::left << std::setw(9) << i << " ";
    std::cout << std::left << std::setw(9) << CATEGORYtoString(vk.at(i)->cat()) << " ";
    std::cout << std::left << std::setw(29) << vk.at(i)->pro() << " ";
    std::cout << std::left << std::setw(7) << vk.at(i)->toch() << " ";
    std::cout << std::left << std::setw(7) << vk.at(i)->mirazh() << " ";
    std::cout << std::left << std::setw(7) << vk.at(i)->nebeska() << " ";
    std::cout << std::left << std::setw(8) << vk.at(i)->podzemka() << " ";
    std::cout << std::left << std::setw(10) << vk.at(i)->mirozdanka();
    std::cout << std::endl;

    std::cout << std::endl;
}

void backspace(int count)
{
    while(count--)
    {
        std::cout << (char)8 << " " << (char)8;
    }
}

void zatochka(std::vector<Dospeh*> &vd)
{
    unsigned int i = 0;
    char choice;
    std::string messages;

    while(1)
    {
        messages = "������� ���������� ����� �������� ��� �������:\n";
    	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

        while(1)
        {
            std::vector<char> vRN;
            iochecker ioRN(2, &vRN, "0123456789");

            ioRN.check(_getch());

            if(iochecker::isDigit(ioRN.charBuffer(iochecker::ALLZEROS))
                    && iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS)) < vd.size())
            {
                i = iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS));

                std::cin.get();
                break;
            }

            backspace(2);
        }

        std::cout << std::endl << std::endl;
        outputResults(vd, i);

        if(i >= 0 && i < vd.size())
        {
            int stone = 0;
            Refine r;

            messages = "������������ �����?\n\t0 (��� ENTER) - ������, 1 - �������, 2 - ��������, 3 - ����������\n";
            std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

            unsigned int t = _getch();
            if(t != 13)
            {
                std::vector<char> vStones;
                iochecker ioStones(1, &vStones, "0123");

                ioStones.check(t);

                stone = iochecker::stoi(ioStones.charBuffer(iochecker::ALLZEROS));
            }
            else
            {
                std::cin.putback(t);
            }

            std::cin.get();
            std::cout << std::endl;

            switch(stone)
            {
            case 0:
            {
                r.goRefining(vd[i], NOSTONE);
                break;
            }
            case 1:
            {
                r.goRefining(vd[i], NEBESKA);
                break;
            }
            case 2:
            {
                r.goRefining(vd[i], PODZEMKA);
                break;
            }
            case 3:
            {
                r.goRefining(vd[i], MIROZDANKA);
                break;
            }
            default: exit(-11);
            }

            refineInfo(r.refineResult());
        }

        std::cout << std::endl;
        outputResults(vd, i);
        std::cout << std::endl;
        messages = "�������� ������ ���� ��������� (p), ���������� ������� (r ��� ENTER) ��� ��������� ��������� (q)?\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

        int t2;
        int ch;

        while(1)
        {
            t2 = _getch();
            if(t2 != 13)
            {
                std::vector<char> vPRQ;
                iochecker ioPRQ(1, &vPRQ, "prq");

                ioPRQ.check(t2);

                ch = ioPRQ.buffer(iochecker::ALLZEROS).at(0);
            }
            else if(t2 == 13)
            {
                std::cin.putback(t2);
                ch = 'r';
            }

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

                outputResults(vd);
                messages = "�������� ������ ���� ��������� (p), ���������� ������� (r ��� ENTER) ��� ��������� ��������� (q)?\n";
                std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
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
    std::vector<Dospeh*> vd;
    char choice;
    std::string messages;

    inputDospehs(vd);

    while(1)
    {
    	messages = "��� �������� �������. �������� ������ ���� ��������� (p) ��� ������ ������� (r)?\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
        while(1)
        {
            int ch = _getch(); // ��������� ������ �� ������, �� �� ������� ��� � �����.
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
        case 'p': outputResults(vd);
            break;
        case 'r': zatochka(vd);
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
