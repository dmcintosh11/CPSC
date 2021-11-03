/// @file Game.cpp
/// @brief Implementation file for Game class
/// @author dmcintosh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream> // defines std::cout
#include <tuple>    // defines std::tuple, std::tie
#include <cmath>    // defines std::abs
#include <random>   // defines random number generation functions
#include <ctime>    // defines time()

#include "Game.h"   // defines Game class

//#define TEST  // macro to enable test mode functionality (not used during ordinary gameplay)
 //#define DIAG  // macro to enable diagnostic output (not used during ordinary gameplay)

// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
// TODO: COMPLETE Game CONSTRUCTOR INITIALIZER LIST
// Member variables are initialized in the Game constructor using an initializer list. The initializer list
// follows the colon
//
//      Game::Game :
//
// Only two member variables initialized:
//
// m_nGridRows(k_nGridRowsDefault), m_nGridColumns(k_nGridColumnsDefault)
//
// Complete the initializer list by initializing m_iRowBoat to 0, m_iColumnBoat to 0, and
// m_nTorpedoes to k_nMaxTorpedoes.
//
// Also, within the body of the Game constructor (i.e. within the braces,{}, call member function
// intitializeGrid to initialize the a_cGrid two-dimensional array member variable.
// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
Game::Game() : m_nGridRows(k_nGridRowsDefault), m_nGridColumns(k_nGridColumnsDefault), m_iRowBoat(0), m_iColumnBoat(0), m_nTorpedoes(k_nMaxTorpedoes) /* ?? add initializers for member variables m_iRowBoat, m_iColumnBoat, and m_nTorpedoes. ?? */
{
	initializeGrid();
}

// Implementation notes on Game::initializeGrid
//
// When the coordinate grid is initialized, all elements of the
// the two dimensional array a_cGrid are set to contain the
// wave character, a tilde: '~'.
//
// When rendered by displayGrid, the initialized grid appears
// as follows:
//
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|

void Game::initializeGrid()
{
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: NESTED FOR LOOP TO INITIALIZE a_cGrid TWO DIMENSIONAL ARRAY
	// Write an outer for loop that iterates over the rows in the two-dimensional character array a_cGrid.
	// The loop index should be iRow. The condition expression of the for loop should be
	//
	//    iRow < this->m_nGridRows
	//
	// Write an inner for loop that iterates over the columns in the two-dimensional character array a_cGrid.
	// The loop index should be iColumn. The condition expression of the for loop should be
	//
	//     iColumn < this->m_nGridColumns
	//
	// Within the inner for loop, assign the array element indexed by iRow and iColumn to the tilde character,
	// '~'.
	//
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	for (int iRow = 0; iRow < this->m_nGridRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < this->m_nGridColumns; ++iColumn)
		{
			/*?? assign '~' to element of 2-D array a_cGrid indexed by iRow and iColumn ?? */
			a_cGrid[iRow][iColumn] = '~';
		}
	}
	return;
}

// Implementation notes on Game::displayGrid
//
// The displayGrid method shows every character within the two-dimensional
// character array a_cGrid. It places a bar on either side of the character
// to make the grid easier for the user to see.
//
// The grid initially contains only tilde characters, '~', ("waves"):
//
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
//
// Later it may contain asterisks ('*'), "torpedo explosions", the symbol for the target boat, 'V',
// or an 'X' to indicate the target boat was sunk at that location.
//
// The display of the target boat requires special handling.
//
// Assume that a the target boat is placed in position 2, 0 and a 'V' character is inserted at
// that location.
//
// During gameplay, the position of the target boat remains hidden and an wave (tilde character, '~')
// is rendered in that location. The displayGrid must "overwrite" the V character when parameter
// bShowboat is false.
//
// When bShowboat is false, the grid is rendered as follows. Note that location 2, 0 contains a '~'
// character.
//
// |*|~|~|~|~|
// |~|~|~|~|~|
// |~|*|*|~|~|
// |*|*|~|*|~|
//
// When the player has expended all of their torpedoes (and lost the game), the location of the
// target boat is rendered with a 'V' character.
//
// When bShowboat is true, the grid is rendered as follows: note that location 2,0 contains a
// 'V' character, indicating the position of the target boat.
// |*|~|*|*|~|
// |~|~|~|*|*|
// |V|*|*|~|~|
// |*|*|~|*|~|

