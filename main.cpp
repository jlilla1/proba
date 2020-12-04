/**
* \author Alfak
* 
* In this game two characters are fighting. You need to give the program the charcter arguments and than the program will generate the outcome.
* Last time code was modified: 2020.10.29
*
* \date 2020/12/02 14:33
*
* Created on: 2020/12/02 14:33
*/


#include <string>
#include "game.h" 
#include "character.h"
#include <iostream>


int main(int argc, char* argv[])
{
	try {
		/// This part is an argument check. If someone gives all the arguments at than the number of arguments is 9 (the name of the program + 2*4 parameter: name,hp,dpr,attackcooldown).
		if (argc < 3) {
			std::cout << "Please give all of the arguments when you start the programe It will work. Or change the comments in the programe if " 
				<< "you are a pussycat, it works just as well. #the programmer " << "\n\n"; ///< If someone did not enter it the program would not die. Just a funny message indicating the error, if necessary you can start another run by taking out the comments.
			return 1;                                  
		}

		/// Once the program has all 9 data than it will create the characters and it runs as needed. Stoi is needed because the argv array is basically a character array and it needs a type conversion to work.
		else {

			Character A = Character::parseUnit(argv[1]);
			Character B = Character::parseUnit(argv[2]);
		
		/// The object of the Game class  "starts" a new game with character A and B. The order of the characters is not important because we completed the baseic task with the option where the user can choose who will start the figth at running the program.
			Game NewGame(A, B);       
										
		/// Starts the Fight method of the game (character A and B punches alternately). 
			NewGame.Fight();    
		}

		return 0;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}

}