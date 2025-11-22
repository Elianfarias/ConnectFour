#include "GridTile.h"
#include <iostream>
#include <Windows.h>

using namespace std;

const int COLOR_WHITE = 7;
const int COLOR_GRAY_BG = 112;

GridTile::GridTile()
    : face(' '), isRevealed(false), isMatched(false)
{
}

void GridTile::DrawTile()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (isRevealed || isMatched)
    {
        SetConsoleTextAttribute(h, COLOR_WHITE);
        cout << face;
    }
    else
    {
        cout << '?';
    }

    SetConsoleTextAttribute(h, COLOR_WHITE);
}