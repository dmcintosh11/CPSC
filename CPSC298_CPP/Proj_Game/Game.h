#if !defined(GAME_H)
#define GAME_H
/// @file Game.cpp
/// @brief Header file for Game class
/// @author dmcintosh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <tuple>    // defines std::tuple, std::tie

/// Implements the game "Battle Boat"
/// @details The "Battle Boat" is an autonomous, robotic boat that the user must find and sink. The user
///          has their own boat with a limited number of torpedoes that can be fired at locations
///          where the Battle Boat is assumed to be. If the user hits the Battle Boat with a
///          torpedo, they win. If they expend all of their torpedoes before hitting the Battle
///          boat, they lose.
class Game
{
	static const int k_nGridRowsDefault = 4;                   ///< Default number of Rows in the 2-D Game Grid
	static const int k_nGridColumnsDefault = 5;                ///< Default number of Columns in the 2-D Game Grid
	static const int k_nMaxTorpedoes = (k_nGridRowsDefault * k_nGridColumnsDefault) / 2; ///< Starting number of torpedoes

private:
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: DECLARE 2-DIMENSIONAL CHAR ARRAY a_cGrid
	// Declare a two-dimensional array of type char whose identifier is a_cGrid; the number of rows in
	// the array should be k_nGridRowsDefault and the number of columns should be k_nGridColumnsDefault.
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	char a_cGrid[k_nGridRowsDefault][k_nGridColumnsDefault];  ///< 2-dimensional Game Grid

	int m_nGridRows;                                           ///< Number of rows in Game Grid; initialized to default
	int m_nGridColumns;                                        ///< Number of columns in Game Grid; initialized to default

	int m_iRowBoat;                                            ///< Row number target boat positioned in
	int m_iColumnBoat;                                         ///< Column number target boat positioned in

	int m_nTorpedoes;                                          ///< Number of torpedoes remaning in magazine

public:
	/// Default constructor for Game object.
	/// @details calls initializeGrid to initialize 2-dimensional game grid. Initializes member variables in
	///          initializer list.
	Game();

	/// Game Loop; plays a complete game.
	/// @return void
	/// @details positions target boat randomly, allows users to launch topedoes, reports results.
	///          Continues looping until target hit (victory) or all torpedoes expended (game over, loss).
	void play();


private:
	/// Initialize two dimensinal playing grid to contain all "wave" characters (~).
	/// @return void
	void initializeGrid();

	/// Reset the Game object for a new game.
	/// @return void
	/// @details places the Battle Boat at a random location in the grid, resets the
	///          number of torbepoes to the maximum number of torpedoes and
	///          re-initializes the grid to hold all wave characters ('~').
	void reset();

	/// Displays the game grid to standard output using ASCII characters; displays or hides the
	/// position of the target boat based on the value of the Boolean parameter bDisplayBoat.
	/// @param[in] bDisplayBoat Boolean value that if true indicates the position of the target boat
	///            is to be displayed in its grid position using a 'V' character. Otherwise, the target
	///            boat's position is rendered as a "wave" character, ~.
	/// @return void
	void displayGrid(bool bDisplayBoat);

	/// Queries the user for the grid location (row,column) at which to fire a torpedo;
	/// updates the game grid with torpedo location and updates the number of torpedoes
	/// remaining.
	/// @return tuple object containing two integer values the first of which is the
	///         row selected by the user and the second is the column selected by the user.
	/// @details Assigns a torpedo explosion character, '*', to the grid location that the
	///          torpedo targets within the a_cGrid character grid member variable. Also
	///          decrements the number of torpedoes by 1.
	std::tuple<int, int>  fireTorpedo();

	/// Places the target boat at a randomly chosen grid location.
	/// @return void
	/// @details updates the m_iRowBoat and int m_iColumnBoat member variables.
	void placeBoatRandomly();

	/// Places the target boat at a grid location chosen by the user; used for
	/// testing as it allows the target boat to be positioned at a predetermined
	/// grid location.
	/// @return void
	/// @details updates the m_iRowBoat and int m_iColumnBoat member variables.
	void placeBoat();

	/// Returns true if the grid location specified by parameters iRow and iColumn is
	/// identical to the location of the target boat.
	/// @param[in] iRow integer row number of a grid location targeted
	/// @param[in] iColumn integer column number of a grid location targeted
	/// @return true if the grid location specified by arguments iRow and iColumn is
	/// identical to the location of the target boat and false otherwise.
	bool isOnTarget(int iRow, int iColumn);

	/// Returns true if the grid location specified by parameters iRow and iColumn
	/// is adjacent to the grid location where the target boat is located.
	/// @param[in] iRow integer row number of a grid location targeted
	/// @param[in] iColumn integer column number of a grid location targeted
	/// @return true if the grid location specified by parameters iRow and iColumn
	///         is adjacent to the actual position of the target boat. An adjacent
	///         grid location is any of the eight grid squares surrounding the
	///         location of the target boat:
	///         |1|2|3|
	///         |4|V|5|
	///         |6|7|8|
	///         Returns false if the grid location specified by parameters iRow and
	///         iColumn is not adjacent to the grid location where the target boat
	///         is located.
	bool isCloseToTarget(int iRow, int iColumn);

	/// Renders a sunk character ('X') in the grid location where the target boat
	/// is located.
	/// @return void
	void showSunk();

	/// Queries the user for a grid location (row,column); utility function used in
	/// other functions.
	/// @return tuple object containing two integer values the first of which is the
	///         row selected by the user and the second is the column selected by the user.
	std::tuple<int, int> promptForGridCoord();
};

#endif // !defined(GAME_H)
