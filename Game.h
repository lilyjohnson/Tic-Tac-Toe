/* Game.h */

#ifndef GAME_H
#define GAME_H

//player struct
struct Player
{   
    char PlayerNum;
    char Character;
    char Color;
    int *MovesList;
};
typedef struct Player PLAYER;

//creates a player
PLAYER *createPlayer(char num, char ch, char clr);

void deletePlayer(PLAYER *player);

//struct that contains the moves list
struct Node
{
    int row;
    int column;
    PLAYER *player;
    struct NODE* next;
};
typedef struct Node NODE;

NODE *createNode(PLAYER *p, int r, int c);

void deleteNode();

//This function checks if there is empty place in board.
int is_there_empty_cell(int board[3][3]);

// win condition
int IsWin(int board[3][3]);

// enters int 1 or 2 in desired position.
void entered_one_char(int board [3][3],int player_num, PLAYER *player);

void replay();

void addMove(PLAYER *player, NODE *boardNode);

// Handle a Human v. Human game
void HumanVsHuman(int board[3][3],PLAYER *player1, PLAYER *player2);

#endif /* GAME_H */
