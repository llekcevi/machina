#ifndef tictactoe_class_h
#define tictactoe_class_h
class TicTacToe
{
private:
    bool win;
    bool humans_turn;
    char board[3][3];
    short int turns;
    char empty;

public:
    TicTacToe();
    int run();
    ~TicTacToe(){};

private:
    void initializeBoard(char gameBoard[3][3], char emptySpace);
    void playGame(bool win_condition, char gameBoard[3][3], bool human, char emptySpace, short int turn_counter);
    void endGame(char gameBoard[3][3], short int turn_counter);
    void showBoard(char gameBoard[3][3]);
    void inputMove(char gameBoard[3][3], bool human, char emptySpace);
    void inputHuman(char gameBoard[3][3], char emptySpace);  
    void inputComputer(char gameBoard[3][3], char emptySpace);
    bool checkWinner(char gameBoard[3][3], char emptySpace);
    bool checkRow(char gameBoard[3][3], char emptySpace);
    bool checkColumn(char gameBoard[3][3], char emptySpace);
    bool checkDiagonalUp(char gameBoard[3][3], char emptySpace);
    bool checkDiagonalDown(char gameBoard[3][3], char emptySpace);



};
#endif