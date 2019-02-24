#pragma once
#include <string>
#include <iostream>
#include "model.h"
#ifndef MONOPOLY_VIEW_H
#define MONOPOLY_VIEW_H
void print(std::string str);
bool skipOrBuy();
int input();
void printMap(std::vector<Player> &players,std::vector<Card*> cards,int a,int b);
char findOwner(int number, std::vector<Card*> cards);

#endif //MONOPOLY_VIEW_H