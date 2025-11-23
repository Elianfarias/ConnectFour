#include "GridTile.h"
#include <iostream>
#include <Windows.h>

using namespace std;

const int COLOR_WHITE = 7;
const int COLOR_GRAY_BG = 112;

GridTile::GridTile()
    : isRevealed(false), player(Player::NONE)
{
}

void GridTile::DrawTile()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (isRevealed)
    {
        char face = this->player == Player::ONE ? 'O' : 'X';
        SetConsoleTextAttribute(h, COLOR_WHITE);
        cout << face;
    }
    else
        cout << ' ';

    SetConsoleTextAttribute(h, COLOR_WHITE);
}