void Game::displayGrid(bool bShowBoat) {



	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: NESTED FOR LOOP TO DISPLAY Game Coordinate Grid
	// Write an outer for loop that iterates over the rows in the two-dimensional character array a_cGrid.
	// The loop index should be iRow. The condition expression of the for loop should be
	//
	//    iRow < this->m_nGridRows
	//
	// Write an inner for loop that iterates over the columns in the two-dimensional character array a_cGrid.
	// The loop index should be iColumn. The condition expression of the for loop should be
	//
	//     iColumn < this->m_nGridColumns
	//
	// Within the inner for loop, display the element at the grid coordinate iRow, iColumn. Surround the
	// element with vertial bar characters, '|', as shown in the example renderings above.
	//
	// If the character in a_cGrid at location iRow and iColumn is a 'V' (the location of the target boat)
	// only display it if the value of parameter bShowBoat is true, otherwise hide it by displaying a
	// '~' (tilde) wave character instead.
	//
	// To emit the bar character '|' next to the character in a_cGrid, consider using std::cout
	// statements such as the following:
	//
	// std::cout << this->a_cGrid[iRow][iColumn] << "|";
	// std::cout << '~' << "|";
	//
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //

	for (int iRow = 0; iRow < this->m_nGridRows; ++iRow)
	{
		std::cout << "|";
		for (int iColumn = 0; iColumn < this->m_nGridColumns; ++iColumn)
		{

			if (this->a_cGrid[iRow][iColumn] == 'V')
			{

				/* HINT: If bShowBoat is true, display the actual contents of array element, a 'V'  */
				/* HINT: else, display a wave character to kee the Battle Boat location secret, '~' */
				if (bShowBoat)
				{
					std::cout << 'V' << "|";
				}
				else
			       	{
					std::cout << '~' << "|";
				}
			}
			else
		       	{
				/* HINT: Display the character actually present in the array element */
				std::cout << a_cGrid[iRow][iColumn] << "|";
			}
		}
		std::cout << std::endl;
	}
	return;
}


// Implementation notes on Game::fireTorpedo
//
// The user is promted to enter a row, column location that is the aimpoint
// for their torpedo by calling the promptForGridCoord member function.
//
// Prior to firing the first torpedo, the game grid would be rendered as
// shown below (all elements of the a_cGrid contain '~' characters.
//
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
//
//
// After the torpedo is "fired" an asterisk character ('*') is rendered
// at the location entered by the user. In the figure below, the
// torpedo was fired at location 2, 1:
//
// |~|~|~|~|~|
// |~|*|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
//
// Game::fireTorpedo inserts an asterisk at the torpedo aimpoint location
// in the a_cGrid two-dimensional array. It also decremements the
// remaining number of torpedoes member variable this->m_nTorpedoes.

std::tuple<int, int>  Game::fireTorpedo()
{
	int iRow = 0;
	int iColumn = 0;

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: DECREMENT COUNT OF REMAINING TORPEDOES
	// Decrement the member variable this->m_nTorpedoes by 1 as one torpedo has been expended.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// Decrement number of torpedoes in Magazine
	this->m_nTorpedoes = this->m_nTorpedoes - 1;

	// Get the grid location (iRow and iColumn) where the user wishes to fire the torpedo
	std::cout << "Enter grid Coordinates (row, column) of torpedo target grid square" << std::endl;
	std::tie(iRow, iColumn) = promptForGridCoord();

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: UPDATE MEMBER VARIABLE this->a_cGrid WITH TORPEDO EXPLOSION CHARACTER, '*'
	// Assign an asterisk ('*') character to row and column location that the user selected as the torpedo
	// target. The location is given by iRow an iColumn returned as a tuple from member function
	// promptForGridGoord as a tuple and extracted into iRow and iColumn by the std::tie tuple function.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	/* ?? Assign '*' to value of a_cGrid at the row and column index returned from promptForGridCoord(). ??*/
	a_cGrid[iRow][iColumn] = '*';


	// Return the coordinates of the torpedo explosion location as a tuple object
	std::tuple<int, int> tupleTorpedoCoord(iRow, iColumn);
	return tupleTorpedoCoord;
}

