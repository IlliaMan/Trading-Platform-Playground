#pragma once
#include <iostream>
#include "account.hpp"
#include "bitcoinInfo.hpp"

void showOptions() {
	std::cout << "0 to show info" << std::endl;
	std::cout << "1 to buy" << std::endl;
	std::cout << "2 to sell" << std::endl;
	std::cout << "3 to top up" << std::endl;
	std::cout << "4 to show BTC price" << std::endl;
	std::cout << "9 to exit" << std::endl << std::endl;
}

void userInputPanel(Account acc) {
	showOptions();
	int i;
	int money;
	double quantity;
	bool loop = true;
	while (loop) {
		std::cin >> i;
		switch (i)
		{
		case 0:
			acc.print();
			break;

		case 1:
			std::cout << "How much money are you willing to spend?" << std::endl;
			std::cout << "You have $" << acc.getMoney() << std::endl;
			std::cin >> money;
			acc.buy(Cryptocurrencies::BTC, money);
			std::cout << "You have $" << acc.getMoney() << std::endl << std::endl;
			break;

		case 2:
			std::cout << "How much bitcoin do you want to sell?" << std::endl;
			std::cout << "You have " << acc.getAmount(Cryptocurrencies::BTC) << " BTC" << std::endl;
			std::cin >> quantity;
			acc.sell(Cryptocurrencies::BTC, quantity);
			std::cout << "You have " << acc.getAmount(Cryptocurrencies::BTC) << " BTC" << std::endl << std::endl;
			break;

		case 3:
			std::cout << "How much money do you want to add to your account?" << std::endl;
			std::cin >> money;
			acc.topUp(money);
			std::cout << "You have $" << acc.getMoney() << std::endl << std::endl;
			break;

		case 4:
			std::cout << "BTC Price is " << BitcoinInfo::getPrice() << std::endl;
			break;

		case 9:
			loop = false;
			break;

		default:
			showOptions();
			break;
		}
	}
}