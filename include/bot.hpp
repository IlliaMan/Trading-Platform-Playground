#pragma once 
#include "account.hpp"

class Bot {
private:
	Account m_account;

public:
	Bot(const std::string& name = "Bot");

	void runAlgoritm();
	void showInfo();
	void printBTCandMoney();
};