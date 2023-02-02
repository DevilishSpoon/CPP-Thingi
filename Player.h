#pragma once
#include <iostream>
#include "Item.h"
#include <vector>
#include <sstream>

using std::vector;
using std::cout;
using std::cin;

class Player {
public:
	Player(int health, int armor, int gold, int damage) : health(health), armor(armor), gold(gold), damage(damage) {}
	~Player();
	virtual void addItem(string name, string description, int gValue);
	virtual void addItem(Item itm);
	virtual void setGold(int goldVal);
	virtual int getGold();
	virtual int getHealth();
	virtual int getArmor();
	virtual string showPlayerStats();
	virtual string showPlayerInventory();
	virtual void takeDamage(int dam);


protected:
	int health, armor, gold, damage;
	vector<Item*>Inventory;
};

void Player::addItem(string name, string description, int gValue) {
	Inventory.push_back(new Item(name, description, gValue));
}

void Player::addItem(Item itm) {
	Inventory.push_back(new Item(itm.getName(),itm.getDescription(),itm.getGValue()));
}

void Player::setGold(int goldVal) {
	gold = goldVal;
}

int Player::getGold() {
	return gold;
}

string Player::showPlayerStats() {
	stringstream ss;
	ss << "Health: " << health << endl;
	ss << "Armor: " << armor << endl;
	return ss.str();
}

string Player::showPlayerInventory() {
	stringstream ss;
	ss << "Gold: " << gold << endl;
	for (int i = 0; i < Inventory.size(); i++) {
		ss << i+1 << "." << endl;
		ss << *Inventory[i];
	}
	return ss.str();
}

Player::~Player() {
	for (Item* c : Inventory) {
		delete c;
	}
}

void Player::takeDamage(int dam) {
	dam -= armor;
	health -= dam;
	if (health <= 0) {
		cout << "You died." << endl;
	}
}

int Player::getHealth() {
	return health;
}

int Player::getArmor() {
	return armor;
}