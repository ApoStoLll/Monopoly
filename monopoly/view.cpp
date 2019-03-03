#include "pch.h"
#include "view.h"

int View::textMenu() {
	char what;
	std::cout << "What do u want to do? " << std::endl;
	std::cin >> what;
	if (what == 'e') return 0;
	if (what == 's') {//stroit domik
		int num;
		std::cin >> num;
		return num;
	}
	if (what == 'p') {//prodat domik
		int num;
		std::cout << "Print number of card with -\n";
		std::cin >> num;
		return num;
	}
	if (what == 'c') {//change
		return -1000;
	}

	else return -100;
}
bool View::skipOrBuy() {
	std::cout << "Do you want to buy it?(Y or N)\n";
	char in;
	while (true) {
		std::cin >> in;
		if (in == 'Y' || in == 'y') return true;
		else {
			if (in == 'N' || in == 'n') return false;
			else std::cout << "Only Y or N, Genius (Try again)\n";
		}
	}
}
int View::naezdOrPolice() {
	std::cout << "Do you want to call the police?(Y or N)\n";
	char in;
	while (true) {
		std::cin >> in;
		if (in == 'Y' || in == 'y') return 1;
		else {
			if (in == 'N' || in == 'n') return 0;
			else std::cout << "Only Y or N, Genius (Try again)\n";
		}
	}
}
int View::birgaStavka() {
	int k = 0;
	std::cout << "Print the amount of money you're willing to bet(only integer numbers)\n";
	std::cin >> k;
	return k;
}
int View::birgaRisk() {
	int n;
	std::cout << "Print the rate(3 or 7 or 9)\n";
	std::cin >> n;
	return n;
}
int View::jailask() {
	char in;
	std::cout << "Do you want to leave jail?(Y or N)\n";
	while (true) {
		std::cin >> in;
		if (in == 'Y' || in == 'y') return 1;
		else {
			if (in == 'N' || in == 'n') return 0;
			else std::cout << "Only Y or N, (Try again)\n";
		}
	}
}
int View::askReide() {
	int n;
	std::cout << "Print the number of card to reid(1-40)\n";
	std::cin >> n;
	return n;
}
char View::findOwner(int number) {
	if (cards->at(number)->getOwner() == 0) return '0';
	else {
		if (cards->at(number)->getOwner() == 1) return '1';
		else return '*';
	}
}
void View::printMap( int a, int b, int num)
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
	screen[43][37] = findOwner(1);
	screen[43][35] = 'a';
	screen[43][34] = 'K';
	screen[43][31] = 'S';
	screen[43][30] = 'M';
	screen[43][29] = findOwner(3);
	screen[43][27] = 'a';
	screen[43][26] = 'F';
	screen[43][23] = 'T';
	screen[43][22] = 'A';
	screen[43][21] = findOwner(5);
	screen[43][19] = 't';
	screen[43][18] = 'A';
	screen[43][17] = findOwner(6);
	screen[43][15] = 'o';
	screen[43][14] = 'S';
	screen[43][13] = findOwner(7);
	screen[43][11] = 'a';
	screen[43][10] = 'K';
	screen[43][7] = 'p';
	screen[43][6] = 'S';
	screen[43][5] = findOwner(9);
	screen[43][0] = 'B';
	screen[39][0] = 'A';
	screen[38][0] = 'v';
	screen[37][0] = findOwner(11);
	screen[35][0] = 'B';
	screen[34][0] = 'r';
	screen[31][0] = 'A';
	screen[30][0] = 'i';
	screen[29][0] = findOwner(12);
	screen[27][0] = 'V';
	screen[26][0] = 'r';
	screen[25][0] = findOwner(13);
	screen[23][0] = 'G';
	screen[22][0] = 't';
	screen[21][0] = findOwner(14);
	screen[19][0] = 'T';
	screen[18][0] = 'i';
	screen[17][0] = findOwner(15);
	screen[15][0] = 'A';
	screen[14][0] = 'v';
	screen[13][0] = findOwner(16);
	screen[11][0] = 'R';
	screen[10][0] = 's';
	screen[9][0] = findOwner(17);
	screen[7][0] = 'T';
	screen[6][0] = 'v';
	screen[5][0] = findOwner(18);
	screen[0][0] = 'k';
	screen[1][0] = 'N';
	screen[0][4] = 'S';
	screen[0][5] = 'k';
	screen[0][6] = findOwner(19);
	screen[0][8] = 'I';
	screen[0][9] = 'k';
	screen[0][10] = findOwner(20);
	screen[0][12] = 'D';
	screen[0][13] = 'c';
	screen[0][16] = 'K';
	screen[0][17] = 'k';
	screen[0][18] = findOwner(21);
	screen[0][20] = 'A';
	screen[0][21] = 't';
	screen[0][22] = findOwner(22);
	screen[0][24] = 'S';
	screen[0][25] = 'l';
	screen[0][26] = findOwner(23);
	screen[0][28] = 'R';
	screen[0][29] = 'b';
	screen[0][32] = 'L';
	screen[0][33] = 'p';
	screen[0][34] = findOwner(24);
	screen[0][36] = 'M';
	screen[0][37] = 'f';
	screen[0][38] = findOwner(25);
	screen[0][42] = 'T';
	screen[0][43] = 'r';
	//screen[1][43] = 'B';
	screen[5][43] = 'N';
	screen[6][43] = 's';
	screen[7][43] = findOwner(26);
	screen[9][43] = 'R';
	screen[10][43] = 'z';
	screen[11][43] = findOwner(27);
	screen[13][43] = 'B';
	screen[14][43] = 'v';
	screen[15][43] = findOwner(28);
	screen[17][43] = 'N';
	screen[18][43] = 'z';
	screen[19][43] = findOwner(29);
	screen[21][43] = 'M';
	screen[22][43] = 'z';
	screen[23][43] = findOwner(30);
	screen[25][43] = 'L';
	screen[26][43] = 'v';
	screen[28][43] = 'Z';
	screen[29][43] = 'p';
	screen[30][43] = findOwner(31);
	screen[32][43] = 'N';
	screen[33][43] = 'a';
	screen[36][43] = 'A';
	screen[37][43] = 'p';
	screen[38][43] = findOwner(32);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << screen[i][j];

		}
		std::cout << std::endl;
	}
	for (int i = 0; i < players->size(); i++) {
		std::cout << "Player " << i << ": " << players->at(i).getMoney() << "   |   Position: " << players->at(i).getPosition() << std::endl;
	}
	std::cout << a << " + " << b << "\n";
	std::cout << "Go player: "<< num << "\n";
}

int* View::change()//consol change
{
	int n;
	int *num = new int[n];
	n = 3;
	std::cout << "sum\n";
	std::cin >> num[1];
	std::cout << "your card\n";
	std::cin >> num[2];
	std::cout << "another card\n";
	std::cin >> num[3];
	return num;
}

int View::chose_player()
{
	int numofpl;
	std::cout << "Player for change";
	std::cin >> numofpl;

	return numofpl;
}