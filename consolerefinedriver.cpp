#include "consolerefinedriver.h"

ConsoleRefineDriver::ConsoleRefineDriver()
: itsCountManager(new CountManager())
{
}

ConsoleRefineDriver::~ConsoleRefineDriver()
{
	delete itsCountManager;
	itsCountManager = 0;
}

void ConsoleRefineDriver::distributor()
{
	if(!itsCountManager->size()) return;
	while (true)
	{
		std::string messages = "Все предметы введены. Показать список всех предметов (p) или начать заточку (r)?\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		char choice;
		while (1)
		{
			int ch = _getch(); // Считывает символ из потока, но не выводит его в поток.
			// Это своего рода защита ввода
			std::vector<char> vGoRefine;
			iochecker ioGoRefine(1, &vGoRefine, "pr");
			ioGoRefine.check(ch);
			ch = ioGoRefine.buffer().at(0);
			if (ch == 'p' || ch == 'r')
			{
				choice = ch;
				break;
			}
		}
		std::cout << std::endl;
		switch (choice)
		{
		case 'p':
		{
			outputResults();
			break;
		}
		case 'r':
		{
			refining();
			break;
		}
		default:
			exit(-10); // TODO exit(-10)
		}
	}
}

void ConsoleRefineDriver::info() const
{
	std::string message1 = "**********************************************************************\n";
	std::string message2 = "** Это программа-эмулятор улучшения доспехов для игры Perfect World **\n";
	std::string message3 = "** ========================== Версия 1.1 ========================== **\n";
	std::string message = "\n" + message1 + message2 + message3 + message1 + "\n";
	std::cout << cp1251to866(const_cast<char*>(message.c_str()));
}

void ConsoleRefineDriver::input()
{
	inputArmors();
}

void ConsoleRefineDriver::driver()
{
	distributor();
}

void ConsoleRefineDriver::output()
{
}

REFINE_LEVEL ConsoleRefineDriver::intToRefineLevel(int refineLevel)
{
	switch (refineLevel)
	{
	case 0:
	{
		return T0;
	}
	case 1:
	{
		return T1;
	}
	case 2:
	{
		return T2;
	}
	case 3:
	{
		return T3;
	}
	case 4:
	{
		return T4;
	}
	case 5:
	{
		return T5;
	}
	case 6:
	{
		return T6;
	}
	case 7:
	{
		return T7;
	}
	case 8:
	{
		return T8;
	}
	case 9:
	{
		return T9;
	}
	case 10:
	{
		return T10;
	}
	case 11:
	{
		return T11;
	}
	case 12:
	{
		return T12;
	}
	default:
		return T0;
	}
}

