#include <iostream>
#include "Set.h"
#include "Game.h"
#include "Player.h"
#include <windows.h>
																//////////////////// JAMIE HADDOW 0705082 DARTS ASSESSMENT ////////////////////
														//////////////////// MAIN.CPP WHERE THE MAIN LOOP AND COUT TAKES PLACE ////////////////////
																/////////////               commenting complete               /////////////

// Two functions below were used in my Slot machine to hide the cursor from going crazy on the screen when the setcursorposition is called. I used these for a visual indicator of what game its currently playing
void ShowConsoleCursor(bool showFlag) // SetConsoleCursorInfo function to hide the cursor from jumping all over the screen
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setCursorPosition() // resetting the cursors positiong back to 0,0 instead of using the system("CLS") command that cause blinking of the screen
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0,0 };
	SetConsoleCursorPosition(hOut, coord);

}

int main()
{
	// creating the array for storing the results of each set
	int JoeSidArray[8][8]{};
	int PlayTimes = 10000;
	//setting the cursor to invisible
	ShowConsoleCursor(false);
	// variables created to allow me to creat a tally of the total wins and work out who won the championship at the end of the program
	int totalJoeWins = 0;
	int totalSidWins = 0;

	//this is the main loop running for the amount of the variable "playtimes"
	for (int i = 0 ; i < PlayTimes; i++)
	{
		// using the setcursor posiiton i made it so the cursor is set to 0,0 and it gives the impression of a incrimenting counter
		std::cout << "\n\n\n\n\n\t\t\t\t\tplaying games : " << i << "/" << "1000";
		
		// creating a new set object to run the set class functions. Set set Set() is nto exactly the best wording but i felt it was better than saying "game"
		Set set = Set();
		set.Set1();

		// once a set is finished, both player scores are added to this array, for exmple, a score of 7-2 might be added to elements  4 and a score of 7-3 to elements 5
		JoeSidArray[set.JoeWins()][set.SidWins()]++;

		//this has a cumulative score to allow me to display the final number of wins and calculate who won the tournament
		totalJoeWins = totalJoeWins + set.JoeWins();
		totalSidWins = totalSidWins + set.SidWins();
		//setting cursor to 0,0
		setCursorPosition();
	}
	//this will clear the screen of the previous counter ready for the frequency chart.
	system("CLS");
	std::cout << "\n\n\n\n\n";

	//this first for statement will print of joes 1-7 wins so his score is always on the left
	for (int joe = 0 ; joe < 8; joe++)
	{
		//this first for statement will print of joes 1-7 wins so his score is always on the right
		for (int sid = 0 ; sid < 8; sid++)
		{
				// we only want to display a score of 7 as thats the number where they win a set. any other score should not happen E.G 5:2, 4:1, 4:6
				if (joe == 7 || sid == 7)
					std::cout << "\t\t\t\tJoe " << joe << " - " << sid << " Sid  =  Joe wins: "
					<< JoeSidArray[joe][sid] << " sets. Win Percentage: "
					//getting the frequency of the games by dividing the arrays by 1000 and then multiplying  by 100
					<< ((100 * JoeSidArray[joe][sid]) / PlayTimes) << "%" << std::endl;
		}
	}
	// a cout to show how many games each player won
	std::cout << "\n\t\t\t\t    Joe won  " <<totalJoeWins << " times. Sid won " << totalSidWins << " times" << std::endl;

	// simple cout if joe won more games give him a win message, if not then give joe a message
	if (totalJoeWins > totalSidWins)
		std::cout << "\n\t\t\t Joe won the championship. Cheating git going first all the time!\n\n" << std::endl;
	else 
		std::cout << "\n\t\t\t Sid won the championship. Hurray for the underdog! \n\n";

	// pausing the console until a user input to allow the user to see the results
	system("pause");
	return 0;
}