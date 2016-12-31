#include <iostream>
#include "board.h"
#include <ctime>
using namespace std;

int main()  {
	cout << "Queen Placement\n\n";
	cout << "Enter size of board (positive integer): ";
	int boardsize;
	cin >> boardsize;
//	assert(boardsize>0);
	cout << "\nPlacing queens on a " << boardsize << " x " << boardsize
		 << " chess board...\n";

	clock_t startTime = clock();


    ChessBoard board(boardsize);
	if (board.PlaceQueens(0))  {
		cout << "Solution found!!\n" << board;
	} else {
		cout << "Impossible - the queen is never safe!!";
	}

	
	if (boardsize <= 18)  {
		board.ClearBoard();
		cout << "\n"
			 << "The total number of ways to place " << boardsize
			 << " queens on this chess board is "
			 << board.CountSolutions(0) << ".\n";
	} else {
		cout << "Sorry, the chess board is too large to compute the total "
			 << "number of solutions.\n";
	}

	clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	cout << endl << "It took " << timeInSeconds << " seconds" << endl << endl;


	return 0;
}
