//Audit.h
#include<iostream>
#include<fstream>

using namespace std;
#ifndef AUDIT_H
#define AUDIT_H
class Audit {
	private:
		static void saveLoginLog(string);
		
	public:
		Audit();
		static void loginLog(int, string);
};

#endif
