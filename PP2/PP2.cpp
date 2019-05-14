#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	int clientNumbers = 2;
	if (argc == 2) {
		clientNumbers = atoi(argv[1]);
	}
	CBank* bank = new CBank();
	for (int i = 0; i < clientNumbers; ++i) {
		CBankClient* client = bank->CreateClient();
	}

	for (;;) {
		std::string in;
		std::getline(std::cin, in);
		if (in == "quit" || in == "exit") {
			break;
		}


	}

	long sum = 0;
	std::cout << "Clents Info: " << "\n";
	for (auto client : bank->GetClients()) {
		int balance = bank->GetBalance(client.GetId());
		std::cout << "	Client Id: " << client.GetId() << "\n";
		std::cout << "		Balance: " << balance << "\n";
		sum += balance;
	}
	std::cout << "Clients balance: " << sum << "\n";
	std::cout << "Bank balance: " << bank->GetTotalBalance() << "\n";
	// TODO: WaitForMultipleObjects

    return 0;
}