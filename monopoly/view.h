#pragma once
#include <string>
#include <iostream>
#include "model.h"
#ifndef MONOPOLY_VIEW_H
#define MONOPOLY_VIEW_H
class View {
private:
	std::vector<Player> players;
	std::vector<Card*> cards;
public:
	View() {}
	View(std::vector<Player> player, std::vector<Card*> card) {
		 players = player;
		 cards = card;
	}
	int textMenu();
	int naezdOrPolice();
	int birgaStavka();
	int birgaRisk();
	bool skipOrBuy();
	void printMap( int a, int b, int num);
	char findOwner(int number);
};
#endif //MONOPOLY_VIEW_H