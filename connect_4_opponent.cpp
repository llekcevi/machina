#include <iostream>
#include <algorithm>

//------------------
// F U N C T I O N S
//------------------
void InitializeBoard(char gameBoard[6][7], char emptySpace)
{
    for (int i = 0; i < 6; i++)
    {
        memset(gameBoard[i], emptySpace, 7);
    }
}

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

void InputHuman(char gameBoard[6][7], char emptySpace)
{
    int chosen_column;

    std::cout << "Human, choose a column: " << std::endl; 
    std::cin >> chosen_column;

    for (int i = 0; i < 7; i++)
    {
        if (gameBoard[i][chosen_column - 1] == emptySpace)
        {
            gameBoard[i][chosen_column - 1] = 'X';
            break;
        }
    }
}

void InputComputer(char gameBoard[6][7], char emptySpace)
{
        while (true){int computer_choice = int(time(NULL) % 7);

        for (int i = 0; i < 7; i++)
        {
            if (gameBoard[i][computer_choice] == emptySpace)
            {   
                gameBoard[i][computer_choice] = '0';
                break;
            }
        } break;
        }
    
}

void InputMove(char gameBoard[6][7], char emptySpace, bool firstPlayersTurn)
{
    firstPlayersTurn ? InputHuman(gameBoard, emptySpace): InputComputer(gameBoard, emptySpace);
}

void EndGame(char gameBoard[6][7])
{
    system("clear");
    ShowBoard(gameBoard);
    std::cout << "game over" << std::endl;
}
//---------------
// WIN CONDITIONS
//---------------
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
//---------------

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
        InputMove(board, empty, first_players_turn);
        win = CheckColumn(board, empty) || CheckRow(board, empty) || CheckDiagonalDown(board, empty) || CheckDiagonalUp(board, empty);
        first_players_turn = !first_players_turn;
    }
    EndGame(board);
}
