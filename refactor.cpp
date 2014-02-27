void Dospeh::refine(Stone* stone);

float Mirazh::itsDopVer = 0;
float Mirazh::dopVer() const
{
    return itsDopVer;
}

virtual float Stone::dopVer() const = 0;

float Refine::verStone(int tochka, Stone* stone)
{
    switch(tochka)
    {
    case 0: return ((float)tochka() + stone->dopVer());
    case 1: return ((float)(tochka() - 20) + stone->dopVer());
    case 2: return ((float)(tochka() - 20) + stone->dopVer());
    case 3: return ((float)(tochka() - 20) + stone->dopVer());
    case 4: return ((float)(tochka() - 20) + stone->dopVer());
    case 5: return ((float)(tochka() - 20) + stone->dopVer());
    case 6: return ((float)(tochka() - 20) + stone->dopVer());
    case 7: return ((float)(tochka() - 20) + stone->dopVer());
    case 8: return ((float)(tochka() - 25) + stone->dopVer());
    case 9: return ((float)(tochka() - 30) + stone->dopVer());
    case 10: return ((float)(tochka() - 38) + stone->dopVer());
    case 11: return ((float)(tochka() - 31) + stone->dopVer());
    default: exit(-3);
    }
}
