/**
* \author Alfak
*
* Last time code was modified: 2020.10.29
*
* \date 2020/12/02 14:33
*
* Created on: 2020/12/02 14:33
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
	
	/// Here the fight starts and continues until one character's HP reaches 0.
	/// The basic program got supplemented with attack cooldown. If A attacked last the value of lastAttack is 0 if B attacked last this number is 1.
	/// i counts the rounds, in the firs Round A attacks than B punches and we start the timers. From the second round the figth is controlled by the timers.
	while (A.GetHp() > 0 && B.GetHp() > 0)
	{
		if (i = 1) {
			A.getAttackedby(B);
			B.getAttackedby(A);
			lastAttack = 1;
			timerA = A.GetAttackCooldown();
			timerB = B.GetAttackCooldown();
			i++;
		}
		else if (timerA < timerB) {
		
			B.getAttackedby(A);
			lastAttack = 0;
			timerA = timerA + A.GetAttackCooldown();
			i++;
			
		}
		else if (timerB < timerA) {
			
			A.getAttackedby(B);
			lastAttack = 1;
			timerB = timerB + B.GetAttackCooldown();
			i++;

		}
		else {
			if (lastAttack = 0) {
				B.getAttackedby(A);
				timerA = timerA + A.GetAttackCooldown();
				i++;
			}
			else {
				A.getAttackedby(B);
				timerB = timerB + B.GetAttackCooldown();
				i++;
			}
		}



	}
	
	/// This part figures out form remaining HP that who is the winner and who is the loser, than prints out the results.
	if (A.GetHp() == 0) {
		std::cout <<  B.Getname() << " WINS. Remaining Hp: "<<B.GetHp() << "\n\n";
	}
	else {
		std::cout << A.Getname() << " WINS. Remaining Hp: " << A.GetHp() << "\n\n";
	}
}

