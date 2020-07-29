#ifndef Tictactoe_H
#define Tictactoe_H


class TicTacToe
{
public:

	void drawgrid(char grid[3][3]);


	void cleargrid(char grid[3][3]);
	int player;
	void playgame(int& player, char &symbol, int X, int Y, char grid[3][3]);
	void mainmenu();
	char XorO();
	bool isMovesLeft(char board[3][3]);
private:
	char grid[3][3];
	int X;
	int Y;

};

#endif