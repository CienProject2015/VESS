#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEM 10



class Sword {
public:
	string name;
	float attack;
	int durability;
	int level;
	char attribute;
	double price;
};

class Shield{
public:
	string name;
	float defense;
	int durability;
	int level;
	char attribute;
	double price;
};


class Item{
public:
	string name;
	char attribute;
	float ganghwaPoint;
	int level;
	double price;
};


class Unit{
public:

	class Sword sword;
	class Shield shield;
	class Item item;

	Item temdul[MAX_ITEM];

	Sword swordGanghwa(Sword sword, Item item);
	Shield shieldGanghwa(Shield shield, Item item);

};