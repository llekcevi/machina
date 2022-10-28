#include <iostream>
#include <algorithm>


int main () {

    char board[9];
    std::fill_n(board, 9 , '_');

    bool win = false;
    bool first_players_turn = true;
    int position;

    while (!win) {
        //prints the board
        std::cout<<board[0]<<" "<<board[1]<<" "<<board[2]<<std::endl;
        std::cout<<board[3]<<" "<<board[4]<<" "<<board[5]<<std::endl;
        std::cout<<board[6]<<" "<<board[7]<<" "<<board[8]<<std::endl;
        //

    //player choses where to put a mark
    std::cout<<"Choose your position"<<std::endl;
    std::cin>>position;
    //inputs x or o based on player order and position availability
        if (board[position-1] == '_') {
            first_players_turn ? board[position-1] = 'X' : board[position-1] = 'O';
            //next players turn
            first_players_turn = !first_players_turn;
            }
        else {std::cout<<"position taken, chose another one"<<std::endl;}
    //
    }
    std::cout<<board[0]<<" "<<board[1]<<" "<<board[2]<<std::endl;
    std::cout<<board[3]<<" "<<board[4]<<" "<<board[5]<<std::endl;
    std::cout<<board[6]<<" "<<board[7]<<" "<<board[8]<<std::endl;


    return 0;
}

