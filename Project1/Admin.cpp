//Admin.cpp
#include"Admin.h"

Admin::Admin(){}

Admin::Admin(string ID, string pswd){
	setID(ID);
	setPass(pswd);
}
void Admin::addUser(string ID, string pswd){
	//inprogress
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
	//inprogress
	return "";
}
