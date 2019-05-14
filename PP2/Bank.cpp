#include "Bank.h"

CBank::CBank()
{
	m_clients = std::vector<CBankClient>();
	m_totalBalance = 0;
}


CBankClient* CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
	CBankClient* client = new CBankClient(this, clientId);
	m_clients.push_back(*client);
	m_balance[(*client).GetId()] = 0;
	return client;
}


void CBank::UpdateClientBalance(CBankClient &client, int value)
{
	int totalBalance = GetTotalBalance();
	std::cout << "Client " << client.GetId() << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;
	
	SomeLongOperations();
	totalBalance += value;
	m_balance[(&client)->GetId()] += value;

	std::cout
		<< "Client " << client.GetId() << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	// Check correctness of transaction through actual total balance
	if (totalBalance != GetTotalBalance() + value) {
		std::cout << "! ERROR !" << std::endl;
	}

	SetTotalBalance(totalBalance);
}

std::vector<CBankClient> CBank::GetClients()
{
	return m_clients;
}


long CBank::GetTotalBalance()
{
	return m_totalBalance;
}

long CBank::GetBalance(long id)
{
	return m_balance[id];
}


void CBank::SetTotalBalance(int value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
	// TODO
}