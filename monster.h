#pragma once
#include <iostream>
#include "player.h"

class Monster : public Player {
private:
	double healthPoints;
	double attack;
	std::string name;
public:
	Monster(double healthPoints, double attack, std::string);
	void combat(Player &player);
	std::string getName();

};