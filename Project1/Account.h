//Account.h
#include<string>
#include<iostream>

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
		int role;
		
	public:
		Account();
		string getID();
		string getPass();
		string getFullNm();
		string getDOB();
		int getRole();
		void setRole(int);
		void setID(string);
		void setPass(string);
		void setFullNm(string, string);
		void setDOB(string);
		virtual void print()=0;
		virtual string  toString()=0;
		virtual int menu()=0;
};

#endif
