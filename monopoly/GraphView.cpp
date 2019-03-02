#include "pch.h"
#include "view.h"
#include <string>
using namespace sf;
int GraphView::pos1(int pos) {
	if (pos > 10 && pos < 20) return 97;
	if (pos > 30) return 767;
	if (pos <= 10) return 767 - pos * 67;
	if (pos >= 20 && pos <= 30) return 97 + pos % 20 * 67;
}
int GraphView::pos2(int pos) {
	if (pos > 10 && pos < 20) return 707 - pos % 10 * 63;
	if (pos > 30) return 77 + pos % 30 * 63;
	if (pos <= 10) return 707;
	if (pos >= 20 && pos <= 30) return 37;
}
int GraphView::menu() {
	Texture menuTexture;
	menuTexture.loadFromFile("images/m.png");
	Sprite menu(menuTexture);
	int menuNum = 0;
	menu.setPosition(500, 500);
	drawMap();
	window->draw(menu);
	window->display();
	while (true) {
		menuNum = 0;
		if (IntRect(500, 500, 300, 50).contains(Mouse::getPosition(*window))) { menu.setColor(Color::Blue); menuNum = 1; }
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (menuNum == 1) return 1;
		}
	}
}
void GraphView::drawMap() {
	window->clear();
	window->draw(mapa);
	window->draw(player11);
	window->draw(player22);
	window->draw(going);
	window->draw(text1);
	window->draw(text2);
	window->draw(text3);
	window->draw(text4);
	window->draw(text5);
	for (int i = 0; i < 40; i++) {
		window->draw(cop0[i]);
		window->draw(cop1[i]);
	}
	
	window->display();
}
bool GraphView::skipOrBuy() {
	Texture menuTexture1, menuTexture2;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(300, 300);
	menu2.setPosition(400, 300);
	drawMap();
	window->draw(menu1);
	window->draw(menu2);
	window->display();
	while (true)
	{
		menuNum = 0;
		//window.clear();
		if (IntRect(300, 300, 300, 50).contains(Mouse::getPosition(*window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(400, 300, 300, 50).contains(Mouse::getPosition(*window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (menuNum == 1) return 1;
			if (menuNum == 2) return 0;
		}
	}
}
void GraphView::createMap(int a, int b, int c, int d) {
	map.loadFromFile("images/1.png");
	player1.loadFromFile("images/2.png");
	player2.loadFromFile("images/3.png");
	for (int i = 0; i < 40; i++) {
		cp0[i].loadFromFile("images/22.png");
		cp1[i].loadFromFile("images/33.png");
		cop0[i].setTexture(cp0[i]);
		cop0[i].setTexture(cp1[i]);
	}

	player11.setTexture(player1);
	player22.setTexture(player2);
	mapa.setTexture(map);
	mapa.setPosition(0, 0);
	font.loadFromFile("images/14.otf");//передаем нашему шрифту файл шрифта
	text1.setFont(font);
	text2.setFont(font);
	text3.setFont(font);
	text4.setFont(font);
	text5.setFont(font);
	text1.setString("Player 1:");
	text2.setString(std::to_string(a));
	text3.setString("Player 2:");
	text4.setString(std::to_string(b));
	text5.setString(std::to_string(c) + '+' + std::to_string(d));
	text1.setPosition(175, 540);
	text1.setFillColor(Color::Black);
	text2.setPosition(175, 580);
	text2.setFillColor(Color::Black);
	text3.setPosition(285, 540);
	text3.setFillColor(Color::Black);
	text4.setPosition(285, 580);
	text4.setFillColor(Color::Black);
	text5.setPosition(200, 200);
	text5.setFillColor(Color::Black);

}

void GraphView::pprintMap(std::vector<Player> &players, std::vector<Card*> cards, int a, int b, int num)
{
	createMap(players[0].getMoney(), players[1].getMoney(), a, b);
	if (cards[players[0].getPosition()]->getOwner() == 0)cop0[players[0].getPosition()].setPosition(pos1(players[0].getPosition()), pos2(players[0].getPosition()));
	if (num == 0) { going.setTexture(player1); going.setPosition(500, 350); }
	else { going.setTexture(player2); going.setPosition(500, 350); }
	for (int i = (a + b); i >= 0; i--) {
		if (num == 0) {
			player11.setPosition(pos1(players[0].getPosition() - i), pos2(players[0].getPosition() - i));
			player22.setPosition(pos1(players[1].getPosition()) + 2, pos2(players[1].getPosition()) + 2);
		}
		else {
			player11.setPosition(pos1(players[0].getPosition()), pos2(players[0].getPosition()));
			player22.setPosition(pos1(players[1].getPosition() - i) + 2, pos2(players[1].getPosition() - i) + 2);
		}
		drawMap();
		Sleep(500);
	}

	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
	}

}