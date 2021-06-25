#pragma once
#include <string>
#include "bitcoinWallet.hpp"
#include "cryptocurrencies.hpp"

class Account {
private:
	std::string m_name;
	double m_money;
	BitcoinWallet m_btcw;

public:
	Account(const std::string& name = "Unknown", double money = 1000.0);

	void print();
	void topUp(double money);
	void buy(Cryptocurrencies cryptocurrency, double money);
	void sell(Cryptocurrencies cryptocurrency, double quantity);
	double getAmount(Cryptocurrencies cryptocurrency);
	double getMoney();
};