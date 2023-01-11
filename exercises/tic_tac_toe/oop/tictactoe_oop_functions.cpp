#include "tictactoe_oop.h"
#include <iostream>
// PUBLIC
// - constructor
TicTacToe::TicTacToe()
{

    win = false;
    humans_turn = true;
    turns = 0;
    empty = '_';
    initializeBoard(board, empty);
}
//
int TicTacToe::run()
{
    srand(time(NULL));

    playGame(win, board, humans_turn, empty, turns);

    endGame(board, turns);

    return 0;
}
// PRIVATE
void TicTacToe::playGame(bool win_condition, char gameBoard[3][3], bool human, char emptySpace, short int turn_counter)
{
    while (!win_condition && turn_counter < 9)
    {
        showBoard(gameBoard);
        inputMove(gameBoard, human, emptySpace);
        win_condition = checkWinner(gameBoard, emptySpace);
        human = !human;
        turn_counter = turn_counter + 1;
    }
}

void TicTacToe::endGame(char gameBoard[3][3], short int turn_counter)
{
    showBoard(gameBoard);
    std::cout << std::endl;
    std::cout << "Game over" << std::endl;
    std::cout << std::endl;
    if (turn_counter == 8)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << (turn_counter ? "Computer wins" : "Human wins") << std::endl;
    }
}

void TicTacToe::showBoard(char gameBoard[3][3])
{
    system("clear");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << gameBoard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// INPUT FUNCTIONS
void TicTacToe::inputMove(char gameBoard[3][3], bool human, char emptySpace)
{
    human ? inputHuman(gameBoard, emptySpace) : inputComputer(board, emptySpace);
}

void TicTacToe::inputHuman(char gameBoard[3][3], char emptySpace)
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

void TicTacToe::inputComputer(char gameBoard[3][3], char emptySpace)
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
// CHECK WIN FUNCTIONS
bool TicTacToe::checkWinner(char gameBoard[3][3], char emptySpace)
{
    return checkColumn(gameBoard, emptySpace) || checkRow(gameBoard, emptySpace) || checkDiagonalDown(gameBoard, emptySpace) || checkDiagonalUp(gameBoard, emptySpace);
}

bool TicTacToe::checkDiagonalDown(char gameBoard[3][3], char emptySpace)
{
    if (gameBoard[0][0] == gameBoard[1][1] &&
        gameBoard[0][0] == gameBoard[2][2] &&
        gameBoard[0][0] != emptySpace)
    {
        return true;
    }
    return false;
}

bool TicTacToe::checkDiagonalUp(char gameBoard[3][3], char emptySpace)
{
    if (gameBoard[2][0] == gameBoard[1][1] &&
        gameBoard[2][0] == gameBoard[0][1] &&
        gameBoard[2][0] != emptySpace)
    {
        return true;
    }
    return false;
}

bool TicTacToe::checkColumn(char gameBoard[3][3], char emptySpace)
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

bool TicTacToe::checkRow(char gameBoard[3][3], char emptySpace)
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

void TicTacToe::initializeBoard(char gameBoard[3][3], char emptySpace)
{
    for (int i = 0; i < 3; i++)
    {
        memset(gameBoard[i], emptySpace, 3);
    }
}
