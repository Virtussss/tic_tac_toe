#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    printf("\n");
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf(" %c ", board[i][j]);
            if(j<SIZE-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<SIZE-1){
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int isValidMove(int row, int col){
    return(row>=0 && row<SIZE && col>=0 && col<SIZE && board[row][col] == ' ');
}

void makeMove(int row, int col){
    if(isValidMove(row, col)){
        board[row][col] = currentPlayer;
    }
    else{
        printf("Invalid move. Try again.\n");
    }
}
int checkWin(){
    // Check rows and columns
    for(int i=0; i<SIZE; i++){
        if(board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer)
            return 1;
        if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer)
            return 1;
    }

    // Check diagonals
    if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer)
        return 1;
    if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer)
        return 1;
    return 0;
}

int isBoardFull(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(board[i][j]==' '){
                return 0;
            }
        }
    }
    return 1;
}

void switchPlayer(){
    currentPlayer = (currentPlayer == 'X') ? 'O':'X';
}

int main(){
    int row, col;
    initializeBoard();
    printBoard();

    while(1){
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if(isValidMove(row-1, col-1)){
            makeMove(row-1, col-1);
            printBoard();

            if(checkWin()){
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            else if(isBoardFull()){
                printf("It's a draw!\n");
                break;
            }
            switchPlayer();
        }
        else{
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}