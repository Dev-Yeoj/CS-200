//Teller.h
#include<iostream>
#include"Account.h"
#include"Client.h"
#ifndef TELLER_H
#define TELLER_H
class Teller:public Account{
	public:
		Teller();
		Client* addClient();
		void openAccount(string, string);
		void print();
		void viewLog();
		string toString();
};
#endif
