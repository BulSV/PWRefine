#ifndef IOCHECKER_H
#define IOCHECKER_H

#include <iostream>
#include <conio.h>
#include <vector.h>

class iochecker
{
public:
    iochecker();
    operator >> (int &ch);
};

#endif //IOCHECKER_H

#define BACKSPACE 8
#define ENTER 13
#define DELETE 127
#define LEFT
#define RIGHT

int ch;
int lim;
vector<char> buf;
char *mas;

bool cmp(const char *mas, const int &ch)
{
    while(*mas)
    {
        if(*mas == ch)
        {
            return true;
        }
        mas++;
    }
    return false;
}

while(buf.size() != lim)
{
    ch = _getch();
    if(cmp(mas, ch))
    {
        buf.push_back(ch);
    }
    switch(ch)
    {
    case BACKSPACE:
    {
        std::cout << (char)ch;
        buf.pop_back();
        break;
    }
    case DELETE:
    {
        std::cout << (char)ch;
        break;
    }
    case LEFT:
    {
        std::cout << (char)ch;
        break;
    }
    case RIGHT:
    {
        std::cout << (char)ch;
        break;
    }
    case ENTER:
    {
        std::cin.putback(ch);
    }
    }
}
