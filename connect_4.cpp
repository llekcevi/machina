#include <iostream>
#include <algorithm>

int main() {
    bool first_players_turn = true;
    bool win = false;
    int chosen_column;
    char board[6][7];
    //intializes array "board" to '_'
    for (int i = 0; i < 7; i++) {memset(board[i],'_', 7);}
    //
    //prints out the board
    std::cout<<"1 2 3 4 5 6 7"<<std::endl;
    for (int i = 5; i >= 0; i--) {
        std::cout<<board[i][0]<<" "<<board[i][1]<<" "<<board[i][2]<<" "<<board[i][3]<<" "<<board[i][4]<<" "<<board[i][5]<<" "<<board[i][6]<<std::endl;
    }
    //
    while (win == false) {
        //player chooses a column to play
        first_players_turn ? std::cout<<"X choose a column: "<<std::endl : std::cout<<"O chose a column"<<std::endl;
        std::cin>>chosen_column;
        //prints players mark on the bottom of selected column
        for (int i = 0; i < 7; i++) {
            if (board[i][chosen_column-1] == '_') {
                first_players_turn ? board[i][chosen_column-1] = 'X' : board[i][chosen_column-1]='O';
                break;
            } ;
        } 
        //
        //prints out the board
        std::cout<<"1 2 3 4 5 6 7"<<std::endl;
        for (int i = 5; i >= 0; i--) {
        std::cout<<board[i][0]<<" "<<board[i][1]<<" "<<board[i][2]<<" "<<board[i][3]<<" "<<board[i][4]<<" "<<board[i][5]<<" "<<board[i][6]<<std::endl;
        }
        first_players_turn = !first_players_turn;
        //
    }
}

        

