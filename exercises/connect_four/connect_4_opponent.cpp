#include <iostream>
#include <algorithm>
#include "connect_4.h"
#include "connect_4_functions.cpp"

int main()
{   
    srand(time(NULL));
    char empty = '_';
    bool first_players_turn = true;
    bool win = false;
    char board[6][7];
    InitializeBoard(board, empty);

    while (!win)
    {
        system("clear");
        ShowBoard(board);
        InputMoveSingle(board, empty, first_players_turn);
        win = CheckColumn(board, empty) || CheckRow(board, empty) || CheckDiagonalDown(board, empty) || CheckDiagonalUp(board, empty);
        first_players_turn = !first_players_turn;
    }
    EndGame(board);
}
