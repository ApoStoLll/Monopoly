#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#ifndef MONOPOLY_MODEL_H
#define MONOPOLY_MODEL_H
class Card {
private:
	int position; //Номер по счету
public:
	Card(int pos) : position(pos) {}
	void buyShop(int number) {}
	int getPosition() { return position; }
	void buy(int owner) {}
	void setPrice(int price) { }
	void setPriceRent(int priceRent) { }
	void setColor(int color) { }
	void setPrizeShop(int prizeShop) { }
	int getPrice() const { return -1; }
	int getPriceRent() const { return -1; }
	int getColor() const { return -1; }
	int getPrizeShop() const { return -1; }
	int getNumberOfShops() const { return -1; }
	int getOwner() const { return -1; }
};

class UsefullCard : public Card {
private:
	int price;//Цена карточки
	int priceRent; //Цена аренды
	int color; // Цвет(тип) 8 шт
	int prizeShop; // Цена домика
	int numberOfShops; // Количество домиков
	int owner; // Номер игрока, которому пренадлежит
public:
	UsefullCard(int num) : Card(num) { owner = 0; }
	UsefullCard(int num, int price, int priceRent, int color) : Card(num) {
		this->price = price;
		this->priceRent = priceRent;
		this->color = color;
	}
	void buy(int owner) { this->owner = owner; }
	void buyShop(int number);

	void setPrice(int price) { UsefullCard::price = price; }
	void setPriceRent(int priceRent) { UsefullCard::priceRent = priceRent; }
	void setColor(int color) { UsefullCard::color = color; }
	void setPrizeShop(int prizeShop) { UsefullCard::prizeShop = prizeShop; }
	int getPrice() const { return price; }
	int getPriceRent() const { return priceRent; }
	int getColor() const { return color; }
	int getPrizeShop() const { return prizeShop; }
	int getNumberOfShops() const { return numberOfShops; }
	int getOwner() const { return owner; }
};

class RoflanCard : public Card {
private:
	int type;
public:
	RoflanCard(int num, int type) : Card(num) { this->type = type;  }
};

class Player {
private:
	int number;
	int money;
	int position;
	std::vector<Card> cards;
public:
	Player(int m_money, int num) : number(num), money(m_money), position(0) {}
	void buyCard(Card &card);
	int random(); // Возвращает сумму кубиков рандомных
	void payRent(Player &player);
	void sell();
	void change();
	void buyShop(int number);
	void setMoney(int money) { this->money = money; }
	void setPosition(int position) { Player::position = position; }
	int getNumber()  { return number; }
	int getMoney()  { return money; }
	int getPosition()  { return position; }
	std::vector<Card>& getCards() { return cards; }
};
#endif //MONOPOLY_MODEL_H
