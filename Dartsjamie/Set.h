#pragma once
#include "Game.h"

													//////////////////// SET CLASS FOR CAULATING WHO HAS WON A SET AND RETURNING THE RESULT TO MAIN ////////////////////
														/////////////                               commenting complete                               /////////////

// This class will play games until a players score has reached 7. Once it has reached 7 it will return the outcome to the array in main to collate the results
class Set
{
public:
	Set();
	int JoeWins(); // If joe wins then return Joe
	int SidWins(); // If sid wins then return Sid
	void Set1(); // function for calculating a set and adding a winning score to the players total. once the total of 7 is reached a new set is played


private:

	int Joe = 0; // Set score for Joe
	int Sid = 0; // Set score for Sid
	bool Whowon = false; // used for who gains a point
	bool gameOver = false ; // once this is true, exit the set1 function

};
