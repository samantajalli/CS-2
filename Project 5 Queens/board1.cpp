#include <iostream>
#include "board.h"

ChessBoard::ChessBoard(int size)
{
	n = size;
	queen = new int[n];
	for (int i = 0; i <= n-1; i++)
		queen[i] = -1;
	
	row = new bool[n];
	for (int j = 0; j <= n-1; j++)
		row[j] = false;
	
	posdiag = new bool[2 * n - 1];
	for (int k = 0; k < 2 * n - 1; k++)
		posdiag[k] = false;
	
	negdiag = new bool[2 * n - 1];
	for (int l = 0; l < 2 * n - 1; l++)
		negdiag[l] = false;
}

ChessBoard::~ChessBoard()
{
	ClearBoard();
	delete [] queen;
	
	delete [] row;
	
	delete [] posdiag;  cout<< "d";
	delete [] negdiag;
	
	
}

void ChessBoard::ClearBoard()
{
	
	for (int i = 0; i <= n-1; i++)
		queen[i] = -1;
	
	
	for (int j = 0; j <= n-1; j++)
		row[j] = false;
	
	
	for (int k = 0; k <= 2 * n-1; k++)
		posdiag[k] = false;
	
	
	for (int l = 0; l <= 2 * n -1; l++)
		negdiag[l] = false;
	
	cout << "\nchessboard has been cleared";
}

bool ChessBoard::PlaceQueens(int c)
{
	
	
	int r = 0; // row starts at 0 position
	
	if (c == n)		// column went past board
		return true;

	while (r <= n - 1)
	{
		if (Safe(r, c))
		{
			SetQueen(r, c);
		if (PlaceQueens(c + 1) == true)
			return true;
		
		RemoveQueen(r, c);
		}
		r++;
	}
	
		return false;
			
		
	
}

bool ChessBoard::Safe(int r, int c) const // if queen in this row already or posdiag/negdiag hit a queen, false
{
	if ( row[r] == false) // if queen is not in the row
	{
		if (posdiag[(r-c) + (n-1)] == true || negdiag[r + c] == true) // queen hits another queen on its diagonals
			return false;
		else
		{
		return true;
		}// now queen is safe
	}
	else 
		return false; // there is a queen in that row
	
}

void ChessBoard::RemoveQueen(int r, int c)
{
	 queen[c] = -1;// take queen out of board
	 row[r] = false;
	 posdiag[(r-c) + (n-1)] = false;
	 negdiag[r + c] = false;
}

void ChessBoard::SetQueen(int r, int c) // put the queen on the board
{
	queen[c] = r; 
	row[r] = true;
	posdiag[(r-c) + (n-1)] = true; // queen exists on this diagonal
	negdiag[r + c] = true; // queen exists on this diagonal
}
ostream& operator<<(ostream& out, const ChessBoard& p)
{
	int a, b, c;
		for (a = 0; a < p.n; a++) // row
		{   
			//for (b = 0; b < p.n; b++) // column
			//out << "-----";
			//out << endl;

			for (c = 0; c < p.n; c++) // location of queen
			{
				out << "| ";
				
				if (p.queen[c] == a) // queen is here in this rowd
				out << "Q";
				 else out <<"-";
			}
				out << '|' << endl;
		}
		

		return out;
}
int ChessBoard::CountSolutions(int c)
{
	int count;
int r = 0; // row starts at 0 position
	
	if (c == n)		// column went past board
		return 1;

	else
	{
		count=0;
		for (; r < n; r++)
		{
		if (Safe(r, c)==true)
		{
			SetQueen(r, c);
		count +=CountSolutions(c+1);
		
		RemoveQueen(r, c);
		}
		}
	}
	return count;
}

