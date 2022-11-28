#include <iostream>
#include <algorithm>
#include "tictactoe.h"
#include "tictactoe_functions.cpp"

int main()
{
    bool win = false;
    bool first_players_turn = true;
    char board[3][3];
    int turns = 0;
    char empty = '_';

    InitializeBoard(board, empty);

    while (!win && turns < 9)
    {
        system("clear");
        ShowBoard(board);
        InputMoveMulti(board, first_players_turn, empty);
        win = CheckWinner(board, empty);
        first_players_turn = !first_players_turn;
        turns = turns + 1;
    }
    GameOver(board, first_players_turn, turns);

    return 0;
}
