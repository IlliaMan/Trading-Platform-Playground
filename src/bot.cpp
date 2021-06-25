#include "bot.hpp"
#include "bitcoinInfo.hpp"
#include "cryptocurrencies.hpp"
#include <chrono>
#include <thread>
#include <iomanip>

Bot::Bot(const std::string& name) : m_account(name) {}

void Bot::runAlgoritm() {
	std::chrono::milliseconds timespan(5000);

	double buyPrice = BitcoinInfo::getPrice();
	double currentPrice = BitcoinInfo::getPrice();

	while (true) {
		if (this->m_account.getMoney() == 0) {
			if (buyPrice < currentPrice) {
				double bitcoinAmount = this->m_account.getAmount(Cryptocurrencies::BTC);
				std::cout << "sell: " << std::right << std::setw(10) << bitcoinAmount << " BTC = $" << std::setw(7) << std::left << bitcoinAmount * BitcoinInfo::getPrice() << " -> ";
				this->m_account.sell(Cryptocurrencies::BTC, this->m_account.getAmount(Cryptocurrencies::BTC));
				this->printBTCandMoney();
			}
		} else {
			if (this->m_account.getMoney() > 10) {
				buyPrice = BitcoinInfo::getPrice();
				double money = this->m_account.getMoney();
				this->m_account.buy(Cryptocurrencies::BTC, money);
				std::cout << "buy : " << std::right << std::setw(10) << this->m_account.getAmount(Cryptocurrencies::BTC) << " BTC = $" << std::setw(7) << std::left << money << " -> ";
				currentPrice = BitcoinInfo::getPrice();
				this->printBTCandMoney();
			}
		}

		currentPrice = BitcoinInfo::getPrice();
		std::this_thread::sleep_for(timespan);
	}

}

void Bot::showInfo() {
	this->m_account.print();
}

void Bot::printBTCandMoney() {
	std::cout << "You have $" << std::setw(7) << std::left << this->m_account.getMoney() << " and ";
	std::cout << std::setw(10) << std::left << this->m_account.getAmount(Cryptocurrencies::BTC) << " BTC" << std::endl;
}