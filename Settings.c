/* Settings.c */

#include <stdio.h>
#include <stdlib.h>
#include "Settings.h"
#include "Game.h"

// players can choose their characters.
void choose_char(PLAYER *player1, PLAYER *player2)
{
	printf("player 1 choose your char between A to Z\n");
	scanf("%c",&player1->Character);
	getchar();
	printf("player 2 choose your char between A to Z\n");
	scanf("%c",&player2->Character);
	getchar();
}

// players can choose their colors.
void choose_color(PLAYER *player1, PLAYER *player2)
{
	int valid_entered = 0;
	printf("player 1 choose from the following list for your color please...\n");
	printf("'r' for red, 'g' for green, 'y' for yellow, 'b' for blue', 'd' for default\n");
	while (valid_entered == 0)
	{
		char col;
		scanf("%c",&col);
		getchar();
		if (col=='r' || col=='g' || col=='y' || col=='b' || col=='d')
		{
			player1->Color=col;
			valid_entered = 1;
		}
		else
		{
			printf("Invalid input, please try agian ...\n");
		}
	}
	valid_entered = 0;
	printf("player 2 choose from the following list for your color please...\n");
	printf("'r' for red, 'g' for green, 'y' for yellow, 'b' for blue', 'd' for default\n");
	while (valid_entered == 0)
	{
		char col;
		scanf("%c",&col);
		getchar();
		if (col=='r' || col=='g' || col=='y' || col=='b' || col=='d')
		{
			player2->Color=col;
			valid_entered = 1;
		}
		else
		{
			printf("Invalid input, please try agian ...\n");
		}
	}
	
}

void settings(PLAYER *player1, PLAYER *player2)
{
	int valid_entered = 0;
	while (valid_entered == 0)
	{
		int select = 0;
		printf("Entering Settings...\n");
		printf("Please enter the setting options below...\n");
		printf("1. Changing the players' character\n");
		printf("2. Changing players' character color\n");
		printf("3. Exiting setting\n");
		scanf("%d",&select);
		getchar();

		if (select == 1)
		{
			choose_char(player1, player2);
		}
		else if (select == 2)
		{
			choose_color(player1, player2);
		}
		else if (select == 3)
		{
			break;
		}
		else
		{
			printf("Invalid input. Please try again...\n");
		}
	}
	printf("Setting completed!\n");
}

// This function prints the board
void print_fun(int board[3][3],PLAYER *player1, PLAYER *player2)
{
    char player1_char=player1->Character;
    char player2_char=player2->Character;
    char player1_color=player1->Color;
    char player2_color=player2->Color;
    // start with row
    for(int i=0;i<3;i++)
	{
        // print out vertical legend
		if(i==0)
			printf("C ");
		if(i==1)
			printf("B ");
		if(i==2)
			printf("A ");
	
        // find corresponding column    
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0) // empty space
				printf(" ");
			else if (board[i][j]==1) // player 1
			{
				if (player1_color== 'r')
				{
					printf("\x1b[31m%c\x1b[0m",player1_char); //Red
				}
				else if (player1_color== 'g')
				{
					printf("\x1b[32m%c\x1b[0m",player1_char); //Green
				}
				else if (player1_color== 'y')
				{
					printf("\x1b[33m%c\x1b[0m",player1_char); // Yellow
				}
				else if (player1_color== 'b')
				{
					printf("\x1b[34m%c\x1b[0m",player1_char); // Blue
				}
				else
				{
					printf("%c\x1b[0m",player1_char); // Default color (theme dependent)
				}
			}
			else if (board[i][j]==2) // player 2
			{
				if (player2_color== 'r')
				{
					printf("\x1b[31m%c\x1b[0m",player2_char); //Red
				}
				else if (player2_color== 'g')
				{
					printf("\x1b[32m%c\x1b[0m",player2_char); //Green
				}
				else if (player2_color== 'y')
				{
					printf("\x1b[33m%c\x1b[0m",player2_char); // Yellow
				}
				else if (player2_color== 'b')
				{
					printf("\x1b[34m%c\x1b[0m",player2_char); // Blue
				}
				else
				{
					printf("%c\x1b[0m",player2_char); // Default color (theme dependent)
				}
			}
				
			// print out lines in between columns 
            if(j!=2)
				printf("|");
		}
		if(i!=2) // print out lines between rows
			printf("\n  -----\n");
		else if(i==2) // prints out horizontal legend
			printf("\n  1 2 3\n");
	}
}


