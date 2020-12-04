/**
* \author Alfak
*
* In this game two characters are fighting. You need to give the program the charcter arguments and than the program will generate the outcome.
* Last time code was modified: 2020.12.02
*
* \date 2020/12/03 09:39
*
* Created on: 2020/12/03 09:39
*/


#include <string>
#include <iostream>
#include "game.h"


int main(int argc, char* argv[])
{
	try {
		/**
		*This part is an argument check. If someone gives all the arguments at than the number of arguments is 9 (the name of the program + 2*4 parameter: name,hp,dpr,attackcooldown).
		* Once the program has all 9 data than it will create the characters and it runs as needed. Stoi is needed because the argv array is basically a character array and it needs a type conversion to work.
		*/
		if (argc == 9) {
			Character A = Character::ManualUnit(argv[1], std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]));
			Character B = Character::ManualUnit(argv[5], std::stoi(argv[6]), std::stoi(argv[7]), std::stoi(argv[8]));

			Game NewGame(A, B);
			NewGame.Fight();
		}
		else if (argc == 1) {
			std::cout << "Please give the file names that you want to use!";
			std::string Fname1, Fname2;
			std::cout << "\nFirst file: ";
			std::cin >> Fname1;
			std::cout << "Second file: ";
			std::cin >> Fname2;

			Character A = Character::parseUnit(Fname1);
			Character B = Character::parseUnit(Fname2);
			/// The object of the Game class  "starts" a new game with character A and B. The order of the characters is not important because we completed the baseic task with the option where the user can choose who will start the figth at running the program.
			Game NewGame(A, B);
			/// Starts the Fight method of the game (character A and B punches alternately).
			NewGame.Fight();
		}

		
		else if(argc == 3){

			Character A = Character::parseUnit(argv[1]);
			Character B = Character::parseUnit(argv[2]);


			Game NewGame(A, B);

			
			NewGame.Fight();
		}
		else {
			std::cout << "nincs data";
		}

		return 0;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}

}