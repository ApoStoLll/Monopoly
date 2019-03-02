#pragma once
#include <string>
#include <iostream>
#include "model.h"
#ifndef MONOPOLY_VIEW_H
#define MONOPOLY_VIEW_H
class GraphView {
private:
	int pos1(int pos);
	int pos2(int pos);
	sf::RenderWindow *window;
	sf::Texture map;
	sf::Sprite mapa;
	sf::Texture player1, player2;
	sf::Sprite player11, player22, going;
	sf::Text text;
public:
	GraphView(){}
	GraphView(sf::RenderWindow *window) {
		this->window = window;
		//createMap();
	}
	void createMap();
	void drawMap();
	int MMenu();
	bool skipOr();
	void pprintMap(std::vector<Player> &players, std::vector<Card*> cards, int a, int b, int num);
};
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
	int jailask();
	bool skipOrBuy();
	void printMap( int a, int b, int num);
	char findOwner(int number);
};
#endif //MONOPOLY_VIEW_H