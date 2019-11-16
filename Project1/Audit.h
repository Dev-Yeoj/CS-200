//Audit.h
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Teller.h"

using namespace std;
#ifndef AUDIT_H
#define AUDIT_H
class Audit {
	private:
		static void saveLoginLog(string);
		static void saveTellerOpenLog(string);
		
	public:
		Audit();
		static void openAccLog(Teller*, Client*);
		static void loginLog(int, string);
};

#endif
