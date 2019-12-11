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
		static string getSysTime();
		static void saveTellerOpenLog(string);
		
	public:
		Audit();
		static void logOpenCli(Teller*, Client*);
		static void logLogin(int, string);
};

#endif
