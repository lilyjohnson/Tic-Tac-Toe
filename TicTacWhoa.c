/*Lily Johnson 19616791
Assignment 1 - Tic-Tac-Whoa

modifications:
1/15 - finished color change
1/14 - completed options 2, 3, 4 except for color change
1/13 - wrote tie and win functions, completed option 1
1/12 - debugging errors
1/10 - wrote menu and printboard function*/

#include <stdio.h>
#include <stdlib.h>

void printBoard();
void clearBoard();
int tie();
void turn(char letter, int num, char player);
int win(char player);
void AImove(char ai);

char board[3][3];
char player1='X';
char player2='O';
int player1Color=7;
int player2Color=7;
int main(void)
{
	clearBoard();
	
	char letter;
    int num;
	int menu = 0;
    while(1) //loops back to the menu unless the player exits
    {
        printf("Welcome to Secure-Tic-Tac-Whoa!\n");
        printf("1. Start New Game (Human v. Human)\n");
        printf("2. Start New Game (Human v. AI)\n");
        printf("3. Game Settings\n");
        printf("4. Exit Game\n");
        printf("Choose Option: ");
        scanf("%d", &menu);
        
        if(menu==1)
        {
            printf("Human v. Human game started\n");
            printBoard();
            while(1)
			{		
			
				//gets Player 1's move, calls turn() with the move, and checks for a win
				printf("Player %c, please choose your move: ", player1);
				scanf(" %c %d", &letter, &num);
				printf("Player %c chose %c%d", player1, letter, num);
				turn(letter, num, player1);
				printBoard();
				if(win(player1)==1)
				{
					printf("Player %c won!\n", player1);
					clearBoard();
					break;
				}
				else if(tie()==1) //check for a tie
				{
					printf("Tie!\n");
					clearBoard();
					break;
				}
				
				//gets Player 2's move, calls turn() with the move, and checks for a win
				printf("Player %c, please choose your move: ", player2);
				scanf(" %c %d", &letter, &num);
				printf("Player %c chose %c%d", player2, letter, num);
				turn(letter, num, player2);
				printBoard();
				if(win(player2)==1)
				{
					printf("Player %c won!\n", player2);
					clearBoard();
					break;
				}
				else if(tie()==1) //check for a tie
				{
					printf("Tie!\n");
					clearBoard();
					break;
				}
			}
        }
        else if(menu==2)
        {
            int player;
			
			printf("Human v. AI game started\n");
			printf("Please choose Player 1 or Player 2\n");
			printf("Enter a number: ");
			scanf("%d", &player);
            printBoard();
			
			if(player==1) //user is player 1
			{
				while(1)
				{
					
					//gets the player's move, calls turn() with the move, and checks for a win
					printf("Player %c, please choose your move: ", player1);
					scanf(" %c %d", &letter, &num);
					printf("Player %c chose %c%d", player1, letter, num);
					turn(letter, num, player1);
					printBoard();
					if(win(player1)==1)
					{
						printf("Player %c won!\n", player1);
						clearBoard();
						break;
					}
					else if(tie()==1) //check for a tie
					{
						printf("Tie!\n");
						clearBoard();
						break;
					}
					
					//calls the AI's move and checks for a win
					AImove(player2);
					printBoard();
					if(win(player2)==1)
					{
						printf("Player %c won!\n", player2);
						clearBoard();
						break;
					}
					else if(tie()==1) //check for a tie
					{
						printf("Tie!\n");
						clearBoard();
						break;
					}
				}
			}
			else //user is player 2
			{
				while(1)
				{
					
					//calls the AI's move and checks for a win
					AImove(player1);
					printBoard();
					if(win(player1)==1)
					{
						printf("Player %c won!\n", player1);
						clearBoard();
						break;
					}
					else if(tie()==1) //check for a tie
					{
						printf("Tie!\n");
						clearBoard();
						break;
					}
					
					//gets the player's move, calls turn() with the move, and checks for a win
					printf("Player %c, please choose your move: ", player2);
					scanf(" %c %d", &letter, &num);
					printf("Player %c chose %c%d", player2, letter, num);
					turn(letter, num, player2);
					printBoard();
					if(win(player2)==1)
					{
						printf("Player %c won!\n", player2);
						clearBoard();
						break;
					}
					else if(tie()==1) //check for a tie
					{
						printf("Tie!\n");
						clearBoard();
						break;
					}
				}
			}
        }
        else if(menu==3)
        {
            int option;
            char new;
			int playerColor;
			
			//game settings menu
            printf("\nGame Settings\n");
            printf("1. Edit Player 1 color\n");
            printf("2. Edit Player 2 color\n");
            printf("3. Edit Player 1 character\n");
            printf("4. Edit Player 2 character\n");
            printf("5. Exit\n");
            printf("Choose Option: ");
            scanf("%d", &option);
            
            if(option==1)
            {
                printf("Edit Player 1 color\n");
                printf("Select a color \x1b[0;31m1.red \x1b[0;32m2.green \x1b[0;33m3.yellow \x1b[0;34m4.blue\n");
				printf("\x1b[0mEnter a number:");
				scanf(" %d", &playerColor);
				player1Color=playerColor;
				
            }
            else if(option==2)
            {
                printf("Edit Player 2 color\n");
                printf("Select a color \x1b[0;31m1.red \x1b[0;32m2.green \x1b[0;33m3.yellow \x1b[0;34m4.blue\n");
				printf("\x1b[0mEnter a number:");
				scanf(" %d", &playerColor);
				player2Color=playerColor;
            }
            else if(option==3)
            {
                printf("Edit Player 1 character\n");
                printf("Enter new character: ");
                scanf(" %c", &new);
                player1=new;
                printf("Player 1: %c\n", player1);
            }
            else if(option==4)
            {
                printf("Edit Player 2 character\n");
                printf("Enter new character: ");
                scanf(" %c", &new);
                player2=new;
                printf("Player 2: %c\n", player2);
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    printf("Goodbye");
	return 0;
}

//prints the tic tac toe board
void printBoard()
{
	//intialize variables that will determine colors of the characters when printed
    int one=7;
    int two=7;
    int three=7;
	
	//checks which characters are filled in row 1
    if(board[0][0]==player1)
    {
        one=player1Color;
    }
    else if(board[0][0]==player2)
    {
        one=player2Color;
    }
    else
    {
        one=0;
    }
    if(board[0][1]==player1)
    {
        two=player1Color;
    }
    else if(board[0][1]==player2)
    {
        two=player2Color;
    }
    else
    {
        two=7;
    }
    if(board[0][2]==player1)
    {
        three=player1Color;
    }
    else if(board[0][2]==player2)
    {
        three=player2Color;
    }
    else
    {
        three=7;
    }
    
    printf("\nC \x1b[0;3%dm%c\x1b[0m|\x1b[0;3%dm%c\x1b[0m|\x1b[0;3%dm%c\x1b[0m\n", one, board[0][0], two, board[0][1], three, board[0][2]);
	printf("  -----\n");
	
	//checks which characters are filled in row 2
	if(board[1][0]==player1)
    {
        one=player1Color;
    }
    else if(board[1][0]==player2)
    {
        one=player2Color;
    }
    else
    {
        one=0;
    }
    if(board[1][1]==player1)
    {
        two=player1Color;
    }
    else if(board[1][1]==player2)
    {
        two=player2Color;
    }
    else
    {
        two=7;
    }
    if(board[1][2]==player1)
    {
        three=player1Color;
    }
    else if(board[1][2]==player2)
    {
        three=player2Color;
    }
    else
    {
        three=7;
    }
	
	printf("B \x1b[0;3%dm%c\x1b[0m|\x1b[0;3%dm%c\x1b[0m|\x1b[0;3%dm%c\x1b[0m\n", one, board[1][0], two, board[1][1], three, board[1][2]);
	printf("  -----\n");
	
	//checks which characters are filled in row 3
	if(board[2][0]==player1)
    {
        one=player1Color;
    }
    else if(board[2][0]==player2)
    {
        one=player2Color;
    }
    else
    {
        one=0;
    }
    if(board[2][1]==player1)
    {
        two=player1Color;
    }
    else if(board[2][1]==player2)
    {
        two=player2Color;
    }
    else
    {
        two=7;
    }
    if(board[2][2]==player1)
    {
        three=player1Color;
    }
    else if(board[2][2]==player2)
    {
        three=player2Color;
    }
    else
    {
        three=7;
    }
	
	printf("A \x1b[0;3%dm%c\x1b[0m|\x1b[0;3%dm%c\x1b[0m|\x1b[0;3%dm%c\x1b[0m\n", one, board[2][0], two, board[2][1], three, board[2][2]);
	printf("  1 2 3\n");
}

//clears the board, fills the board array with empty spaces
void clearBoard()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//checks for a tie
int tie()
{
   for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(board[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//takes the player's move and inputs the assigned character into the board array
void turn(char letter, int num, char player)
{
    int row;
    int col=num-1;
    if(letter=='C')
    {
        row=0;
    }
    else if(letter=='B')
    {
        row=1;
    }
    else if(letter=='A')
    {
        row=2;
    }
    board[row][col]=player;
}

//checks for a win
int win(char player)
{
    //check rows
    if(board[0][0]==player && board[0][1]==player && board[0][2]==player)
    {
        return 1;
    }
	else if(board[1][0]==player && board[1][1]==player && board[1][2]==player)
    {
        return 1;
    }
	else if(board[2][0]==player && board[2][1]==player && board[2][2]==player)
    {
        return 1;
    }
	
	//check columns
	else if(board[0][0]==player && board[1][0]==player && board[2][0]==player)
    {
        return 1;
    }
	else if(board[0][1]==player && board[1][1]==player && board[2][1]==player)
    {
        return 1;
    }
	else if(board[0][2]==player && board[1][2]==player && board[2][2]==player)
    {
        return 1;
    }
	
	//check diagonals
	else if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
	{
		return 1;
	}
	else if(board[2][0]==player && board[1][1]==player && board[0][2]==player)
	{
		return 1;
	}
	
	return 0;
}

//inputs the AI's move into the board array
void AImove(char ai)
{
	int i,j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(board[i][j]==' ')
			{ 
				break;
			}
		}
		if(board[i][j]==' ')
		{
			board[i][j]=ai;
			break;
		}
	}
}

/*EOF*/