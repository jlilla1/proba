/**
* \author Alfak
*
* Last time code was modified: 2020.12.02
*
* \date 2020/12/03 09:39
*
* Created on: 2020/12/03 09:39
*/


#include "game.h"
#include "character.h"
#include <iostream>

/**
* The methods of the Game class are explained here, descriptions are in the class itself.
*/

Game::Game(const Character& A, const Character& B) : A(A), B(B)
{
}

void Game::Fight() {

	int i = 1;				///< i counst the rounds
	int lastAttack = 0;		///< lastAttack shows who attacked last

	double timerA = 0;		///< timerA and timerB keep track of which character's timer expires when.
	double timerB = 0;		///< timerA and timerB keep track of which character's timer expires when.
	A.setAkthp();
	B.setAkthp();
	/// Here the fight starts and continues until one character's HP reaches 0.
	/// The basic program got supplemented with attack cooldown. If A attacked last the value of lastAttack is 0 if B attacked last this number is 1.
	/// i counts the rounds, in the firs Round A attacks than B punches and we start the timers. From the second round the figth is controlled by the timers.
	while (A.getAkthp() > 0 && B.getAkthp() > 0)
	{
		std::cout << i<<". kor"<<"\n\n";
		std::cout << A.Getname() << "  " << A.getAkthp() << " " << A.getLvl() << "\n\n";
		std::cout << B.Getname() << " " << B.getAkthp() << " " << B.getLvl() << "\n\n";
		

		if (i == 1) {
			A.getAttackedby(B);
			std::cout << A.Getname() << "  " << A.getAkthp() << " " << A.getLvl() << "\n\n";
			if (A.getAkthp() != 0) {
				B.getAttackedby(A);
				std::cout << B.Getname() << " " << B.getAkthp() << " " << B.getLvl() << "\n\n";
				lastAttack = 1;
				timerA = A.GetAttackCooldown();
				timerB = B.GetAttackCooldown();
				i++;
			}
			else {
				break;
			}
			
		}
		else if (timerA < timerB) {

			B.getAttackedby(A);
			std::cout << B.Getname() << " " << B.getAkthp() << " " << B.getLvl() << "\n\n";
			lastAttack = 0;
			timerA = timerA + A.GetAttackCooldown();
			i++;

		}
		else if (timerB < timerA) {

			A.getAttackedby(B);
			std::cout << A.Getname() << "  " << A.getAkthp() << " " << A.getLvl() << "\n\n";
			lastAttack = 1;
			timerB = timerB + B.GetAttackCooldown();
			i++;

		}
		else {
			if (lastAttack == 0) {
				B.getAttackedby(A);
				std::cout << B.Getname() << " " << B.getAkthp() << " " << B.getLvl() << "\n\n";
				timerA = timerA + A.GetAttackCooldown();
				lastAttack = 1;
				i++;
			}
			else {
				A.getAttackedby(B);
				std::cout << A.Getname() << "  " << A.getAkthp() << " " << A.getLvl() << "\n\n";
				timerB = timerB + B.GetAttackCooldown();
				lastAttack = 0;
				i++;
			}
		}



	}

	/// This part figures out form remaining HP that who is the winner and who is the loser, than prints out the results.
	if (A.getAkthp() == 0) {
		std::cout << B.Getname() << " WINS. Remaining Hp: " << B.getAkthp() << " "<<B.getLvl()<<"\n\n";
	}
	else {
		std::cout << A.Getname() << " WINS. Remaining Hp: " << A.getAkthp() << " " << A.getLvl() << "\n\n";
	}
}


