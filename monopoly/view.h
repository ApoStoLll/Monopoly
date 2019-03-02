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
	
	sf::Texture cp0[40];
	sf::Texture cp1[40];
	sf::Sprite player11, player22, going;
	sf::Sprite cop0[40];
	sf::Sprite cop1[40];
	sf::Font font;//רנטפע 
	sf::Text text1, text2, text3, text4, text5;//סמחהאול מבתוךע 

public:
	GraphView(){}
	GraphView(sf::RenderWindow *window) {
		this->window = window;
		//createMap();
	}
	void createMap(int a, int b, int c, int d);
	void drawMap();
	//int MMenu();
	int menu();
	bool skipOrBuy();
	void pprintMap(std::vector<Player> &players, std::vector<Card*> cards, int a, int b, int num);
};
class View {
private:
	std::vector<Player> *players;
	std::vector<Card*> *cards;
public:
	View() {}
	View(std::vector<Player> *player, std::vector<Card*> *card) {
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