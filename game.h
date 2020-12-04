/**
* \author Alfak
*
* Last time code was modified: 2020.12.02
*
* \date 2020/12/03 09:39
*
* Created on: 2020/12/03 09:39
*/


#pragma once
#include "character.h"

/**
* \calss Game
*/
class Game
{
public:
	/// This constructor that waits for 2 character reference. These references will not change so they are constants.
	Game(const Character& A, const Character& B);

	/// This method runs the fight between the 2 characters.
	void Fight();

private:				///< Private data members.
	Character A;		///< One of the characters.
	Character B;		///< The other character.

};

