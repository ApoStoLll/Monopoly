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
	if (cards[number]->getOwner() == 0) return '0';
	else {
		if (cards[number]->getOwner() == 1) return '1';
		else return '*';
	}
}

void printMap(std::vector<Player> &players,std::vector<Card*> cards)
{
	//system("cls");
	const int n = 44;
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
	screen[43][43] = 't'; 
	screen[43][42] = 'S';
	screen[43][39] = 'S';
	screen[43][38] = 'K';
	screen[43][37] = findOwner(1, cards);
	screen[43][35] = 'a';
	screen[43][34] = 'K'; 
	screen[43][31] = 'S';
	screen[43][30] = 'M';
	//screen[43][29] = findOwner(3, cards);
	screen[43][27] = 'a';
	screen[43][26] = 'F';
	screen[43][23] = 'T';
	screen[43][22] = 'A';
	//screen[43][21] = findOwner(5, cards);
	screen[43][19] = 't';
	screen[43][18] = 'A';
	//screen[43][17] = findOwner(6, cards);
	screen[43][15] = 'o';
	screen[43][14] = 'S';
	//screen[43][13] = findOwner(7, cards);
	screen[43][11] = 'a';
	screen[43][10] = 'K';
	screen[43][7] = 'p';
	screen[43][6] = 'S';
	//screen[43][5] = findOwner(9, cards);
	screen[43][0] = 'B';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << screen[i][j];

		}
		std::cout << std::endl;
	}
	for (int i = 0; i < players.size(); i++) {
		std::cout << "Player "<<i<<": "<< players[i].getMoney() <<"   |   Position: "<<players[i].getPosition()<<std::endl;
	}
	

}