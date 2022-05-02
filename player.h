#pragma once
#include <iostream>
#include <conio.h>

class Player {
private:
	double vitality;
	double strength;
	double dexterity;
	std::string weapon;
	std::string race;
	double attack;
public:
	Player();
	Player(double vitality, double strength, double dexterity, std::string race, std::string weapon, double attack);
	void setStats();
	void setRace();
	double getHealthPoints();
	void chooseWeapon();
	double getAttack();
	double getVitality();
};
