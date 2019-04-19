#include "Game.h"
#include <iostream>
#include <time.h>

													//////////////////// GAME CLASS FOR A SINGLE GAME ////////////////////
														/////////////        commenting complete        /////////////
// the constructor
Game::Game()
{
	//creating the player objects and setting their accurancy using the "setAccuracy"
	Joe = Player();
	Sid = Player();
	//manually setting the players accurancy for the bullhit in accorance to the week 8 docuemnt"Joe and Sid hit bulls with, as before, 71% and 73% success rates respectively."  
	//Normal acuracy is both 80 and 10% left chance, 10% right chance during the actual throw process again as set in the week 8 document
	Joe.SetBullAccuracy(71);
	Sid.SetBullAccuracy(73);
}


//I decided on the name "update"  due to Pauls course using Update for pretty much anything ongoing in the program. I already had the class called Game and did not want to get confused. i could have called it "SingleGame"
//Purpose - the main function containing the logic of the game and passing in the functions from player
//Paramaters - None
//Output - returtning a bool if a condition is met
void Game::Update()
{


	//Add 1 to the current throw variable until 3 has been reached, calculate the players score and then switch player. 
	//This was causing a bug when added to "if (Playingnow->GetScore() <= 1)" statement and would go to a 4th throw. However in a game of darts, if a player is on 5, and throws a 6, his turn is not over,
	//The throw is just not taken into account and he can then throw his next dart.
	currentThrow++;
	//I originally intended to make a very large switch statement with all the different possibilities. Throw for T20 if score > 180 then if score = 179 do this throw, 178, do this, 177 do that, 
	//but after watching some darts games and looking at the nine-dart-finish wiki i realized the professionals are constantly aiming for 20s unless that other number can win the game 
	//By throwing 6 T20s you will reduce your score to 141. By throwing another T20 Your score would be 81 ( If score > 82) and (if score <= 81). 
	//I tried originally having  <= 40 for a doubles win, ==50 for a bull win and <=81 to get into a double win position
	// however, in the test runs the score would get stuck on 41 due to the <= 81 logic trying to throw a triple to win. I realize that i would need another number between 40 and 82 as the logic was struggling.
	//I added <=60 so i could try andd aim for a single 20 to get a score of 40 for a winning double and that seems to be working
	// I attempted to make it <=61 but then it could potentially be 61-40  for the dubloe throw logic and that would leave 21 which is not on the dart board and if i increased he 40 to 42, then i might get a -1 or -2

	// on the 501 rule "the last dart thrown must land in a double or the bullseye"
	// if the current players score is less or equal to 40 then he can win in the next shot by throwing a double unless the current score is odd, if thats the case, he will throw a single and aim for 1
	if (Playingnow->GetScore() <= 40)
	{
		if ((Playingnow->GetScore() % 2) == 0) // using the pointer for the player whos now playing and getting access to the player score, 
											      //we check to see if the score modules of 2 is equal to zero, if so then its even and a double can be thrown to win the game
												  // If the modulus is not 0 then we have a remaining number. such as 7/%2 would nto be zero, but 6%2 would be
												  // E.G score is 36. Divide by 2 is 18, if we throw a double 18 we win the game, so below it would be (Double, 18)
		{
			Playingnow->Throw(Double, Playingnow->GetScore() / 2); //calling the Throw function and passing in the parameter of the enum "double" and the current score/2 for what number to aim at
		}
		else
		{
			Playingnow->Throw(Single, 1 ); // if the current score is not equal to an even number then we must reduce the score by 1 to make it even for the next throw using the paramaters 1 and the enum single
		}
	}
	// if the current score is equal to 50 then player and attempt to hit a bull and win the game, putting a zero in the second parameter for throw as we d
	else if (Playingnow->GetScore() == 50)
	{
		Playingnow->Throw(Bull, 0);
	}

	//if the current score is less or equal to 60, then using the enum single and take the current score -40 to get into a winning score with a double
	//E.G score of 54, and the current score -40 is 14, throw a single 14 to reduce score to 40 and then throw a double 20 to win 
	else if (Playingnow->GetScore() <= 60)
	{
		Playingnow->Throw(Single, Playingnow->GetScore() - 40);
	}

	//if the current score is less or equal to 81 and even then called a double throw. If score is odd call a triple throw
	//E.G score of 70 - 40  /2 would be double 15 which would reduce the score to 40 and the above if statement would be called to win the game
	//E.G score of 67 - 40 /3 would be triple 9 which would reduce the score to 40 and again the above if statment would be called to win the game
	else if (Playingnow->GetScore() <= 81) 
	{
		if ((Playingnow->GetScore() % 2) == 0)
		{
			Playingnow->Throw(Double, (Playingnow->GetScore() - 40) / 2);
		}
		else
		{
			// We can still throw a triple 20 here as that would reduce the score 
			Playingnow->Throw(Triple, (Playingnow->GetScore() - 40) / 3);
		}
	}

	// if the score is > 82 then throw for a triple 20 for the maximum reduction in score like the professionals would aim for.
	else
	{
		Playingnow->Throw(Triple, 20);
	}

	//Once the player has thrown 3 darts which is what you get in an official darts game, the next player will take his turn and repeating until a winner is decided.
	if (currentThrow == 3)
	{
		// if the current player is joe then set the current player to sid. If its already sid then set to joe and reset the current throw to zero and get the score of that player.
		// If we dont reset the counter then we will start the nw turn with a throw counter of 3 and get stuck in an infinite loop
		// The starting score for that player round will be gottten by calling the "GetScore" function and setting that as the new start score.
		if (Playingnow == &Joe)
			Playingnow = &Sid;
		else
			Playingnow = &Joe;
		currentThrow = 0;
		startScore = Playingnow->GetScore();
	}

	// if the score is equal to zero then set the bool gameover to true which will make the program leaving the game function and then give a player a point depending on who won
	if (Playingnow->GetScore() == 0)
	{
		// once true, the game will exit the update loop and depending on the currentplayer(the current player being the first to reach zero) that will either return true or false
		gameOver = true;
		return;
	}
	// If the score is 1 or below then set the score to what it was at the start of the throw
	if (Playingnow->GetScore() <= 1)
	{
		Playingnow->SetScore(startScore);
		currentThrow = 2;
	}
}

//Purpose - A boolean to see if the game has finished
//Paramaters - None
//Output - returning a true or false to increment the players scores in the set.cpp.
bool Game::Joewin()
{
	// As stated in the assessment task 1, Joe is to go first
	Playingnow = &Joe;

	while (!gameOver) // until the GameOver state has been reached, call the update function to continue the game
	{
		Update();
	}

	// This must happen after the gameOver loop has ended otherwise joe will win EVERY game. 
	if (Playingnow == &Joe)
		return true;
	else
		return false;

}