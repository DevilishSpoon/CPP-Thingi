#include <iostream>
#include "Player.h"
#include "Shop.h"
#include "Dungeon.h"

using std::cin;


void disMainMenu();

enum mainChoices { SHOP = 1, BUY, INV, STATS, DUNGEON, QUIT };

int main() {
	Shop shop;
	Player p(50, 0, 100, 1);
	int choice;
	int buyChoice;
	Dungeon d(&p);

	for (int i = 0; i < 5; i++) {
		shop.addItem("Trash", "a piece of garbage", 10);
	}
	shop.addItem("Dragon Bones", "bones of a dragon", 100);
	do {
		disMainMenu();
		cin >> choice;

		switch (choice) {
		case SHOP:
			cout << shop;
			break;
		case BUY:
			cout << "Pick the number of the item you would like to buy:" << endl;
			cin >> buyChoice;
			shop.sellItem(buyChoice, &p);
			break;
		case INV:
			cout << endl;
			cout << p.showPlayerInventory();
			cout << endl;
			break;
		case STATS:
			cout << endl;
			cout << p.showPlayerStats();
			cout << endl;
			break;
		case DUNGEON:
			d.start();
			cout << endl;
			break;
		default:
			break;
		}

	} while (choice != QUIT && p.getHealth() > 0);
	cout << "Goodbye!";
	cin.get();

	return 0;
}

void disMainMenu() {
	cout << "Choose what you would like to do." << endl;
	cout << "1. See shop wares." << endl;
	cout << "2. Buy an Item" << endl;
	cout << "3. Check your Inventory" << endl;
	cout << "4. Check your Stats" << endl;
	cout << "5. Dungeon" << endl;
	cout << "6. QUIT" << endl;
	cout << endl;
}