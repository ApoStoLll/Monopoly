#pragma once
#include "model.h"
#include "view.h"
#include <vector>
#include <Windows.h>

#ifndef MONOPOLY_CONTROLLER_H
#define MONOPOLY_CONTROLLER_H
class Controler {
private:
	std::vector<Card*> cards;
	std::vector<Player> players;
	std::vector<Card*> createCards();
	std::vector<Player> createPlayers();
	View view;
public:
	Controler() {
		cards = createCards();
		players = createPlayers();
		view = View(players, cards);
	}
	void gameCycle();
	void step(Player &player);
	int menu();
	//void addPlayer(std::vector<Player> &players);
	void okCard(Player &player);
	bool choose(Player &player);
	void cycleBody(Player &player);
	void menu(Player &player);
};
 //Меню после хода
#endif //MONOPOLY_CONTROLLER_H