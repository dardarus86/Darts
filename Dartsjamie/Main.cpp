#include <iostream>
#include "Game.h"
#include "Darts.h"
#include "Player.h"

#include <windows.h>
#include <time.h>

// code below was used in  my Slot machine to hide the cursor from going crazy on the screen when the setcursorposition is called
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
	ShowConsoleCursor(false);
	int playerScoreArray[8][8]{};
	int aiPlayTimes = 1000;

	for (int i = 0 ; i < aiPlayTimes; ++i)
	{
		std::cout << "playing games : " << i << "/" << "10000";
		
		Game game = Game();
		game.Game1();

		playerScoreArray[game.Player1Wins()][game.Player2Wins()]++;
		setCursorPosition();
	}

	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			// Only print out numbers with 7 (because thats the end of the game)
			if (i == 7 || j == 7)
				std::cout << "Joe " << i << " - " << j << " Sid ----- Frequency: "
				<< playerScoreArray[i][j] << " Percentage: "
				<< (float)(100 * (float)playerScoreArray[i][j] / (float)aiPlayTimes) << "%" << std::endl;
		}
	}

	//int playerScoreArray[8][8]{};
	//int numOfGames = 1000 ; // We are calculating the results after 1000 games

	//for (int i = 0; i < numOfGames; ++i) //First loop to go through the number of games
	//{ //numOfGames open

	//	for (int m = 0; m <= 13; m++)// second loop for calculating the set of 13 matches
	//	{ //set open

	//		for (int s = 0; s <= 5; s++) // Third loop for calculating the 5 sets of games
	//		{ // games open

	//		} // games close

	//	}//set close

	//}//numOfGames close

	//for (int i{ 0 }; i < 8; ++i)
	//{
	//	for (int j{ 0 }; j < 8; ++j)
	//	{
	//		// Only print out numbers with 7 (because thats the end of the game)
	//		if (i == 7 || j == 7)
	//			std::cout << "Joe " << i << " - " << j << " Sid ----- Frequency: "
	//			<< playerScoreArray[i][j] << " Percentage: "
	//			<< (float)(100 * (float)playerScoreArray[i][j] / (float)aiPlayTimes) << "%" << std::endl;
	//	}
	//}
	system("pause");
	return 0;
}