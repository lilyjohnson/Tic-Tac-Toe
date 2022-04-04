/* Settings.h */

#ifndef SETTINGS_H
#define SETTINGS_H

#include "Game.h"

// players can choose their characters.
void choose_char(PLAYER *player1, PLAYER *player2);

// players can choose their colors.
void choose_color(PLAYER *player1, PLAYER *player2);

void settings(PLAYER *player1, PLAYER *player2);

// This function prints the board
void print_fun(int board[3][3],PLAYER *player1, PLAYER *player2);


#endif /* SETTINGS_H */
