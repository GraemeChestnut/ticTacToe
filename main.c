#include <stdio.h>

//board characteristics
char board[3][3];
int rows = sizeof(board) / sizeof(board[0]);
int cols = sizeof(board[0]) / sizeof(board[0][0]);

//player input first number cols, second rows
int playerInput[2];
    
int playerTurn = 0; // 0 is X | 1 is Y

void printBoard(){

    
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            printf("%c_|", board[j][i]);
        }
        printf("\n");
    }
}

void setBoard(int col, int row, int playerTurn){
    if(playerTurn == 0){
        board[col][row] = 'X';
        playerTurn = 1;
    }
    else{
        board[col][row] = 'O';
        playerTurn = 0;
    }
}

void inputMove(){
    printf("\n\nPlease make a move.\nSimply input you move as a single digit number. \nfirst, you will input your col value, and then your row value.\nYour first number will indicate your column and your row.\nTop left should be 1, 1, bottom right should be 3, 3.\n\n");
    
    printf("please type in you col value\n");
    scanf("%d", &playerInput[0]);
    printf("please type in your row value\n");
    scanf("%d", &playerInput[1]);
    printf("%d", playerInput[0]);
    printf("%d\n", playerInput[1]);
}

int main(){
    
    printBoard();
    inputMove();
    setBoard(playerInput[0], playerInput[1], playerTurn);
    printBoard();
    
    return 0;
}
