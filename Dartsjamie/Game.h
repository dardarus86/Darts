#pragma once


class Game
{
public:
	Game();

	void Game1();
	int Player1Wins();
	int Player2Wins();

private:

	int player1 = 0;
	int player2 = 0;
	bool gameOver = false ;

};
