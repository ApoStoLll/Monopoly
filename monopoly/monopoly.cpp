#include "pch.h"
#include "controller.h"

std::vector<Card> createCards() {
	std::vector<Card> cards;
	for (int i = 0; i < 40; i++) {
		UsefullCard card(i);
		cards.push_back(card);
	}
	cards[0].setPrice(60000);
	//Для каждой карты нужно прописать setPrice, setPriceRent, setColor и setPrizeShop
	return cards;
}

std::vector<Player> createPlayers() {
	std::vector<Player> players;
	Player player1(1500000, 0);
	Player player2(1500000, 1);
	players.push_back(player1);
	players.push_back(player2);
	return players;
}

void menu(Player &player) {
	//Меню после хода
}

void gameCycle(std::vector<Player> &players, std::vector<Card> &cards) {
	while (players.size() > 1) {
		for (int i = 0; i < players.size(); i++) {
			Player &player = players[i]; //Пока ходит первый игрок 
			player.setPosition(player.getPosition() + player.random()); // изменение позиции
			printMap(players);//изменить карту
			if (cards[player.getPosition()].getOwner() == 0 //Если карту никто не купил
				&& player.getMoney() >= cards[player.getPosition()].getPrice()) {//Если хватает дене
				if (skipOrBuy()) player.buyCard(cards[player.getPosition()]); // Если решил
				// купить, то покупает
			}
			else {
				if (cards[player.getPosition()].getOwner() > 0) { // если куплено то плоти налоги
					player.payRent(players[cards[player.getPosition()].getOwner()]);
				}
			}
			//printMap(players);//изменить карту
			menu(player); //Вызвать меню для игрока
		}
	}
}

int main() {
	std::vector<Card> cards;
	cards = createCards();
	std::vector<Player> players;
	players = createPlayers();
	//printMap(players);//изменить карту
	gameCycle(players, cards);
	return 0;
}