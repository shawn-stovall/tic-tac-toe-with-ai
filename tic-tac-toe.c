/*
	Shawn Stovall
	Tic-Tac-Toe functions
	
	2018-05-19
*/

#include "tic-tac-toe.h"

// Function to display the board.
void display_board(int board[DIMENSION][DIMENSION]) {
	// Declare counters
	int row;
	int col;
	int spacer;
	
	// Loop through board and display it.
	for (row = 0; row < DIMENSION; row++) {
		for (col = 0; col < DIMENSION; col++) {
			printf(" %c ", convert_xo(board[row][col]));
			if (col != DIMENSION - 1)
				printf("\xBA");
			else
				printf("\n");
		}
		
		if (row != DIMENSION - 1) {
			for (spacer = 0; spacer < DIMENSION - 1; spacer++)
				printf("\xCD\xCD\xCD\xCE");
		
			printf("\xCD\xCD\xCD\n");
		}
	}
}

// Function for querying for a location from the user.
location select_location(int board[DIMENSION][DIMENSION]) {
	location selection;
	
	// Ask for location and validate input.
	while (1) {
		printf("Please enter the row and then the column of your selection, seperated by a space: ");
		scanf("%d", &selection.row);
		scanf("%d", &selection.col);
		
		// Adjust the input to indecies.
		selection.row -= 1;
		selection.col -= 1;
		
		if ((selection.row >= DIMENSION || selection.row < 0) || (selection.col >= DIMENSION || selection.col < 0)) 
			printf("\nSelection is out of bounds, please try again.\n\n");
		else if (occupied(selection, board))
			printf("\nSelected spot is already occupied, please try again.\n\n");
		else
			break;
	}
	
	return selection;
}

// Set a spot on the board give a player (X or O), a location, and the board.
void set_turn(int xo, location loc, int board[DIMENSION][DIMENSION]) {
	board[loc.row][loc.col] = xo;
}

// Check for a win, returns int representation of X if X wins,
// int representatin of O if O wins, or 0 if there is no winner.
int check_for_win(int board[DIMENSION][DIMENSION]) {
	// Check all possible ways a person can win.
	int hwin = check_for_hwin(board);
	int vwin = check_for_vwin(board);
	int dwin = check_for_dwin(board);
	
	// Return the winner if there is one.
	if (hwin)
		return hwin;
	else if (vwin)
		return vwin;
	else if (dwin)
		return dwin;
	else
		return 0;
}

// Check for horizontal wins.
int check_for_hwin(int board[DIMENSION][DIMENSION]) {
	int row;
	int col;
	int sum;
	
	for (row = 0; row < DIMENSION; row++) {
		sum = 0;
		
		for (col = 0; col < DIMENSION; col++)
			sum += board[row][col];
		
		if (sum == X_WIN)
			return X;
		else if (sum == O_WIN)
			return O;
	}
	
	return 0;
}

// Check for vertical wins.
int check_for_vwin(int board[DIMENSION][DIMENSION]) {
	int row;
	int col;
	int sum;
	
	for (col = 0; col < DIMENSION; col++) {
		sum = 0;
		
		for (row = 0; row < DIMENSION; row++)
			sum += board[row][col];
		
		if (sum == X_WIN)
			return X;
		else if (sum == O_WIN)
			return O;
	}
	
	return 0;
}

// Check for diagonal wins.
int check_for_dwin(int board[DIMENSION][DIMENSION]) {
	int row;
	int sum;
	
	sum = 0;
	for (row = 0; row < DIMENSION; row++)
		sum += board[row][row];
	
	if (sum == X_WIN)
		return X;
	if (sum == O_WIN)
		return O;
	
	sum = 0;
	for (row = 0; row < DIMENSION; row++)
		sum += board[row][(DIMENSION - 1) - row];
	
	if (sum == X_WIN)
		return X;
	if (sum == O_WIN)
		return O;
	
	return 0;
}

// Check to see if the board is full.
int is_board_full(int board[DIMENSION][DIMENSION]) {
	int row;
	int col;
	
	for (row = 0; row < DIMENSION; row++)
		for (col = 0; col < DIMENSION; col++)
			if (board[row][col] == EMPTY)
				return 0;
	
	return 1;
}

// Check to see if a spot on the board is occupied.
int occupied(location loc, int board[DIMENSION][DIMENSION]) {
	if (board[loc.row][loc.col] != EMPTY)
		return 1;
	else
		return 0;
}

// Convert the int representation of X, O, or EMPTY
// to its string representation.
char convert_xo(int xo) {
	if (xo == X)
		return 'X';
	else if (xo == O)
		return 'O';
	else
		return ' ';
}

// Populate the board with EMPTY.
void populate_board(int board[DIMENSION][DIMENSION]) {
	int row;
	int col;
	
	for (row = 0; row < DIMENSION; row++)
		for (col = 0; col < DIMENSION; col++)
			board[row][col] = EMPTY;
}
