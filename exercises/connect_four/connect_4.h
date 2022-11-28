//---------------------------------
// G E N E R A L  F U N C T I O N S
//---------------------------------
void InitializeBoard(char gameBoard[6][7], char emptySpace);

void ShowBoard(char game_board[6][7]);

void EndGame(char gameBoard[6][7]);

//-----------------------------
// I N P U T  F U N C T I O N S
//-----------------------------
void InputMoveSingle(char gameBoard[6][7], char emptySpace, bool firstPlayersTurn);

void InputMoveMulti(char gameBoard[6][7], char emptySpace, bool firstPlayersTurn);

void InputComputer(char gameBoard[6][7], char emptySpace);

void InputHuman(char gameBoard[6][7], char emptySpace);

//---------------
// WIN CONDITIONS
//---------------
bool CheckDiagonalDown(char gameBoard[6][7], char emptySpace);

bool CheckDiagonalUp(char gameBoard[6][7], char emptySpace);

bool CheckColumn(char game_board[6][7], char emptySpace);

bool CheckRow(char game_board[6][7], char emptySpace);

bool CheckWin(char gameBoard[6][7], char emptySpace);

