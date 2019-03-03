#include "pch.h"
#include "view.h"
#include <string>

using namespace sf;
int GraphView::pos1(int pos) {
	if (pos < 0) pos = 40 + pos;
	if (pos > 10 && pos < 20) return 97;
	if (pos > 30) return 767;
	if (pos <= 10) return 767 - pos * 67;
	if (pos >= 20 && pos <= 30) return 97 + pos % 20 * 67;
}
int GraphView::pos2(int pos) {
	if (pos < 0) pos = 40 + pos;
	if (pos > 10 && pos < 20) return 707 - pos % 10 * 63;
	if (pos > 30) return 77 + pos % 30 * 63;
	if (pos <= 10) return 707;
	if (pos >= 20 && pos <= 30) return 37;
}
int GraphView::menu() {
	Sprite menu(menuTexture);
	menu.setPosition(170, 340);
	drawMap();
	window->draw(menu);
	window->display();
	while (true) {
		if (IntRect(190, 430, 260, 36).contains(Mouse::getPosition(*window))) if (Mouse::isButtonPressed(Mouse::Left)) return 1;
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
	for (int i = 0; i < 40; i++){
		window->draw(cop0[i]);
		window->draw(cop1[i]);
	}
	
	window->display();
}
bool GraphView::skipOrBuy() {
	menu1.setPosition(230, 360);
	menu2.setPosition(230, 400);
	drawMap();
	window->draw(menu1);
	window->draw(menu2);
	window->display();
	while (true)
	{
		if (IntRect(230, 360, 145, 31).contains(Mouse::getPosition(*window))) if (Mouse::isButtonPressed(Mouse::Left)) return 1;	
		if (IntRect(230, 400, 145, 31).contains(Mouse::getPosition(*window))) if (Mouse::isButtonPressed(Mouse::Left)) return 0;
	}
}
void GraphView::createMap(int a, int b, int c, int d, std::vector<Player> &players) {
	text2.setString(std::to_string(a));
	text4.setString(std::to_string(b));
	text5.setString(std::to_string(c) + '+' + std::to_string(d));
	drawBought(players);
	drawMap();
}
void GraphView::pprintMap(std::vector<Player> &players, std::vector<Card*> cards, int a, int b, int num)
{
	createMap(players[0].getMoney(), players[1].getMoney(), a, b,players);
	
	if (num == 0) { going.setTexture(p1g); going.setPosition(210, 620); }
	else { going.setTexture(p2g); going.setPosition(320, 620); }
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
void GraphView::loadMap() {
	map.loadFromFile("images/map.png");
	player1.loadFromFile("images/p0.png");
	player2.loadFromFile("images/p1.png");
	p1g.loadFromFile("images/p0g.png");
	p2g.loadFromFile("images/p1g.png");
	menuTexture1.loadFromFile("images/buy.png");
	menuTexture2.loadFromFile("images/skip.png");
	menuTexture.loadFromFile("images/m.png");
	naezdM.loadFromFile("images/naezdMenu.png");
	for (int i = 0; i < 40; i++) {
		cp0[i].loadFromFile("images/cop0.png");
		cp1[i].loadFromFile("images/cop1.png");
		cop0[i].setTexture(cp0[i]);
		cop1[i].setTexture(cp1[i]);
		cop0[i].setPosition(1000, 1000);
		cop1[i].setPosition(1000, 1000);
	}
	player11.setTexture(player1);
	player22.setTexture(player2);
	menu1.setTexture(menuTexture1);
	menu2.setTexture(menuTexture2);
	naezdT.setTexture(naezdM);
	mapa.setTexture(map);
	mapa.setPosition(0, 0);
	font.loadFromFile("images/14.otf");//передаем нашему шрифту файл шрифта
	text1.setFont(font);
	text2.setFont(font);
	text3.setFont(font);
	text4.setFont(font);
	text5.setFont(font);
	text6.setFont(font);
	text7.setFont(font);
	text8.setFont(font);
	text9.setFont(font);
	text6.setFillColor(Color::Black);
	text7.setFillColor(Color::Black);
	text8.setFillColor(Color::Black);
	text9.setFillColor(Color::Black);
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
	text1.setString("Player 1:");
	text3.setString("Player 2:");
}
bool GraphView::naezd(int money) {
	naezdT.setPosition(200,207);
	text6.setString(std::to_string(money));
	text6.setPosition(273, 342);
	drawMap();
	window->draw(naezdT);
	window->draw(text6);
	window->display();
	while (true)
	{
		if (IntRect(220, 390, 155, 28).contains(Mouse::getPosition(*window))) if (Mouse::isButtonPressed(Mouse::Left)) return 0;
		if (IntRect(220, 420, 155, 28).contains(Mouse::getPosition(*window))) if (Mouse::isButtonPressed(Mouse::Left)) return 1;
	}
}
void GraphView::drawBought(std::vector<Player> &players) { //BE CAREFUL STRASHNO NEPONYATNA VIRYBAI
	for (int i = 0; i < players[0].getCards().size(); i++) 
		cop0[players[0].getCards()[i]->getPosition()].setPosition(pos1(players[0].getCards()[i]->getPosition()), pos2(players[0].getCards()[i]->getPosition()) - 10);
	for (int i = 0; i < players[1].getCards().size(); i++)
		cop1[players[1].getCards()[i]->getPosition()].setPosition(pos1(players[1].getCards()[i]->getPosition()), pos2(players[1].getCards()[i]->getPosition()) - 10);
}
void GraphView::rentView(int a,int b,int rentPrice){
	text7.setCharacterSize(22);
	text8.setCharacterSize(22);
	text7.setPosition(160, 230);
	text8.setPosition(160, 260);
	text7.setString("Player number " + std::to_string(a) + " pays rent to ");
	text8.setString("player number "+std::to_string(b) + "the amount of "+ std::to_string(rentPrice));
	drawMap();
	window->draw(text7);
	window->draw(text8);
	window->display();
	Sleep(3500);
	//text7.setString(std::to_string(rentPrice));
}
void GraphView::fasView(int j) {
	text9.setCharacterSize(22);
	text9.setPosition(180, 250);
	text9.setString("You have to pay " + std::to_string(j));
	drawMap();
	window->draw(text9);
	window->display();
	Sleep(3000);
}
void GraphView::kaznaView(int l ,bool k) {
	text9.setCharacterSize(22);
	text9.setPosition(180, 250);
	if (k) text9.setString("You've been given " + std::to_string(l));
	if (!k) text9.setString("You lost " + std::to_string(l));
	drawMap();
	window->draw(text9);
	window->display();
	Sleep(3000);
}


