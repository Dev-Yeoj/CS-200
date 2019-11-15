//Client.h
#include<iostream>
#include"Account.h"
#ifndef CLIENT_H
#define CLIENT_H
class Client:public Account{
	private:
		double bal;
	public:
		Client();
		double getBal();
		void deposit(double);
		void withdraw(double);
		void print();
		string toString();
		int menu();
};
#endif