void Game::placeBoatRandomly()
{
	// Background on C++ Random Number Generator Suitability
	//
	// The default random number generator is adequate for games; for better statistical
	// randomness as might be required in scientific applications, consider the
	// Mersenne Twister Random Number Generator, declared as follows:
	//    std::random_device randomDevice;
	//    std::mt19937 randomNumberGenerator(randomDevice());
	// For cryptographic applications you need a source of entropy such as the
	// Linux getrandom call and a cryptographic library  such as
	// libsodium, https://doc.libsodium.org/)
	//
	// For this game, we'll use the default random number generator.

	// Declare a random Device which will be used to seed the random number generator,
	// then declare a random number generator and seed using randomDevice()
	// Random device has limited entropy pool but adequate for this game.
	std::random_device randomDevice;

	std::default_random_engine randomNumbreGenerator(randomDevice());

	// Declare a uniform integer distribution from 0 to the number of rows in the grid
	// Then, generate a random number within that distribution. Assign the row position
	// of the boat to the generated random row position.
	std::uniform_int_distribution<int> uniformIntegerDistributionRows(0, (this->m_nGridRows - 1));

	this->m_iRowBoat = uniformIntegerDistributionRows(randomNumbreGenerator);

	// Declare a uniform integer distribution from 0 to the number of columns in the grid,
	// then generate a random number within that distribution. Assign the column position
	// of the boat to the generated random column position.
	std::uniform_int_distribution<int> uniformIntegerDistributionColumns(0, (this->m_nGridColumns - 1));

	this->m_iColumnBoat = uniformIntegerDistributionColumns(randomNumbreGenerator);

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: UPDATE MEMBER VARIABLE this->a_cGrid WITH TARGET BOAT CHARACTER, 'V'
	// Assign a capital V ('V') character to randomly chosen row and column location within the a_cGrid
	// two-dimensional character array member variable that is the target boat location.
	//
	// The location is given by this->m_iRowBoat and this->m_iColumnBoat member variables, which have
	// been given values returned by a random number generator. Use these member variables to
	// index the array and then assign that location the value 'V'.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //

	// Assign the boat symbol, a 'V', to the boat's random grid location
	/* ?? Assign 'V' to the element of 2-D member variable a_cGrid. ?? */
	a_cGrid[m_iRowBoat][m_iColumnBoat] = 'V';

#if defined(DIAG)
	std::cout << "DIAG: Boat location (Row/Column): " << this->m_iRowBoat << "; " << this->m_iColumnBoat << std::endl;
#endif

}

// Implementation notes on Game::placeBoat
// Game::placeBoat is used for testing purposes only. During gameplay,  Game::placeBoatRandomly()
// is used instead.

void Game::placeBoat()
{
	int iRow = 0;
	int iColumn = 0;

	std::cout << "Enter the grid square coordinates  (row, column) of target boat" << std::endl;

	std::tie(iRow, iColumn) = promptForGridCoord();

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: UPDATE MEMBER VARIABLE this->a_cGrid WITH TARGET BOAT CHARACTER, 'V'
	// Assign a capital V ('V') character to row and column location that the user selected as the target
	// boat location.
	// The location is given by iRow and iColumn returned as a tuple from member function
	// promptForGridGoord as a tuple and extracted into iRow and iColumn by the std::tie tuple function.
	//
	// Assign the value of member variable this->m_iRowBoat to iRow.
	// Assign the value of member variable this->m_iColumnBoat to iColumn
	// The assignment statements set the location of the target boat in the coordinate grid.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	/* ?? Assign 'V' to a_cGrid at the appropriate row and column index ?? */
	a_cGrid[iRow][iColumn] = 'V';
	/* ?? Assign value to this->m_iRowBoat ?? */
	this->m_iRowBoat = iRow;
	this->m_iColumnBoat = iColumn;
	/* ?? Assign value to this->m_iRowColumn ?? */
	return;
}


