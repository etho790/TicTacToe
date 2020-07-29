#include "Tictactoe.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
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

void TicTacToe::cleargrid(char grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = ' ';
		}
	}
}

void TicTacToe::playgame(int& player, char & symbol, int X, int Y, char grid[3][3])
{
	char player2symbol;
	drawgrid(grid);
Player1:
	while (player == 1)
	{

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

		if (grid[Y - 1][X - 1] == 'X' || grid[Y - 1][X - 1] == '0')
		{
			cout << "cant place it there, Try again" << endl;
			system("CLS");
			goto tryagain;
		}
		if (grid[Y - 1][X - 1] != 'X' || grid[Y - 1][X - 1] != '0')		//doesnt execute this part
		{
			grid[Y - 1][X - 1] = symbol;
			drawgrid(grid);



			//verticals
			if (grid[0][0] == symbol && grid[1][0] == symbol && grid[2][0] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			if (grid[0][1] == symbol && grid[1][1] == symbol && grid[2][1] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			if (grid[0][2] == symbol && grid[1][2] == symbol && grid[2][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			//horizontals
			if (grid[0][0] == symbol && grid[0][1] == symbol && grid[0][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			if (grid[1][0] == symbol && grid[1][1] == symbol && grid[1][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			if (grid[2][0] == symbol && grid[2][1] == symbol && grid[2][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			//diagonals

			if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			if (grid[2][0] == symbol && grid[1][1] == symbol && grid[0][2] == symbol)
			{
				cout << "YOU WIN!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			cout << "AI's turn" << endl;
			player = 2;				//AI
		}
	}
	while (player == 2)				//AI
	{
		if (symbol == 'X')
		{
			player2symbol = '0';
		}
		if (symbol == '0')
		{
			player2symbol = 'X';
		}
		cout << "The AI will use " << player2symbol << endl;


	tryagain2:
		int x = 1 + rand() % 3;
		int y = 1 + rand() % 3;
		X = x;
		while (X < 1 || X>3)
		{
			cout << "testing... X co-ord" << x << endl;

			if (X >= 1 && X <= 3)
			{
				break;
			}
		}
		Y = y;

		while (Y < 1 || Y>3)
		{
			cout << "testing... Y co-ord" << y << endl;
			if (Y >= 1 && Y <= 3)
			{
				break;
			}
		}

		if (grid[Y - 1][X - 1] == 'X' || grid[Y - 1][X - 1] == '0')
		{

			system("CLS");
			goto tryagain2;
		}
		if (grid[Y - 1][X - 1] != 'X' || grid[Y - 1][X - 1] != '0')
		{
			grid[Y - 1][X - 1] = player2symbol;
			drawgrid(grid);


			//verticals
			if (grid[0][0] == player2symbol && grid[1][0] == player2symbol && grid[2][0] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			if (grid[0][1] == player2symbol && grid[1][1] == player2symbol && grid[2][1] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			if (grid[0][2] == player2symbol && grid[1][2] == player2symbol && grid[2][2] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			//horizontals
			if (grid[0][0] == player2symbol && grid[0][1] == player2symbol && grid[0][2] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			if (grid[1][0] == player2symbol && grid[1][1] == player2symbol && grid[1][2] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			if (grid[2][0] == player2symbol && grid[2][1] == player2symbol && grid[2][2] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			//diagonals

			if (grid[0][0] == player2symbol && grid[1][1] == player2symbol && grid[2][2] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}
			if (grid[2][0] == player2symbol && grid[1][1] == player2symbol && grid[0][2] == player2symbol)
			{
				cout << "AI WINS!!" << endl;
				cout << "The system will now EXIT!!" << endl;
				//system("CLS");
				return;
			}

			cout << "player 1's turn" << endl;
			player = 1;
			goto Player1;
		}
	}
}

void TicTacToe::mainmenu()
{

	char symbol;
	int option = -1;
	cout << "Welcome to TicToeToe, choose from the options below." << endl;
	cout << "1: PLAY GAME." << endl;
	cout << "2: EXIT." << endl;;
	cin >> option;
	switch (option)
	{
	case (1):
		system("CLS");
		cleargrid(grid);

		cout << "choose your symbol" << endl;
		symbol = XorO();

		playgame(player = 1, symbol, X, Y, grid);
		if (isMovesLeft(grid) == false)
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

	int g;
	std::cin >> g;
	return;
}



char TicTacToe::XorO()
{
	char Symbol;
	int input;
	cout << "choose X (1) or 0(2)" << endl;
	cin >> input;
	switch (input)
	{
	case (1):
		Symbol = 'X';
		return (Symbol);
		break;

	case(2):
		Symbol = '0';
		return (Symbol);
		break;
	}

	if (input != 1 || input != 2)
	{
		exit(0);
	}
	return 0;
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
