#include "pch.h"
#include "model.h"

int Player::random(int num) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, 6);
	return dist(mt);
}

Card& Player::findCard(int pos) {
	for (int i = 0; i < getCards().size(); i++)
		if (getCards()[i]->getPosition() == pos) 
			return *getCards()[i];
}

void Player::payRent(Player &player) {
	int rentPrice = player.findCard(position).getPriceRent();
	money = money - rentPrice;
	player.setMoney(player.getMoney() - rentPrice);
}
void Player::buyCard(Card *card) {
	card->buy(number);
	money = money - card->getPrice();
	cards.push_back(card);
}

void Player::createShop(int number) {
	Card &card = findCard(number);
	money -= card.getPriceShop();
	card.setPriceRent(card.getPriceRent() * 2 + 80000);
	card.setNumberOfShops(card.getNumberOfShops() + 1);
}

void Player::buyShop(int number) {
	int color = findCard(number).getColor();
	int count = 0;
	for (int i = 0; i < getCards().size(); i++)
		if (getCards()[i]->getColor() == color) count++;
	if (count < 3) return; // FUU
	if (count == 3) if (number == 1 || number == 3 || number == 40 || number == 38) createShop(number); // OK
	if (count == 4) if (number != 5 && number != 15) createShop(number);
}

/*void RoflanCard::caraganda(Player &player) {
	player.setPosition(player.random(20));
}*/