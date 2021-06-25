#include <string>
#include <iostream>

#include "bitcoinWallet.hpp"

BitcoinWallet::BitcoinWallet(double bitcoin) : m_bitcoin(bitcoin) {}

std::ostream& operator<<(std::ostream& out, const BitcoinWallet& btcw) {
	out << "Your bitcoin wallet has " << btcw.m_bitcoin;
	return out;
}

void BitcoinWallet::buy(double bitcoin) {
	this->m_bitcoin += bitcoin;
}

void BitcoinWallet::sell(double bitcoin) {
	this->m_bitcoin -= bitcoin;
}

bool BitcoinWallet::isLess(double bitcoin) {
	if (bitcoin <= this->m_bitcoin) {
		return true;
	} else {
		return false;
	}
}

double BitcoinWallet::getAmount() {
	return this->m_bitcoin;
}