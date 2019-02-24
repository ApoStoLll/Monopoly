#include "pch.h"
#include "view.h"
#include <Windows.h>


bool skipOrBuy() {
	std::cout << "Do you want to buy it?(Y or N)";
	char in;
	while (true) {
		std::cin >> in;
		if (in == 'Y' || in == 'y') return true;
		else {
			if (in == 'N' || in == 'n') return false;
			else std::cout << "Only Y or N, dolbaeb (Try again)";
		}
	}
}

char findOwner(int number, std::vector<Card*> cards) {
	if (cards[number]->getOwner() == 0) return 'F';
	else {
		if (cards[number]->getOwner() == 1) return 'S';
		else return 'o';
	}
}

void printMap(std::vector<Player> &players,std::vector<Card*> cards)
{
	//system("cls");
	const int n = 40;
	char screen[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n - 1)  screen[i][j] = '_';
			else {
				if (j == 0 || j == n - 1)  screen[i][j] = '|';
				else screen[i][j] = ' ';
			}
		}
	}
	screen[39][39] = 't'; 
	screen[39][38] = 'S';
	screen[39][35] = 'S';
	screen[39][34] = 'K';
	screen[39][33] = findOwner(1, cards);
	screen[39][31] = 'a';
	screen[39][30] = 'K'; 
	screen[39][27] = 'S';
	screen[39][26] = 'M';
	screen[39][25] = findOwner(3, cards);
	screen[39][23] = 'a';
	screen[39][22] = 'F';
	screen[39][19] = 'T';
	screen[39][18] = 'A';
	screen[39][17] = findOwner(5, cards);;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << screen[i][j];

		}
		std::cout << std::endl;
	}


}