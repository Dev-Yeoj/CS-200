//Teller.h
#include<iostream>
#include"Account.h"
#include"Client.h"
#include"BankingProject.cpp"
#ifndef TELLER_H
#define TELLER_H
class Teller:public Account{
	public:
		Teller();
		Client* addClient();
		void openAccount();
		void print();
		void viewLog();
		string toString();
		int menu();
};
#endif