void ConsoleRefineDriver::inputArmors()
{
	int i = 0;
	char cCategory;
	std::string category;
	std::string property;

	std::string messages = "Введите предметы для заточки.";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
	messages = "Предмет № ";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << i << ":\n";

	while(true)
	{
		messages = "0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги,";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
		messages = "5 - Наручи, 6 - Плащ, 7 - Ожерелье, 8 - Пояс, 9 - Кольцо";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";

		std::vector<char> vInput;
		iochecker ioInput(1, &vInput, "0123456789qp");

		ioInput.check(_getch());

		if(iochecker::isDigit(ioInput.charBuffer(iochecker::ALLZEROS)))
		{
			cCategory = (char)iochecker::stoi(ioInput.charBuffer(iochecker::ALLZEROS));
		}
		else
		{
			cCategory = ioInput.buffer(iochecker::ALLZEROS).at(0);
		}


		if(cCategory == 'p')
		{
			std::cout << std::endl;
			outputResults();
			messages = "Предмет № ";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << i;
			messages = ", вывести список всех предметов (p) или выход (q):\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			continue;
		}
		if(cCategory == 'q')
		{
			std::cout << std::endl;
			std::cin.get();
			break;
		}

		messages = "\nВведите название ";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		messages = " (или ENTER):\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		std::cin.ignore(); // Обязательно перед getline()
		/*std::getline(std::cin, pro); // Считывает всю строку (даже с пробелами)
         std::cout << std::endl;*/

		int t2 = _getch();
		if(t2 != 13)
		{
			std::vector<char> vPro;
			messages = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ -";
			iochecker ioPro(29, &vPro, cp1251to866(const_cast<char*>(messages.c_str())));
			ioPro.check(t2);
			std::cout << std::endl;
			property = ioPro.stringBuffer(iochecker::ALLZEROS);
		}
		else
		{
			std::cin.putback(t2);
		}
		std::cin.ignore();

		messages = "Введите уровень заточки (или ENTER):\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

		int t = _getch();
		int refineLevel = 0;
		if(t != 13)
		{
			std::vector<char> vTochka;
			iochecker ioTochka(2, &vTochka, "0123456789");

			ioTochka.check(t);
			refineLevel = iochecker::stoi(ioTochka.charBuffer(iochecker::ALLZEROS));
		}
		else
		{
			std::cin.putback(t);
		}

		Armor *armor = 0;

		switch(cCategory)
		{
		case 0:
		{

			category = "ОРУЖИЕ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 2, category, property);
			break;
		}
		case 1:
		{

			category = "ШЛЕМ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 2:
		{

			category = "НАКИДКА";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 3:
		{

			category = "БРИДЖИ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 4:
		{

			category = "САПОГИ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 5:
		{

			category = "НАРУЧИ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 6:
		{

			category = "ПЛАЩ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 7:
		{

			category = "ОЖЕРЕЛЬЕ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 8:
		{

			category = "ПОЯС";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		case 9:
		{

			category = "КОЛЬЦО";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(refineLevel), 1, category, property);
			break;
		}
		default: exit(-7); // TODO exit(-7)
		}

		property.clear();

		itsCountManager->addArmorToCount(armor);

		std::cin.get();

		std::cout << std::endl;
		messages = "Предмет № ";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << ++i;
		messages = ", вывести список всех предметов (p) или выход (q):\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	}
}

void ConsoleRefineDriver::headOutputResults()
{
	std::string messages;
	std::cout.fill(' ');
	messages = "Предмет №";
	std::cout << std::left << std::setw(10)	<< cp1251to866(const_cast<char*>(messages.c_str()));
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
}

void ConsoleRefineDriver::tailOutputResults()
{
	std::string messages;
	messages = "Всего:";
	std::cout << std::setw(57)
	<< cp1251to866(const_cast<char*>(messages.c_str())) << " "
	<< std::setw(7) << itsCountManager->totalMirageCelestone() << " "
	<< std::setw(7) << itsCountManager->totalTienkangStone() << " "
	<< std::setw(8) << itsCountManager->totalTishaStone() << " "
	<< std::setw(10) << itsCountManager->totalChienkunStone()
	<< std::endl << std::endl;
}

void ConsoleRefineDriver::outputResults()
{
	headOutputResults();

	std::cout.fill('.');

	for(int index = 0; index < itsCountManager->size(); ++index)
	{
		detaleArmorOutputResults(index);
	}

	tailOutputResults();
}

void ConsoleRefineDriver::detaleArmorOutputResults(int index)
{
	std::cout.fill('.');
	std::cout << std::left << std::setw(9) << index << " ";
	std::cout << std::left << std::setw(9) << itsCountManager->at(index)->armor()->category() << " ";
	std::cout << std::left << std::setw(29) << itsCountManager->at(index)->armor()->property() << " ";
	std::cout << std::left << std::setw(7) << itsCountManager->at(index)->armor()->refineLevel() << " ";
	std::cout << std::left << std::setw(7) << itsCountManager->at(index)->mirageCelestone() << " ";
	std::cout << std::left << std::setw(7) << itsCountManager->at(index)->tienkangStone() << " ";
	std::cout << std::left << std::setw(8) << itsCountManager->at(index)->tishaStone() << " ";
	std::cout << std::left << std::setw(10)	<< itsCountManager->at(index)->chienkunStone();
	std::cout << std::endl;
}

void ConsoleRefineDriver::outputResults(int index)
{
	headOutputResults();
	detaleArmorOutputResults(index);
	std::cout << std::endl;
}

void ConsoleRefineDriver::refineInfo(REFINE refine)
{
	std::string messages;

	switch(refine)
	{
	case SUCCESS:
	{
		messages = "Улучшение прошло успешно!\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case FAIL:
	{
		messages = "Улучшение не прошло. Уровень заточки снизился на 1 уровень.\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		break;
	}
	case NOCHANGE:
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
	default: exit(-12); // TODO exit(-12)
	}
}

void ConsoleRefineDriver::refining()
{
	int i = 0;
	char choice;
	std::string messages;
	REFINE refineResult = NOCHANGE;

	while(true)
	{
		messages = "Введите порядковый номер предмета для заточки:\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

		while(true)
		{
			std::vector<char> vRN;
			iochecker ioRN(2, &vRN, "0123456789");

			ioRN.check(_getch());

			if(iochecker::isDigit(ioRN.charBuffer(iochecker::ALLZEROS))
			&& iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS)) < itsCountManager->size())
			{
				i = iochecker::stoi(ioRN.charBuffer(iochecker::ALLZEROS));

				std::cin.get();
				break;
			}

			backspace(2);
		}

		std::cout << std::endl << std::endl;
		outputResults(i);

		if(i >= 0 && i < itsCountManager->size())
		{
			int stone = 0;

			messages = "Использовать камни?\n\t0 (или ENTER) - Миражи, 1 - Небески, 2 - Подземки, 3 - Мирозданки\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

			int t = _getch();
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
				refineResult = Refine::goRefining(itsCountManager->at(i)->armor(), new MirageCelestone());
				break;
			}
			case 1:
			{
				itsCountManager->at(i)->incTienkangStone();
				refineResult = Refine::goRefining(itsCountManager->at(i)->armor(), new MirageCelestone(), new TienkangStone());
				break;
			}
			case 2:
			{
				itsCountManager->at(i)->incTishaStone();
				refineResult = Refine::goRefining(itsCountManager->at(i)->armor(), new MirageCelestone(), new TishaStone());
				break;
			}
			case 3:
			{
				itsCountManager->at(i)->incChienkunStone();
				refineResult = Refine::goRefining(itsCountManager->at(i)->armor(), new MirageCelestone(), new ChienkunStone());
				break;
			}
			default: exit(-11); // TODO exit(-11)
			}
			itsCountManager->at(i)->incMirageCelestone();

			if((itsCountManager->at(i)->armor()->wasRefineLevel() == T0 || itsCountManager->at(i)->armor()->wasRefineLevel() == T12)
					&& (refineResult == FAIL || refineResult == RESET))
			{
				refineResult = NOCHANGE;
			}

			refineInfo(refineResult);
		}

		std::cout << std::endl;
		outputResults(i);
		std::cout << std::endl;
		messages = "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

		int t2;
		int ch;

		while(true)
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

				outputResults();
				messages = "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
				std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			}
		}

		if(choice == 'q')
		{
			exit(0); // TODO exit(0)
		}
	}
}


char* ConsoleRefineDriver::cp1251to866(char *c) const
{
	int i = 0;

	while(*c)
	{
		if(*c >= -16 && *c <= -1) // р...я
		{
			*c -= 16;
		}
		else if(*c <= -17 && *c >= -64) // А...Я, а...п
		{
			*c -= 64;
		}
		else if(*c == -71) // №
		{
			*c +=67;
		}
		else if(*c == -72) // ё
		{
			*c +=57;
		}
		else if(*c == -88) // Ё
		{
			*c +=72;
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

void ConsoleRefineDriver::backspace(int count)
{
	while(count--)
	{
		std::cout << (char)8 << " " << (char)8;
	}
}

