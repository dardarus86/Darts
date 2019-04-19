#pragma once
#include "Player.h"

class Darts
{
public:
	Darts();
	bool Game(); // if Joe wins, then return true

private:
	//functions
	void Update(); // this function contains the process until the gameOver bool is set to true

	//variables
	int currentThrow = 0; // setting the number of throws to zero
	int startScore = 501; // setting the starting score to 501
	bool gameOver = false; // setting the gameOver bool to false so the game does not finish immediatly!

	//objects
	Player Joe; // creating player object "joe"
	Player Sid; // creating player object "Sid"
	Player *currentPlayer; // using a pointer to get the current player. I was going to use a ** and an array but was unsure how to impliment it and went for creating two objects instead



};
