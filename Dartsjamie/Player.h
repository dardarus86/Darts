#pragma once
#include "EnumHit.h"
	
												//////////////////// PLAYER LOGIC FOR THROWING SINGLE,DOUBLE,TRIPLE,BULL & OUTER BULL ////////////////////
									    				/////////////                      commenting complete                         /////////////
class Player
{
public:
	Player() // constructor
	{
		
		//setting the total score to 501 as per the games rules, giving both players an accurancy of 80 by default but setting the bull accurancy to zero as it will be set in the darts.cpp
		totalScore = 501;
		playerAccuracy = 80;
		bullAccuracy = 0;

	}

	int GetScore() { return totalScore; } // the getter for the private variable "totalScore"
	void SetScore(int score) { totalScore = score; }; // the setter for the private variable "totalScore"
	void Throw(EnumHit segment, int Number); // The main function for calculating the dart throws. Passing in 2 parameteres of an Enum and a number being either a number or the current score

	void SetAccuracy(int acc); //setting the accuracy
	void SetBullAccuracy(int bullacc); //setting the bull accuracy
protected:
	int bull(int p); // the function for hitting the bullseye
	int treble(int d, int p); // the function for hitting a treble
	int dble(int d);  // the function for hitting a double
	int single(int d); // the function for hitting a single

	//variables for the score
	int totalScore;
	int playerAccuracy;
	int bullAccuracy;
};