#include "tictactoe.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;



void TicTacToe::drawgrid(char grid[3][3])  //takes in an array which is the value to be placed in the board
{
	cout << "  "; // Inital spacing

	cout << endl << " "; // new line and initial spacing 

	for (int Xvalue = 0; Xvalue < 3; Xvalue++)
	{
		cout << "--" << Xvalue + 1 << "-"; // Top line
	}
	cout << " " << endl;
	for (int Yvalue = 0; Yvalue < 3; Yvalue++)
	{
		cout << Yvalue + 1;
		for (int Xvalue = 0; Xvalue < 3; Xvalue++)
		{
			cout << "| " << grid[Yvalue][Xvalue] << " "; // the acWhichBoard[row][coloumn] is the array or the value thats going to be placed in grid
		}
		cout << "|" << endl;
		cout << " ";
		for (int Xvalue = 0; Xvalue < 3; Xvalue++)
		{
			cout << "----"; // Draws last lines
		}
		cout << " " << endl;
	}
	cout << endl;
}

void TicTacToe::cleargrid(char grid[3][3])	//clears the grid
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = ' ';
		}
	}

}

void TicTacToe::playgame(int& player, char & symbol, int X, int Y, char grid[3][3])	//looks for wins and ties for player 1 and player 2
{

	char player2symbol;
	drawgrid(grid);
Player1:
	while (player == 1)
	{
		symbol = 'o';		//do the same for player 2

	tryagain:
		cout << "where would you place your X mark?" << endl;
		cin >> X;
		while (X < 1 || X>3)
		{
			cout << "X must be between 1 and 3" << endl;
			cin >> X;
			if (X >= 1 && X <= 3)
			{
				break;
			}
		}
		cout << "where would you place your Y mark?" << endl;
		cin >> Y;

		while (Y < 1 || Y>3)
		{
			cout << "Y must be between 1 and 3" << endl;
			cin >> Y;
			if (Y >= 1 && Y <= 3)
			{
				break;
			}
		}

		if (grid[Y - 1][X - 1] == 'x' || grid[Y - 1][X - 1] == 'o')
		{
			cout << "cant place it there, Try again" << endl;
			system("CLS");
			goto tryagain;
		}
		if (grid[Y - 1][X - 1] != 'x' || grid[Y - 1][X - 1] != 'o')		//doesnt execute this part
		{
			grid[Y - 1][X - 1] = symbol;
			drawgrid(grid);



			//verticals
			if (grid[0][0] == symbol && grid[1][0] == symbol && grid[2][0] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}

			if (grid[0][1] == symbol && grid[1][1] == symbol && grid[2][1] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}

			if (grid[0][2] == symbol && grid[1][2] == symbol && grid[2][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}

			//horizontals
			if (grid[0][0] == symbol && grid[0][1] == symbol && grid[0][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}
			if (grid[1][0] == symbol && grid[1][1] == symbol && grid[1][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}
			if (grid[2][0] == symbol && grid[2][1] == symbol && grid[2][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}
			//diagonals

			if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}
			if (grid[2][0] == symbol && grid[1][1] == symbol && grid[0][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				system("CLS");
				exit(0);
			}

			cout << "AI's turn" << endl;
			player = 2;				
		}
	}

	while (player == 2)				
	{
		symbol = 'x';
		TicTacToe bestmove = findBestMove(grid);
		grid[bestmove.row][bestmove.col] = symbol;
		system("CLS");
		drawgrid(grid);
		


		//verticals
		if (grid[0][0] == symbol && grid[1][0] == symbol && grid[2][0] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}

		if (grid[0][1] == symbol && grid[1][1] == symbol && grid[2][1] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}

		if (grid[0][2] == symbol && grid[1][2] == symbol && grid[2][2] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}

		//horizontals
		if (grid[0][0] == symbol && grid[0][1] == symbol && grid[0][2] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}
		if (grid[1][0] == symbol && grid[1][1] == symbol && grid[1][2] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}
		if (grid[2][0] == symbol && grid[2][1] == symbol && grid[2][2] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}
		//diagonals

		if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}
		if (grid[2][0] == symbol && grid[1][1] == symbol && grid[0][2] == symbol)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The system will now EXIT!!" << endl;
			
			return;
		}

		if (isMovesLeft(grid) == false)
		{

			return;
		}




		cout << "Your turn" << endl;
		player = 1;
		goto Player1;
	}
}



void TicTacToe::mainmenu()
{
	
	
	TicTacToe bestMove;
	bestMove.col = 10;
	bestMove.row = 10;
	char symbol;
	int option;

	cout << "Welcome to TicToeToe, choose from the options below." << endl;
	cout << "1: PLAY GAME." << endl;
	cout << "2: EXIT." << endl;;
	cin >> option;
	switch (option)
	{
	case (1):
		system("CLS");
		cleargrid(grid);

		
		playgame(player = 1, symbol, X, Y, grid);
		bestMove = findBestMove(grid);
		if (isMovesLeft(grid) == false && bestMove.col == -1 && bestMove.row == -1)
		{
			cout << "IT'S A TIE!!!!." << endl;
			cout << "play again!!" << endl;
			mainmenu();
			exit(0);
		}

		
		
		break;
	case (2):
		return;

	}
	
	int H;
	cin >> H;
	return;
}

TicTacToe TicTacToe::findBestMove(char board[3][3])		
{
	int bestVal = -1000;

	TicTacToe bestMove;
	bestMove.row = -1;		//can be any arbitrary number
	bestMove.col = -1;		//can be any arbitrary number

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			
			if (board[i][j] == ' ')
			{
				// Make the move
				board[i][j] = 'x'; 
				drawgrid(board);


				// compute evaluation function for this
				// move.
				int Movevaluation = minimax(board, 0, 0, -1000, 1000);		

				board[i][j] = ' ';
				drawgrid(board);
			


			
				if (Movevaluation > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = Movevaluation;		//this sets the new value of the maximizer
				}
			}
		}
	}

	

	return bestMove;


	
}

