#include <iostream>
#include <string>

const char* iochecker::repeatedChars(const char* in, bool mask = true)
{
	std::string unRptMask;
	std::string symMask = in;

	for(unsigned int i = 0; i < symMask.size(); ++i)
	{
		for(unsigned int j = i + 1; j < symMask.size(); ++j)
		{
			if(symMask.at(i) == symMask.at(j))
			{
				unRptMask.push_back(symMask.at(j));
				symMask.erase(j, 1);
			}
		}
	}

	if(!mask)
    {
        return repeatedChars(unRptMask.c_str());
    }

	return symMask.c_str();
}

bool iochecker::eqSym(const char *mas, const unsigned char &ch)
{
	while(*mas)
	{
		if(*mas == ch)
		{
			return true;
		}
		++mas;
	}
	return false;
}

void iochecker::checker(unsigned int ch)
{
	fillUnMaskSmbs();
	if(eqSym(repeatedChars(m_mas), ch) && 
	(!eqSym(repeatedChars(m_mas, false), ch) || !emergUnMaskSym(ch)) && 
	m_buf->size() < m_lim)
	{		
		std::cout << (char)ch;
		m_buf->push_back(ch);
		checker(_getch());
	}
	else
	{
		switch(ch)
		{
		case BACKSPACE:
		{
			std::cout << (char)BACKSPACE << ' ' << (char)BACKSPACE;
			m_buf->pop_back();
			checker(_getch());
			break;
		}
		case ENTER:
		{
			std::cin.putback(ch);
			break;
		}
		default:
		{
			checker(_getch());
		}
		}
	}
}

private:
	struct UnMaksSymStruct
	{
		bool symWas;
		char name;
	};

std::vector<UnMaksSymStruct> m_vUnMaskSmbs;
void iochecker::fillUnMaskSmbs()
{
	UnMaksSymStruct smb;
	std::string s = repeatedChars(m_mas, false);
	for(unsigned int i = 0; i < s.size(); ++i)
	{
		smb.name = s.at(i);
		smb.symWas = false;
		m_vUnMaskSmbs.push_back(smb);
	}
}

bool iochecker::emergUnMaskSym(unsigned char ch)
{
	for(unsigned int i = 0; i < m_vUnMaskSmbs.size(); ++i)
	{
		if(m_vUnMaskSmbs.at(i).name == ch)
		{
			if(m_vUnMaskSmbs.at(i).symWas)
			{
				return true;
			}
			else
			{
				m_vUnMaskSmbs.at(i).symWas = true;
			}
		}
	}
	
	return false;
}
/******************************************************************************/
enum ZEROFLAGS
{
    LEADING = 0x01,
    TRAILING = 0x02,
    NOCHANGED = -1
};

std::vector<unsigned char> iochecker::buffer(ZEROFLAGS zeros)
{
    if((zeros == LEADING) && m_buf->size() > 1)
    {
        while(m_buf->at(0) == '0' && m_buf->at(1) != '.')
        {
            m_buf->erase(m_buf->begin());
        }

        return *m_buf;
    }

    if((zeros == TRAILING) && m_buf->size() > 1)
    {
        bool dot = false;
        unsigned int i = 0;
        while(i < m_buf->size() && !dot)
        {
            if(m_buf->at(i++) == '.')
            {
                dot = true;
            }
        }
        while(m_buf->at(m_buf->size() - 1) == '0' && dot)
        {
            m_buf->erase(m_buf->end() - 1);
        }

        return *m_buf;
    }

    return *m_bufOrigin;
}

std::string iochecker::stringBuffer(ZEROFLAGS zeros)
{
    std::string s;

    buffer(zeros);


        if(zeros == NOCHANGED)
        {
            for(unsigned int index = 0; index < m_bufOrigin->size(); ++index)
            {
                s.push_back(m_bufOrigin->at(index));
            }
        }
        else
        {
            for(unsigned int index = 0; index < m_buf->size(); ++index)
            {
                s.push_back(m_buf->at(index));
            }
        }

    return s;
}

const char *iochecker::charBuffer(ZEROFLAGS zeros)
{
    return stringBuffer(zeros).c_str();
}
