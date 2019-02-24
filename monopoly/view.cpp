#include "pch.h"
#include "view.h"

using namespace std;

bool skipOrBuy() {
	cout << "Do you want to buy it?(Y or N)";
	char in;
	while (true) {
		cin >> in;
		if (in == 'Y' || in == 'y') return true;
		else {
			if (in == 'N' || in == 'n') return false;
			else cout << "Only Y or N, dolbaeb (Try again)";
		}
	}
}

void printMap(std::vector<Player> &players) {
	system("cls");
	const int n = 40;
	char screen[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0)  screen[i][j]='_';
			if (i == n-1 || j == n-1)  screen[i][j]='_';
			else screen[i][j] = ' ';
			cout << screen[i][j];

		}
		cout << endl;
	}

}

