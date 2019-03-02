#include "pch.h"
#include "controller.h"

void Controler::caraganda(Player &player) {
	player.setPosition(player.random(40));
}
void Controler::fas(Player &player) {
	int j = 0;
	for (int i = 0; i < cards.size(); i++)
		if (cards[i]->getNumberOfShops() > 0) j += cards[i]->getNumberOfShops();
	player.setMoney(player.getMoney() - j * 30000);
}
void Controler::kazna(Player &player) {
	int i = player.random(2);
	if (i == 1) player.setMoney(player.getMoney() + ((50 + player.random(150)) * 1000));
	else player.setMoney(player.getMoney() - ((50 + player.random(150)) * 1000));
}
void Controler::naezd(Player &player) {
	int i = viewConsole.naezdOrPolice();
	int j = ((10 + player.random(50)) * 1000);
	int k = player.random(4);
	if (i == 0) player.setMoney(player.getMoney() - j);
	if (i == 1) {
		if (k == 1 || k == 2 || k == 3) player.setMoney(player.getMoney() - j * 2);
	}
}
void Controler::birga(Player &player) {
	int k = viewConsole.birgaStavka();
	int n = viewConsole.birgaRisk();
	int a = player.random();
	int b = player.random();
	if (n == 3 && n < (a + b))  player.setMoney(player.getMoney() + 2 * k); 
	if (n == 3 && n >= (a + b))  player.setMoney(player.getMoney() - k); 
	if (n == 7 && n < (a + b)) player.setMoney(player.getMoney() + 4 * k); 
	if (n == 7 && n >= (a + b))  player.setMoney(player.getMoney() - k); 
	if (n == 9 && n < (a + b))  player.setMoney(player.getMoney() + 8 * k); 
	if (n == 9 && n >= (a + b))  player.setMoney(player.getMoney() - k); 
}

void Controler::inverse(Player &player) {
	player.setPosition(player.getPosition() - player.random() - player.random());
}
void Controler::present(Player &player1, Player &player2) {
	int k = player1.random(2);
	if (k == 1) {
		player1.setMoney(player1.getMoney() + ((25 + player1.random(35)) * 10000));
		player2.setMoney(player2.getMoney() - ((25 + player1.random(35)) * 10000));
	}
	else {
		player2.setMoney(player2.getMoney() + ((25 + player1.random(35)) * 10000));
		player1.setMoney(player1.getMoney() - ((25 + player1.random(35)) * 10000));
	}
}

void Controler::avos(Player &player) {
	int i = player.random(5);
	if (i == 1)  present(player, player); 
	if (i == 2)  inverse(player); 
	if (i == 3)  player.setMoney(player.getMoney() + (25 + player.random(175) * 1000)); 
	if (i == 4)  player.setMoney(player.getMoney() + (25 + player.random(175) * 1000)); 
	if (i == 5) caraganda(player);
}
void Controler::kanikulu(Player &player) {
	player.setMoney(player.getMoney() + (200 + player.random(200)) * 10000);
}
void Controler::svazi(Player &player) {
	if (player.getCountchin() == 0) {
		player.setCountchin(1);
	}
	else {
		player.setCountchin(0);
		int i = player.random(2);
		int k = player.random(40);
		if (i = 1) {
			player.setMoney(player.getMoney() + (50 + player.random(125) * 10000));
		}
		if (i = 2) {
			player.setPosition(k);
			player.buyCard(cards[player.getPosition()]);
			player.setMoney(player.getMoney() + cards[player.getPosition()]->getPrice());
			player.setPosition(23);
		}
	}
}
void Controler::rusbiznes(Player &player) {
	if (player.getCountrus() == 0) {
		player.setCountrus(1);
	}
	else {
		player.setCountrus(0);
		int i = player.random(4);
		int k = player.random(40);
		if (i = 1) {
			for (int i = 0; i < cards.size(); i++)
				if (cards[i]->getNumberOfShops() == 0) cards[i]->buy(-1);//rusbiznes zabral kart
			i = 4;//esli y igroka vezde est domiki,y nego zaberut dengi
		}
		if (i = 2) 	player.setMoney(player.getMoney() + (player.random(50) + player.random(75) + player.random(325)) * 10000);
		if (i = 3) {
			player.setPosition(k);
			player.buyCard(cards[player.getPosition()]);
			player.setMoney(player.getMoney() + cards[player.getPosition()]->getPrice());
			player.setPosition(27);
		}
		if (i = 4) player.setMoney(player.getMoney() - (player.random(50) + player.random(75) + player.random(325)) * 10000);
	}
}
void Controler::jail(Player &player) {
	int i = viewConsole.jailask();
	int a = player.random();
	int b = player.random();
	if (player.getCountjail() != 3 ){ //sidit v turme ne bolshe 3 hodov
		if (i == 0) {//if igrok ostaetsa v jail
			if ((a + b) % 2 == 0)//vupal dubl
			{
				player.setCountjail(0);
				step(player);
			}
			else {//dubl ne vupal, ne hodit, schetchik turmu +1
				player.setCountjail(player.getCountjail() + 1);
				step(player);
			}
		}
		if (i = 1) {//igrok platit dengi i uhodit s turmu
			player.setMoney(player.getMoney() - 50000);
			player.setCountjail(0);
			step(player);
		}
	}
	if (player.getCountjail() == 3) {
		player.setCountjail(0);
		step(player);
	}
}
void Controler::reide(Player &player) {
	int k = viewConsole.askReide();
	player.setPosition(k);
	player.buyCard(cards[player.getPosition()]);
	player.setMoney(player.getMoney() + cards[player.getPosition()]->getPrice());
	player.setPosition(32);
}
void Controler::love(Player &player) {
	kazna(player);
}
void Controler::nalogi(Player &player) {
	player.setMoney(player.getMoney()*0.8);//20 percent 
}