bool Game::isOnTarget(int iRow, int iColumn)
{
	bool bHit = false; // true if target boat has been hit

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: CHECK IF iRow AND iColumn ARE IDENTICAL TO this->m_iRowBoat AND this->m_iColumnBoat RESPECTIVELY
	// Compare this->m_iRowBoat to iRow for equality and compare this->m_iColumnBoat  to iColumn for equality.
	// If both expressions are true, then the location of the torpedo (given by iRow and iColumn) is identical
	// to the location of the target boat (given by this->m_iRowBoat and this->m_iColumnBoat) and the target
	// boat has been hit. Set bHit to true in this case.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	if ((iRow == this->m_iRowBoat) && (iColumn == this->m_iColumnBoat))
	{
		bHit = true;
	}

	return bHit;
}

// Implementation notes on Game::isCloseToTarget
//
// The Game::isCloseToTarget returns true if the value of the iRow and iColumn
// parameters are in a any of the eight grid squares surrounding the
// location of the target boat, shown with a V.
//
// |~|1|2|3|~|
// |~|4|V|5|~|
// |~|6|7|8|~|
// |~|~|~|~|~|
//
// If iRow and iColumn are identical to the location of the target boat, 'V',
// Game::isCloseToTarget should also return true. (Hitting it is pretty close!)
// The Game::isOnTarget member functions handles the case where the target is
// hit; nonetheless, it's OK for Game::isCloseToTarget to report that location
// as close.
//
// One way to determine "closeness" is to check if iRow and iColumn and at most 1
// square away from the location of the target boat, given by this->m_iRowBoat and
// this->m_iColumnBoat. By at most one is meant 0 or 1 (as might be expressed by
// an expression ivolving <=1.)

bool Game::isCloseToTarget(int iRow, int iColumn)
{
	bool bClose = false;

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: CHECK IF iRow AND iColumn within 0 or 1 of this->m_iRowBoat and this->m_iColumnBoat respectively.
	// Write an if statement that checks if iRow is within 0 or 1 of this->m_iRowBoat AND if
	// iColumn is within 0 or 1 of this->m_iColumnBoat. Consider using the std::abs absolute value
	// function. Consider using the <= operator (perhaps more than once) and the AND operator, &&.
	// This corresonds to iRow and iColumn being in one of the eight grid squares surrounding the
	// location of the target boat (this->m_iRowBoat, this->m_iColumnBoat) or being exactly the
	// location of the target boat.
	// Set bClose to true in the if block indicating the torpedo location is "close to the location of
	// the target boat.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	if (std::abs(iRow - m_iRowBoat) < 2 && std::abs(iColumn - m_iColumnBoat) < 2)
	{
		bClose = true;
	}

	return bClose;
}


void Game::showSunk()
{
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: Assign an 'X' to the grid coordinate of the target boat showing it has been sunk.
	// Assign an 'X' character to the location of the target boat within the two-dimensional array member
	// variable this->a_cGrid at the location of the target boat given by (this->m_iRowBoat, this->m_iColumnBoat).
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	/* ?? Assign 'X' to a_cGrid at location (row/column) of Battle Boat ?? */
	this->a_cGrid[this->m_iRowBoat][this->m_iColumnBoat] = 'X';
	return;
}


std::tuple<int, int> Game::promptForGridCoord()
{
	int iRow = 0;
	int iColumn = 0;

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: GET GRID COORDINATES FROM USER
	// Prompt the user to "Please enter grid row number: " and recover the value they enter into variable
	// iRow using std::cin.
	// Prompt the user to "Please enter grid column number: " and recover the value they enter into variable
	// iColumn using std::cin.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
        std::cout << "Enter row: " << std::endl;
	std::cin >> iRow;

				std::cout << "Enter column: " << std::endl;
	std::cin >> iColumn;

	// Create a tuple holding the iRow and iColumn integer values and return the tuple.
	std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iColumn);

	return tupleCoord;
}


