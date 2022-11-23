#include <iostream>
#include <algorithm>
// TIC TAC TOE
//------------------
// F U N C T I O N S
//------------------
void InitializeBoard(char gameBoard[3][3], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        memset(gameBoard[i], emptySpace, 3);
    }
}

void ShowBoard(char gameBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << gameBoard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void GameOver(char gameBoard[3][3], bool turn, int numberOfTurns)
{
    system("clear");
    std::cout << std::endl;
    ShowBoard(gameBoard);
    std::cout << std::endl;
    std::cout << "Game over" << std::endl;
    if (numberOfTurns == 8)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << (turn ? "O wins" : "X wins") << std::endl;
    }
}

void InputMove(char board[3][3], bool firstPlayersTurn, char emptySpace)
{
    while (true)
    {
        int position;
        std::cout << std::endl;
        if (firstPlayersTurn)
        {
            std::cout << "X, choose your position" << std::endl;
        }
        else
        {
            std::cout << "O, choose your position" << std::endl;
        }
        std::cin >> position;
        if (board[(position - 1) / 3][(position - 1) % 3] == emptySpace)
        {
            firstPlayersTurn ? board[(position - 1) / 3][(position - 1) % 3] = 'X' : board[(position - 1) / 3][(position - 1) % 3] = 'O';
            break;
        }
        else
        {
            std::cout << "position taken" << std::endl;
        }
    }
}


//---------------
// WIN CONDITIONS
//---------------
bool CheckRow(char gameBoard[3][3], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        if ((gameBoard[i][0] == gameBoard[i][1]) &&
            (gameBoard[i][0] == gameBoard[i][2]) && (gameBoard[i][0] != emptySpace))
        {
            return true;
        }
        else
            continue;
    }
    return false;
}

bool CheckColumn(char gameBoard[3][3], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        if (gameBoard[0][i] == gameBoard[1][i] &&
            gameBoard[0][i] == gameBoard[2][i] && gameBoard[0][i] != emptySpace)
        {
            return true;
        }
        else
            continue;
    }
    return false;
}

bool CheckDiagonalUp(char gameBoard[3][3], char emptySpace)
{
    if (gameBoard[2][0] == gameBoard[1][1] &&
        gameBoard[2][0] == gameBoard[0][1] &&
        gameBoard[2][0] != emptySpace)
    {
        return true;
    }
    return false;
}

bool CheckDiagonalDown(char gameBoard[3][3], char emptySpace)
{
    if (gameBoard[0][0] == gameBoard[1][1] &&
        gameBoard[0][0] == gameBoard[2][2] &&
        gameBoard[0][0] != emptySpace)
    {
        return true;
    }
    return false;
}

bool CheckWinner(char gameBoard[3][3], char emptySpace)
{
    return CheckColumn(gameBoard, emptySpace) || CheckRow(gameBoard, emptySpace) || CheckDiagonalDown(gameBoard, emptySpace) || CheckDiagonalUp(gameBoard, emptySpace);
}

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
        //system("clear");
        ShowBoard(board);
        InputMove(board, first_players_turn, empty);
        win = CheckWinner(board, empty);
        first_players_turn = !first_players_turn;
        turns = turns + 1;
    }
    GameOver(board, first_players_turn, turns);

    return 0;
}
