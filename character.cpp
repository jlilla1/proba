/**
* \author Alfak
*
*Last time code was modified: 2020.12.02
*
* \date 2020/12/03 09:39
*
* Created on: 2020/12/03 09:39
*/

#include "character.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

/**
* The methods of the Character class are explained here. The descreptions are in the class.
*/

using namespace std;


Character::Character(const std::string name, int Hp, const int Dpr, float AttackCooldown) : name(name), Hp(Hp), Dpr(Dpr), AttackCooldown(AttackCooldown)
{
	xp = 0;			///< The xp the character has.
	level = 0;		///< The level the character is on.
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
const void Character::setAkthp()
{
	aktHP = Hp;
}
const int& Character::getAkthp()
{
	return aktHP;
}
const void Character::setDpr()
{
	int* newdpr = (int*)(&Dpr);
	*newdpr = std::round(Dpr*1.10);
}
const void Character::setXP(int amount)
{
	xp = xp + amount;
}
const int& Character::getLvl()
{
	return level;
}
void Character::lUp()
{
	while (xp >= 100) {
		Hp = std::round(Hp * 1.10);
		setAkthp();
		setDpr();
		level = level + 1;
		xp = xp - 100;
	}

	
	
}



void Character::Attackedby(const Character& X) {
	Character* newx = (Character*)(&X);
	


	if (aktHP - X.GetDpr() < 0) {
		aktHP = 0;
		newx->setXP(Hp);
	}
	else {
		aktHP = aktHP - X.GetDpr();
		newx->setXP(X.GetDpr());
	}

	if (X.xp >= 100) {
		newx->lUp();
	}



}



std::string Character::toString() const {
	std::string s;
	s = "Name: " + Getname() + " Hp: " + std::to_string(GetHp()) + " DPR: " + std::to_string(GetDpr()) + "Attack cooldown: " + std::to_string(GetAttackCooldown());
	return s;
}

Character Character::ManualUnit(std::string _name, int _hp, int _dmg, int _cdown) {

	return Character(_name,_hp,_dmg, _cdown);
}


Character Character::parseUnit(std::string fajlnev) {
	ifstream fajl(fajlnev);
	if (fajl) {				///< Checks the file's existence.
		string data[4];		///< The total amount of data.
		string sortores;	///< The .txt file's first "empty row"
		getline(fajl, sortores);	///< fajl.get(sortores); 
		int n = 0;
		while(n<4){
			string check;	///< This is the current character.
			string choose = "";
			getline(fajl, check);
			int kezdes;
			for (int i = 0; i < check.length(); i++) {
				if (check[i] != '"' && check[i] != ' ' && check[i] != ':') {
					choose += check[i];
				}else if (check[i] == ':' && (choose == "nev" || choose == "hp" || choose == "dmg" || choose == "attackcooldown")) {///< The check of the current character.
					n = n + 1;
					kezdes = i + 1;
					for (int j = kezdes; j < check.length(); j++) { ///< The processing of the data starting from ':'.
						if (check[j] != '"' && check[j] != ' ' && check[j] != ',') {
							if (choose == "nev") {
								data[0] += check[j];
							}
							else if (choose == "hp") {
								data[1] += check[j];
							}
							else if (choose == "dmg") {
								data[2] += check[j];
							}
							else if (choose == "attackcooldown") {
								data[3] += check[j];
							}
						}
					}
					break;
				}
			}
		}
		

		return Character(data[0], stoi(data[1]), stoi(data[2]), stoi(data[3]));
	}
	else {
		const std::string FajlHiba("File does not exist!");
		throw std::runtime_error(FajlHiba);
	}
}

