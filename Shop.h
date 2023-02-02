#pragma once
#include <iostream>
#include <sstream>
#include "Item.h"
#include "Player.h"
#include <vector>

using std::vector;
using std::stringstream;
using std::cout;

class Shop {
public:
	Shop();
	~Shop();
	void addItem(string name, string description, int gValue);
	void sellItem(int itemNum, Player* pl);
	virtual string showInventory();
	friend ostream& operator<<(ostream& out, Shop& sh);

private:
	vector<Item*>Inventory;

};

Shop::Shop() {

}

void Shop::addItem(string name, string description, int gValue) {
	Inventory.push_back(new Item(name, description, gValue));
}

void Shop::sellItem(int itemNum,Player* pl) {
	itemNum -= 1; // accounts for the +1 shown in the Inventory
	if (pl->getGold() >= Inventory[itemNum]->getGValue()) {
		pl->addItem(Inventory[itemNum]->getName(), Inventory[itemNum]->getDescription(), Inventory[itemNum]->getGValue()); // Creates an object with the same stats
		pl->setGold(pl->getGold() - Inventory[itemNum]->getGValue()); // Removes gold from player inventory
		Inventory.erase(Inventory.begin() + itemNum); //Removes Item from shop inventory
	}
	else cout << "You are too broke to buy this item.\n" << endl;
	
}

string Shop::showInventory() {
	stringstream ss;
	ss << "\nTake a look." << endl;
	ss << endl;
	for (int i = 0; i < Inventory.size(); i ++) {
		ss << i+1 << "." << endl;
		ss << *Inventory[i] << endl;
	}
	return ss.str();
}

ostream& operator<<(ostream& out, Shop& sh) {
	out << sh.showInventory();
	return out;
}

Shop::~Shop() { 
	for (Item* a : Inventory) {
		delete a;
	}
}