void Game::play()
{
	int iRow = 0;
	int iColumn = 0;

	this->reset();            // Reset member variables for a new game.
	this->displayGrid(false); // Display the grid but hide the location of the target boat
	std::cout << "Magazine: " << this->m_nTorpedoes << " torpedoes" << std::endl;
	std::cout << std::endl;

	// Execute a sequence of turns within a while loop. Each turn is an interation
	// of the file loop. Within a turn, the user fires a torpedo and checks are
	// performed to see if the torpedo hit the target (i.e. the user selected the
	// exact grid square in which the target boat is placed), if the torpedo was
	// "close" to the target (i.e. aimed at a grid square adjacent to the target
	// boat. If neither a hit (isOnTarget is true) or a close miss (isCloseToTarget is true)
	// the torpedo is a miss. The while loop iterates until either the target boat
	// is hit (and thus sunk), in which case the player wins, or all torpedoes have
	// been expended, and the target boat survives, in which case the computer wins.
	bool bSunk = false;
	while ((!bSunk) && (this->m_nTorpedoes > 0))
	{
		std::cout << std::endl;
		// Accept input from user as to grid location where torpedo is fired
		// Return location as a tuple and extract the row and column values
		// from the tuple into iRow and iColumn, respectively.
		std::tie(iRow, iColumn) = this->fireTorpedo();


		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		// TODO: IF/ELSE IF/ ELSE statement to handle turn outcome
		//
		// If iRow and iColumn are on target (as determined by member function isOnTarget, execute the following
		//    Call member function showSunk
		//    Call member function displayGrid with bShowBoat set to false.
		//    Set bSunk to true
		//
		// Else If isCloseToTarget returns true,
		//    Call member function displayGrid with bShowBoat set to false.
		//
		// Else
		//    Call member function displayGrid with bShowBoat set to false.
		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //

		if (isOnTarget(iRow, iColumn))
		{
			this->showSunk();
			this->displayGrid(false);
			std::cout << "Hit!  Kaboom!" << std::endl;
			std::cout << "Victory!" << std::endl;
			bSunk = true;
		}
		else if (this->isCloseToTarget(iRow, iColumn))
		{
			this->displayGrid(false);
			std::cout << "Location row: " << iRow << "; column: " << iColumn << " is close!" << std::endl;
		}
		else
		{
			this->displayGrid(false);
			std::cout << "Location row: " << iRow << "; column: " << iColumn << " is a miss." << std::endl;
		}

		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		// TODO: If the target boat has not been sunk (bSunk is false), display the remaining number of torpedoes
		// (which is held in member variable this->m_nTorpedoes).
		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		if (!bSunk)
		{
			std::cout << "Magazine: " << m_nTorpedoes << " torpedoes" << std::endl;
		}

		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		// TODO: If the number of torpedoes (which is held in member variable this->m_nTorpedoes) is 0 and the
		// target boat has not been sunk:
		//     Call the displayGrid member function with the bShowBoat parameter set to true.
		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		if (m_nTorpedoes == 0 && !bSunk)
		{
			// Display grid shown boat's location
			/* ?? call member function to dislay the grid and show the location of the battle boat ?? */
			displayGrid(true);
			std::cout << "Torpedoes expended" << std::endl;
			std::cout << "Game over" << std::endl;
		}
	}
}


void Game::reset()
{
	this->initializeGrid();
#if defined TEST
	// Place the target boat at a specified location for testing/diagnostic purposes.
	// This code is executed only if the TEST macro is defined (#define TEST or -DTEST).
	// If the macro is defined, the program is in "test mode."
	this->placeBoat();
#else
	// The target boat is placed at a random location on the grid; this is used for
	// normal gameplay.
	this->placeBoatRandomly();
#endif
	this->m_nTorpedoes = Game::k_nMaxTorpedoes;
}
