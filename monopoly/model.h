#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#ifndef MONOPOLY_MODEL_H
#define MONOPOLY_MODEL_H
class Card {
private:
	int position; //Íîìåð ïî ñ÷åòó
public:
	Card(int pos) : position(pos) {}
	void buyShop(int number) {}
	void buy(int owner) {}
	//void caraganda(Player &player) {}
	int getPosition() { return position; }
	void setPrice(int price) { }
	void setPriceRent(int priceRent) { }
	void setColor(int color) { }
	void setPrizeShop(int prizeShop) { }
	void setNumberOfShops(int numberOfShops) { }
	int getPrice() const { return -1; }
	int getPriceRent() const { return -1; }
	int getColor() const { return -1; }
	int getPriceShop() const { return -1; }
	int getNumberOfShops() const { return -1; }
	int getOwner() const { return -1; }
	int getType() const { return -1; }
};

class UsefullCard : public Card {
private:
	int price;//Öåíà êàðòî÷êè
	int priceRent; //Öåíà àðåíäû
	int color; // Öâåò(òèï) 8 øò
	int priceShop; // Öåíà äîìèêà
	int numberOfShops; // Êîëè÷åñòâî äîìèêîâ
	int owner; // Íîìåð èãðîêà, êîòîðîìó ïðåíàäëåæèò
public:
	UsefullCard(int num) : Card(num) { }
	UsefullCard(int num, int price, int priceRent, int color) : Card(num) {
		this->price = price;
		this->priceRent = priceRent;
		this->color = color;
		owner = 0;
	}
	void buy(int owner) { this->owner = owner; }
	void setPrice(int price) { UsefullCard::price = price; }
	void setPriceRent(int priceRent) { UsefullCard::priceRent = priceRent; }
	void setColor(int color) { UsefullCard::color = color; }
	void setPrizeShop(int prizeShop) { UsefullCard::priceShop = prizeShop; }
	void setNumberOfShops(int numberOfShops) { this->numberOfShops = numberOfShops; }
	int getPrice() const { return price; }
	int getPriceRent() const { return priceRent; }
	int getColor() const { return color; }
	int getPriceShop() const { return priceShop; }
	int getNumberOfShops() const { return numberOfShops; }
	int getOwner() const { return owner; }
	int getType()  { return -10; }
};

class RoflanCard : public Card {
private:
	int type;
public:
	RoflanCard(int num, int type) : Card(num) { this->type = type;  }
	//void caraganda(Player &player);
	int getType() const { return type; }
};

class Player {
private:
	int number;
	int money;
	int position;
	std::vector<Card> cards;
public:
	Player(int m_money, int num) : number(num), money(m_money), position(0) {}
	Card& findCard(int pos);
	void buyCard(Card &card);
	int random(int num = 6); // Âîçâðàùàåò ñóììó êóáèêîâ ðàíäîìíûõ
	void payRent(Player &player);
	void sell();
	void change();
	void buyShop(int number);
	void createShop(int number);
	void setMoney(int money) { this->money = money; }
	void setPosition(int position) { Player::position = position; }
	int getNumber()  { return number; }
	int getMoney()  { return money; }
	int getPosition()  { return position; }
	std::vector<Card>& getCards() { return cards; }
};
#endif //MONOPOLY_MODEL_H
