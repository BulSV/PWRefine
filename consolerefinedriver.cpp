#include "consolerefinedriver.h"
#include "matematika.h"
#include "ConsoleIO.h"
#include "Utf8ToWinDecoderIO.h"
#include "WinToDosDecoderIO.h"

ConsoleRefineDriver::ConsoleRefineDriver()
: itsCountManager(new CountManager())
, itsAbstractIO(new WinToDosDecoderIO(new Utf8ToWinDecoderIO(new ConsoleIO())))
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
		std::cerr << "\nEmpty exception. Was not input any armor. Program is closing...\n\n";
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
				std::cerr << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cerr << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cerr << "Candidates are: " << e.mask() << std::endl << std::endl;
			}
		}
		choice = inputChecker.str();

		try {
			isStringEmpty(choice);
		} catch (EmptyException &e) {
			std::cerr << "Empty exception. Wasn't selected any conditions\n\n";
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
		}
	}
}

void ConsoleRefineDriver::info() const
{
	std::string message1 = "**********************************************************************\n";
	std::string message2 = "** Это программа-эмулятор улучшения доспехов для игры Perfect World **\n";
	std::string message3 = "** ========================== Версия 1.2 ========================== **\n";

	std::cout << itsAbstractIO->input("\n" + message1 + message2 + message3 + message1 + "\n");
}

void ConsoleRefineDriver::input()
{
	try {
		inputArmors();
	} catch (StoiException &e) {
		std::cerr << e.message();
		std::cerr << "Number was: " << e.number() << std::endl;
		std::cerr << "Program is closing...\n";
		return;
	}
}

void ConsoleRefineDriver::driver()
{
	distributor();
}

bool ConsoleRefineDriver::refineArmorNumber(InputChecker& inputChecker)
{
	std::string armorNumber;
	std::cout << itsAbstractIO->input("Введите порядковый номер доспеха для заточки:\n");
	std::getline(std::cin, armorNumber);

	return inputChecker.check(armorNumber, "0123456789", itsCountManager->size());
}

bool ConsoleRefineDriver::refineStoneChoice(InputChecker& inputChecker)
{
	std::string stone;
	std::cout << itsAbstractIO->input("Использовать камни?\n\t0 (или ENTER) - Миражи, 1 - Небески, 2 - Подземки, 3 - Мирозданки\n");
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
	default:
	{
		std::cerr << "Stone with index " << stone << " - dosn't exist\n";
		std::cerr <<"It will be set to 0\n";
		refineResult = Refine::goRefining(itsCountManager->at(MLib::stoi(armorNumber.c_str()))->armor(), new MirageCelestone());
	}
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
	std::string choice;
	std::cout << itsAbstractIO->input("\nПоказать список всех доспехов (p), продолжить заточку (r или ENTER) или завершить программу (q)?\n");
	std::getline(std::cin, choice);

	return inputChecker.check(choice, "prq", 1);
}

bool ConsoleRefineDriver::distributorInput(InputChecker& inputChecker)
{
	std::string choice;
	std::cout << itsAbstractIO->input("Все доспехи введены. Показать список всех доспехов (p) или начать заточку (r)?\n");
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
	std::cout << itsAbstractIO->input(message1 + message2 + message1 + "\n");
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
		std::cerr << "Refine level is not in range 0..12\n";
		std::cerr <<"It will be set to 0\n";
		return T0;
	}
}

bool ConsoleRefineDriver::inputArmorCategory(InputChecker &inputChecker)
{
	std::string cCategory;
	std::cout << itsAbstractIO->input("0 - Оружие, 1 - Шлем, 2 - Накидка, 3 - Бриджи, 4 - Сапоги,\n");
	std::cout << itsAbstractIO->input("5 - Наручи, 6 - Плащ, 7 - Ожерелье, 8 - Пояс, 9 - Кольцо\n");
	std::getline(std::cin, cCategory);

	return inputChecker.check(cCategory, "0123456789qp", 1);
}

