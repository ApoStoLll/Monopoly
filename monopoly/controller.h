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
	bool p = false;
public:
	Controler() {
		cards = createCards();
		players = createPlayers();
		view = View(players, cards);
	}
	void gameCycle();
	void step(Player &player,bool p);
	//void addPlayer(std::vector<Player> &players);
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
	void kanikulu(Player &player);
	void svazi(Player &player);
	void rusbiznes(Player &player);
	void jail(Player &player,bool p);
};
 //Меню после хода
#endif //MONOPOLY_CONTROLLER_H