#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "account.hpp"
#include "bitcoinInfo.hpp"

Account::Account(const std::string& name, double money)
	: m_name(name), m_money(money), m_btcw() {}


void Account::print() {
	std::cout << m_name << " has $" << m_money << std::endl;
	std::cout << this->m_btcw << std::endl << std::endl;
}

void Account::topUp(double money) {
	this->m_money += money;
}

void Account::buy(Cryptocurrencies cryptocurrency, double money) {
	if (this->m_money < money) {
		std::cout << "You don't have enough money" << std::endl;
		return;
	}

	if (cryptocurrency == Cryptocurrencies::BTC) {
		this->m_money -= money;
		double bitcoin = (money + 0.0) / BitcoinInfo::getPrice();
		this->m_btcw.buy(bitcoin);
	}
}

void Account::sell(Cryptocurrencies cryptocurrency, double quantity) {
	if (this->m_btcw.isLess(quantity) == false) {
		std::cout << "You don't have that much of BTC" << std::endl;
		return;
	}

	if (cryptocurrency == Cryptocurrencies::BTC) {
		this->m_money += BitcoinInfo::getPrice() * quantity;
		this->m_btcw.sell(quantity);
	}
}

double Account::getAmount(Cryptocurrencies cryptocurrency) {
	if (cryptocurrency == Cryptocurrencies::BTC) {
		return this->m_btcw.getAmount();
	}

	return 0.0;
}

double Account::getMoney() {
	return this->m_money;
}