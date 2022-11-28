#include <iostream>
#include <algorithm>
#include "connect_4_functions.cpp"
#include "connect_4.h"

// M A I N
int main()
{
    char empty = '_';
    bool first_players_turn = true;
    bool win = false;
    char board[6][7];
    InitializeBoard(board, empty);

    while (!win)
    {
        system("clear");
        ShowBoard(board);
        InputMoveMulti(board, empty, first_players_turn);
        win = CheckWin(board, empty);
        first_players_turn = !first_players_turn;
    }
    EndGame(board);
}

