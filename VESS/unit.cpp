
#pragma once

#include "unit.h"

Sword Unit::swordGanghwa(Sword sword, Item item){

	sword.attack += item.ganghwaPoint;
	sword.attribute += item.attribute;
	sword.level += item.level;
	sword.price += item.price;

	return sword;
}


Shield Unit::shieldGanghwa(Shield shield, Item a){

	shield.defense += a.ganghwaPoint;
	shield.attribute += a.attribute;
	shield.level += a.level;
	shield.price += a.price;

	return shield;
}