int TicTacToe::evaluate(char b[3][3])
{

	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		if (b[row][0] == b[row][1] && b[row][1] == b[row][2])
		{
			if (b[row][0] == 'x')
			{
				return +10;
			}
			else if (b[row][0] == 'o')
			{
				return -10;
			}
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (b[0][col] == b[1][col] && b[1][col] == b[2][col])
		{
			if (b[0][col] == 'x')
			{
				return +10;
			}

			else if (b[0][col] == 'o')
			{
				return -10;
			}
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == 'x')
		{
			return +10;
		}
		else if (b[0][0] == 'o')
		{
			return -10;
		}
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == 'x')
		{
			return +10;
		}
		else if (b[0][2] == 'o') 
		{
			return -10;
		}
	}

	// Else if none of them have won then return 0
	return 0;
}

int TicTacToe::minimax(char board[3][3], int temp, int isMax, int alpha, int beta)		
{
	int Score = evaluate(board);// gives a Score vased on a win condition if none its 0
	if (Score != 0) {
		
		if (Score == 10) {
			return Score;
		}
		
		if (Score == -10) {
			return Score;
		}

	}
	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(board) == false) 
	{
		return 0;
	}
	

	// If this maximizer's move( AI)
	if (isMax==1)
	{
		int value = -1000;


		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == ' ')
				{
					// Make the move
					board[i][j] = 'x';
					
					


					// Call minimax recursively and choose
					// the maximum value

					Score = minimax(board, temp, 0, alpha, beta);
					value = max(value, Score);
					alpha = max(value, alpha);

					// Undo the move
					board[i][j] = ' ';
					if (value > beta)
					{
						return value;
					}
					
					
				}
			}
		}
		return value;
	}

	// If this minimizer's move

	if(isMax==0)
	{
		int value = 1000;
		

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == ' ')
				{
					// Make the move
					board[i][j] = 'o';
					
					// Call minimax recursively and choose
					// the minimum value ie; THE BEST SPOT FOR THE AI WHICH GIVES A Score
					
					
					Score = minimax(board, temp, 1, alpha, beta);
					
					value = min(value, Score);
					beta = min(value, beta);

					// Undo the move
					board[i][j] = ' ';
					if (value < alpha)
					{
						return value;
					}
					

				}
			}
		}
		return value;
	}

}

bool TicTacToe::isMovesLeft(char board[3][3])
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (board[i][j] == ' ')
			{
				return true;
			}
		}
	}
	return false;
}
