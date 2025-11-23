#pragma once
#include "Gridtile.h"

const int MAX_ROWS = 6;
const int MAX_COLUMNS = 7;
const int PAIRS = (MAX_ROWS * MAX_COLUMNS) / 2;
const int COLOR_RED_BG = 64;      // Fondo rojo
const int COLOR_BLUE_BG = 16;     // Fondo azul

extern GridTile grid[MAX_ROWS][MAX_COLUMNS];

void InitializeBoard();
void DrawGrid();
int GetRowPosition(int col);