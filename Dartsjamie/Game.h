#pragma once
#include "Player.h"

										    		//////////////////// GAME CLASS FOR A SINGLE GAME ////////////////////
									                	/////////////        commenting complete        /////////////
	
// This class will play a single game of darts until a player reaches zero. Once that is reached, if Joe is the current player it will return the  "Joewin" bool as true and give Joe++ score, otherwise it will sid++
class Game
{
public:
	Game();
	bool Joewin(); // if Joe wins, then return true. I did this after one of Pauls lectures showing the easiest way to do something is "if true then A else B"

private:
	//functions
	void Update(); // this function contains the process until the gameOver bool is set to true

	//variables
	int currentThrow = 0; // setting the number of throws to zero
	int startScore = 501; // setting the starting score to 501. This variable is also used for keeping tabs on the current score of each player and if the score is 1 or less than zero, the score will be reverted back
	bool gameOver = false; // setting the gameOver bool to false so the game does not finish immediatly!

	//objects
	Player Joe; // creating player object "joe"
	Player Sid; // creating player object "Sid"
	Player *Playingnow; // using a pointer to get the current player. I was going to use a ** and an array which is what Martin Ng did in his code, but couldnt get it working so went for creating two objects instead



};
