#include "main.h"

int main(void) {
	std::cout << "Welcome warrior, ahead of you are three different paths, but before you continue." << std::endl << "You should choose your race, weapon and statistics." << std::endl << std::endl;
	Player player;
	player.setRace();
	player.setStats();
	player.chooseWeapon();
	int monsterChoice;
	std::cout << std::endl << "Which monster would you like to face:" << std::endl;
	std::cout << "If you want to face Orc press 1" << std::endl;
	std::cout << "If you want to face Goblin press 2" << std::endl;
	std::cout << "If you want to face Kobold press 3" << std::endl << std::endl;;
	std::cin >> monsterChoice;
	if (monsterChoice == 1) {
		Monster orc(200, 5, "orc");
		orc.combat(player);
	}
	else if (monsterChoice == 2) {
		Monster goblin(50, 3, "goblin");
		goblin.combat(player);
	}
	else if (monsterChoice == 3) {
		Monster kobold(40, 4, "kobold");
		kobold.combat(player);
	}
	return 0;
}