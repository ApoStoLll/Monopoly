#include "pch.h"
#include "controller.h"

void Controler::caraganda(Player &player) {
	player.setPosition(player.random(40));
}
void Controler::fas(Player &player) {
	int j = 0;
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i]->getNumberOfShops() > 0) {
			j += cards[i]->getNumberOfShops();
		}
	}
	player.setMoney(player.getMoney() - j * 30000);
}
void Controler::kazna(Player &player) {
	int i = player.random(2);
	if (i == 1) {
		player.setMoney(player.getMoney() + ((50 + player.random(150)) * 1000));
	}
	else player.setMoney(player.getMoney() - ((50 + player.random(150)) * 1000));
}
void Controler::naezd(Player &player) {
	int i = view.naezdOrPolice();
	int j = ((10 + player.random(50)) * 1000);
	int k = player.random(4);
	if (i == 0) {
		player.setMoney(player.getMoney() - j);
	}
	else
		if (k == 1 || k == 2 || k == 3) {
			player.setMoney(player.getMoney() - j * 2);
		}
}
void Controler::birga(Player &player) {
	int k = view.birgaStavka();
	int n = view.birgaRisk();
	int a = player.random();
	int b = player.random();
	int c = a + b;
	if (n == 0 && 3 < c) { player.setMoney(player.getMoney() + 2 * k); }
	if (n == 0 && 3 > c) { player.setMoney(player.getMoney() - k); }
	if (n == 1 && 7 < c) { player.setMoney(player.getMoney() + 4 * k); }
	if (n == 1 && 7 > c) { player.setMoney(player.getMoney() - k); }
	if (n == 2 && 9 < c) { player.setMoney(player.getMoney() + 8 * k); }
	if (n == 2 && 9 > c) { player.setMoney(player.getMoney() - k); }
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
	else player2.setMoney(player2.getMoney() + ((25 + player1.random(35)) * 10000));
	player1.setMoney(player1.getMoney() - ((25 + player1.random(35)) * 10000));
}
void Controler::teleport(Player &player) {
	int i = player.random(14) - 1;
	//player.setPosition(
}
void Controler::avos(Player &player) {
	int i = player.random(4);
	if (i == 1) { present(player, player); }
	if (i == 2) { inverse(player); }
	if (i == 3) { player.setMoney(player.getMoney() + (25 + player.random(175) * 1000)); }
	if (i == 4) { player.setMoney(player.getMoney() + (25 + player.random(175) * 1000)); }
}

