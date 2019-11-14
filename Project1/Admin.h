//Admin.h
#include<iostream>
#include"Account.h"
#ifndef ADMIN_H
#define ADMIN_H
class Admin:public Account{
	public:
		Admin();
		Admin(string, string);
		void addUser(string, string);
		void addTeller(string, string);
		void addAdmin(string, string);
		void viewLog();
		void print();
		string toString();
};
#endif
