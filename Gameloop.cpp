#include "GameLoop.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "Board.h"

using namespace std;

void ClearConsoleAndDraw()
{
    system("cls");
    DrawGrid();
}

bool CheckWinPlayer(GridTile::Player player)
{
    return false;
}

void GameLoop()
{
    srand((unsigned)time(nullptr));
    InitializeBoard();

    int pairsFound = 0;
    int moves = 0;

    while (pairsFound < PAIRS)
    {
        int col1, col2;

        ClearConsoleAndDraw();
        cout << "Movimientos: " << moves << "    Parejas encontradas: " << pairsFound << " / " << PAIRS << "\n\n";

        cout << "Jugador 1 - Selecciona la COLUMNA: ";
        cin >> col1;
        col1--;
        int row = GetRowPosition(col1);

        if (!IsValidPosition(row, col1))
        {
            cout << "Selecciona una columna/fila valida. Presiona una tecla para continuar...";
            grid[row][col1].isRevealed = false;
            _getch();
            continue;
        }

        if (CheckWinPlayer(GridTile::Player::ONE))
        {
            cout << "Felicidades Jugador 1, has ganado!";
            _getch();
            continue;
        }

        if (grid[row][col1].isRevealed)
        {
            cout << "Este lugar ya está ocupado. Presiona una tecla para continuar...";
            _getch();
            continue;
        }

        grid[row][col1].isRevealed = true;
        grid[row][col1].player = GridTile::Player::ONE;

        ClearConsoleAndDraw();

        cout << "Jugador 2 - Selecciona la COLUMNA: ";
        cin >> col2;
        col2--;

        if (!IsValidPosition(row, col2))
        {
            cout << "Selecciona una columna/fila valida. Presiona una tecla para continuar...";
            grid[row][col2].isRevealed = false;
            _getch();
            continue;
        }

        if (CheckWinPlayer(GridTile::Player::TWO))
        {
            cout << "Felicidades Jugador 2, has ganado!";
            _getch();
            continue;
        }

        if (grid[row][col2].isRevealed)
        {
            cout << "Este lugar ya está ocupado. Presiona una tecla para continuar...";
            grid[row][col2].isRevealed = false;
            _getch();
            continue;
        }

        grid[row][col2].isRevealed = true;
        grid[row][col2].player = GridTile::Player::TWO;
        ClearConsoleAndDraw();

        moves++;
    }

    ClearConsoleAndDraw();
    cout << "\nFelicidades! encontraste todas las parejas en " << moves << " movimientos.\n";
    cout << "Presiona una tecla para finalizar...";
    _getch();
}