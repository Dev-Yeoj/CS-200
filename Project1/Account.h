//Account.h
#include<iostream>
#include<string>

using namespace std;
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
	private:
		string userID;
		string firstName;
		string lastName;
		string DOB;
		string password;
		string role;
		
	public:
		Account();
		string getID();
		string getPass();
		string getFullNm();
		string getDOB();
		string getRole();
		void setRole(string);
		void setID(string);
		void setPass(string);
		void setFullNm(string, string);
		void setDOB(string);
		void virtual print()=0;
		string virtual toString()=0;
		int virtual menu()=0;
};

#endif
