#pragma once
#include <string>
#include <iostream>
#include "model.h"
#ifndef MONOPOLY_VIEW_H
#define MONOPOLY_VIEW_H
void print(std::string str);
bool skipOrBuy();
int input();
int textMenu();
void printMap(std::vector<Player> &players,std::vector<Card*> cards,int a,int b,int num);
bool skipOrBuy();
char findOwner(int number, std::vector<Card*> cards);
class GraphView {
private:
	int pos1(int pos);
	int pos2(int pos);
	sf::RenderWindow *window;
	sf::Texture map;
	sf::Sprite mapa;
	sf::Texture player1, player2;
	sf::Sprite player11, player22, going;
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
#endif //MONOPOLY_VIEW_H