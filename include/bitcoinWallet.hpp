#pragma once
#include <string>

class BitcoinWallet {
private:
	double m_bitcoin;

public:
	BitcoinWallet(double bitcoin = 0.0);

	friend std::ostream& operator<<(std::ostream& out, const BitcoinWallet& btcw);
	void buy(double bitcoin);
	void sell(double bitcoin);
	bool isLess(double bitcoin);
	double getAmount();
};