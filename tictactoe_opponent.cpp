#include <iostream>
#include <algorithm>

void InitializeBoard(char gameBoard[], char emptySpace)
{
    std::fill_n(gameBoard, 9, emptySpace);
}

void ShowBoard(char gameBoard[9])
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << gameBoard[i] << ' ';
        if (i % 3 == 2)
        {
            std::cout << std::endl;
        }
    }
}

bool CheckWinner(char gameBoard[], char emptySpace)
{
    bool first_row = ((gameBoard[0] == gameBoard[1]) && (gameBoard[0] == gameBoard[2])) && (gameBoard[0] != emptySpace);
    bool second_row = ((gameBoard[3] == gameBoard[4]) && (gameBoard[3] == gameBoard[5])) && (gameBoard[3] != emptySpace);
    bool third_row = ((gameBoard[6] == gameBoard[7]) && (gameBoard[6] == gameBoard[8])) && (gameBoard[6] != emptySpace);
    bool first_column = ((gameBoard[0] == gameBoard[3]) && (gameBoard[0] == gameBoard[6])) && (gameBoard[0] != emptySpace);
    bool second_column = ((gameBoard[2] == gameBoard[4]) && (gameBoard[2] == gameBoard[7])) && (gameBoard[2] != emptySpace);
    bool third_column = ((gameBoard[3] == gameBoard[5]) && (gameBoard[3] == gameBoard[8])) && (gameBoard[3] != emptySpace);
    bool left_to_right_diagonal = ((gameBoard[0] == gameBoard[4]) && (gameBoard[0] == gameBoard[8])) && (gameBoard[0] != emptySpace);
    bool right_to_left_diagonal = ((gameBoard[3] == gameBoard[4]) && (gameBoard[3] == gameBoard[6])) && (gameBoard[3] != emptySpace);

    if (
        (first_row || second_row || third_row || first_column ||
         second_column || third_column || left_to_right_diagonal || right_to_left_diagonal))
    {
        return true;
    }

    return false;
};

void InputComputer(char gameBoard[], char emptySpace)
{


        int computer_choice = int(time(NULL)) % 10;

        if (gameBoard[computer_choice] == emptySpace)
        {
            gameBoard[computer_choice] = '0';
            //<break;
        }
    
}

void InputHuman(char gameBoard[], char emptySpace)
{
    while (true)
    {
        int position;
        std::cout << std::endl;
        std::cout << "Choose your position" << std::endl;
        std::cin >> position;
        if (gameBoard[position - 1] == emptySpace)
        {
            gameBoard[position - 1] = 'X';
            break;
        }
        else
        {
            std::cout << "position taken" << std::endl;
        }
    }
}

void InputMove(char board[], bool firstPlayersTurn, char emptySpace)
{
    firstPlayersTurn? InputHuman(board, emptySpace): InputComputer(board, emptySpace);
}

void GameOver(char gameBoard[], bool turn, int numberOfTurns)
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

int main()
{
    bool win = false;
    bool humans_turn = true;
    char board[9];
    int turns = 0;
    char empty = '_';

    InitializeBoard(board, empty);

    while (!win && turns < 9)
    {
        system("clear");
        ShowBoard(board);
        InputMove(board, humans_turn, empty);
        win = CheckWinner(board, empty);
        humans_turn = !humans_turn;
        turns = turns + 1;
    }
    GameOver(board, humans_turn, turns);

    return 0;
}
