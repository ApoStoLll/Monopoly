#include "pch.h"
#include "controller.h"

void caraganda(Player &player) {
	player.setPosition(player.random(40));
}

bool Controler::choose(Player &player) {
	if ((cards[player.getPosition()]->getOwner() == -1)
		&& (player.getMoney() > cards[player.getPosition()]->getPrice())) return true;
	else return false;
}
void Controler::menu(Player &player) {
	if (textMenu() == 0) return;
}
void Controler::okCard(Player &player) {
	if (choose(player)) {	//Если хватает денег и текущая карточка не куплена
		if (view.skipOr()) player.buyCard(cards[player.getPosition()]); // Если тру купить
	}
	else
		if (cards[player.getPosition()]->getOwner() > -1) player.payRent(players[cards[player.getPosition()]->getOwner()]);
	//Плоти нологи
}
void Controler::step(Player &player) {
	int a = player.random();
	int b = player.random();
	if ((player.getPosition() + a + b) / 40 > 0) player.setMoney(player.getMoney() + 200000);
	player.setPosition((player.getPosition() + a + b) % 40); // изменение позиции
	printMap(players, cards, a, b, player.getNumber());	//изменить карту
	view.pprintMap(players, cards, a, b, player.getNumber());
	if (cards[player.getPosition()]->getType() == -1) { //If UsefullCard
		okCard(player);
	}
	if (cards[player.getPosition()]->getType() == 1) {
		//cards[player.getPosition()].caraganda(player);
		caraganda(player);
	}
	if (a == b) step(player);
}
void Controler::gameCycle() {
	//sf::RenderWindow window(sf::VideoMode(900, 813), "Mono");
	int i = 0;
	while (players.size() > 1) {
		if (i == players.size()) i = 0;
		step(players[i]);	//Походить
		view.MMenu();	//Вызвать меню
		i++;	//следующий игрок	
	}
}

std::vector<Card*> Controler::createCards() {
	std::vector<Card*> cards;
	int k = 1000;
	RoflanCard *start = new RoflanCard(0, 0); // Первая ячейка (Старт)
	cards.push_back(start);
	UsefullCard *cabSeti = new UsefullCard(1, 60 * k, 2 * k, 0); // Кабельные сети
	cards.push_back(cabSeti);
	RoflanCard *karaganda = new RoflanCard(2, 1); // караганнда
	cards.push_back(karaganda);
	UsefullCard *magisSeti = new UsefullCard(3, 60 * k, 4 * k, 0); // Магис сети
	cards.push_back(magisSeti);
	RoflanCard *fas = new RoflanCard(4, 2); // Ф.А.С.
	cards.push_back(fas);
	UsefullCard *autotrans = new UsefullCard(5, 200 * k, 25 * k, 1); // автотранс
	cards.push_back(autotrans);
	UsefullCard *ats = new UsefullCard(6, 100 * k, 6 * k, 2); // атс
	cards.push_back(ats);
	UsefullCard *svaz = new UsefullCard(7, 100 * k, 8 * k, 2); // звязь
	cards.push_back(svaz);
	RoflanCard *kazna = new RoflanCard(8, 3); // казна
	cards.push_back(kazna);
	UsefullCard *sputnic = new UsefullCard(9, 120 * k, 10 * k, 2); // спутниковая связь
	cards.push_back(sputnic);
	RoflanCard *naezd = new RoflanCard(10, 4); // наезд
	cards.push_back(naezd);
	UsefullCard *autoprom = new UsefullCard(11, 140 * k, 12 * k, 3); // автопром
	cards.push_back(autoprom);
	RoflanCard *birga = new RoflanCard(12, 5); // биржа
	cards.push_back(birga);
	UsefullCard *aviaprom = new UsefullCard(13, 140 * k, 14 * k, 3); // авиапром
	cards.push_back(aviaprom);
	UsefullCard *verf = new UsefullCard(14, 160 * k, 16 * k, 3); // верфь
	cards.push_back(verf);
	UsefullCard *gdtrans = new UsefullCard(15, 50 * k, 25 * k, 1); // жд транс
	cards.push_back(gdtrans);
	UsefullCard *tipography = new UsefullCard(16, 180 * k, 18 * k, 3); // типография
	cards.push_back(tipography);
	RoflanCard *avos = new RoflanCard(17, 6); // авось
	cards.push_back(avos);
	UsefullCard *radio = new UsefullCard(18, 180 * k, 20 * k, 3); // радиостанция
	cards.push_back(radio);
	UsefullCard *televishka = new UsefullCard(19, 200 * k, 22 * k, 3); // телевышка
	cards.push_back(televishka);
	RoflanCard *naloh = new RoflanCard(20, 7); // плати налох
	cards.push_back(naloh);
	UsefullCard *strah = new UsefullCard(21, 220 * k, 24 * k, 5); // страх ком
	cards.push_back(strah);
	UsefullCard *invest = new UsefullCard(22, 220 * k, 26 * k, 5); // инвест ком
	cards.push_back(invest);
	RoflanCard *svazi = new RoflanCard(23, 8); // дружба с чиновником
	cards.push_back(svazi);
	UsefullCard *credit = new UsefullCard(24, 240 * k, 28 * k, 5); // кредит ком
	cards.push_back(credit);
	UsefullCard *aviatrans = new UsefullCard(25, 50 * k, 25 * k, 1); // авиатранс
	cards.push_back(aviatrans);
	UsefullCard *sibir = new UsefullCard(26, 260 * k, 30 * k, 6); // сибир лес
	cards.push_back(sibir);
	RoflanCard *rusbiznes = new RoflanCard(27, 9); // русский бизнес
	cards.push_back(rusbiznes);
	UsefullCard *lesopilka = new UsefullCard(28, 260 * k, 32 * k, 6); // сибир лес
	cards.push_back(lesopilka);
	UsefullCard *mebel = new UsefullCard(29, 280 * k, 34 * k, 6); // сибир лес
	cards.push_back(mebel);
	RoflanCard *jail = new RoflanCard(30, 10); // обезъянник
	cards.push_back(jail);
	UsefullCard *neft = new UsefullCard(31, 300 * k, 36 * k, 7); // нефтяные скважины
	cards.push_back(neft);
	RoflanCard *raiders = new RoflanCard(32, 11); // рейдерский захват
	cards.push_back(raiders);
	UsefullCard *neftvishki = new UsefullCard(33, 300 * k, 38 * k, 7); // буровые вышки
	cards.push_back(neftvishki);
	UsefullCard *neftzavod = new UsefullCard(34, 320 * k, 40 * k, 7); // нефтяной завод
	cards.push_back(neftzavod);
	UsefullCard *mortrans = new UsefullCard(35, 200 * k, 25 * k, 1); // мор транс
	cards.push_back(mortrans);
	RoflanCard *love = new RoflanCard(36, 12); // любовь (секс)
	cards.push_back(love);
	UsefullCard *gold = new UsefullCard(37, 350 * k, 42 * k, 8); // золотой прииск
	cards.push_back(gold);
	RoflanCard *nalohpolice = new RoflanCard(38, 13); // налоговая (не налох) 
	cards.push_back(nalohpolice);
	UsefullCard *almazi = new UsefullCard(39, 400 * k, 44 * k, 8); // minecraft алмазы (го в шахту)
	cards.push_back(almazi);
	return cards;
}

std::vector<Player> Controler::createPlayers() {
	std::vector<Player> players;
	Player player1(1500000, 0);
	Player player2(1500000, 1);
	players.push_back(player1);
	players.push_back(player2);
	return players;
}