//Teller.cpp
#include"Teller.h"

Teller::Teller(){
	setRole("Teller");
}

void Teller::addUser(string ID, string pswd){
	//inprogress
}

void Teller::openAccount(string ID, string pswd){
	//inprogress
}

void Teller::viewLog(){
	//inprogress
}

void Teller::print(){
	cout<<"Teller Account\n";
	Account::print();
}

string Teller::toString(){
	string output;
	output=Account::toString();
	return output;
}
