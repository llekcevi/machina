#include <iostream>
#include <algorithm>

void show_board(char game_board[]);
bool check_winner(char game_board[]);
void game_over(char game_board[], bool turn);

int main()
{
    bool win = false;
    bool first_players_turn = true;
    int position;

    char board[9];
    std::fill_n(board, 9, '_');

    while (win == false)
    {
        show_board(board);

        // player choses where to put a mark
        std::cout << "Choose your position" << std::endl;
        std::cin >> position;
        //
        // inputs x or o based on player order and position availability then reverses player order
        if (board[position - 1] == '_')
        {
            first_players_turn ? board[position - 1] = 'X' : board[position - 1] = 'O';
            first_players_turn = !first_players_turn;
        }
        else
        {
            std::cout << "position taken, chose another one" << std::endl;
        }
        //
        win = check_winner(board);
    }
    game_over(board, first_players_turn);

    return 0;
}
void show_board(char game_board[9])
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << game_board[i]<<' ';
        if (i % 3 == 2)
        {
            std::cout << std::endl;
        }
    }
}

bool check_winner(char game_board[])
{
    bool first_row = ((game_board[0] == game_board[1]) && (game_board[0] == game_board[2])) && (game_board[0] != '_');
    bool second_row = ((game_board[3] == game_board[4]) && (game_board[3] == game_board[5])) && (game_board[3] != '_');
    bool third_row = ((game_board[6] == game_board[7]) && (game_board[6] == game_board[8])) && (game_board[6] != '_');
    bool first_column = ((game_board[0] == game_board[3]) && (game_board[0] == game_board[6])) && (game_board[0] != '_');
    bool second_column = ((game_board[2] == game_board[4]) && (game_board[2] == game_board[7])) && (game_board[2] != '_');
    bool third_column = ((game_board[3] == game_board[5]) && (game_board[3] == game_board[8])) && (game_board[3] != '_');
    bool left_to_right_d = ((game_board[0] == game_board[4]) && (game_board[0] == game_board[8])) && (game_board[0] != '_');
    bool right_to_left_d = ((game_board[3] == game_board[4]) && (game_board[3] == game_board[6])) && (game_board[3] != '_');

    if (
        ((first_row || second_row) || (third_row || first_column)) ||
        ((second_column || third_column) || (left_to_right_d || right_to_left_d)))

    {
        return true;
    }

    return false;
};

void game_over(char game_board[], bool turn)
{
    std::cout << std::endl;
    show_board(game_board);
    std::cout << std::endl;
    std::cout << "game over" << std::endl;
    std::cout << (turn ? "O wins" : "x wins") << std::endl;
}