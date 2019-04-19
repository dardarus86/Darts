#include "Player.h"
#include <random>
#include <time.h>
#include <iostream>
										//////////////////// PLAYER LOGIC FOR THROWING SINGLE,DOUBLE,TRIPLE,BULL & OUTER BULL ////////////////////
											   /////////////                      commenting complete                         /////////////

//Purpose - setting the accuracy of the private variable
//Paramaters - int
//Output - none as its only setting
void Player::SetAccuracy(int acc)
{
	playerAccuracy = acc;
}

//Purpose - setting the bullaccuracy of the private variable
//Paramaters - int
//Output - none as its only setting
void Player::SetBullAccuracy(int bullacc)
{
	bullAccuracy = bullacc;
}



//functions below given by Lecturers
//Purpose - taking a random number, if its below the accuracy of the player, 71 or 73 which is p, if its below p then returnscore of 50, ,below60 return 25 else return 1 + rand of modulus 20 t0 choose a random number
//Paramaters - taking in an int which is then set within the game.cpp
//Output - returning 50,25 or 1-20  and minusing the score inside the enum switch statement below
int Player::bull(int p) {
	
	int r = rand() % 100;
	if (r<(p))
		return 50;
	else if (r<60)
		return 25;
	else
		return 1 + rand() % 20;
}

//Purpose - taking a random number, if its below the accuracy of the player 80 which is p, if its below p then 3 * the score passed into the function in Game.cpp. Alongside multiple other outcomes depending on rand.
//Paramaters - taking in an int which is then set within the game.cpp
//Output - returning 50,25 or 1-20 and minusing the score inside the enum switch statement below
int Player::treble(int d, int p) {

	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
	int r = rand() % 100;

	if (r<p)
		return 3 * d;
	else if (r<90)
		return d;
	else if (r<93)
		return 3 * bd[0][d];
	else if (r<96)
		return 3 * bd[1][d];
	else if (r<98)
		return bd[0][d];
	else
		return bd[1][d];
}

//Purpose - taking a random number, if its below the accuracy of the player 80 which is p, if its below p then 2 * the score passed into the function in Game.cpp. Alongside multiple other outcomes depending on rand.
//Paramaters - taking in an int which is then set within the game.cpp
//Output - returning 2* the int d else returning multiple outcomes depending on rand number
int Player::dble(int d) {

	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
	
	int r = rand() % 100;

	if (r<80)
		return 2 * d;
	else if (r<85)
		return 0;
	else if (r<90)
		return d;
	else if (r<93)
		return 2 * bd[0][d];
	else if (r<96)
		return 2 * bd[1][d];
	else if (r<98)
		return bd[0][d];
	else
		return bd[1][d];
}


//Purpose - taking a random number, if its below the accuracy of the player 80, if the score is 25, aim for the outer bull else aim for the number thats in int d
//Paramaters - taking in an int which is then set within the game.cpp
//Output - returning either an outerbull, bull or a random single number depending on the score input
int Player::single(int d) {

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
	int r = rand() % 100;

	if (d == 25) {		// outer  80%
		if (r<80)
			return 25;
		else if (r<90)
			return 50;
		else
			return 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (r<88)
			return d;
		else if (r<92)
			return bd[0][d];
		else if (r<96)
			return bd[1][d];
		else if (r<98)
			return 3 * d;
		else
			return 2 * d;
}


//Purpose - A throw function using enumerators shown in the games module
//Paramaters - taking in the enum type and an int which is then set within the game.cpp
//Output - returning the value of the throws above nad then minusing that number from the totalscore
void Player::Throw(EnumHit segment, int Number)
{
	switch (segment)
	{
	case Single:
		totalScore -= single(Number);
		break;
	case Double:
		totalScore -= dble(Number);
		break;
	case Triple:
		totalScore -= treble(Number, playerAccuracy);
		break;
	case Bull:
		totalScore -= bull(bullAccuracy);
		break;
	}
}