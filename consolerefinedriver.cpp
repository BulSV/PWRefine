#include <stdlib.h>
#include "consolerefinedriver.h"
#include "matematika.h"

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
	try {
		isEmptyCountManager();
	} catch (EmptyException &e) {
		std::cout << "\nEmpty exception. Was not input any armor. Program is closing...\n\n";
		return;
	}

	InputChecker inputChecker;
	bool isWasQuit = false;

	while (!isWasQuit)
	{
		std::string choice;
		while (true)
		{
			try {
				if(distributorInput(inputChecker))
				{
					break;
				}
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		choice = inputChecker.str();

		try {
			isStringEmpty(choice);
		} catch (EmptyException &e) {
			std::cout << "Empty exception. Wasn't selected any conditions\n\n";
			continue;
		}

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
			isWasQuit = true;
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
	std::string message3 = "** ========================== Версия 1.2 ========================== **\n";
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

bool ConsoleRefineDriver::refineArmorNumber(InputChecker& inputChecker)
{
	std::string messages;
	std::string armorNumber;
	messages = "Введите порядковый номер доспеха для заточки:\n";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	std::getline(std::cin, armorNumber);

	return inputChecker.check(armorNumber, "0123456789", itsCountManager->size());
}

bool ConsoleRefineDriver::refineStoneChoice(InputChecker& inputChecker)
{
	std::string messages;
	std::string stone;
	messages = "Использовать камни?\n\t0 (или ENTER) - Миражи, 1 - Небески, 2 - Подземки, 3 - Мирозданки\n";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	std::getline(std::cin, stone);

	return inputChecker.check(stone, "0123", 1);
}

REFINE ConsoleRefineDriver::refineArmor(std::string stone, std::string armorNumber)
{
	REFINE refineResult;

	switch(MLib::stoi(stone.c_str()))
	{
	case 0:
	{
		refineResult = Refine::goRefining(itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor(), new MirageCelestone());
		break;
	}
	case 1:
	{
		refineResult = Refine::goRefining(itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor(), new MirageCelestone(), new TienkangStone());
		itsCountManager->at(MLib::stoi(armorNumber.c_str()))->incTienkangStone();
		break;
	}
	case 2:
	{
		refineResult = Refine::goRefining(itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor(), new MirageCelestone(), new TishaStone());
		itsCountManager->at(MLib::stoi(armorNumber.c_str()))->incTishaStone();
		break;
	}
	case 3:
	{
		refineResult = Refine::goRefining(itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor(), new MirageCelestone(), new ChienkunStone());
		itsCountManager->at(MLib::stoi(armorNumber.c_str()))->incChienkunStone();
		break;
	}
	default: exit(-11); // TODO exit(-11)
	}
	itsCountManager->at(MLib::stoi(armorNumber.c_str()))->incMirageCelestone();

	if((itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor()->wasRefineLevel() == T0 || itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor()->wasRefineLevel() == T12)
			&& (refineResult == FAIL || refineResult == RESET))
	{
		refineResult = NOCHANGE;
	}

	return refineResult;
}

bool ConsoleRefineDriver::refineContinue(InputChecker& inputChecker)
{
	std::string messages;
	std::string choice;
	std::cout << std::endl;
	messages = "Показать список всех доспехов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	std::getline(std::cin, choice);

	return inputChecker.check(choice, "prq", 1);
}

bool ConsoleRefineDriver::distributorInput(InputChecker& inputChecker)
{
	std::string choice;
	std::string messages = "Все доспехи введены. Показать список всех доспехов (p) или начать заточку (r)?\n";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	std::getline(std::cin, choice);

	return inputChecker.check(choice, "pr", 1);
}

bool ConsoleRefineDriver::isEmptyCountManager() const
throw (EmptyException)
{
	if(!itsCountManager->size())
	{
		throw EmptyException();
	}

	return false;
}

bool ConsoleRefineDriver::isStringEmpty(std::string str) const
throw (EmptyException)
{
	if(!str.size())
	{
		throw EmptyException();
	}

	return false;
}

void ConsoleRefineDriver::output()
{
	outputResults();

	std::string message1 = "**********************************************************************\n";
	std::string message2 = "** ====================== Программа завершена ===================== **\n";
	std::string message = message1 + message2 + message1 + "\n";
	std::cout << cp1251to866(const_cast<char*>(message.c_str()));
}

REFINE_LEVEL ConsoleRefineDriver::intToRefineLevel(int refineLevel)
throw(IntToRefineLevelException)
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
		std::string message = "Refine level is not in 0..12\n";
		throw IntToRefineLevelException(message, (REFINE_LEVEL)refineLevel);
	}
}

bool ConsoleRefineDriver::inputArmorCategory(InputChecker &inputChecker)
{
	std::string messages;
	std::string cCategory;
	messages = "0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги,";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
	messages = "5 - Наручи, 6 - Плащ, 7 - Ожерелье, 8 - Пояс, 9 - Кольцо";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";
	std::getline(std::cin, cCategory);

	return inputChecker.check(cCategory, "0123456789qp", 1);
}

bool ConsoleRefineDriver::inputArmorProperty(InputChecker &inputChecker)
{
	std::string messages;
	std::string property;
	messages = "\nВведите название доспеха ";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = " (или ENTER):\n";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	messages = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ -";
	std::getline(std::cin, property);

	return inputChecker.check(property, cp1251to866(const_cast<char*>(messages.c_str())), 29);
}

bool ConsoleRefineDriver::inputArmorRefineLevel(InputChecker &inputChecker)
{
	std::string messages;
	std::string refineLevel;
	messages = "Введите уровень заточки (или ENTER):\n";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str()));
	std::getline(std::cin, refineLevel);

	return inputChecker.check(refineLevel, "0123456789", 2);
}

