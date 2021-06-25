#pragma once 
#include <fstream>
#include <string>
#include <iostream>

class BitcoinInfo {
private:

public:

	static double getPrice() {
		system("../scripts/updateBitcoinPrice.sh");
		std::ifstream file("../data/bitcoinPrice.txt");
		std::string stringPrice;
		std::getline(file, stringPrice);
		file.close();

		return std::stod(stringPrice);
	}
};

