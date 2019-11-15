//Admin.cpp
#include"Admin.h"

Admin::Admin(){
	setRole("Admin");
}

Client* Admin::addClient(){
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

Teller* Admin::addTeller(){
	Teller* a1 = new Teller;
	string dob, first, last, ID, pswd;
	cout<<"Please enter User ID, Password, First name, last name, and date of birth for new teller: ";
	cin>> ID>> pswd>> first>> last>> dob;
	a1->setID(ID);
	a1->setPass(pswd);
	a1->setDOB(dob);
	a1->setFullNm(first, last);
	return a1;
}

Admin* Admin::addAdmin(){
	Admin* a1 = new Admin;
	string dob, first, last, pswd, ID;
	cout<<"Please enter User ID, Password, First name, last name, and date of birth for new admin: ";
	cin>> ID>> pswd>> first>> last>> dob;
	a1->setID(ID);
	a1->setPass(pswd);
	a1->setDOB(dob);
	a1->setFullNm(first, last);
	return a1;
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

int Admin::menu(){
	return 0;
}
