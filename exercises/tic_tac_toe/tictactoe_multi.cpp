#include <iostream>
#include <algorithm>
#include <string>
#include "tictactoe.h"
#include "tictactoe_functions.cpp"

int main()
{
    bool win = false;
    bool first_players_turn = true;
    char board[3][3];
    int turns = 0;
    char empty = '_';
    std::string names[2];


    InitializeBoard(board, empty);
    //input names
    std::cout<<"Input your names."<<std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout<<"Player no. "<<i+1<<". :"<<std::endl;
        std::cin>>names[i];
    }
    //

    while (!win && turns < 9)
    {
        //system("clear");
        ShowBoard(board);
        InputMoveMulti(board, first_players_turn, empty);
        win = CheckWinner(board, empty);
        first_players_turn = !first_players_turn;
        turns = turns + 1;
    }
    GameOver(board, first_players_turn, turns);

    return 0;
}
