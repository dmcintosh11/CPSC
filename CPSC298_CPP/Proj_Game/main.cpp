/// @file main.cpp
/// @brief main function file for Game
/// @author dmcintosh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>   // defines std::cout, std::cin

#include "Game.h"     // defines Game class

// Main function for Game progam.
// @return 0 in all circumstances
int main()
{
	bool bPlay = true;
	Game game;

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: WRITE WHILE LOOP TO ASK IF USER WISHES TO PLAY ANOTHER GAME
	//
	// Within the while loop, have the Game object, game, call the play() member function.
	// Then, prompt the user if they want to play another game. If so, iterate through the
	// while loop again, otherwise, set bPlay to false (so that the while loop will cease iterating).
	// Consider using logical expressions like ('y' == cPlay) as in earlier assignments to check the
	// user input.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	while(bPlay)
	{
		game.play();

		std::cout << std::endl;
		char cPlay = 'n';
		std::cout << "Play another game? (y/n)" << std::endl;
		std::cin >> cPlay;
		if (cPlay =='n')
		{
			bPlay = false;
		}
	}

	return 0;
}
