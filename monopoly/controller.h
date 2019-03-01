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
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(900, 813), "Mono");
	GraphView view;
public:
	Controler() {
		cards = createCards();
		players = createPlayers();
		view = GraphView(window);
	}
	void step(Player &player);
	void gameCycle();
	int menu();
	//void addPlayer(std::vector<Player> &players);
	void okCard(Player &player);
	bool choose(Player &player);
	void cycleBody(Player &player);
	void menu(Player &player);
};
 //Меню после хода
#endif //MONOPOLY_CONTROLLER_H