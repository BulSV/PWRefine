bool flag = false;
while(1)
{
int ch = _getch(); // —читывает символ из потока, но не выводит его в поток.
// Ёто своего рода защита ввода
if(flag && ch == 13)
{
    std::cin.putback(ch);
    break;
}
if( (ch >= '0' && ch <= '9') || ch == 'q')
{
    cat = ch;
    std::cout << '\r' << cat;
    ch = _getch();
    if(ch == 13)
    {
        std::cin.putback(ch);
        break;
    }
    //std::cout << (char)8;
    std::cout << '\r';
    std::cout << (char)ch;
    flag = true;
}
}
std::cin.get();

std::cout << std::endl;
/******************************************************************************/
void inputSymbol(int &ch, char beginCh, char endCh)
{
    bool flag = false;
    int tempCh;
    while(1)
    {
        ch = _getch(); // —читывает символ из потока, но не выводит его в поток.
        // Ёто своего рода защита ввода
        if(flag && ch == 13)
        {
            std::cin.putback(ch);
            ch = tempCh;
            break;
        }
        if(ch >= beginCh && ch <= endCh)
        {
            std::cout << '\r' << (char)ch;
            tempCh = ch;
            ch = _getch();
            if(ch == 13)
            {
                std::cin.putback(ch);
                ch = tempCh;
                break;
            }
            //std::cout << (char)8;
            std::cout << '\r';
            std::cout << (char)ch;
            flag = true;
        }
    }
    std::cin.get();

    std::cout << std::endl;
}
