#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class ChessBoard  {
public:
	// The parameter in this constructor gives the size of the board
	ChessBoard(int size);
	~ChessBoard();

	// Removes all queens from the board
	void ClearBoard();

	//Pre: There is one queen in column 0 through column c-1, and none
	//     of these queens can attack each other.
	//     It attempts to place queens in the remaining columns, and returns
	//     true if all the other queens were placed and false otherwise.
	bool PlaceQueens(int c);

    //int CountSolutions(int);

	//  Prints the current state of the board
	friend ostream& operator<<(ostream&, const ChessBoard&);

	//  Counts the total number of solutions - do this last - uncomment it when you need it.
	//  Returns the TOTAL number of solutions
	//  int CountSolutions(int)


private:
	//Pre: There is a queen at row r and column c
	//Post: There is no queen in row r and column c
	void RemoveQueen(int r, int c);

	//Pre: The square at row r and column c is safe
	//Post: A queen is placed at row r and column c
	void SetQueen(int r, int c);

	//Pre: 0 <= r < n  and 0 <= c < n
	//     Returns true if the square at row r and column c is safe (i.e., 
	//     can't be attacked by any queen currently placed on the board), 
	//     and false otherwise.
	bool Safe(int r, int c) const;

	// Contains the number of squares on one side of the chess board.
    int n;

	// queen[c] is the row where the queen in column c is currently placed.
	int* queen;

	// row[r] is true if there is currently a queen in row r.
	bool* row;

	// negdiag[i] is true if there is a queen in the ith negative diagonal.
	bool* negdiag;

	// posdiag[i] is true if there is a queen in the ith positive diagonal.
	bool* posdiag;
};
#endif