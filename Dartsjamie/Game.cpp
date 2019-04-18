#include "Game.h"
#include "Darts.h"

//empty constructor
Game::Game()
{

}

int Game::Player1Wins()
{
	return player1;
}

int Game::Player2Wins()
{
	return player2;
}

void Game::Game1()
{
	while (!gameOver)
	{
		
		Darts currentGame = Darts();

		
		bool didPlayer1Win = currentGame.Game();

	
		if (didPlayer1Win)
			++player1;
		else
			++player2;


		if (player1 == 7 || player2 == 7)
			return;
	}
}

