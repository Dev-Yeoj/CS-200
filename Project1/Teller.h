//Teller.h
#include<iostream>
#include"Account.h"
#ifndef TELLER_H
#define TELLER_H
class Teller:public Account{
	public:
		Teller();
		void addUser(string, string);
		void openAccount(string, string);
		void print();
		void viewLog();
		string toString();
};
#endif
