#pragma once
#include "Gridtile.h"

const int MAX_ROWS = 4;
const int MAX_COLUMNS = 4;
const int PAIRS = (MAX_ROWS * MAX_COLUMNS) / 2;

extern GridTile grid[MAX_ROWS][MAX_COLUMNS];

void InitializeBoard();
void DrawGrid();