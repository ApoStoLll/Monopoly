#include "pch.h"
#include "controller.h"

std::vector<Card> createCards() {
	std::vector<Card> cards;
	/*for (int i = 0; i < 40; i++) {
		UsefullCard card(i);
		cards.push_back(card);
	}
	cards[0].setPrice(60000);*/
	int k = 1000;
	RoflanCard start(0, 0); // Первая ячейка (Старт)
	Card &cardStart = start;
	cards.push_back(cardStart);
	UsefullCard cabSeti(1, 60*k, 2 * k, 0); // Кабельные сети
	Card &card2 = start;
	cards.push_back(card2);
	RoflanCard caraganda(2, 1); // CARAGANDA
	Card &card3 = caraganda;
	cards.push_back(card3);
	UsefullCard magSeti(3, 60 * k, 4 * k, 0); // Магис сети
	Card &card4 = magSeti;
	cards.push_back(card4);
	RoflanCard fas(4, 2); // FAS
	Card &card5 = fas;
	cards.push_back(card5);
	UsefullCard autoTrans(3, 200 * k, 25 * k, 1); // TRANSPORT 1
	Card &card6 = autoTrans;
	cards.push_back(card6);
	//5 cards
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

bool choose(std::vector<Card> &cards, Player &player) {
	if (cards[player.getPosition()].getOwner() == 0 
		&& player.getMoney() > cards[player.getPosition()].getPrice()) return true;
	else return false;
}

/*void menu(Player &player) {
	//Меню после хода
	if (input == 0) return;
}*/

void okCard(std::vector<Player> &players, std::vector<Card> &cards, Player &player) {
	if (choose(cards, player))	//Если хватает денег и текущая карточка не куплена
		if (skipOrBuy()) player.buyCard(cards[player.getPosition()]); // Если тру купить
	else 
		if (cards[player.getPosition()].getOwner() == 0) player.payRent(players[cards[player.getPosition()].getOwner()]);
		//Плоти нологи
}

void gameCycle(std::vector<Player> &players, std::vector<Card> &cards) {
	int i = 0;
	while (players.size() > 1) {
		if (i == players.size()) i = 0;
		Player &player = players[i]; //Пока ходит первый игрок 
		player.setPosition(player.getPosition() + player.random()); // изменение позиции
		printMap(players,cards);	//изменить карту
		if (cards[player.getPosition()].getType() == -10) okCard(players, cards, player);
		if (cards[player.getPosition()].getType() == 1) {
			//cards[player.getPosition()].caraganda(player);
			player.setPosition(player.random(20));
		}
		printMap(players,cards); //изменить карту
		//menu(player); //Вызвать меню для игрока
		i++;//следующий игрок
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