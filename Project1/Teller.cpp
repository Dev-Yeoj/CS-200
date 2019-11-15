//Teller.cpp
#include"Teller.h"

Teller::Teller(){
	setRole("Teller");
}

Client* Teller::addClient(){
	Client* a1 = new Client;
	string dob, first, last, ID, pswd;
	cout<<"Please enter User ID, Password, First name, last name, and date of birth for new client: ";
	cin>> ID>> pswd>> first>> last>> dob;
	a1->setID(ID);
	a1->setPass(pswd);
	a1->setDOB(dob);
	a1->setFullNm(first, last);
	return a1;
}

void Teller::openAccount(){//ask for username and password call menu
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

int Teller::menu(){
	return 0;
}
