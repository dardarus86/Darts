#include "Game.h"
#include "Darts.h"

Game::Game()
{

}

void Game::Play()
{
	while (!gameOver)
	{
		// Creates new game
		Darts currentGame = Darts();

		// Returns true if player1 wins
		bool didPlayer1Win = currentGame.Game1();

		// Increase game win
		if (didPlayer1Win)
			++player1;
		else
			++player2;

		// If player won championship return
		if (player1 == 7 || player2 == 7)
			return;
	}
}

int Game::Player1Wins()
{
	return player1;
}

int Game::Player2Wins()
{
	return player2;
}