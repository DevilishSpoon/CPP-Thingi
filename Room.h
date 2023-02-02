#pragma once
#include <iostream>
#include <random>
#include <vector>
#include "Item.h"
#include "Player.h"
#include "FightMan.h"
#include <string>

using std::vector;

class Room {
public:
	Room(int itm, Player* p) : p(p) {
		srand(time(NULL));
		for (int i = 0; i < itm; i++) {
			generate();
		}
	}
	~Room();
	void generate();
	void search();
	

protected:
	vector<Item>iList;
	vector<string> nameList = { "Slime", "Trash", "Treasure", "Mouse", "Legendary sword", "Empty Bottle", "Ticking Package", "Sphagetti"};
	vector<string> desList = { "It's gross", "Shiny", "Treasure? I guess.", "Pretty cool honestly.", "It shines to show itself off", "Useless junk"};
	vector<string> enmyNames = { "Trash monster", "Spider",  "Goblin", "Soul Stealer", "Viper", "Pokemon"};
	Player* p;
};

Room::~Room() {
}

void Room::generate() {
	iList.push_back(Item(nameList[rand() % nameList.size()], desList[rand() % desList.size()], 10));
}


void Room::search() {
	int chance = rand() % 9 + 1;
	if (chance > 6) {
			cout << endl;
			p->addItem(iList[0]);
			cout << endl;
			cout << "Added " << "\n" << iList[rand() % iList.size()] << " to your inventory" << endl;
			cout << endl;
		
	}
	else if (chance > 2) {
		// Enemy encounter
		int goldGain = rand() % 5 * 10;
		int healthLoss = rand() % 10;
		string enmyCounter = enmyNames[rand() % enmyNames.size()];
		cout << endl;
		cout << "You encounter a(n) "  << enmyCounter << " and kill it" << endl;
		cout << "You gain " << goldGain << " gold" << endl;
		cout << "You lose " << healthLoss - p->getArmor() << " HP" << endl;
		p->takeDamage(healthLoss);
		cout << endl;
	}
	else {
		cout << endl;
		cout << "You can't seem to find anything" << endl;
		cout << endl;
	}
}