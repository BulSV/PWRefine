/*
 * Utf8ToWinDecoderIO.cpp
 *
 *  Created on: 21 ���. 2014 �.
 *      Author: sergey
 */
#include "Utf8ToWinDecoderIO.h"

int* Utf8ToWinDecoderIO::reverse(int* c, int size)
{
	for(int i = 0; i < size; ++i)
	{
		c[i] = (c[i] & 0x0000ffff) << 16 | (c[i] & 0xffff0000) >> 16;
		c[i] = (c[i] & 0x00ff00ff) << 8 | (c[i] & 0xff00ff00) >> 8;
	}

	return c;
}

int Utf8ToWinDecoderIO::tableCheck(int c) throw (DecodingException)
{
	bool isMatch = false;

	for(int i = 0; i < itsKeys->size(); ++i)
	{
		if(c == itsKeys->getKey(i).inChar)
		{
			c = itsKeys->getKey(i).outChar;
			isMatch = true;
			break;
		}
	}

	if(!isMatch)
	{
		throw DecodingException(c, "Utf8ToWinDecoderIO. Letter didn't match with key-table!");
	}

	return c;
}

char* Utf8ToWinDecoderIO::cpUtf8to1251(int* c, int size)
{
	int count = size % sizeof(int) ? (size / 4 + 1) : size / 4;
	int tempChar = 0;
	std::string strChar;
	int* Char = new int[sizeof(int)];
	int* tempC = new int[count];

	for(int i = 0; i < count; ++i)
	{
		tempC[i] = c[i];
	}

	tempC = reverse(tempC, count);

	for(int i = 0; i < count; ++i)
	{
		for(size_t j = 0; j < sizeof(int); ++j)
		{
			Char[j] = (tempC[i] & (0xff000000 >> 8*j)) >> (8*(sizeof(int) - 1 - j));

			if(Char[j] < 0x7f && Char[j] >= 0)
			{
				strChar.push_back((char)Char[j]);
			}
			else
			{
				if(tempChar)
				{
					tempChar += Char[j];
					strChar.push_back((char)tableCheck(tempChar));
					tempChar = 0;
				}
				else
				{
					tempChar = (Char[j] << 8);
				}
			}
		}
	}

	return const_cast<char*>(strChar.c_str());
}


Utf8ToWinDecoderIO::Utf8ToWinDecoderIO(AbstractIO* abstractIO)
: itsAbstractIO(abstractIO)
{
	Key<int, char> c[] = {
			{0xd090, 192}, // Cyrillic big Ah
			{0xd091, 193},
			{0xd092, 194},
			{0xd093, 195},
			{0xd094, 196},
			{0xd095, 197},
			{0xd096, 198},
			{0xd097, 199},
			{0xd098, 200},
			{0xd099, 201},
			{0xd09a, 202},
			{0xd09b, 203},
			{0xd09c, 204},
			{0xd09d, 205},
			{0xd09e, 206},
			{0xd09f, 207},
			{0xd0a0, 208},
			{0xd0a1, 209},
			{0xd0a2, 210},
			{0xd0a3, 211},
			{0xd0a4, 212},
			{0xd0a5, 213},
			{0xd0a6, 214},
			{0xd0a7, 215},
			{0xd0a8, 216},
			{0xd0a9, 217},
			{0xd0aa, 218},
			{0xd0ab, 219},
			{0xd0ac, 220},
			{0xd0ad, 221},
			{0xd0ae, 222},
			{0xd0af, 223}, // Cyrillic big Ya
			{0xd0b0, 224}, // Cyrillic small Ah
			{0xd0b1, 225},
			{0xd0b2, 226},
			{0xd0b3, 227},
			{0xd0b4, 228},
			{0xd0b5, 229},
			{0xd0b6, 230},
			{0xd0b7, 231},
			{0xd0b8, 232},
			{0xd0b9, 233},
			{0xd0ba, 234},
			{0xd0bb, 235},
			{0xd0bc, 236},
			{0xd0bd, 237},
			{0xd0be, 238},
			{0xd0bf, 239},
			{0xd180, 240},
			{0xd181, 241},
			{0xd182, 242},
			{0xd183, 243},
			{0xd184, 244},
			{0xd185, 245},
			{0xd186, 246},
			{0xd187, 247},
			{0xd188, 248},
			{0xd189, 249},
			{0xd18a, 250},
			{0xd18b, 251},
			{0xd18c, 252},
			{0xd18d, 253},
			{0xd18e, 254},
			{0xd18f, 255}, // Cyrillic small Ya
			{0xd191, 184}, // Cyrillic small Yo
			{0xd194, 186}, // Cyrillic small Ukrainian Ye
//			{0xd196, 179}, // Cyrillic small Ukrainian I
			{0xd197, 191}, // Cyrillic small Ukrainian Yi
			{0xd081, 168}, // Cyrillic big Yo
			{0xd087, 175}, // Cyrillic big Ukrainian Yi
//			{0xd086, 178}, // Cyrillic big Ukrainian I
			{0xd084, 170}, // Cyrillic big Ukrainian Ye
			{0xe284, 185}  // Cyrillic number
	};

//	int size = 73;
	int size = 71;
	Key<int, char>* keys_utf8_1251 = new Key<int, char>[size];
	for(int i = 0; i < size; ++i)
	{
		keys_utf8_1251[i].inChar = c[i].inChar;
		keys_utf8_1251[i].outChar = c[i].outChar;
	}

	itsKeys = new KeysUtf8to1251(keys_utf8_1251, size);

	delete[] keys_utf8_1251;
	keys_utf8_1251 = 0;
}

Utf8ToWinDecoderIO::~Utf8ToWinDecoderIO()
{
	delete itsAbstractIO;
	itsAbstractIO = 0;

	delete itsKeys;
	itsKeys = 0;
}

std::string Utf8ToWinDecoderIO::output()
{
	std::string s = itsAbstractIO->output();

	return cpUtf8to1251((int*)const_cast<char*>(s.c_str()), s.size());
}

std::string Utf8ToWinDecoderIO::input(std::string s)
{
	itsAbstractIO->input(s);

	return output();
}