bool Controler::choose(Player &player) {
	if ((cards[player.getPosition()]->getOwner() == -1) //Если не куплена
		&& (player.getMoney() > cards[player.getPosition()]->getPrice())) return true;
	else return false;
}
void Controler::menu(Player &player) {
	int n = viewConsole.textMenu();
	if (n == 0) return;
	if (n > 0) player.buyShop(n);
}
void Controler::okCard(Player &player) {
	if (choose(player)) {	//Если хватает денег и текущая карточка не куплена
		if (view.skipOrBuy()) {
			view.drawCard(player.getPosition(),player.getNumber());
			player.buyCard(cards[player.getPosition()]);
		}// Если тру купить
		//if (viewConsole.skipOrBuy()) player.buyCard(cards[player.getPosition()]); // Если тру купить
	}
	else
		if (cards[player.getPosition()]->getOwner() > -1) player.payRent(players[cards[player.getPosition()]->getOwner()]);
	//Плоти нологи
}
void Controler::step(Player &player) {
	int a = player.random();
	int b = player.random();
	if (player.getCountjail() == 0) {
		if ((player.getPosition() + a + b) / 40 > 0) player.setMoney(player.getMoney() + 200000);
		player.setPosition((player.getPosition() + a + b) % 40); // изменение позиции
		viewConsole.printMap(a, b, player.getNumber());
		view.pprintMap(players, cards, a, b, player.getNumber());//изменить карту
		if (cards[player.getPosition()]->getType() == -1) okCard(player);
		if (cards[player.getPosition()]->getType() == 1) caraganda(player);
		if (cards[player.getPosition()]->getType() == 2) fas(player);
		if (cards[player.getPosition()]->getType() == 3) kazna(player);
		if (cards[player.getPosition()]->getType() == 4) naezd(player);
		if (cards[player.getPosition()]->getType() == 5) birga(player);
		if (cards[player.getPosition()]->getType() == 6) avos(player);
		if (cards[player.getPosition()]->getType() == 7) kanikulu(player);
		if (cards[player.getPosition()]->getType() == 8) svazi(player);
		if (cards[player.getPosition()]->getType() == 9) rusbiznes(player);
		if (cards[player.getPosition()]->getType() == 10) jail(player);
		if (cards[player.getPosition()]->getType() == 11) reide(player);
		if (cards[player.getPosition()]->getType() == 12) love(player);
		if (cards[player.getPosition()]->getType() == 13) nalogi(player);
		if (a == b) step(player);
	}
	if (player.getCountjail()>0) {
		player.setPosition(player.getPosition());
	}
}

void Controler::gameCycle() {
	int i = 0;
	view.loadMap();
	while (players.size() > 1) {
		if (i == players.size()) i = 0;
		step(players[i]);	//Походить
		view.menu();	//Вызвать меню
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
	RoflanCard *kanikulu = new RoflanCard(20, 7); // плати налох
	cards.push_back(kanikulu);
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
	RoflanCard *reide = new RoflanCard(32, 11); // рейдерский захват
	cards.push_back(reide);
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