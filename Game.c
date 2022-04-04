/* Game.c */

#include "Game.h"
#include "Settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

NODE *head=NULL;
//head=(struct NODE*)malloc(sizeof(struct NODE));
int temp=0;

//struct that contains the moves list
NODE *createNode(PLAYER *p, int r, int c)
{
    NODE *board;
    board=malloc(sizeof(NODE));
    
    board->row=r;
    board->column=c;
    board->player=p;
    board->next=NULL;

    return board;
}

//player struct
PLAYER *createPlayer(char num, char ch, char clr)
{
    PLAYER *player;
    player=malloc(sizeof(PLAYER));
      
    player->PlayerNum=num;
    player->Character=ch;
    player->Color=clr;

    return player;
}

void deletePlayer(PLAYER *player)
{
    assert(player);
    free(player);
    player=NULL;
}

void deleteNode()
{
    while(head!=NULL)
    {
	NODE* current= head;
	head=(NODE*)(head->next);
	free(current);
	current=NULL;
    }
}

//This function checks if there is empty place in board.
int is_there_empty_cell(int board[3][3])
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				if(board[i][j]==0)
				{
					count++;
				}	
		}
	}
	if (count!=0)
		return 1; // we have empty cell
	else
		return 0; // we do not have empty cell
}

// win condition
int IsWin(int board[3][3])
{
	
	int win_flag=0;
	if(((board[0][0]==1)&&(board[1][0]==1)&&(board[2][0]==1))||
		((board[0][1]==1)&&(board[1][1]==1)&&(board[2][1]==1))||
		((board[0][2]==1)&&(board[1][2]==1)&&(board[2][2]==1))||
		((board[0][0]==1)&&(board[0][1]==1)&&(board[0][2]==1))||
		((board[1][0]==1)&&(board[1][1]==1)&&(board[1][2]==1))||
		((board[2][0]==1)&&(board[2][1]==1)&&(board[2][2]==1))||
		((board[0][0]==1)&&(board[1][1]==1)&&(board[2][2]==1))||
		((board[0][2]==1)&&(board[1][1]==1)&&(board[2][0]==1)))
		{
			win_flag =1;
		}
	
	else if(((board[0][0]==2)&&(board[1][0]==2)&&(board[2][0]==2))||
				((board[0][1]==2)&&(board[1][1]==2)&&(board[2][1]==2))||
				((board[0][2]==2)&&(board[1][2]==2)&&(board[2][2]==2))||
				((board[0][0]==2)&&(board[0][1]==2)&&(board[0][2]==2))||
				((board[1][0]==2)&&(board[1][1]==2)&&(board[1][2]==2))||
				((board[2][0]==2)&&(board[2][1]==2)&&(board[2][2]==2))||
				((board[0][0]==2)&&(board[1][1]==2)&&(board[2][2]==2))||
				((board[0][2]==2)&&(board[1][1]==2)&&(board[2][0]==2)))
				{
					win_flag =2;
				}

	return win_flag;		
}

// enters int 1 or 2 in desired position.
void entered_one_char(int board [3][3],int player_num,PLAYER *player)
{
	int valid_entered = 0;
	int c;
	int r;
	while(valid_entered == 0)
	{
		char letters_num[2];
		c=0;
		r=0;
		scanf("%s",letters_num);
		
		if (letters_num[0]=='A')
		{
			r=2;
		}
		else if(letters_num[0]=='B')
		{
			r=1;
		}
		else if(letters_num[0]=='C')
		{
			r=0;
		}
		
		if (letters_num[1]=='1')
		{
			c=0;
		}
		else if(letters_num[1]=='2')
		{
			c=1;
		}
		else if(letters_num[1]=='3')
		{
			c=2;
		}

		if (board[r][c] == 0)
		{
			valid_entered = 1;
		}
		else
		{
			printf("The entered position is not available! Please try again...\n");
		}
	}
	board [r][c]=player_num;
	NODE* boardNode = createNode(player,r,c);
	if (temp==0)
	{
		head = boardNode;
		temp++;
	}
	else
	{
		NODE* current= head;
		while(current->next != NULL)
		{
			current=(NODE*)(current->next);
		}
		current->next=(struct NODE*)boardNode;
	}
}

void addMove(PLAYER *player, NODE *boardNode)
{
	if (temp==0)
	{
		head = boardNode;
		temp++;
	}
	else
	{
		NODE* current= head;
		while(current->next != NULL)
		{
			current=(NODE*)(current->next);
		}
		current->next=(struct NODE*)boardNode;
	}

}

void replay()
{
	FILE *fptr = fopen("TicTacWowWeeWow.txt","w" );
	PLAYER *p;
	int r;
	int c;
	char symbol;
	char color;
	int board[3][3];
	NODE *current=head;
	while(current->next != NULL)
	{
		r = current->row;
		c = current->column;
		p  = current->player;
		symbol = p->Character;	
		color = p->Color;	
		board[r][c]= symbol;
		// start with row
		for(int i=0;i<3;i++) //writes the board array contents 
		{
			// print out vertical legend
			if(i==0)
				fprintf(fptr,"C ");
			if(i==1)
				fprintf(fptr,"B ");
			if(i==2)
				fprintf(fptr,"A ");
		
			// find corresponding column    
			for(int j=0;j<3;j++)
			{
				if(board[i][j]==0) // empty space
					fprintf(fptr," ");
				else
				{
					fprintf(fptr,"%c", board[r][c]);
				}
					// print out lines in between columns 
				if(j!=2)
					fprintf(fptr,"|");
			}
			if(i!=2) // print out lines between rows
				fprintf(fptr,"\n  -----\n");
			else if(i==2) // prints out horizontal legend
				fprintf(fptr,"\n  1 2 3\n");
		}
	}
	current=(NODE*)(current->next);
	fclose(fptr);

	deleteNode();	
}


// Handle a Human v. Human game
void HumanVsHuman(int board[3][3],PLAYER *player1, PLAYER *player2)
{
	printf("Human v. Human game started\n");
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
				printf("Player 2 wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	
		printf("Player 2, please choose your move:");
		entered_one_char(board,2, player2);
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
				printf("Player 2 wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
	}
	if (tie==1)
		printf("The game is a tie!\n");
}




