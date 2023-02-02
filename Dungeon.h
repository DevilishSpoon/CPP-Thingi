#pragma once
#include "Room.h"
#include <array>
#include <iostream>
#include <random>


using std::array;
using std::cout;
using std::cin;

class Dungeon {
public:
	Dungeon(Player* p) : p(p) {
		int dunRooms = rand() % 5 + 1;
		for (int i = 0; i < rList.size(); i++) {
			srand(time(NULL));
			rList[i] = new Room(1 + rand() % 10, p);
		}
	}
	~Dungeon();
	void start();
	string display();
	void reset();
	


protected:
	int Rnum = 0;
	Room* curRoom;
	array<Room*, 5>rList;
	Player* p;
	int menuChoice;
};

Dungeon::~Dungeon() {
	for (int i = 0; i < rList.size(); i++) {
		delete rList[i];
	}
}

void Dungeon::reset() {
	for (int i = 0; i < rList.size(); i++) {
		delete rList[i];
	}
	for (int i = 0; i < rList.size(); i++) {
		srand(time(NULL));
		rList[i] = new Room(1 + rand() % 10, p);
	}
}

void Dungeon::start() {
	int dunLeave = 0;
	Rnum = 0;
	while (dunLeave < 3 && p->getHealth() > 0) {
		cout << display();
		cin >> dunLeave;

		switch (dunLeave) {
		case 1:
			if (Rnum < rList.size()) {
				rList[Rnum]->search();
				Rnum += 1;
				break;
			}
		case 2:
			if (Rnum < rList.size()) {
				Rnum += 1;
				break;
			}
			else {
				cout << endl;
				cout << "There are no more rooms" << endl;
				cout << endl;
				break;
			}
			
		default:
			cout << "You leave the dungeon" << endl;
			reset();
		}
	}
}

string Dungeon::display() {
	stringstream ss;
	ss << "Room number: " << Rnum << "/" << rList.size() << endl;
	ss << "What would you like to do?" << endl;
	ss << "1. Search the Room." << endl;
	ss << "2. Continue to the next room" << endl;
	ss << "3. Leave" << endl;
	return ss.str();
}