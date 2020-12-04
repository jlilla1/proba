/**
* \author Alfak
*
* Last time code was modified: 2020.10.29
*
* \date 2020/12/02 14:33
*
* Created on: 2020/12/02 14:33
*/

#include "character.h" 
#include <iostream>
#include <fstream>
#include <string>

/**
* The methods of the Character class are explained here. The descreptions are in the class. 
*/


using namespace std;


Character::Character(const std::string name, int Hp, const int Dpr, float AttackCooldown) : name(name), Hp(Hp), Dpr(Dpr), AttackCooldown(AttackCooldown)
{
}


const std::string& Character::Getname() const {
	return name;
}

const int& Character::GetHp() const {
	return Hp;
}

const int& Character::GetDpr() const {
	return Dpr;
}

const float& Character::GetAttackCooldown() const {
	return AttackCooldown;
}

const void Character::getAttackedby(const Character& X) {
	Attackedby(X);
}


void Character::Attackedby(const Character& X) {


	if (Hp - X.GetDpr() < 0) {
		Hp = 0;
	}
	else {
		Hp = Hp - X.GetDpr();
	}


}



std::string Character::toString() const {
	std::string s;
	s = "Name: " + Getname() + " Hp: " + std::to_string(GetHp()) + " DPR: " + std::to_string(GetDpr()) + "Attack cooldown: " + std::to_string(GetAttackCooldown());
	return s;
}


Character Character::parseUnit(std::string fajlnev) {
	ifstream fajl(fajlnev);
	if (fajl) {				///< Checks the file's existence.
		string data[4];		///< The total amount of data.
		string name;
		int hp;
		int dmg;
		float attackcooldown;

		string sortores;	///< The .txt file's first "empty row"
		getline(fajl, sortores);	///< fajl.get(sortores); 
		for (int n = 0; n < 4; n++) {
			string check;	///< This is the current character.
			getline(fajl, check);
			int kezdes;
			for (int i = 0; i < check.length(); i++) {
				if (check[i] == ':') {			///< The check of the current character.
					kezdes = i + 1;
					for (int j = kezdes; j < check.length(); j++) {			///< The processing of the data starting from ':'.
						if (check[j] != '"' and check[j] != ' ' and check[j] != ',') data[n] += check[j];
					}
					break;
				}
			}
		}
		name = data[0];
		hp = stoi(data[1]);
		dmg = stoi(data[2]);
		attackcooldown = stoi(data[3]);

		return Character(name, hp, dmg, attackcooldown);
	}
	else {
		const std::string FajlHiba("File does not exist!");
		throw std::runtime_error(FajlHiba);
	}
}

