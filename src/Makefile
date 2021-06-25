OUTPUT = execute 
FLAGS  = -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++11

output:
	g++ $(FLAGS) main.cpp account.cpp bitcoinWallet.cpp bot.cpp bitcoinInfo.cpp -o $(OUTPUT) -I ../include/

clean: 
	rm *.o
