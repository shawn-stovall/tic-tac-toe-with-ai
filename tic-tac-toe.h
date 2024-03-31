/*
	Shawn Stovall
	Tic-Tac-Toe header
	
	2018-05-19
*/

#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

#include <stdio.h>
#include <time.h>

// Representations

#define X           1
#define O          -1
#define EMPTY       0
#define DIMENSION   3
#define X_WIN       DIMENSION * X
#define O_WIN       DIMENSION * O
#define X_COMPARE   >=
#define O_COMPARE   <=

// Struct for holding the location a of spot on the board.
typedef struct location {
	int row;
	int col;
} location;

// Prototypes

void display_board(int board[DIMENSION][DIMENSION]);
location select_location(int board[DIMENSION][DIMENSION]);
void set_turn(int xo, location loc, int board[DIMENSION][DIMENSION]);
int check_for_win(int board[DIMENSION][DIMENSION]);
int check_for_hwin(int board[DIMENSION][DIMENSION]);
int check_for_vwin(int board[DIMENSION][DIMENSION]);
int check_for_dwin(int board[DIMENSION][DIMENSION]);
void populate_board(int board[DIMENSION][DIMENSION]);
int is_board_full(int board[DIMENSION][DIMENSION]);
int occupied(location loc, int board[DIMENSION][DIMENSION]);
char convert_xo(int xo);

#endif
