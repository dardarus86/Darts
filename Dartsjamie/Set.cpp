#include "Set.h"

																//////////////////// SET CLASS FOR CALCULATING WHO HAS WON A SET AND RETURNING THE RESULT TO MAIN ////////////////////
																	/////////////                               commenting complete                               /////////////

//empty constructor
Set::Set(){}

//Purpose - create a new object to run a single game, once that game is complete take the winn by the joewin bool and increiment the score depending on result
//Paramaters - int
//Output - returning the values of the joe/sid int
void Set::Set1()
{
	// do this while loop until game over is set to true
	while (!gameOver)
	{
		//create a new game object for a game
		Game currentGame = Game();

		//reteive the bool state from the current game once a winner has been decided
		Whowon = currentGame.Joewin();

		// use the above data, if true then give joe +1, else sid +1
		if (Whowon)
			++Joe;
		else
			++Sid;

		//When either joe or Sid's scores have reached 7 then set the gameover state to true to exit the loop
		if (Joe == 7 || Sid == 7)
			gameOver = true;
	}
}

//Purpose - returning the values of joe or sid depending on who won
//Paramaters - int
//Output - returning the values of the joe/sid int
int Set::JoeWins() { return Joe; }
int Set::SidWins() { return Sid; }