void ConsoleRefineDriver::armorCreator(std::string choiceCategory,
		std::string property,
		std::string refineLevel,
		Armor *&armor)
{
	std::string category;
	switch(MLib::stoi(choiceCategory.c_str()))
	{
	case 0:
	{
		category = "ОРУЖИЕ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 2, category, property);
		break;
	}
	case 1:
	{

		category = "ШЛЕМ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 2:
	{

		category = "НАКИДКА";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 3:
	{

		category = "БРИДЖИ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 4:
	{

		category = "САПОГИ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 5:
	{

		category = "НАРУЧИ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 6:
	{

		category = "ПЛАЩ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 7:
	{

		category = "ОЖЕРЕЛЬЕ";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 8:
	{

		category = "ПОЯС";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	case 9:
	{

		category = "КОЛЬЦО";
		category = cp1251to866(const_cast<char*>(category.c_str()));
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, category, property);
		break;
	}
	default: exit(-7); // TODO exit(-7)
	}
}

void ConsoleRefineDriver::inputArmors()
{
	int armorNumber = 0;
	std::string choiceCategory;
	std::string property;
	std::string refineLevel;
	InputChecker inputChecker;
	Armor *armor = 0;

	std::string messages = "Введите доспехи для заточки.";
	std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << "\n";

	while(true)
	{
		messages = "Доспех № ";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str())) << armorNumber;
		messages = ", вывести список всех доспехов (p) или выход (q):\n";
		std::cout << cp1251to866(const_cast<char*>(messages.c_str()));

		while(true)
		{
			try {
				if(inputArmorCategory(inputChecker))
				{
					break;
				}
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		choiceCategory = inputChecker.str();

		if(choiceCategory == "p")
		{
			std::cout << std::endl;
			outputResults();
			continue;
		}
		if(choiceCategory == "q")
		{
			std::cout << std::endl;
			break;
		}

		armorNumber++;

		while(true)
		{
			try {
				if(inputArmorProperty(inputChecker))
				{
					break;
				}
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		property = inputChecker.str();

		while(true)
		{
			try {
				if(inputArmorRefineLevel(inputChecker))
				{
					break;
				}
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		refineLevel = inputChecker.str();

		try {
		armorCreator(choiceCategory, property, refineLevel, armor);
		} catch (IntToRefineLevelException &e) {
			std::cout << cp1251to866(const_cast<char*>(e.message().c_str()));
			std::cout << "It was: " << e.refineLevel() << ". And it will be set to 0\n";
			armorCreator(choiceCategory, property, "0", armor);
		}

		choiceCategory.clear();
		property.clear();
		refineLevel.clear();

		itsCountManager->addArmorToCount(armor);

		std::cout << std::endl;
	}
}

void ConsoleRefineDriver::headOutputResults()
{
	std::string messages;
	std::cout.fill(' ');
	messages = "Доспех №";
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
	std::string armorNumber;
	std::string choice = " ";
	std::string messages;
	std::string stone;
	InputChecker inputChecker;

	while(true)
	{
		try {
			isEmptyCountManager();
			break;
		} catch (EmptyException &e) {
			std::cout << "Empty exception. Was not input any armor\n\n";
			inputArmors();
		}
	}

	while(choice != "q")
	{
		while(true)
		{
			try {
				if(refineArmorNumber(inputChecker))
				{
					break;
				}
			} catch (InputLimitException &e) {
				std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		armorNumber = inputChecker.str();

		std::cout << std::endl << std::endl;

		if(MLib::stoi(armorNumber.c_str()) >= 0 && MLib::stoi(armorNumber.c_str()) < itsCountManager->size())
		{
			outputResults(MLib::stoi(armorNumber.c_str()));

			while(true)
			{
				try {
					if(refineStoneChoice(inputChecker))
					{
						break;
					}
				} catch (InputLimitException &e) {
					std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
				} catch (InputException &e) {
					std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
					std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
				}
			}
			stone = inputChecker.str();

			std::cout << std::endl;

			try {
				refineInfo(refineArmor(stone, armorNumber));
			} catch (RefineLevelException &e) {
				std::cout << e.message() << std::endl;
			}
			std::cout << std::endl;
			outputResults(MLib::stoi(armorNumber.c_str()));
		}

		do {
			std::cout << std::endl;
			if(choice == "p")
				outputResults();

			while(true)
			{
				try {
					if(refineContinue(inputChecker))
					{
						break;
					}
				} catch (InputLimitException &e) {
					std::cout << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
				} catch (InputException &e) {
					std::cout << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
					std::cout << "Candidates are: " << e.mask() << std::endl << std::endl;
				}
			}
			choice = inputChecker.str();
		} while(choice == "p");
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
