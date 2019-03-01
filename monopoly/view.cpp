#include "pch.h"
#include "view.h"

int textMenu() {
	//return 0;
	char what;
	std::cout << "What do u want to do? " << std::endl;
	std::cin >> what;
	if (what == 'e') return 0;
	else return -1;
}

bool skipOrBuy() {
	std::cout << "Do you want to buy it?(Y or N)\n";
	char in;
	while (true) {
		std::cin >> in;
		if (in == 'Y' || in == 'y') return true;
		else {
			if (in == 'N' || in == 'n') return false;
			else std::cout << "Only Y or N, dolbaeb (Try again)\n";
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

void printMap(std::vector<Player> &players, std::vector<Card*> cards,int a,int b,int num)
{
	system("cls");
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
	screen[43][29] = findOwner(3, cards);
	screen[43][27] = 'a';
	screen[43][26] = 'F';
	screen[43][23] = 'T';
	screen[43][22] = 'A';
	screen[43][21] = findOwner(5, cards);
	screen[43][19] = 't';
	screen[43][18] = 'A';
	screen[43][17] = findOwner(6, cards);
	screen[43][15] = 'o';
	screen[43][14] = 'S';
	screen[43][13] = findOwner(7, cards);
	screen[43][11] = 'a';
	screen[43][10] = 'K';
	screen[43][7] = 'p';
	screen[43][6] = 'S';
	screen[43][5] = findOwner(9, cards);
	screen[43][0] = 'B';
	screen[39][0] = 'A';
	screen[38][0] = 'v';
	screen[37][0] = findOwner(11, cards);
	screen[35][0] = 'B';
	screen[34][0] = 'r';
	screen[31][0] = 'A';
	screen[30][0] = 'i';
	screen[29][0] = findOwner(12, cards);
	screen[27][0] = 'V';
	screen[26][0] = 'r';
	screen[25][0] = findOwner(13, cards);
	screen[23][0] = 'G';
	screen[22][0] = 't';
	screen[21][0] = findOwner(14, cards);
	screen[19][0] = 'T';
	screen[18][0] = 'i';
	screen[17][0] = findOwner(15, cards);
	screen[15][0] = 'A';
	screen[14][0] = 'v';
	screen[13][0] = findOwner(16, cards);
	screen[11][0] = 'R';
	screen[10][0] = 's';
	screen[9][0] = findOwner(17, cards);
	screen[7][0] = 'T';
	screen[6][0] = 'v';
	screen[5][0] = findOwner(18, cards);
	screen[0][0] = 'k';
	screen[1][0] = 'N';
	screen[0][4] = 'S';
	screen[0][5] = 'k';
	screen[0][6] = findOwner(19, cards);
	screen[0][8] = 'I';
	screen[0][9] = 'k';
	screen[0][10] = findOwner(20, cards);
	screen[0][12] = 'D';
	screen[0][13] = 'c';
	screen[0][16] = 'K';
	screen[0][17] = 'k';
	screen[0][18] = findOwner(21, cards);
	screen[0][20] = 'A';
	screen[0][21] = 't';
	screen[0][22] = findOwner(22, cards);
	screen[0][24] = 'S';
	screen[0][25] = 'l';
	screen[0][26] = findOwner(23, cards);
	screen[0][28] = 'R';
	screen[0][29] = 'b';
	screen[0][32] = 'L';
	screen[0][33] = 'p';
	screen[0][34] = findOwner(24, cards);
	screen[0][36] = 'M';
	screen[0][37] = 'f';
	screen[0][38] = findOwner(25, cards);
	screen[0][42] = 'T';
	screen[0][43] = 'r';
	//screen[1][43] = 'B';
	screen[5][43] = 'N';
	screen[6][43] = 's';
	screen[7][43] = findOwner(26, cards);
	screen[9][43] = 'R';
	screen[10][43] = 'z';
	screen[11][43] = findOwner(27, cards);
	screen[13][43] = 'B';
	screen[14][43] = 'v';
	screen[15][43] = findOwner(28, cards);
	screen[17][43] = 'N';
	screen[18][43] = 'z';
	screen[19][43] = findOwner(29, cards);
	screen[21][43] = 'M';
	screen[22][43] = 'z';
	screen[23][43] = findOwner(30, cards);
	screen[25][43] = 'L';
	screen[26][43] = 'v';
	screen[28][43] = 'Z';
	screen[29][43] = 'p';
	screen[30][43] = findOwner(31, cards);
	screen[32][43] = 'N';
	screen[33][43] = 'a';
	screen[36][43] = 'A';
	screen[37][43] = 'p';
	screen[38][43] = findOwner(32, cards);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << screen[i][j];

		}
		std::cout << std::endl;
	}
	for (int i = 0; i < players.size(); i++) {
		std::cout << "Player " << i << ": " << players[i].getMoney() << "   |   Position: " << players[i].getPosition() << std::endl;
	}
	std::cout << a << '+' << b << "\n";
	std::cout << "Go player: "<< num << "\n";
}