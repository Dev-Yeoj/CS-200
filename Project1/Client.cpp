//Client.cpp
#include"Client.h"

Client::Client(){
	this->bal=0.0;
}
Client::Client(string ID, string pswd){
	this->bal=0;
	setID(ID);
	setPass(pswd);
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
	//inprogress
}

string Client::toString(){
	//inprogress
	return "";
}
