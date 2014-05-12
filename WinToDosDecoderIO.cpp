/*
 * WinToDosConvertor.cpp
 *
 *  Created on: 21 апр. 2014
 *      Author: sergey
 */

#include "WinToDosDecoderIO.h"

WinToDosDecoderIO::WinToDosDecoderIO(AbstractIO* abstractIO)
: itsAbstractIO(abstractIO)
{
	Key<char, char> c[] = {
			{192, 128}, // Cyrillic big Ah
			{193, 129},
			{194, 130},
			{195, 131},
			{196, 132},
			{197, 133},
			{198, 134},
			{199, 135},
			{200, 136},
			{201, 137},
			{202, 138},
			{203, 139},
			{204, 140},
			{205, 141},
			{206, 142},
			{207, 143},
			{208, 144},
			{209, 145},
			{210, 146},
			{211, 147},
			{212, 148},
			{213, 149},
			{214, 150},
			{215, 151},
			{216, 152},
			{217, 153},
			{218, 154},
			{219, 155},
			{220, 156},
			{221, 157},
			{222, 158},
			{223, 159}, // Cyrillic big Ya
			{224, 160}, // Cyrillic small Ah
			{225, 161},
			{226, 162},
			{227, 163},
			{228, 164},
			{229, 165},
			{230, 166},
			{231, 167},
			{232, 168},
			{233, 169},
			{234, 170},
			{235, 171},
			{236, 172},
			{237, 173},
			{238, 174},
			{239, 175},
			{240, 224},
			{241, 225},
			{242, 226},
			{243, 227},
			{244, 228},
			{245, 229},
			{246, 230},
			{247, 231},
			{248, 232},
			{249, 233},
			{250, 234},
			{251, 235},
			{252, 236},
			{253, 237},
			{254, 238},
			{255, 239}, // Cyrillic small Ya
			{168, 240}, // Cyrillic big Yo
			{184, 241}, // Cyrillic small Yo
			{170, 242}, // Cyrillic big Ukrainian Ye
			{186, 243}, // Cyrillic small Ukrainian Ye
			{175, 244}, // Cyrillic big Ukrainian Yi
			{191, 245}, // Cyrillic small Ukrainian Yi
			{185, 252}  // Cyrillic number
	};

	int size = 71;
	Key<char, char>* keys_1251_866 = new Key<char, char>[size];
	for(int i = 0; i < size; ++i)
	{
		keys_1251_866[i].inChar = c[i].inChar;
		keys_1251_866[i].outChar = c[i].outChar;
	}

	itsKeys = new Keys1251to866(keys_1251_866, size);

	delete[] keys_1251_866;
	keys_1251_866 = 0;
}

WinToDosDecoderIO::~WinToDosDecoderIO() {
	delete itsAbstractIO;
	itsAbstractIO = 0;

	delete itsKeys;
	itsKeys = 0;
}

char* WinToDosDecoderIO::cp1251to866(char* c) throw(DecodingException)
{
	int count = 0;
	bool isMatch = false;

	while(c[count++])
	{
		isMatch = false;
		for(int i = 0; i < itsKeys->size(); ++i)
		{
			if(itsKeys->getKey(i).inChar == c[count])
			{
				c[count] = itsKeys->getKey(i).outChar;
				isMatch = true;
				break;
			}
		}
		if(!isMatch && c[count] > 0x7f)
		{
			throw DecodingException(*c, "WinToDosDecoderIO. Letter didn't match with key-table!");
		}
	}

	return c;
}

std::string WinToDosDecoderIO::output()
{
	return cp1251to866(const_cast<char*>(itsAbstractIO->output().c_str()));
}

std::string WinToDosDecoderIO::input(std::string s)
{
	itsAbstractIO->input(s);

	return output();
}
