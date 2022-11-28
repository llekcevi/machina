#include <iostream>
#include <algorithm>
#include "tictactoe.h"
#include "tictactoe_functions.cpp"

int main()
{
    srand(time(NULL));
    bool win = false;
    bool humans_turn = true;
    char board[3][3];
    int turns = 0;
    char empty = '_';

    InitializeBoard(board, empty);

    while (!win && turns < 9)
    {
        system("clear");
        ShowBoard(board);
        InputMoveSingle(board, humans_turn, empty);
        win = CheckWinner(board, empty);
        humans_turn = !humans_turn;
        turns = turns + 1;
    }
    GameOver(board, humans_turn, turns);

    return 0;
}
