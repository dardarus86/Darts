#include "Darts.h"
#include <iostream>
#include <time.h>
// the constructor
Darts::Darts()
{
	
	//creating the player objects and setting their accurancy using the "setAccuracy"
	Joe = Player();
	Sid = Player();
	//manually setting the players accurancy for the bullhit in accorance to the week 8 docuemnt"Joe and Sid hit bulls with, as before, 71% and 73% success rates respectively."  
	//Normal acuracy is both 80 and 10% left chance, 10% right chance during the actual throw process again as set in the week 8 document
	Joe.SetBullAccuracy(71);
	Sid.SetBullAccuracy(73);
}
//Purpose - A boolean to see if the game has finished
//Paramaters - None
//Output - none, but it will exit when a condition is met
bool Darts::Game()
{
	// As stated in the assessment task 1, Joe is to go first
	currentPlayer = &Joe;
	
	while (!gameOver) // until the GameOver state has been reached, call the update function to continue the game
	{
		Update();
	}

	if (currentPlayer == &Joe)
		return true;
	else
		return false;
}
// i decided on the name update due to Pauls course using Update for pretty much anything ongoing in the program
//Purpose - the main function containing the logic of the game and passing in the functions from player
//Paramaters - None
//Output - returtning a bool if a condition is met
void Darts::Update()
{


	// add 1 to the current throw variable until 3 has been reached, calculate the players score and then switch player
	currentThrow++;
	// I originally intended to make a very large switch statement with all the different possibilities. Throw for T20 if score > 180 then if score = 179 do this thorw, 178, do this, 177 do that, 
	// but after watching some darts games i realized the professionals are constantly aiming for 20s unless that other number can win the game so decided to simplify my logic to 5 choices.  <= 40, == 50, <=60 and <=80 else go for T20

	// if the current players score is less or equal to 40 then he can win in the next shot by throwing a double unless the current score is odd, if thats the case, he will throw a single and aim for 1
	if (currentPlayer->GetScore() <= 40) 
	{
		if ((currentPlayer->GetScore() % 2) == 0) // using the pointer for current player and getting access to the player score, 
											      //we check to see if the score divided by 2 is equal to zero, if so then its even and a double can be thrown to win the game
												  // E.G score is 36. Divide by 2 is 18, if we throw a double 18 we win the game, so below it would be (Double, 18)
		{
		currentPlayer->Throw(Double, currentPlayer->GetScore() / 2); //calling the Throw function and passing in the parameter of the enum "double" and the current score/2 for what number to aim at
		}
		else
		{
		currentPlayer->Throw(Single, 1 ); // if the current score is not equal to an even number then we must reduce the score by 1 to make it even for the next throw using the paramaters 1 and the enum single
		}
	}
	else if (currentPlayer->GetScore() == 50) // if the current score is equal to 50 then player and attempt to hit a bull and win the game, putting a zero in the second parameter for throw
	{
	currentPlayer->Throw(Bull, 0);
	}
	else if (currentPlayer->GetScore() <= 60) //if the current score is less or equal to 60, then using the enum single and take the current score -40 to get into a winning score with a double
											  //E.G score of 54, and the current score -40 is 14, throw a single 14 to reduce score to 40 and then throw a double 20 to win 
	{
	currentPlayer->Throw(Single, currentPlayer->GetScore() - 40);
	}
	else if (currentPlayer->GetScore() <= 80) //if the current score is less or equal to 80 and even then called a double throw. If score is odd call a triple throw
											  //E.G score of 70 - 40  /2 would be double 15 which would reduce the score to 40 and the above if statement would be called to win the game
											  //E.G score of 67 - 40 /3 would be triple 9 which would reduce the score to 40 and again the above if statment would be called to win the game
	{
		if ((currentPlayer->GetScore() % 2) == 0)
		{
		currentPlayer->Throw(Double, (currentPlayer->GetScore() - 40) / 2);
		}
		else
		{
		currentPlayer->Throw(Triple, (currentPlayer->GetScore() - 40) / 3);
		}
	}
	else // if the score is > 80 then throw for a triple 20 for the maximum reduction in score like the professionals would aim for.
	{
		currentPlayer->Throw(Triple, 20);
	}

	//for switching the player
	if (currentThrow == 3)
	{
		// if the current player is joe then set the cirrent player to sid. If its already sid then set to joe and reset the current throw to zero and get the score of that player
		if (currentPlayer == &Joe)
			currentPlayer = &Sid;
		else
			currentPlayer = &Joe;
		currentThrow = 0;
		startScore = currentPlayer->GetScore();
	}

	// if the score is equal to zero then set the bool gameover to true which will make the program leaving the game function
	if (currentPlayer->GetScore() == 0)
	{
		gameOver = true;
		return;
	}
	// If the score is 1 or below then set the score to what it was at the start of the throw and then set the current throws to 3 so it will switch player
	if (currentPlayer->GetScore() <= 1)
	{
		currentPlayer->SetScore(startScore);
		currentThrow = 2;
	}


}