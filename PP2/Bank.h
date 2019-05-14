#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "BankClient.h"

class CBank
{
public:
	CBank();
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	std::vector<CBankClient> GetClients();
	long GetTotalBalance();
	long GetBalance(long id);


private:
	std::vector<CBankClient> m_clients;
	std::unordered_map<unsigned, long> m_balance;
	int m_totalBalance;

	void SetTotalBalance(int value);
	void SomeLongOperations();
};