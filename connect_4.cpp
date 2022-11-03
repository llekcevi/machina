#include <iostream>
#include <algorithm>

void showBoard(char game_board[6][7]);

int main() {
    bool first_players_turn = true;
    bool win = false;
    int chosen_column;
    char board[6][7];
    //intializes array "board" to '_'
    for (int i = 0; i < 7; i++) {memset(board[i],'_', 7);}
    //
    while (win == false) {
        //prints out the board
        showBoard(board);
        //
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
        first_players_turn = !first_players_turn;
        //
    }
}

//F U N C T I O N S    
void showBoard (char game_board[6][7]){    
    std::cout<<"1 2 3 4 5 6 7"<<std::endl;
    for (int i = 5; i >= 0; i--) {
        std::cout<<game_board[i][0]<<" "<<game_board[i][1]<<" "<<game_board[i][2]<<" "<<game_board[i][3]<<" "<<game_board[i][4]<<" "<<game_board[i][5]<<" "<<game_board[i][6]<<std::endl;
    }
}    
//

