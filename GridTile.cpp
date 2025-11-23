#include "GridTile.h"
#include <iostream>
#include <Windows.h>

using namespace std;

const int COLOR_WHITE = 7;
const int COLOR_GRAY_BG = 112;


GridTile::GridTile()
    : isRevealed(false), player(Player::NONE), color(COLOR_GRAY_BG)
{
}