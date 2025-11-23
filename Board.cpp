#include "Board.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iostream>

using namespace std;

const char VERTICAL = 186;
const char HORIZONTAL = 205;
const char TOP_LEFT = 201;
const char BOTTOM_LEFT = 200;
const char BOTTOM_RIGHT = 188;
const char TOP_RIGHT = 187;
const char T_UP = 202;
const char T_DOWN = 203;
const char T_RIGHT = 204;
const char T_LEFT = 185;
const char CROSS = 206;

const int COLOR_GRAY_BG = 112;
const int COLOR_WHITE = 7;

GridTile grid[MAX_ROWS][MAX_COLUMNS];

void InitializeBoard()
{
    vector<char> symbols;

    for (int i = 0; i < PAIRS; ++i)
    {
        char ch = 'A' + i;
        symbols.push_back(ch);
        symbols.push_back(ch);
    }

    random_shuffle(symbols.begin(), symbols.end());

    int idx = 0;
    for (int r = 0; r < MAX_ROWS; ++r)
    {
        for (int c = 0; c < MAX_COLUMNS; ++c)
        {
            grid[r][c].isRevealed = false;
        }
    }
}

void DrawGrid()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, COLOR_GRAY_BG);

    for (int fil = 0; fil < MAX_ROWS; fil++)
    {
        if (fil == 0)
            cout << TOP_LEFT;
        else
            cout << T_RIGHT;

        for (int i = 0; i < MAX_COLUMNS; i++)
        {
            cout << HORIZONTAL << HORIZONTAL << HORIZONTAL;
            if (i != MAX_COLUMNS - 1)
            {
                if (fil == 0)
                    cout << T_DOWN;
                else
                    cout << CROSS;
            }
        }

        if (fil == 0)
            cout << TOP_RIGHT << endl;
        else
            cout << T_LEFT << endl;

        cout << VERTICAL;
        for (int col = 0; col < MAX_COLUMNS; col++)
        {
            SetConsoleTextAttribute(h, grid[fil][col].color);
            cout << "   ";
            SetConsoleTextAttribute(h, COLOR_GRAY_BG);
            cout << VERTICAL;
        }
        cout << endl;
    }

    cout << BOTTOM_LEFT;
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        cout << HORIZONTAL << HORIZONTAL << HORIZONTAL;

        if (i != MAX_COLUMNS - 1)
            cout << T_UP;
    }
    cout << BOTTOM_RIGHT << endl;
    SetConsoleTextAttribute(h, COLOR_WHITE);
}

int GetRowPosition(int col)
{
    for (int r = MAX_ROWS - 1; r >= 0; r--)
    {
        if (!grid[r][col].isRevealed)
            return r;
    }

    return -1;
}