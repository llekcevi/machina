#include <iostream>
#include <algorithm>

void InitializeBoard(char gameBoard[]) 
{
    std::fill_n(gameBoard, 9, '_');

}

void ShowBoard(char gameBoard[9])
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << gameBoard[i]<<' ';
        if (i % 3 == 2)
        {
            std::cout << std::endl;
        }
    }
}

bool CheckWinner(char gameBoard[])
{
    bool first_row = ((gameBoard[0] == gameBoard[1]) && (gameBoard[0] == gameBoard[2])) && (gameBoard[0] != '_');
    bool second_row = ((gameBoard[3] == gameBoard[4]) && (gameBoard[3] == gameBoard[5])) && (gameBoard[3] != '_');
    bool third_row = ((gameBoard[6] == gameBoard[7]) && (gameBoard[6] == gameBoard[8])) && (gameBoard[6] != '_');
    bool first_column = ((gameBoard[0] == gameBoard[3]) && (gameBoard[0] == gameBoard[6])) && (gameBoard[0] != '_');
    bool second_column = ((gameBoard[2] == gameBoard[4]) && (gameBoard[2] == gameBoard[7])) && (gameBoard[2] != '_');
    bool third_column = ((gameBoard[3] == gameBoard[5]) && (gameBoard[3] == gameBoard[8])) && (gameBoard[3] != '_');
    bool left_to_right_d = ((gameBoard[0] == gameBoard[4]) && (gameBoard[0] == gameBoard[8])) && (gameBoard[0] != '_');
    bool right_to_left_d = ((gameBoard[3] == gameBoard[4]) && (gameBoard[3] == gameBoard[6])) && (gameBoard[3] != '_');

    if (
        ((first_row || second_row) || (third_row || first_column)) ||
        ((second_column || third_column) || (left_to_right_d || right_to_left_d)))

    {
        return true;
    }

    return false;
};

void GameOver(char gameBoard[], bool turn)
{
    std::cout << std::endl;
    ShowBoard(gameBoard);
    std::cout << std::endl;
    std::cout << "game over" << std::endl;
    std::cout << (turn ? "O wins" : "x wins") << std::endl;
}

void InputMove(char board[], bool firstPlayersTurn) 
{   
    
    int position;// player choses where to put a mark
    std::cout << "Choose your position" << std::endl;
    std::cin >> position;
    //
    // inputs x or o based on player order and position availability then reverses player order
    if (board[position - 1] == '_')
    {
        firstPlayersTurn ? board[position - 1] = 'X' : board[position - 1] = 'O';
    }
    else
    {
        std::cout << "position taken, chose another one" << std::endl;
    }
}


int main()
{
    bool win = false;
    bool first_players_turn = true;
    int position;
    char board[9];

    InitializeBoard(board);

    while (!win)
    {
        ShowBoard(board);
        InputMove(board, first_players_turn);
        first_players_turn = !first_players_turn;
        win = CheckWinner(board);
    }
    GameOver(board, first_players_turn);

    return 0;
}
