#include "monster.h"

Monster::Monster(double healthPoints, double attack, std::string name){
	this->healthPoints = healthPoints;
	this->attack = attack;
	this->name = name;
}

std::string Monster::getName() {
	return name;
}

void Monster::combat(Player &player) {
	
	double playerHealth = player.getHealthPoints();
	double monsterHealth = healthPoints;
	double playerAttack = player.getAttack();
	bool flag = true;

	do
	{
		char playerInput;
		std::cout << "If you want to attack press a or A" << std::endl;
		std::cout << "If you want to block press b or B" << std::endl;
		std::cin >> playerInput;
		
		if (playerInput == 'A' || playerInput == 'a')
		{
			std::cout << "You decided to attack" << std::endl;
			monsterHealth = monsterHealth - playerAttack;
			std::cout << "You have dealth " << playerAttack << " damage to " << getName() << " and he has " << monsterHealth << " hp left..." << std::endl << std::endl;
			playerHealth = playerHealth - attack;
			std::cout << "You have been attacked by " << getName() << " you lost " << attack << " hp and you have " << playerHealth << " hp left..." << std::endl << std::endl;
			if (playerHealth <= 0 && monsterHealth > 0)
			{
				flag = false;
				std::cout << "You have died!" << std::endl;
			}
			else if (playerHealth > 0 && monsterHealth <= 0)
			{
				flag = false;
				std::cout << "Congratulations you have defeated " << getName() << "!" << std::endl << std::endl;
			}
		}
		else if (playerInput == 'B' || playerInput == 'b')
		{
			std::cout << "You decided to block" << std::endl;
			std::cout << "You have blocked " << getName() << " attack..." << std::endl << std::endl;
		}


	} while (flag);
}
