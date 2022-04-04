/* AI.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AI.h"
#include "Game.h"
#include "Settings.h"

// Handle a Human v. AI game, Inky Level 1
void Inky(int board[3][3],PLAYER *player1, PLAYER *player2) // Human is always player1 and AI is player2
{
	printf("Human v. Inky game started\n");
	NODE *boardNode; //initialize node
	print_fun(board,player1,player2);
	int tie=1;
	while((is_there_empty_cell(board)))
	{
		printf("Player 1, please choose your move:");
		entered_one_char(board,1,player1);
		print_fun(board,player1,player2);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Inky wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;

		printf("AI is choosing its move:\n");
        	int foundMove = 0;
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (board[i][j] == 0)
				{
                    			board[i][j] = 2;
					boardNode=createNode(player2,i,j); //creates the node containing the move's row and column
					addMove(player2,boardNode); //add the node to the linked list
                    			foundMove = 1;
					break;
				}
			}
            		if(foundMove)
            		{
               			break;
            		}  

		}
		
		print_fun(board,player1,player2);
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Inky wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
}

// Blinky Level 2
void Blinky(int board[3][3],PLAYER *player1,PLAYER *player2)
{
	srand(time(NULL));
	NODE *boardNode; //initialize node	
	printf("Human v. Blinky game started\n");
	print_fun(board,player1,player2);
	int tie=1;
	while((is_there_empty_cell(board)))
	{
		printf("Player 1, please choose your move:");
		entered_one_char(board,1,player2);
		print_fun(board,player1,player2);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Blinky wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;

		printf("AI is choosing its move:\n");
        	int foundMove = 0;
		int randr=0; //initialize random number for the rows
		int randc=0; //initialize random number for the columns
		while(foundMove==0) //finds a random move for the AI
		{
			randr=rand()%3;
			randc=rand()%3;
			if(board[randr][randc]==0)
			{
				board[randr][randc]=2;
				boardNode=createNode(player2,randr,randc); //creates the node containing the move's row and column
				addMove(player2,boardNode); //adds the node to the linked list
				foundMove=1;
			}
		}
		
		print_fun(board,player1,player2);
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Blinky wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
}

// Pinky Level 3
void Pinky(int board[3][3], PLAYER *player1, PLAYER *player2)
{
	srand(time(NULL));
	NODE *boardNode; //intialize node
	printf("Human v. Pinky game started\n");
	print_fun(board,player1,player2);
	int tie=1;
	while((is_there_empty_cell(board)))
	{
		printf("Player 1, please choose your move:");
		entered_one_char(board,1, player1);
		print_fun(board,player1,player2);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Pinky wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;

		printf("AI is choosing its move:\n");
        	int foundMove = 0;
		int randr=0; //initialize random number for the rows
		int randc=0; //initialize random number for the columns
		for (int i=0; i<3; i++) //checks which moves will allow the player to win next turn
		{
			for (int j=0; j<3; j++)
			{	
				if(board[i][j]==0)
				{
					board[i][j]=1;
					if(IsWin(board)==1)
					{
						board[i][j]=2; //if a win for player 1, set the AI move
						boardNode=createNode(player2,i,j); //creates the node containing the move's row and column
						addMove(player2, boardNode); //adds the node to the linked list
						foundMove=1;
						break;
					}
					else
					{
						board[i][j]=0; //if not a win for player 1, reset to 0
					}
				}
			}
		}
		while(foundMove==0) //finds a random move for the AI
		{
			randr=rand()%3;
			randc=rand()%3;
			if(board[randr][randc]==0)
			{
				board[randr][randc]=2;
				boardNode=createNode(player2,randr,randc); //creates the node containing the move's row and column
				addMove(player2, boardNode); //adds the node to the linked list
				foundMove=1;
			}
		}

		print_fun(board,player1,player2);
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Pinky wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
}


