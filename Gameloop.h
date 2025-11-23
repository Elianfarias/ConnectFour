#pragma once
#include "GridTile.h"

void GameLoop();
bool IsValidPosition(int col);
bool CheckWinPlayer(enum GridTile::Player player);
void ClearConsoleAndDraw();