bool Controler::choose(Player &player) {
	if ((cards[player.getPosition()]->getOwner() == -1) //���� �� �������
		&& (player.getMoney() > cards[player.getPosition()]->getPrice())) return true;
	else return false;
}
void Controler::menu(Player &player) {
	int n = view.textMenu();
	if (n == 0) return;
	if (n > 0) player.buyShop(n);
}
void Controler::okCard(Player &player) {
	if (choose(player)) {	//���� ������� ����� � ������� �������� �� �������
		if (view.skipOrBuy()) player.buyCard(cards[player.getPosition()]); // ���� ��� ������
	}
	else
		if (cards[player.getPosition()]->getOwner() > -1) player.payRent(players[cards[player.getPosition()]->getOwner()]);
	//����� ������
}
void Controler::step(Player &player) {
	int a = player.random();
	int b = player.random();
	if ((player.getPosition() + a + b) / 40 > 0) player.setMoney(player.getMoney() + 200000);
	player.setPosition((player.getPosition() + a + b) % 40); // ��������� �������
	view.printMap( a, b, player.getNumber());	//�������� �����
	if (cards[player.getPosition()]->getType() == -1) { //If UsefullCard
		okCard(player);
	}
	if (cards[player.getPosition()]->getType() == 1) {
		caraganda(player);
	}
	if (cards[player.getPosition()]->getType() == 2) {
		fas(player);
	}
	if (cards[player.getPosition()]->getType() == 3) {
		kazna(player);
	}
	if (cards[player.getPosition()]->getType() == 4) {
		naezd(player);
	}
	if (cards[player.getPosition()]->getType() == 5) {
		birga(player);
	}
	if (cards[player.getPosition()]->getType() == 6) {
		avos(player);
	}

	if (a == b) step(player);
}
void Controler::gameCycle() {
	int i = 0;
	while (players.size() > 1) {
		if (i == players.size()) i = 0;
		step(players[i]);	//��������
		menu(players[i]);	//������� ����
		i++;	//��������� �����	
	}
}
std::vector<Card*> Controler::createCards() {
	std::vector<Card*> cards;
	int k = 1000;
	RoflanCard *start = new RoflanCard(0, 0); // ������ ������ (�����)
	cards.push_back(start);
	UsefullCard *cabSeti = new UsefullCard(1, 60 * k, 2 * k, 0); // ��������� ����
	cards.push_back(cabSeti);
	RoflanCard *karaganda = new RoflanCard(2, 1); // ����������
	cards.push_back(karaganda);
	UsefullCard *magisSeti = new UsefullCard(3, 60 * k, 4 * k, 0); // ����� ����
	cards.push_back(magisSeti);
	RoflanCard *fas = new RoflanCard(4, 2); // �.�.�.
	cards.push_back(fas);
	UsefullCard *autotrans = new UsefullCard(5, 200 * k, 25 * k, 1); // ���������
	cards.push_back(autotrans);
	UsefullCard *ats = new UsefullCard(6, 100 * k, 6 * k, 2); // ���
	cards.push_back(ats);
	UsefullCard *svaz = new UsefullCard(7, 100 * k, 8 * k, 2); // �����
	cards.push_back(svaz);
	RoflanCard *kazna = new RoflanCard(8, 3); // �����
	cards.push_back(kazna);
	UsefullCard *sputnic = new UsefullCard(9, 120 * k, 10 * k, 2); // ����������� �����
	cards.push_back(sputnic);
	RoflanCard *naezd = new RoflanCard(10, 4); // �����
	cards.push_back(naezd);
	UsefullCard *autoprom = new UsefullCard(11, 140 * k, 12 * k, 3); // ��������
	cards.push_back(autoprom);
	RoflanCard *birga = new RoflanCard(12, 5); // �����
	cards.push_back(birga);
	UsefullCard *aviaprom = new UsefullCard(13, 140 * k, 14 * k, 3); // ��������
	cards.push_back(aviaprom);
	UsefullCard *verf = new UsefullCard(14, 160 * k, 16 * k, 3); // �����
	cards.push_back(verf);
	UsefullCard *gdtrans = new UsefullCard(15, 50 * k, 25 * k, 1); // �� �����
	cards.push_back(gdtrans);
	UsefullCard *tipography = new UsefullCard(16, 180 * k, 18 * k, 3); // ����������
	cards.push_back(tipography);
	RoflanCard *avos = new RoflanCard(17, 6); // �����
	cards.push_back(avos);
	UsefullCard *radio = new UsefullCard(18, 180 * k, 20 * k, 3); // ������������
	cards.push_back(radio);
	UsefullCard *televishka = new UsefullCard(19, 200 * k, 22 * k, 3); // ���������
	cards.push_back(televishka);
	RoflanCard *naloh = new RoflanCard(20, 7); // ����� �����
	cards.push_back(naloh);
	UsefullCard *strah = new UsefullCard(21, 220 * k, 24 * k, 5); // ����� ���
	cards.push_back(strah);
	UsefullCard *invest = new UsefullCard(22, 220 * k, 26 * k, 5); // ������ ���
	cards.push_back(invest);
	RoflanCard *svazi = new RoflanCard(23, 8); // ������ � ����������
	cards.push_back(svazi);
	UsefullCard *credit = new UsefullCard(24, 240 * k, 28 * k, 5); // ������ ���
	cards.push_back(credit);
	UsefullCard *aviatrans = new UsefullCard(25, 50 * k, 25 * k, 1); // ���������
	cards.push_back(aviatrans);
	UsefullCard *sibir = new UsefullCard(26, 260 * k, 30 * k, 6); // ����� ���
	cards.push_back(sibir);
	RoflanCard *rusbiznes = new RoflanCard(27, 9); // ������� ������
	cards.push_back(rusbiznes);
	UsefullCard *lesopilka = new UsefullCard(28, 260 * k, 32 * k, 6); // ����� ���
	cards.push_back(lesopilka);
	UsefullCard *mebel = new UsefullCard(29, 280 * k, 34 * k, 6); // ����� ���
	cards.push_back(mebel);
	RoflanCard *jail = new RoflanCard(30, 10); // ����������
	cards.push_back(jail);
	UsefullCard *neft = new UsefullCard(31, 300 * k, 36 * k, 7); // �������� ��������
	cards.push_back(neft);
	RoflanCard *raiders = new RoflanCard(32, 11); // ���������� ������
	cards.push_back(raiders);
	UsefullCard *neftvishki = new UsefullCard(33, 300 * k, 38 * k, 7); // ������� �����
	cards.push_back(neftvishki);
	UsefullCard *neftzavod = new UsefullCard(34, 320 * k, 40 * k, 7); // �������� �����
	cards.push_back(neftzavod);
	UsefullCard *mortrans = new UsefullCard(35, 200 * k, 25 * k, 1); // ��� �����
	cards.push_back(mortrans);
	RoflanCard *love = new RoflanCard(36, 12); // ������ (����)
	cards.push_back(love);
	UsefullCard *gold = new UsefullCard(37, 350 * k, 42 * k, 8); // ������� ������
	cards.push_back(gold);
	RoflanCard *nalohpolice = new RoflanCard(38, 13); // ��������� (�� �����) 
	cards.push_back(nalohpolice);
	UsefullCard *almazi = new UsefullCard(39, 400 * k, 44 * k, 8); // minecraft ������ (�� � �����)
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