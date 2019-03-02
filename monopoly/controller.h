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
	View viewConsole;
public:
	Controler() {
		cards = createCards();
		players = createPlayers();
		viewConsole = View(players, cards);
		view = GraphView(window);
	}
	void gameCycle();
	void step(Player &player);
	void okCard(Player &player);
	bool choose(Player &player);
	void menu(Player &player);
	void naezd(Player &player);
	void kazna(Player &player);
	void fas(Player &player);
	void caraganda(Player &player);
	void birga(Player &player);
	void inverse(Player &player);
	void present(Player &player1, Player &player2);
	//void roflanCards(Player &player);
	void teleport(Player &player);
	void avos(Player &player);
};
 //Меню после хода
#endif //MONOPOLY_CONTROLLER_H