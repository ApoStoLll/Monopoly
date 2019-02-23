#include "pch.h"
#include "model.h"

int Player::random() {
	srand(time(0));
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;
	return a + b;
}
void Player::payRent(Player &player) {
	int rentPrice;
	for (int i = 0; i < player.getCards().size(); i++)
		if (player.getCards()[i].getPosition() == position)
			rentPrice = player.getCards()[i].getPriceRent();
	money = money - rentPrice;
	player.setMoney(player.getMoney() - rentPrice);
}
void Player::buyCard(Card &card) {
	card.buy(number);
	money = money - card.getPrice();
	cards.push_back(card);
}