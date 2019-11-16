//Admin.h
#include"Account.h"
#include"Client.h"
#include"Teller.h"
#include<fstream>
#ifndef ADMIN_H
#define ADMIN_H
class Admin:public Account{
	public:
		Admin();
		Client* addClient();
		Teller* addTeller();
		Admin* addAdmin();
		void viewLog();
		void print();
		string toString();
		int menu();
};
#endif
