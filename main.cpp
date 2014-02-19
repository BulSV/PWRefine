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

void inputDospehs(std::vector<Dospeh*> &vd)
{
    int i = 0;
    char cat;
    std::string predmet;
    std::string pro;
    std::vector<Kuznitsa*> vk;

    std::cout << "Введите предметы для заточки.\n";
    std::cout << "Предмет № " << i++ << ":\n";

    while(1)
    {

        std::cout << "0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги,\n";
        std::cout << "5 - Наручи, 6 - Плащ, 7 - Ожерелье, 8 - Пояс, 9 - Кольцо\n";

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
        case 0: predmet = "оружия";
            break;
        case 1: predmet = "шлема";
            break;
        case 2: predmet = "накидки";
            break;
        case 3: predmet = "бриджей";
            break;
        case 4: predmet = "сапог";
            break;
        case 5: predmet = "наручей";
            break;
        case 6: predmet = "плаща";
            break;
        case 7: predmet = "ожерелья";
            break;
        case 8: predmet = "пояса";
            break;
        case 9: predmet = "кольца";
            break;
        default: exit(-7);
        }

        std::cout << "\nВведите название " << predmet << " (или ENTER):\n";
        std::cin.ignore(); // Обязательно перед getline()
        /*std::getline(std::cin, pro); // Считывает всю строку (даже с пробелами)
        std::cout << std::endl;*/
        unsigned int t2 = _getch();
        if(t2 != 13)
        {
            std::vector<unsigned char> vPro;
            iochecker ioPro(29, &vPro, "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
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

        std::cout << "Введите уровень заточки (или ENTER):\n";

        unsigned int t = _getch();
        unsigned int tochka = 0;
        if(t != 13)
        {
            std::vector<unsigned char> vTochka;
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
        std::cout << "Предмет № " << i++ << " или выход (q):\n";
    }
}

std::string CATEGORYtoString(CATEGORY cat)
{
    switch(cat)
    {
    case WEAPON: return "Оружие";
        break;
    case SHLEM: return "Шлем";
        break;
    case NAKIDKA: return "Накидка";
        break;
    case BRIDGY: return "Бриджи";
        break;
    case SAPOGI: return "Сапоги";
        break;
    case NARUCHI: return "Наручи";
        break;
    case PLASCH: return "Плащ";
        break;
    case OZHERELYE: return "Ожерелье";
        break;
    case POYAS: return "Пояс";
        break;
    case RING: return "Кольцо";
        break;
    default: exit(-9);
    }

    return "Нет категории";
}

void refineInfo(TOCHKA t)
{
    switch(t)
    {
    case UDACH: std::cout << "Улучшение прошло успешно!\n";
        break;
    case NEUDACH: std::cout << "Улучшение не прошло. Уровень заточки снизился на 1 уровень.\n";
        break;
    case NEIZMEN: std::cout << "Улучшение не прошло. Уровень заточки не изменился.\n";
        break;
    case RESET: std::cout << "Улучшение не прошло. Уровень заточки снизился до 0.\n";
        break;
    default: exit(-12);
    }
}

void outputResults(const std::vector<Dospeh*> &vd)
{
    int mirazh = 0;
    int nebeska = 0;
    int podzemka = 0;
    int mirozdanka = 0;

    std::cout.fill(' ');

    std::cout << std::left << std::setw(10) << "Предмет №"
              << std::setw(10) << "Категория"
              << std::setw(30) << "Описание"
              << std::setw(8) << "Заточка"
              << std::setw(8) << "Миражей"
              << std::setw(8) << "Небесок"
              << std::setw(9) << "Подземок"
              << std::setw(10) << "Мирозданок\n";

    std::cout.fill('.');

    for(unsigned int i = 0; i < vd.size(); ++i)
    {
        std::cout << std::left << std::setw(9) << i << " ";
        std::cout << std::left << std::setw(9) << CATEGORYtoString(vd.at(i)->cat()) << " ";
        std::cout << std::left << std::setw(29) << vd.at(i)->pro() << " ";
        std::cout << std::left << std::setw(7) << vd.at(i)->toch() << " ";
        std::cout << std::left << std::setw(7) << vd.at(i)->mirazh() << " ";
        std::cout << std::left << std::setw(7) << vd.at(i)->nebeska() << " ";
        std::cout << std::left << std::setw(8) << vd.at(i)->podzemka() << " ";
        std::cout << std::left << std::setw(10) << vd.at(i)->mirozdanka();
        std::cout << std::endl;

        mirazh += vd.at(i)->mirazh();
        nebeska += vd.at(i)->nebeska();
        podzemka += vd.at(i)->podzemka();
        mirozdanka += vd.at(i)->mirozdanka();
    }

    std::cout << std::setw(57) << "Всего:" << " "
              << std::setw(7)<< mirazh << " "
              << std::setw(7) << nebeska << " "
              << std::setw(8) << podzemka << " "
              << std::setw(10) << mirozdanka
              << std::endl << std::endl;
}

void outputResults(const std::vector<Dospeh*> &vd, unsigned int i)
{
    std::cout.fill(' ');

    std::cout << std::left << std::setw(10) << "Предмет №"
              << std::setw(10) << "Категория"
              << std::setw(30) << "Описание"
              << std::setw(8) << "Заточка"
              << std::setw(8) << "Миражей"
              << std::setw(8) << "Небесок"
              << std::setw(9) << "Подземок"
              << std::setw(10) << "Мирозданок\n";

    std::cout.fill('.');

    std::cout << std::left << std::setw(9) << i << " ";
    std::cout << std::left << std::setw(9) << CATEGORYtoString(vd.at(i)->cat()) << " ";
    std::cout << std::left << std::setw(29) << vd.at(i)->pro() << " ";
    std::cout << std::left << std::setw(7) << vd.at(i)->toch() << " ";
    std::cout << std::left << std::setw(7) << vd.at(i)->mirazh() << " ";
    std::cout << std::left << std::setw(7) << vd.at(i)->nebeska() << " ";
    std::cout << std::left << std::setw(8) << vd.at(i)->podzemka() << " ";
    std::cout << std::left << std::setw(10) << vd.at(i)->mirozdanka();
    std::cout << std::endl;

    std::cout << std::endl;
}

void backspace(unsigned int count)
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

    while(1)
    {
        std::cout << "Введите порядковый номер предмета для заточки:\n";

        while(1)
        {
            std::vector<unsigned char> vRN;
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

            std::cout << "Использовать камни?\n\t0 (или ENTER) - Миражи, 1 - Небески, 2 - Подземки, 3 - Мирозданки\n";

            unsigned int t = _getch();
            if(t != 13)
            {
                std::vector<unsigned char> vStones;
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
        std::cout << "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";

        unsigned int t2;
        int ch;

        while(1)
        {
            t2 = _getch();
            if(t2 != 13)
            {
                std::vector<unsigned char> vPRQ;
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
                std::cout << "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
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
    //system("chcp 1251");
    std::vector<Dospeh*> vd;
    char choice;

    inputDospehs(vd);

    while(1)
    {
        std::cout << "Все предметы введены. Показать список всех предметов (p) или начать заточку (r)?\n";
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
        case 'p': outputResults(vd);
            break;
        case 'r': zatochka(vd);
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
