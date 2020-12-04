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
#include <string>

/**
* \calss Character
*
*  The class of the fighting characters
*/
class Character
{
public:

	/// This is a parametric constructor. The parameters: name, health points, damage per round, attack speed. Some of them are constants because they are not changing during the program running.
	Character(const std::string name, int Hp, const int Dpr, float AttackCooldown);

	const std::string& Getname() const;			///< Returns the name of the character.

	const int& GetHp() const;					///< Returns the HP of the character.

	const int& GetDpr() const;					///< Returns the Dpr of the character. We need the const at the end because of Attackedby, without it we would not be able to call the function.

	const float& GetAttackCooldown() const;		///< Returns the attack speed of the character

	/// It is a simple tostring method that returns a string with the character's parameters in it, it makes the code nicer.
	std::string toString() const;

	static Character parseUnit(std::string fajlnev);

	const void getAttackedby(const Character& X);

	const void setAkthp();						///< Sets the actual HP of the character.
	const int& getAkthp();						///< Returns the actual HP of the character.
	const void setDpr();						///< Sets the Dpr of the character according to its level.
	const void setXP(int amount);				///< Sets the XP of the character.
	const int& getLvl();						///< Returns the character's level.

	/// This method does the characters level ups according to the XP they collected.
	void lUp();

	static Character ManualUnit(std::string _name, int _hp, int _dmg, int _cdown);

private:						///< Private data members.
	const std::string name;		///< The name of the character.
	int Hp; ///< The health points of the character.
	int aktHP;
	const int Dpr;				///< The character's strength, Dpr = damage per round.
	float AttackCooldown;		///< The required between two punches.
	int xp;
	int level;
	/// In this funcion one character attacks the other. It expects a constant character reference as parameter.
	void Attackedby(const Character& X);
};


