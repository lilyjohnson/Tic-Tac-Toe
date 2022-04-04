/*********************************************************************/
/* Reference solution for Assignment 1 for EECS 22 @ UCI Winter 2021 */
/*                                                                   */
/* This is an "A" level representation of the Tic-Tac-Whoa game.     */
/* There are improvements that can be made, but this is considered   */
/* very good.                                                        */
/*                                                                   */
/* This solution is for your reference for this course and           */
/* copyright belongs to the authors below. Reproduction or sharing   */
/* of this code outside of this class is prohibited except with the  */
/* express written consent of the authors.                           */
/*                                                                   */
/* Authors: Mozhgan Moradiganjeh, QV Dang                            */
/* Modifications:                                                    */
/* 03/15/21 LJ  error handling, comments, work on replay             */
/* 03/14/21 LJ  node(board) struct for replay                        */
/* 03/13/21 LJ  finish AI, error handling			     */
/* 03/12/21 LJ  work on AIs, error handling			     */
/* 03/11/21 LJ  player struct					     */
/* 01/18/21 QV  AI, function, and comment updates                    */
/* 01/13/21 MM  Initial version                                      */
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Settings.h"
#include "Game.h"
#include "AI.h"

// Handle Menu Options
int print_menu()
{
	int select=0;
	printf("1. Start New Game (Human v. Human)\n");
	printf("2. Start New Game (Human v. AI)\n");
	printf("3. Game Settings\n");
	printf("4. Exit Game\n");
	printf("Choose Option: ");
	scanf("%d",&select);
	getchar(); // one solution for clearing the "\n" char from the input
	return select;
}

// Main Program for Tic-Tac-Whoa
int main()
{
    // initialize game
    	PLAYER* player1= createPlayer(1,'X','d');
	PLAYER* player2= createPlayer(2, 'O', 'd');

	printf("Welcome to Secure-Tic-Tac-Whoa!\n");
	int done=0;
	while(done==0)
	{
		int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
		int option = print_menu();
		switch(option)
		{
			case 1:
				HumanVsHuman(board,player1,player2);
				break;
			case 2:
				printf("\nWould you like to play 1.Inky, 2.Blinky, or 3.Pinky?\nEnter a number 1-3: ");
				int num;
				scanf("%d",&num);
				if(num==1)
				{
					Inky(board,player1,player2);
				}
				else if(num==2)
				{
					Blinky(board,player1,player2);
				}
				else
				{
					Pinky(board,player1,player2);
				}
				break;
			case 3:
				settings(player1, player2);
				break;
			case 4:
				printf("Thanks for playing. Exiting game...\n");
				done=1;
				break;
		}
		
	}
	//replay();
	deletePlayer(player1);
	deletePlayer(player2);	
	return 0;
}

/* EOF */
