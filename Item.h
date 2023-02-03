#pragma once
#include <iostream>
#include <sstream>

using std::ostream;
using std::string;
using std::stringstream;
using std::endl;

class Item  {
public:
	Item(string name, string description, int gValue) : name(name), description(description), gValue(gValue) { }
	string getName();
	string getDescription();
	int getGValue();
	virtual string showStats();
	friend ostream& operator<<(ostream& out,Item& im);
protected:
	string name, description;
	int gValue;
};

string Item::getName() {
	return name;
}

string Item::getDescription() {
	return description;
}

int Item::getGValue() {
	return gValue;
}

string Item::showStats() {
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Description: " << description << endl;
	ss << "Value: " << gValue << " gold" << endl;
	return ss.str();
}

ostream& operator<<(ostream& out,Item& im) {
	out << im.showStats();
	return out;
}