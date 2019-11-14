//Client.cpp
#include"Client.h"
#include<string>
Client::Client(){
	this->bal=0.0;
	setRole("Client");
}
Client::Client(string ID, string pswd){
	this->bal=0;
	setID(ID);
	setPass(pswd);
	setRole("Client");
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
	output=Account::toString()+" "+std::to_string(bal); //needs fixing how to convert double to string
	return output;
}
