/*
	Shawn Stovall
	Tic-Tac-Toe AI header
	
	2018-05-19
*/

#ifndef AI_H_
#define AI_H_

#include "tic-tac-toe.h"
#include "stdlib.h"

#define EASY   0
#define MEDIUM 1
#define HARD   2

// A rank stored in each spot.
typedef struct spot_rank {
	int possible_wins;     // How many wins can be obtained for a point.
	int win_rank;          // All connected spots added up to give a rank.
	int blocking;          // If a spot blocks an opponent win.
	int win;               // If a spot leads to a win.
} spot_rank;

// Prototypes

void rank_board(int xo, int board[DIMENSION][DIMENSION], spot_rank ai_board[DIMENSION][DIMENSION]);
void rank_spot(int xo, location loc, int board[DIMENSION][DIMENSION], spot_rank ai_board[DIMENSION][DIMENSION]);
spot_rank scan_vh(int xo, location loc, int board[DIMENSION][DIMENSION]);
spot_rank scan_diag(int xo, location loc, int board[DIMENSION][DIMENSION]);
spot_rank scan_ldiag(int xo, int board[DIMENSION][DIMENSION]);
spot_rank scan_rdiag(int xo, int board[DIMENSION][DIMENSION]);
spot_rank add_rank(spot_rank first, spot_rank second);
int is_along_diag(location loc);
void place_spot(int xo, int difficulty, int board[DIMENSION][DIMENSION]);
void copy_spot_rank(spot_rank* dest, spot_rank source);

// Prototypes for testing functions

void display_ai_board(spot_rank ai_board[DIMENSION][DIMENSION]);

#endif
