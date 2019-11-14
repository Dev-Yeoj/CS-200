//Teller.h
#include<iostream>
#include"Account.h"
#ifndef TELLER_H
#define TELLER_H
class Teller:public Account{
	public:
		Teller();
		Teller(string, string);
		void addUser(string, string);
		void openAccount(string, string);
		void print();
		string toString();
};
#endif
