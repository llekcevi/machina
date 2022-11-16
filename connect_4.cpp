#include <iostream>
#include <algorithm>

// F U N C T I O N S
// draws the board with the all the moves made
void showBoard(char game_board[6][7])
{
    std::cout << "1 2 3 4 5 6 7" << std::endl;
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << game_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// checks for 4 same chars in every column in sequence that are not inital '_'
bool checkColumn(char game_board[6][7], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if ((game_board[i][j] == game_board[i + 1][j]) &&
                (game_board[i][j] == game_board[i + 2][j]) &&
                (game_board[i][j] == game_board[i + 3][j]) &&
                game_board[i + 2][j] != emptySpace)
            {
                return true;
            }
            else
                continue;
        }
    }
    return false;
}
// checks for 4 same chars in every row in sequence that are not inital '_'
bool checkRow(char game_board[6][7], char emptySpace)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((game_board[i][j] == game_board[i][j + 1]) &&
                (game_board[i][j] == game_board[i][j + 2]) &&
                (game_board[i][j] == game_board[i][j + 3]) &&
                game_board[i][j] != emptySpace)
            {
                return true;
            }
            else
                continue;
            ;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
// M A I N
int main()
{
    char empty = '_';
    bool first_players_turn = true;
    bool win = false;
    int chosen_column;
    char board[6][7];
    // intializes array "board" to '_'
    for (int i = 0; i < 6; i++)
    {
        memset(board[i], empty, 7);
    }
    //
    while (!win)
    {
        // prints out the board
        showBoard(board);
        //
        // player chooses a column to play
        first_players_turn ? std::cout << "X choose a column: " << std::endl : std::cout << "O chose a column" << std::endl;
        std::cin >> chosen_column;
        // prints players mark on the bottom of selected column
        for (int i = 0; i < 7; i++)
        {
            if (board[i][chosen_column - 1] == empty)
            {
                first_players_turn ? board[i][chosen_column - 1] = 'X' : board[i][chosen_column - 1] = 'O';
                break;
            };
        }
        //
        first_players_turn = !first_players_turn;
        //
        win = checkColumn(board, empty) || checkRow(board, empty);
    }
    showBoard(board);

    std::cout << "game over" << std::endl;
}
