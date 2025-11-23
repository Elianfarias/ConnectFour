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
    // Verificar horizontal
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c <= MAX_COLUMNS - 4; c++)
        {
            if (grid[r][c].isRevealed && grid[r][c].player == player &&
                grid[r][c + 1].isRevealed && grid[r][c + 1].player == player &&
                grid[r][c + 2].isRevealed && grid[r][c + 2].player == player &&
                grid[r][c + 3].isRevealed && grid[r][c + 3].player == player)
            {
                return true;
            }
        }
    }

    // Verificar vertical
    for (int c = 0; c < MAX_COLUMNS; c++)
    {
        for (int r = 0; r <= MAX_ROWS - 4; r++)
        {
            if (grid[r][c].isRevealed && grid[r][c].player == player &&
                grid[r + 1][c].isRevealed && grid[r + 1][c].player == player &&
                grid[r + 2][c].isRevealed && grid[r + 2][c].player == player &&
                grid[r + 3][c].isRevealed && grid[r + 3][c].player == player)
            {
                return true;
            }
        }
    }

    // Verificar diagonal descendente (\)
    for (int r = 0; r <= MAX_ROWS - 4; r++)
    {
        for (int c = 0; c <= MAX_COLUMNS - 4; c++)
        {
            if (grid[r][c].isRevealed && grid[r][c].player == player &&
                grid[r + 1][c + 1].isRevealed && grid[r + 1][c + 1].player == player &&
                grid[r + 2][c + 2].isRevealed && grid[r + 2][c + 2].player == player &&
                grid[r + 3][c + 3].isRevealed && grid[r + 3][c + 3].player == player)
            {
                return true;
            }
        }
    }

    // Verificar diagonal ascendente (/)
    for (int r = 3; r < MAX_ROWS; r++)
    {
        for (int c = 0; c <= MAX_COLUMNS - 4; c++)
        {
            if (grid[r][c].isRevealed && grid[r][c].player == player &&
                grid[r - 1][c + 1].isRevealed && grid[r - 1][c + 1].player == player &&
                grid[r - 2][c + 2].isRevealed && grid[r - 2][c + 2].player == player &&
                grid[r - 3][c + 3].isRevealed && grid[r - 3][c + 3].player == player)
            {
                return true;
            }
        }
    }

    return false;
}

bool IsValidPosition(int col)
{
    if (col < 0 || col >= MAX_COLUMNS)
        return false;

    return !grid[0][col].isRevealed;
}

void GameLoop()
{
    InitializeBoard();
    GridTile::Player currentPlayer = GridTile::Player::ONE;
    bool gameOver = false;
    int movesPlayed = 0;
    const int MAX_MOVES = MAX_ROWS * MAX_COLUMNS;

    while (!gameOver)
    {
        ClearConsoleAndDraw();

        char playerSymbol = (currentPlayer == GridTile::Player::ONE) ? '1' : '2';
        cout << "\nTurno del jugador " << playerSymbol << endl;
        cout << "Ingresa la columna (1-" << MAX_COLUMNS<< "): ";

        int col;
        cin >> col;
        col--;

        if (!IsValidPosition(col))
        {
            cout << "Columna invalida o llena. Presiona Enter para continuar...";
            cin.ignore();
            cin.get();
            continue;
        }

        int row = GetRowPosition(col);

        grid[row][col].isRevealed = true;
        grid[row][col].player = currentPlayer;
        grid[row][col].color = currentPlayer == GridTile::Player::ONE ? COLOR_RED_BG : COLOR_BLUE_BG;
        movesPlayed++;

        if (CheckWinPlayer(currentPlayer))
        {
            ClearConsoleAndDraw();
            cout << "\nJugador " << playerSymbol << " ha ganado!" << endl;
            gameOver = true;
        }
        else if (movesPlayed == MAX_MOVES)
        {
            ClearConsoleAndDraw();
            cout << "\nEmpate! El tablero esta lleno." << endl;
            gameOver = true;
        }
        else
        {
            currentPlayer = (currentPlayer == GridTile::Player::ONE)
                ? GridTile::Player::TWO
                : GridTile::Player::ONE;
        }
    }
}