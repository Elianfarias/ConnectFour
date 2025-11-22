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

bool IsValidPosition(int row, int col)
{
    return row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLUMNS;
}

void GameLoop()
{
    srand((unsigned)time(nullptr));
    InitializeBoard();

    int pairsFound = 0;
    int moves = 0;

    while (pairsFound < PAIRS)
    {
        int row1, row2, col1, col2;

        ClearConsoleAndDraw();
        cout << "Movimientos: " << moves << "    Parejas encontradas: " << pairsFound << " / " << PAIRS << "\n\n";

        // Primera selección
        cout << "Selecciona la FILA: ";
        cin >> row1;
        cout << "Selecciona la COLUMNA: ";
        cin >> col1;
        row1--;
        col1--;

        if (!IsValidPosition(row1, col1))
        {
            cout << "Selecciona una columna/fila valida. Presiona una tecla para continuar...";
            _getch();
            continue;
        }

        if (grid[row1][col1].isMatched)
        {
            cout << "Esa carta ya fue emparejada. Presiona una tecla para continuar...";
            _getch();
            continue;
        }

        if (grid[row1][col1].isRevealed)
        {
            cout << "Esa carta ya está revelada. Presiona una tecla para continuar...";
            _getch();
            continue;
        }

        grid[row1][col1].isRevealed = true;
        ClearConsoleAndDraw();

        // Segunda selección
        cout << "Selecciona la FILA: ";
        cin >> row2;
        cout << "Selecciona la COLUMNA: ";
        cin >> col2;
        row2--;
        col2--;

        if (!IsValidPosition(row2, col2))
        {
            cout << "Selecciona una columna/fila valida. Presiona una tecla para continuar...";
            grid[row1][col1].isRevealed = false;
            _getch();
            continue;
        }

        if (row1 == row2 && col1 == col2)
        {
            cout << "No podés seleccionar la misma carta dos veces. Presiona una tecla para continuar...";
            grid[row1][col1].isRevealed = false;
            _getch();
            continue;
        }

        if (grid[row2][col2].isMatched)
        {
            cout << "Esa carta ya fue emparejada. Presiona una tecla para continuar...";
            grid[row1][col1].isRevealed = false;
            _getch();
            continue;
        }

        if (grid[row2][col2].isRevealed)
        {
            cout << "Esa carta ya está revelada. Presiona una tecla para continuar...";
            grid[row1][col1].isRevealed = false;
            _getch();
            continue;
        }

        grid[row2][col2].isRevealed = true;
        ClearConsoleAndDraw();

        moves++;
        if (grid[row1][col1].face == grid[row2][col2].face)
        {
            grid[row1][col1].isMatched = true;
            grid[row2][col2].isMatched = true;
            pairsFound++;
            cout << "\n¡Encontraste una pareja!\n";
            cout << "Presiona una tecla para continuar...";
            _getch();
        }
        else
        {
            cout << "\nNo hay coincidencia.";
            cout << " Se ocultaran en 1.5 segundos...";
            Sleep(1500);
            grid[row1][col1].isRevealed = false;
            grid[row2][col2].isRevealed = false;
        }
    }

    ClearConsoleAndDraw();
    cout << "\nFelicidades! encontraste todas las parejas en " << moves << " movimientos.\n";
    cout << "Presiona una tecla para finalizar...";
    _getch();
}