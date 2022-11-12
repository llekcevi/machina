#include <iostream>
#include <algorithm>

void show_board(char game_board[]);
bool check_winner(char game_board[]);
void game_over(char game_board[], bool turn);
void computers_turn(char game_board[], bool win);
int random_number();

int main()
{
    bool win = false;
    bool players_turn = true;
    int position;

    char board[9];
    std::fill_n(board, 9, '_');

    while (win == false)
    {
        show_board(board);

        while (players_turn)
        {
            std::cout << "Choose your position" << std::endl;
            std::cin >> position;
            if (board[position - 1] == '_')
            {
                board[position - 1] = 'X';
                win = check_winner(board);
                players_turn = !players_turn;
            }
            else
            {
                std::cout << "position taken, chose another one" << std::endl;
            }
        }
        while (!players_turn)
        {
            computers_turn(board, win);
            players_turn = !players_turn;
        }
    }
    game_over(board, players_turn);

    return 0;
}
void show_board(char game_board[9])
{
    std::cout << game_board[0] << " " << game_board[1] << " " << game_board[2] << std::endl;
    std::cout << game_board[3] << " " << game_board[4] << " " << game_board[5] << std::endl;
    std::cout << game_board[6] << " " << game_board[7] << " " << game_board[8] << std::endl;
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

int random_number()
{
    return time(NULL);
}

void computers_turn(char game_board[], bool win)
{

    while (true)
    {
        int computer_choice = random_number() % 10;

        if (game_board[computer_choice] == '_')
        {
            game_board[computer_choice] = '0';
            win = check_winner(game_board);
            break;
        }
    }
}

void game_over(char game_board[], bool turn)
{
    std::cout << std::endl;
    show_board(game_board);
    std::cout << std::endl;
    std::cout << "game over" << std::endl;
    std::cout << (turn ? "X wins" : "0 wins") << std::endl;
}