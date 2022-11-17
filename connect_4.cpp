#include <iostream>
#include <algorithm>

// F U N C T I O N S
//-------------------
void ShowBoard(char game_board[6][7])
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

void InitializeBoard(char gameBoard[6][7], char emptySpace)
{
    for (int i = 0; i < 6; i++)
    {
        memset(gameBoard[i], emptySpace, 7);
    }
}

void EndGame(char gameBoard[6][7])
{   
    system("clear");
    ShowBoard(gameBoard);
    std::cout << "game over" << std::endl;
}
// WIN CONDITIONS
bool CheckDiagonalDown(char gameBoard[6][7], char emptySpace)
{
    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((gameBoard[i][j] == gameBoard[i - 1][j + 1]) &&
                (gameBoard[i][j] == gameBoard[i - 2][j + 2]) &&
                (gameBoard[i][j] == gameBoard[i - 3][j + 3]) &&
                gameBoard[i][j] != emptySpace)
            {
                return true;
            }
            else
                continue;
        }
    }
    return false;
}

bool CheckDiagonalUp(char gameBoard[6][7], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((gameBoard[i][j] == gameBoard[i + 1][j + 1]) &&
                (gameBoard[i][j] == gameBoard[i + 2][j + 2]) &&
                (gameBoard[i][j] == gameBoard[i + 3][j + 3]) &&
                gameBoard[i][j] != emptySpace)
            {
                return true;
            }
            else
                continue;
        }
    }
    return false;
}

bool CheckColumn(char game_board[6][7], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if ((game_board[i][j] == game_board[i + 1][j]) &&
                (game_board[i][j] == game_board[i + 2][j]) &&
                (game_board[i][j] == game_board[i + 3][j]) &&
                game_board[i][j] != emptySpace)
            {
                return true;
            }
            else
                continue;
        }
    }
    return false;
}

bool CheckRow(char game_board[6][7], char emptySpace)
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
    InitializeBoard(board, empty);

    while (!win)
    {   
        //dodati funkcije i petlju za ponovni upis ako je stupac pun
        system("clear");
        ShowBoard(board);
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
        win = CheckColumn(board, empty) || CheckRow(board, empty) || CheckDiagonalDown(board, empty) || CheckDiagonalUp(board, empty);
    }
    EndGame(board);
}
