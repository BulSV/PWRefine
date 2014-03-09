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

void inputdospehs(std::vector<Kuznitsa> &vk)
{
    int i = 0;
    char cat;
    std::string predmet;
    std::string pro;

    std::string messages = "Введите предметы для заточки.";
    std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
    messages = "Предмет № ";
    std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << i++ << ":\n";

    while(1)
    {

        messages = "0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги,";
    	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
    	messages = "5 - Наручи, 6 - Плащ, 7 - Ожерелье, 8 - Пояс, 9 - Кольцо";
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
        	messages = "оружия";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 1:
        {
        	messages = "шлема";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 2:
        {
        	messages = "накидки";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 3:
        {
        	messages = "бриджей";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 4:
        {
        	messages = "сапог";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 5:
        {
        	messages = "наручей";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 6:
        {
        	messages = "плаща";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 7:
        {
        	messages = "ожерелья";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 8:
        {
        	messages = "пояса";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        case 9:
        {
        	messages = "кольца";
        	predmet = cp1251to866(const_cast<char*>(messages.c_str()));
        	break;
        }
        default: exit(-7);
        }

        messages = "Введите название ";
        std::cout << "\n" << cp1251to866(const_cast<char*>(messages.c_str())) << predmet;
        messages = " (или ENTER):\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
        std::cin.ignore(); // Обязательно перед getline()
        /*std::getline(std::cin, pro); // Считывает всю строку (даже с пробелами)
        std::cout << std::endl;*/
        int t2 = _getch();
        if(t2 != 13)
        {
            std::vector<char> vPro;
            messages = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";
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

        messages = "Введите уровень заточки (или ENTER):\n";
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

        vk[vk.size() - 1].dospeh()->setToch(tochka);
        std::cin.get();

        std::cout << std::endl;
        messages = "Предмет № ";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << i++;
        messages = " или выход (q):\n";
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
		messages = "Оружие";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case SHLEM:
	{
		messages = "Шлем";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NAKIDKA:
	{
		messages = "Накидка";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case BRIDGY:
	{
		messages = "Бриджи";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case SAPOGI:
	{
		messages = "Сапоги";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NARUCHI:
	{
		messages = "Наручи";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case PLASCH:
	{
		messages = "Плащ";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case OZHERELYE:
	{
		messages = "Ожерелье";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case POYAS:
	{
		messages = "Пояс";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case RING:
	{
		messages = "Кольцо";
		return cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	default: exit(-9);
	}

	messages = "Нет категории";
	return cp1251to866(const_cast<char*>(messages.c_str()));
}

void refineInfo(TOCHKA t)
{
	std::string messages;

	switch(t)
	{
	case UDACH:
	{
		messages = "Улучшение прошло успешно!\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NEUDACH:
	{
		messages = "Улучшение не прошло. Уровень заточки снизился на 1 уровень.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NEIZMEN:
	{
		messages = "Улучшение не прошло. Уровень заточки не изменился.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case RESET:
	{
		messages = "Улучшение не прошло. Уровень заточки снизился до 0.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	default: exit(-12);
	}
}

void outputResults(const std::vector<Kuznitsa> &vk)
{
	int mirazh = 0;
	int nebeska = 0;
	int podzemka = 0;
	int mirozdanka = 0;

	std::string messages;

	std::cout.fill(' ');

	messages = "Предмет №";
	std::cout << std::left << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Категория";
	std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Описание";
	std::cout << std::setw(30) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Заточка";
	std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Миражей";
	std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Небесок";
	std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Подземок";
	std::cout << std::setw(9) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Мирозданок\n";
	std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));

	std::cout.fill('.');

	for(unsigned int i = 0; i < vk.size(); ++i)
	{
		std::cout << std::left << std::setw(9) << i << " ";
		std::cout << std::left << std::setw(9) << CATEGORYtoString(vk.at(i).dospeh()->cat()) << " ";
		std::cout << std::left << std::setw(29) << vk.at(i).dospeh()->pro() << " ";
		std::cout << std::left << std::setw(7) << vk.at(i).dospeh()->toch() << " ";
		std::cout << std::left << std::setw(7) << vk.at(i).dospeh()->mirazh() << " ";
		std::cout << std::left << std::setw(7) << vk.at(i).dospeh()->nebeska() << " ";
		std::cout << std::left << std::setw(8) << vk.at(i).dospeh()->podzemka() << " ";
		std::cout << std::left << std::setw(10) << vk.at(i).dospeh()->mirozdanka();
		std::cout << std::endl;

		mirazh += vk.at(i).dospeh()->mirazh();
		nebeska += vk.at(i).dospeh()->nebeska();
		podzemka += vk.at(i).dospeh()->podzemka();
		mirozdanka += vk.at(i).dospeh()->mirozdanka();
	}

	messages = "Всего:";
	std::cout << std::setw(57) << cp1251to866(const_cast<char*>(messages.c_str())) << " "
			<< std::setw(7)<< mirazh << " "
			<< std::setw(7) << nebeska << " "
			<< std::setw(8) << podzemka << " "
			<< std::setw(10) << mirozdanka
			<< std::endl << std::endl;
}

void outputResults(const std::vector<Kuznitsa> &vk, /*unsigned */int i)
{
	std::cout.fill(' ');

	std::string messages;

	messages = "Предмет №";
	std::cout << std::left << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Категория";
	std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Описание";
	std::cout << std::setw(30) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Заточка";
	std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Миражей";
	std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Небесок";
	std::cout << std::setw(8) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Подземок";
	std::cout << std::setw(9) << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "Мирозданок\n";
	std::cout << std::setw(10) << cp1251to866(const_cast<char*>(messages.c_str()));

	std::cout.fill('.');

	std::cout << std::left << std::setw(9) << i << " ";
	std::cout << std::left << std::setw(9) << CATEGORYtoString(vk.at(i).dospeh()->cat()) << " ";
	std::cout << std::left << std::setw(29) << vk.at(i).dospeh()->pro() << " ";
	std::cout << std::left << std::setw(7) << vk.at(i).dospeh()->toch() << " ";
	std::cout << std::left << std::setw(7) << vk.at(i).dospeh()->mirazh() << " ";
	std::cout << std::left << std::setw(7) << vk.at(i).dospeh()->nebeska() << " ";
	std::cout << std::left << std::setw(8) << vk.at(i).dospeh()->podzemka() << " ";
	std::cout << std::left << std::setw(10) << vk.at(i).dospeh()->mirozdanka();
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

void zatochka(std::vector<Kuznitsa> &vk)
{
    unsigned int i = 0;
    char choice;
    std::string messages;

    while(1)
    {
        messages = "Введите порядковый номер предмета для заточки:\n";
    	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

        while(1)
        {
            std::vector<char> vRN;
            iochecker ioRN(2, &vRN, "0123456789");

            ioRN.check(_getch());

            if(iochecker::isDigit(ioRN.charBuffer(iochecker::ALLZEROS))
                    && (int)iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS)) < vk.size())
            {
                i = iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS));

                std::cin.get();
                break;
            }

            backspace(2);
        }

        std::cout << std::endl << std::endl;
        outputResults(vk, i);

        if(i >= 0 && i < vk.size())
        {
            int stone = 0;
            Refine r;

            messages = "Использовать камни?\n\t0 (или ENTER) - Миражи, 1 - Небески, 2 - Подземки, 3 - Мирозданки\n";
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
                r.goRefining(vk[i].dospeh(), NOSTONE);
                break;
            }
            case 1:
            {
                r.goRefining(vk[i].dospeh(), NEBESKA);
                break;
            }
            case 2:
            {
                r.goRefining(vk[i].dospeh(), PODZEMKA);
                break;
            }
            case 3:
            {
                r.goRefining(vk[i].dospeh(), MIROZDANKA);
                break;
            }
            default: exit(-11);
            }

            refineInfo(r.refineResult());
        }

        std::cout << std::endl;
        outputResults(vk, i);
        std::cout << std::endl;
        messages = "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
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
                outputResults(vk);
                messages = "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
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
    std::vector<Kuznitsa> vk;
    char choice;
    std::string messages;

    inputdospehs(vk);

    while(1)
    {
    	messages = "Все предметы введены. Показать список всех предметов (p) или начать заточку (r)?\n";
        std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
        while(1)
        {
            int ch = _getch(); // Считывает символ из потока, но не выводит его в поток.
            // Это своего рода защита ввода
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

/* Введите предметы для заточки.
Предмет № 1 или выход (q):
    //0 - WEAPON, 1 - SHLEM, 2 - NAKIDKA, 3 - BRIDGY, 4 - SAPOGI, 5 - PLASCH, 6 - OZHERELYE, 7 - POYAS, 8 - RING
    0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги, 5 - Плащ, 6 - Ожерелье, 7 - Пояс, 8 - Кольцо
0
Введите название оружия:
Кастеты с лезвиями

Предмет № 2 или выход (q):
    //0 - WEAPON, 1 - SHLEM, 2 - NAKIDKA, 3 - BRIDGY, 4 - SAPOGI, 5 - PLASCH, 6 - OZHERELYE, 7 - POYAS, 8 - RING
    0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги, 5 - Плащ, 6 - Ожерелье, 7 - Пояс, 8 - Кольцо
0
Введите название оружия:
Кастеты с лезвиями

...

Предмет № N или выход (q):
q

Все предметы введены. Показать список всех предметов (p) или начать заточку (r).
p
Предмет №   Категория   Описание            Заточка     Миражей     Небесок     Подземок    Мирозданок
0           Оружие      Кастеты с лезвием   +0          0           0           0           0
1           Оружие      Кастеты с лезвием   +0          0           0           0           0

Все предметы введены. Показать список всех предметов (p) или начать заточку (r).
r

Введите порядковый номер предмета для заточки или вывести список всех предметов (p):
0

Использовать:
    0 - Ничего, 1 - Небеску, 2 - Подземку, 3 - Мирозданку
0

Улучшение прошло успешно!
Предмет №   Категория   Описание            Заточка     Миражей     Небесок     Подземок    Мирозданок
0           Оружие      Кастеты с лезвием   +1          2           0           0           0

Продолжить заточку (r) или выход (q)?
r

Введите порядковый номер предмета для заточки или вывести список всех предметов (p):
1

Использовать:
    0 - Ничего, 1 - Небеску, 2 - Подземку, 3 - Мирозданку
1

Улучшение прошло успешно!
Предмет №   Категория   Описание            Заточка     Миражей     Небесок     Подземок    Мирозданок
1           Оружие      Кастеты с лезвием   +1          2           1           0           0

Продолжить заточку (r) или выход (q)?
q

Результаты зоточки.
Предмет №   Категория   Описание            Заточка     Миражей     Небесок     Подземок    Мирозданок
0           Оружие      Кастеты с лезвием   +1          2           0           0           0
1           Оружие      Кастеты с лезвием   +1          2           1           0           0

Всего                                                   4           1           0           0
*/
