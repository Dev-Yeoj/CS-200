//Admin.cpp
#include"Admin.h"

Admin::Admin(){
	setRole("Admin");
}

Client* Admin::addClient(string ID, string pswd){
	Client* a1 = new Client;
	a1->setID(ID);
	a1->setPass(pswd);
	string dob, first, last;
	cout<<"Please enter First name, last name, and date of birth for new client: ";
	cin>> first, last, dob;
	a1->setDOB(dob);
	a1->setFullNm(first, last);
	return a1;
}

void Admin::addTeller(string ID, string pswd){
	//inprogress
}

void Admin::addAdmin(string ID, string pswd){
	//inprogress
}

void Admin::viewLog(){
	//inprogress
}

void Admin::print(){
	cout<<"Admin Account\n";
	Account::print();
}

string Admin::toString(){
	string output;
	output=Account::toString();
	return output;
}
