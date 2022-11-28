//------------------
// GENERAL FUNCTIONS
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
    std::cout << std::endl;
    if (numberOfTurns == 8)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << (turn ? "Computer wins" : "Human wins") << std::endl;
    }
}
//----------------
// INPUT FUNCTIONS
//----------------
void InputHuman(char gameBoard[3][3], char emptySpace)
{
    while (true)
    {
        int position;
        std::cout << std::endl;
        std::cout << "Choose your position" << std::endl;
        std::cin >> position;
        if (gameBoard[(position - 1) / 3][(position - 1) % 3] == emptySpace)
        {
            gameBoard[(position - 1) / 3][(position - 1) % 3] = 'X';
            break;
        }
        else
        {
            std::cout << "position taken" << std::endl;
        }
    }
}

void RandomInputComputer(char gameBoard[3][3], char emptySpace)
{
    while (true)
    {
        int computer_choice = rand() % 10;

        if (gameBoard[(computer_choice - 1) / 3][(computer_choice - 1) % 3] == emptySpace)
        {
            gameBoard[(computer_choice - 1) / 3][(computer_choice - 1) % 3] = '0';
            break;
        }
    }
}

void InputMoveSingle(char board[3][3], bool humansTurn, char emptySpace)
{
    humansTurn ? InputHuman(board, emptySpace) : RandomInputComputer(board, emptySpace);
}

void InputMoveMulti(char board[3][3], bool firstPlayersTurn, char emptySpace)
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
