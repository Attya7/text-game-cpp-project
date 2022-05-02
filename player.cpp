#include "player.h"

Player::Player(double vitality, double strength, double dexterity, std::string race, std::string weapon, double attack) {
	this->vitality = vitality;
	this->strength = strength;
	this->dexterity = dexterity;
	this->race = race;
	this->weapon = weapon;
	this->attack = attack;
}

Player::Player()
{
	vitality = 0;
	strength = 0;
	dexterity = 0;
	race = "Human";
	weapon = "Sword";
	attack = 0;
}

void Player::setRace() {
	int raceChoice;
	std::cout << "Each race has it's own advantages and disadvantages:" << std::endl << std::endl; 
	std::cout << "Humans gain additional point in Vitality, Strength and Dexterity." << std::endl;
	std::cout << "Elfs gain additional point in Vitality and two points in Dexterity." << std::endl;
	std::cout << "Dwarfs gain additional point in Vitality and two points in Strength." << std::endl << std::endl;
	std::cout << "Please choose your race" << std::endl << std::endl;
	std::cout << "To choose Human press 1" << std::endl;
	std::cout << "To choose Elf press 2" << std::endl;
	std::cout << "To choose Dwarf press 3" << std::endl << std::endl;
	std::cin >> raceChoice;
	if (raceChoice == 1)
	{
		race = "Human";
	}
	else if (raceChoice == 2)
	{
		race = "Elf";
	}
	else if (raceChoice == 3) 
	{
		race = "Dwarf";
	}
}


void Player::chooseWeapon() {
	int weaponChoice;
	std::cout << std::endl << "Please choose your weapon:" << std::endl << std::endl;
	std::cout << "If you want to choose Sword press 1" << std::endl;
	std::cout << "If you want to choose Dagger press 2" << std::endl;
	std::cout << "If you want to choose Axe press 3" << std::endl << std::endl;
	std::cin >> weaponChoice;
	if (weaponChoice == 1)
	{
		weapon = "Sword";
	}
	else if (weaponChoice == 2)
	{
		weapon = "Dagger";
	}
	else if (weaponChoice == 3)
	{
		weapon = "Axe";
	}
}


void Player::setStats() {
	std::cout << std::endl << "Please assign your statistics. You have 15 points to assign." << std::endl << std::endl;
	double vitalityInput;
	double strengthInput;
	double dexterityInput;
	bool flag = true;
	do
	{
		double sum = 15;
		std::cout << "How many points would you like to assign to vitality?" << std::endl;
		std::cin >> vitalityInput;
		sum = sum - vitalityInput;

		std::cout << "How many points would you like to assign to strength?" << std::endl;
		std::cin >> strengthInput;
		sum = sum - strengthInput;

		std::cout << "How many points would you like to assign to dexterity?" << std::endl;
		std::cin >> dexterityInput;
		sum = sum - dexterityInput;

		if (sum > 0) {
			std::cout << "You still have some points left, let's assign stats from the beggining" << std::endl << std::endl;
		}
		else if (sum < 0)
		{
			std::cout << "You have only 15 stat points and you want to assign more than you have. Assign points once again." << std::endl << std::endl;
		}
		else if (sum == 0)
		{
			std::cout << "You have used all your stat points, let's continue with weapon choice" << std::endl << std::endl;
			if (race == "Human")
			{
				vitality = vitalityInput + 1;
				strength = strengthInput + 1;
				dexterity = dexterityInput + 1;
			}
			else if (race == "Elf")
			{
				vitality = vitalityInput + 1;
				strength = strengthInput;
				dexterity = dexterityInput + 2;
			}
			else if (race == "Dwarf")
			{
				vitality = vitalityInput + 1;
				strength = strengthInput + 2;
				dexterity = dexterityInput;
			}
			
			std::cout << vitality << " " << strength << " " << dexterity << std::endl;
			flag = false;
		}


	} while (flag);


}


double Player::getHealthPoints() {
	double healthPoints = 25 + vitality * 10;
	return healthPoints;
}

double Player::getAttack() {
	if (weapon == "Sword")
	{
		attack = strength + dexterity;
	}
	else if (weapon == "Dagger")
	{
		attack = 0.5 * strength + 1.5 * dexterity;
	}
	else if (weapon == "Axe")
	{
		attack = 1.5 * strength + 0.5 * dexterity;
	}
	return attack;
}