bool ConsoleRefineDriver::inputArmorProperty(InputChecker &inputChecker)
{
	std::string property;
	std::cout << itsAbstractIO->input("\nВведите название доспеха ");
	std::cout << itsAbstractIO->input(" (или ENTER):\n");
	itsAbstractIO->input("абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ -");
	std::getline(std::cin, property);

	return inputChecker.check(property, itsAbstractIO->output(), 29);
}

bool ConsoleRefineDriver::inputArmorRefineLevel(InputChecker &inputChecker)
{
	std::string refineLevel;
	std::cout << itsAbstractIO->input("Введите уровень заточки (или ENTER):\n");
	std::getline(std::cin, refineLevel);

	return inputChecker.check(refineLevel, "0123456789", 2);
}

void ConsoleRefineDriver::armorCreator(std::string choiceCategory,
		std::string property,
		std::string refineLevel,
		Armor *&armor)
{
	switch(MLib::stoi(choiceCategory.c_str()))
	{
	case 0:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 2, itsAbstractIO->input("ОРУЖИЕ"), property);
		break;
	}
	case 1:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("ШЛЕМ"), property);
		break;
	}
	case 2:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("НАКИДКА"), property);
		break;
	}
	case 3:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("БРИДЖИ"), property);
		break;
	}
	case 4:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("САПОГИ"), property);
		break;
	}
	case 5:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("НАРУЧИ"), property);
		break;
	}
	case 6:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("ПЛАЩ"), property);
		break;
	}
	case 7:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("ОЖЕРЕЛЬЕ"), property);
		break;
	}
	case 8:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("ПОЯС"), property);
		break;
	}
	case 9:
	{
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 1, itsAbstractIO->input("КОЛЬЦО"), property);
		break;
	}
	default:
	{
		std::cerr << "Category is not in range 0..9\n";
		std::cerr << "It will be set to \""	<< itsAbstractIO->input("ОРУЖИЕ") << "\"\n";
		armor = new Armor(intToRefineLevel(MLib::stoi(refineLevel.c_str())), 2, itsAbstractIO->output(), property);
	}
	}
}

void ConsoleRefineDriver::setArmorCategory(InputChecker& inputChecker)
{
	while (true)
	{
		try {
			if (inputArmorCategory(inputChecker))
			{
				break;
			}
		} catch (InputLimitException& e) {
			std::cerr << "Input limit exception. Maximum characters limit is "
					<< e.limit() << std::endl << std::endl;
		} catch (InputException& e)	{
			std::cerr << "Input exception. String " << inputChecker.str()
							<< " contains non legal characters: " << e.errorString()
							<< std::endl;
			std::cerr << "Candidates are: " << e.mask() << std::endl
					<< std::endl;
		}
	}
}

void ConsoleRefineDriver::setArmorProperty(InputChecker& inputChecker)
{
	while (true)
	{
		try
		{
			if (inputArmorProperty(inputChecker))
			{
				break;
			}
		} catch (InputLimitException& e)
		{
			std::cerr << "Input limit exception. Maximum characters limit is "
					<< e.limit() << std::endl << std::endl;
		} catch (InputException& e)
		{
			std::cerr << "Input exception. String " << inputChecker.str()
					<< " contains non legal characters: " << e.errorString()
					<< std::endl;
			std::cerr << "Candidates are: " << e.mask() << std::endl
					<< std::endl;
		}
	}
}

