#pragma once
#include "Gridtile.h"

const int MAX_ROWS = 6;
const int MAX_COLUMNS = 7;
const int PAIRS = (MAX_ROWS * MAX_COLUMNS) / 2;

extern GridTile grid[MAX_ROWS][MAX_COLUMNS];

void InitializeBoard();
void DrawGrid();
int GetRowPosition(int col);