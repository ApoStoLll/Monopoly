#pragma once
#include <string>
#include <iostream>
#include "model.h"
#ifndef MONOPOLY_VIEW_H
#define MONOPOLY_VIEW_H
void print(std::string str);
bool skipOrBuy();
int input();
void printMap(std::vector<Player> &players);
#endif //MONOPOLY_VIEW_H