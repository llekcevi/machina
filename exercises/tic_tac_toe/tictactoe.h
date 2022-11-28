//------------------
// GENERAL FUNCTIONS
//------------------
void InitializeBoard(char gameBoard[3][3], char emptySpace);

void ShowBoard(char gameBoard[3][3]);

void GameOver(char gameBoard[3][3], bool turn, int numberOfTurns);

//----------------
// INPUT FUNCTIONS
//----------------
void InputHuman(char gameBoard[3][3], char emptySpace);

void RandomInputComputer(char gameBoard[3][3], char emptySpace);

void InputMoveSingle(char board[3][3], bool humansTurn, char emptySpace);

void InputMoveMulti(char board[3][3], bool firstPlayersTurn, char emptySpace);

//---------------
// WIN CONDITIONS
//---------------
bool CheckRow(char gameBoard[3][3], char emptySpace);

bool CheckColumn(char gameBoard[3][3], char emptySpace);

bool CheckDiagonalUp(char gameBoard[3][3], char emptySpace);

bool CheckDiagonalDown(char gameBoard[3][3], char emptySpace);

bool CheckWinner(char gameBoard[3][3], char emptySpace);
