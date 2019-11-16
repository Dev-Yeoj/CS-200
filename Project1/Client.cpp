//Client.cpp
#include"Client.h"
#include<sstream>
Client::Client(){
	this->bal=0.0;
	setRole(3);
}

double Client::getBal(){
	return this->bal;
}

void Client::deposit(double amount){
	this->bal+= amount;
}

void Client::withdraw(double amount){
	if(amount>this->bal){
		cout<<"Overdrawn! Cannot complete"<<endl;
	}
	else{
		this->bal-=amount;
	}
}

void Client::print(){
	cout<<"Client Account\n";
	Account::print();
	cout<<"Current balance: "<<this->bal<<endl;
}

string Client::toString(){
	string output;
	string balance;
	stringstream amount;
	amount>>bal;
	balance=amount.str();
	output=Account::toString()+" "+balance;
	return output;
}

int Client::menu(){

    int choice;
    cout <<"ATM\n"
         <<"~~~~~~~~~~~~~~~~~~\n"
         <<"1. Deposit\n"
         <<"2. Withdrawl\n"
		 <<"3. View Balance\n"
  		 <<"4. EXIT\n"
         <<"\nEnter your choice: ";
    cin >>choice;
    return choice;
}
