#include<stdio.h>
#include<unistd.h>

void displayBoard(char board[3][3]){

    printf("\n");
    printf("+-----+-----+-----+\n");
    for(int i=0;i<3;i++){
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n",board[i][0],board[i][1],board[i][2]);
        printf("|     |     |     |\n");
        printf("+-----+-----+-----+\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]){

    //check rows
    for(int i=0;i<3;i++){

        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        return 1;
    }

    //check column
    for(int i=0;i<3;i++){

        if(board[0][i]==board[1][i] && board[1][i] ==board[2][i]){
            return 1;
        }
    }

    //first diagonal
    if(board[0][0] ==board[1][1] && board[1][1] == board[2][2]){
        return 1;
    }

    //second diagonal
    if(board[0][2]==board[1][1] && board[1][1] == board[2][1]){
        return 1;
    }
    return 0;
}
int main(){

    char player1[50];
    char player2[50];

    char play;
    char again;

    printf("\n");
    printf("----------------------------------------\n");
    printf("-------------TIC TAC TOE----------------\n");
    printf("----------------------------------------\n");

    printf("Loading");

    for(int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
        fflush(stdout);
    }


    do
    {
        printf("\nWant to play !! (Y/N) : ");
        scanf(" %c", &play);

        if (play == 'N' || play == 'n')
        {
            printf("\nThank You! Goodbye.\n");
            break;
        }

        if (play != 'Y' && play != 'y')
        {
            printf("\nInvalid choice! Please enter Y or N.\n");
            continue;
        }

        printf("Enter Player1 Name : ");
        scanf("%49s", player1);

        printf("Enter Player2 Name : ");
        scanf("%49s", player2);

        printf("[ %s -> X ] [ %s -> O ]\n",
               player1, player2);

        printf("\nNOTE : Enter 1-9 to select box!\n");

        char board[3][3] =
        {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        int choice;
        int moves = 0;
        int row, col;

        char player = 'X';

        while(1){

        displayBoard(board);

        if (player == 'X')
            {
                printf("\n%s (X), Enter position : ", player1);
            }
            else
            {
                printf("\n%s (O), Enter position : ", player2);
            }

            scanf("%d", &choice);

            if(choice <1 || choice >9){

                printf("Invalid Input  ! Try Again.\n");
                continue;
            }

        //convert into position using row & column
        row = (choice-1)/3;
        col = (choice-1)%3;

        //if current positon is occupied
        if(board[row][col]=='X'||board[row][col]=='O'){

            printf("Entry is Occupied! Try Again.\n");
            continue;
        }


        board[row][col]=player;
        moves++;

        if (checkWinner(board))
            {
                displayBoard(board);

                if (player == 'X')
                {
                    printf("\n🎉🏆 %s wins!!! 🏆🎉\n", player1);
                }
                else
                {
                    printf("\n🎉🏆 %s wins!!! 🏆🎉\n", player2);
                }

                break;
            }

        if(moves==9){

            displayBoard(board);
            printf("🤝 Game Drawn!!\n");
            break;
        }

        if(player=='X'){

            player = 'O';
        }
        else{
            player = 'X';
        }
    }

    printf("\nContinue (Y/N) ? ");
        scanf(" %c", &again);

    } while (again == 'Y' || again == 'y');

    printf("\nThank You for playing!\n");


    return 0;

}