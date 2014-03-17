#include "consolerefinedriver.h"
#include <stdlib.h>

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
		std::string choice;
		while (true)
		{
			std::string messages = "Все предметы введены. Показать список всех предметов (p) или начать заточку (r)?\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			try {
				std::getline(std::cin, choice);
				InputChecker::isContaineErrorString(choice, "pr", 1);
				break;
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << choice
						<< " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		std::cout << std::endl;
		// FIXME add exception on this
		if(!choice.size()) continue;
		switch (choice.at(0))
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

int ConsoleRefineDriver::stoi(const char *str)
{
	int number=0;
	int temp;
	int sign=1;
	//Проверка на отрицательность
	if(*str=='-'){
		str++;
		sign=-1;
	}
	//Преобразование символов строки в разряды числа
	while(*str){
		temp=(int)*str++-48;
		number+=temp;
		number*=10;
	}
	number/=10;
	//Проверка на вхождения числа в допустимый диапазон значений
	if((number<-32768)||(number>32767)){
		std::cout<<"Error 1. ";
		std::cout<<"Number overload long int"<<std::endl;
		exit(1); // TODO exit(1)
	}

	return number*sign;
}

void ConsoleRefineDriver::inputArmors()
{
	int armorNumber = 0;
	std::string cCategory;
	std::string category;
	std::string property;

	std::string messages = "Введите предметы для заточки.";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";

	while(true)
	{
		messages = "Предмет № ";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << armorNumber++;
		messages = ", вывести список всех предметов (p) или выход (q):\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

		while(true)
		{
			messages = "0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги,";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
			messages = "5 - Наручи, 6 - Плащ, 7 - Ожерелье, 8 - Пояс, 9 - Кольцо";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";

			try {
				std::getline(std::cin, cCategory);
				InputChecker::isContaineErrorString(cCategory, "0123456789qp", 1);
				break;
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << cCategory
						<< " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}

		if(cCategory == "p")
		{
			std::cout << std::endl;
			outputResults();
			continue;
		}
		if(cCategory == "q")
		{
			std::cout << std::endl;
			break;
		}

		while(true)
		{
			messages = "\nВведите название доспеха ";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			messages = " (или ENTER):\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			messages = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ -";

			try {
				std::getline(std::cin, property);
				InputChecker::isContaineErrorString(property, cp1251to866(const_cast<char*>(messages.c_str())), 29);
				break;
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << property
						<< " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}

		std::string refineLevel;
		while(true)
		{
			messages = "Введите уровень заточки (или ENTER):\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			char* c = new char[2];
			try {
				std::getline(std::cin, refineLevel);
				InputChecker::isContaineErrorString(refineLevel, "0123456789", 2);
				break;
			} catch (InputLimitException &e) {
				delete [] c;
				c = 0;
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				delete [] c;
				c = 0;
				std::cout << "Input exception. String " << refineLevel
						<< " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}

		Armor *armor = 0;

		switch(stoi(cCategory.c_str()))
		{
		case 0:
		{
			category = "ОРУЖИЕ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 2, category, property);
			break;
		}
		case 1:
		{

			category = "ШЛЕМ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 2:
		{

			category = "НАКИДКА";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 3:
		{

			category = "БРИДЖИ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 4:
		{

			category = "САПОГИ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 5:
		{

			category = "НАРУЧИ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 6:
		{

			category = "ПЛАЩ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 7:
		{

			category = "ОЖЕРЕЛЬЕ";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 8:
		{

			category = "ПОЯС";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		case 9:
		{

			category = "КОЛЬЦО";
			category = cp1251to866(const_cast<char*>(category.c_str()));
			armor = new Armor(intToRefineLevel(stoi(refineLevel.c_str())), 1, category, property);
			break;
		}
		default: exit(-7); // TODO exit(-7)
		}

		property.clear();
		cCategory.clear();
		category.clear();

		itsCountManager->addArmorToCount(armor);

		std::cout << std::endl;
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
	std::string armorNumer;
	std::string choice;
	std::string messages;
	REFINE refineResult = NOCHANGE;

	while(true)
	{
		while(true)
		{
			messages = "Введите порядковый номер предмета для заточки:\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			try {
				std::getline(std::cin, armorNumer);
				InputChecker::isContaineErrorString(armorNumer, "0123456789", itsCountManager->size());
				break;
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
				break;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << armorNumer
						<< " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
				break;
			}
		}

		std::cout << std::endl << std::endl;

		std::cout << "Don't work?\n";
		if(stoi(armorNumer.c_str()) >= 0 && stoi(armorNumer.c_str()) < itsCountManager->size())
		{
			std::cout << "Work!\n";
			outputResults(stoi(armorNumer.c_str()));
			std::string stone;

			while(true)
			{
				messages = "Использовать камни?\n\t0 (или ENTER) - Миражи, 1 - Небески, 2 - Подземки, 3 - Мирозданки\n";
				std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

				try {
					std::getline(std::cin, stone);
					InputChecker::isContaineErrorString(stone, "0123", 1);
					break;
				} catch (InputLimitException &e) {
					std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
				} catch (InputException &e) {
					std::cout << "Input exception. String " << stone
							<< " contains non legal characters: " << e.errorString() << std::endl;
					std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
				}
			}

			std::cin.get();
			std::cout << std::endl;

			switch(stoi(stone.c_str()))
			{
			case 0:
			{
				refineResult = Refine::goRefining(itsCountManager->at(stoi(armorNumer.c_str()))->armor(), new MirageCelestone());
				break;
			}
			case 1:
			{
				itsCountManager->at(stoi(armorNumer.c_str()))->incTienkangStone();
				refineResult = Refine::goRefining(itsCountManager->at(stoi(armorNumer.c_str()))->armor(), new MirageCelestone(), new TienkangStone());
				break;
			}
			case 2:
			{
				itsCountManager->at(stoi(armorNumer.c_str()))->incTishaStone();
				refineResult = Refine::goRefining(itsCountManager->at(stoi(armorNumer.c_str()))->armor(), new MirageCelestone(), new TishaStone());
				break;
			}
			case 3:
			{
				itsCountManager->at(stoi(armorNumer.c_str()))->incChienkunStone();
				refineResult = Refine::goRefining(itsCountManager->at(stoi(armorNumer.c_str()))->armor(), new MirageCelestone(), new ChienkunStone());
				break;
			}
			default: exit(-11); // TODO exit(-11)
			}
			itsCountManager->at(stoi(armorNumer.c_str()))->incMirageCelestone();

			if((itsCountManager->at(stoi(armorNumer.c_str()))->armor()->wasRefineLevel() == T0 || itsCountManager->at(stoi(armorNumer.c_str()))->armor()->wasRefineLevel() == T12)
					&& (refineResult == FAIL || refineResult == RESET))
			{
				refineResult = NOCHANGE;
			}

			refineInfo(refineResult);
			std::cout << std::endl;
			outputResults(stoi(armorNumer.c_str()));
		}

		while(true)
		{
			std::cout << std::endl;
			messages = "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
			try {
				std::cin >> choice;
				InputChecker::isContaineErrorString(choice, "prq", 1);
				break;
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << choice
						<< " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}

		if( choice == "r" || choice == "q")
		{
			std::cout << std::endl;
			break;
		}
		if(choice == "p")
		{
			std::cout << std::endl;

			outputResults();
			messages = "Показать список всех предметов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
			std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
		}
	}

	if(choice == "q")
	{
		exit(0); // TODO exit(0)
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
