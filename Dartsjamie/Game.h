#pragma once


class Game
{
public:
	Game();

	void Play();
	int Player1Wins();
	int Player2Wins();

private:

	int player1{ 0 }, player2{ 0 };
	bool gameOver{ false };

};
