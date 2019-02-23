#pragma once
#include "model.h"
#include "view.h"
#ifndef MONOPOLY_CONTROLLER_H
#define MONOPOLY_CONTROLLER_H
void gameCycle(std::vector<Player> &players, std::vector<Card> &cards);
bool win(std::vector<Player> &players);
std::vector<Card> createCards();
std::vector<Player> createPlayers();
//void addPlayer(std::vector<Player> &players);
bool choose(std::vector<Card> &cards, Player &player);
void cycleBody(Player &player);
void menu(Player &player); //Меню после хода
#endif //MONOPOLY_CONTROLLER_H