//Teller.cpp
#include"Teller.h"

Teller::Teller(){
	setRole("Teller");
}

Teller::Teller(string ID, string pswd){
	setID(ID);
	setPass(pswd);
	setRole("Teller");
}

void Teller::addUser(string ID, string pswd){
	//inprogress
}

void Teller::openAccount(string ID, string pswd){
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
