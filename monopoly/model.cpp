#include "pch.h"
#include "model.h"

int Player::random(int num) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, num);
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
	player.setMoney(player.getMoney() + rentPrice);
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
	if (number == 5 || number == 15 || number == 25 || number == 35) return;
	if (count < 3) return; // FUU
	if (count == 3) if (number == 1 || number == 3 || number == 40 || number == 38) createShop(number); // OK
	if (count == 4) if (number != 5 && number != 15) createShop(number);
}
void Player::sellShop(int number) {
	number = -1 * number;
	Card &card = findCard(number);
	money += card.getPriceShop();
}
void Player::pledgeCard(int number) {

}

void Player::changeCard(Player &player, int num){
	player.findCard(num).buy(number);
}

void Player::pay(int sum, Player &player){
	money -= sum;// sum < 0, якщо цей player отримує гроші
	player.setMoney(player.getMoney() + sum);
}

bool Player::checkCard(int num)
{
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i]->getPosition() == num) return 1;
	}
	return 0;
}

bool Player::checkMoney(int sum)
{
	if (Player::money < sum) return 1;
	else return 0;
}

void Player::change(Player &player1, Player &player2, int num1, int num2, int sum){
	if (player1.checkMoney(sum) && player2.checkMoney(-sum) && player1.checkCard(num1) && player2.checkCard(num2)){
		player1.changeCard(player2, num2);
		player2.changeCard(player1, num1);
		player1.pay(sum, player2);
	}
	else return;
}
/*int RoflanCard::caraganda() {
	return random(40);
}*/