#include <stdio.h>

//board characteristics
char board[3][3];

int rows = sizeof(board) / sizeof(board[0]);
int cols = sizeof(board[0]) / sizeof(board[0][0]);

//player input first number cols, second rows
int playerInput[2];
    
int playerTurn = 0; // 0 is X | 1 is 0

int numOfMoves = 0;

void printBoard(){
    
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            printf("%c_|", board[j][i]);
        }
        printf("\n");
    }
}

int isValidMove(int col, int row){
    
    if(col > 2 || col < 0 || row > 2 || row < 0){
        return 1;
    }
    else if(board[col][row] == 'X' || board[col][row] == 'O'){
        return 1;
    }
    return 0;
}

void inputMove(){
    
    if(playerTurn == 0){
        printf("\nX's TURN\n");
    }
    else{
        printf("\nO's TURN\n");
    }
    printf("\n\nPlease make a move.\nSimply input you move as a single digit number. \nfirst, you will input your col value, and then your row value.\nYour first number will indicate your column and your row.\nTop left should be 1, 1, bottom right should be 3, 3.\n\n");
    
    //col value
    printf("please type in you col value\n");
    scanf("%d", &playerInput[0]);
   
    
    //row value
    printf("please type in your row value\n");
    scanf("%d", &playerInput[1]);
    
    //decrement each input so that you first row is 1 instead of 0
    playerInput[0]--;
    playerInput[1]--;
    
    printf("%d", playerInput[0]);
    printf("%d\n", playerInput[1]);
}

void setBoard(int col, int row, int playerTurn){
    
    if(isValidMove(col, row) == 0){
        if(playerTurn == 0){
            board[col][row] = 'X';
        }
        else{
            board[col][row] = 'O';
        }
        numOfMoves++;
    }
    else{
        printf("\n\nthat is not a legal move\n\n");
        printf("\n\nplease enter a valid move\n\n");
        printBoard();
        inputMove();
        setBoard(playerInput[0] , playerInput[1], playerTurn);
    }
}

int isGameover(){ //0 is returned for not win. 1 for X win, 2 for O win, -1 for tie
    
    
    //vertical wins
    //go through each column and check if each thing equals the same
    
    for(int i = 0; i < cols; i++){
        if(board[i][0] == 'X'){
            if(board[i][1] == 'X' && board[i][2] == 'X'){
                return 1; //X wins
            }
        }
        else if(board[i][0] == 'O'){
            if(board[i][1] == 'O' && board[i][2] == 'O'){
                return 2; //O wins
            }
        }
    }
    
    //horizontal winss
    //go throuhg each row and check if each space equals the same
    for(int i = 0; i < rows; i++){
        if(board[0][i] == 'X'){
            if(board[1][i] == 'X' && board[2][i] == 'X'){
                return 1; //X wins
            }
        }
        else if(board[0][i] == 'O'){
            if(board[1][i] == 'O' && board[2][i] == 'O'){
                return 2; //O wins
            }
        }
    }
    
    
    //check for diagonal wins
    //checks both foward and backward diagonal
    //does for both colors
    
    //check for x
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
            return 1; //X wins
    }
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'O'){
        return 1; // x WINS
    }
    
    //check for O
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
            return 2; //O wins
    }
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        return 2; // O WINS
    }
    
    
    //check for tie
    //check if each char in board is occupied
    if(numOfMoves == 9){
        return -1;
    }
      
    return 0;
}

int main(){
    
    while(isGameover() == 0){
        printBoard();
        inputMove();
        setBoard(playerInput[0] , playerInput[1], playerTurn);
        if(playerTurn == 1){
            playerTurn--;
        }
        else{
            playerTurn++;
        }
    }
    if(isGameover() == 1){
        printBoard();
        printf("\n\n X WINS");
    }
    if(isGameover() == 2){
        printBoard();
        printf("\n\n O WINS");
    }
    if(isGameover() == -1){
	    printBoard();
        printf("\n\n ITS A TIE");
    }
    return 0;
}