void ConsoleRefineDriver::setArmorRefineLevel(InputChecker& inputChecker)
{
	while (true)
	{
		try
		{
			if (inputArmorRefineLevel(inputChecker))
			{
				break;
			}
		} catch (InputLimitException& e)
		{
			std::cerr << "Input limit exception. Maximum characters limit is "
					<< e.limit() << std::endl << std::endl;
		} catch (InputException& e)
		{
			std::cerr << "Input exception. String " << inputChecker.str()
					<< " contains non legal characters: " << e.errorString()
					<< std::endl;
			std::cerr << "Candidates are: " << e.mask() << std::endl
					<< std::endl;
		}
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


	std::cout << itsAbstractIO->input("Введите доспехи для заточки.\n");

	while(true)
	{
		std::cout << itsAbstractIO->input("Доспех № ") << armorNumber;
		std::cout << itsAbstractIO->input(", вывести список всех доспехов (p) или выход (q):\n");

		setArmorCategory(inputChecker);
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

		setArmorProperty(inputChecker);
		property = inputChecker.str();

		setArmorRefineLevel(inputChecker);
		refineLevel = inputChecker.str();

		armorCreator(choiceCategory, property, refineLevel, armor);

		choiceCategory.clear();
		property.clear();
		refineLevel.clear();

		itsCountManager->addArmorToCount(armor);

		std::cout << std::endl;
	}
}

void ConsoleRefineDriver::headOutputResults()
{
	std::cout.fill(' ');
	std::cout << std::left << std::setw(10)	<< itsAbstractIO->input("Доспех №");
	std::cout << std::setw(10) << itsAbstractIO->input("Категория");
	std::cout << std::setw(30) << itsAbstractIO->input("Описание");
	std::cout << std::setw(8) << itsAbstractIO->input("Заточка");
	std::cout << std::setw(8) << itsAbstractIO->input("Миражей");
	std::cout << std::setw(8) << itsAbstractIO->input("Небесок");
	std::cout << std::setw(9) << itsAbstractIO->input("Подземок");
	std::cout << std::setw(10) << itsAbstractIO->input("Мирозданок\n");
}

void ConsoleRefineDriver::tailOutputResults()
{

	std::cout << std::setw(57)
	<< itsAbstractIO->input("Всего: ")
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
	switch(refine)
	{
	case SUCCESS:
	{
		std::cout << itsAbstractIO->input("Улучшение прошло успешно!\n");
		break;
	}
	case FAIL:
	{
		std::cout << itsAbstractIO->input("Улучшение не прошло. Уровень заточки снизился на 1 уровень.\n");
		break;
	}
	case NOCHANGE:
	{
		std::cout << itsAbstractIO->input("Улучшение не прошло. Уровень заточки не изменился.\n");
		break;
	}
	case RESET:
	{
		std::cout << itsAbstractIO->input("Улучшение не прошло. Уровень заточки снизился до 0.\n");
		break;
	}
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
			std::cerr << "Empty exception. Was not input any armor\n\n";
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
				std::cerr << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
			} catch (InputException &e) {
				std::cerr << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
				std::cerr << "Candidates are: " << e.mask() << std::endl << std::endl;
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
					std::cerr << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
				} catch (InputException &e) {
					std::cerr << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
					std::cerr << "Candidates are: " << e.mask() << std::endl << std::endl;
				}
			}
			stone = inputChecker.str();

			std::cout << std::endl;

			try {
				refineInfo(refineArmor(stone, armorNumber));
			} catch (RefineLevelException &e) {
				std::cerr << e.message() << std::endl;
			}
			std::cout << std::endl;
			outputResults(MLib::stoi(armorNumber.c_str()));
		}
		else
		{
			std::cerr << "Armor number dosn't in range 0.." << itsCountManager->size() - 1 << std::endl;
			std::cerr << "Try again...\n";
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
					std::cerr << "Input limit exception. Maximum characters limit is " << e.limit() << std::endl << std::endl;
				} catch (InputException &e) {
					std::cerr << "Input exception. String " << inputChecker.str() << " contains non legal characters: " << e.errorString() << std::endl;
					std::cerr << "Candidates are: " << e.mask() << std::endl << std::endl;
				}
			}
			choice = inputChecker.str();
		} while(choice == "p");
	}
}
