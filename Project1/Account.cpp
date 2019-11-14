//Account.cpp
#include"Account.h"

Account::Account(){
	setID("");
	setFullNm("","");
	setDOB("");
}

void Account::setID(string id){
	this->userID=id;
}

void Account::setPass(string pswd){
	this->password=pswd;
}

void Account::setFullNm(string first,string last){
	this->firstName=first;
	this->lastName=last;
}

void Account::setDOB(string dob){
	this->DOB=dob;
}

string Account::getID(){
	return userID;
}

string Account::getPass(){
	return password;
}

string Account::getFullNm(){
	return firstName+lastName;
}

string Account::getDOB(){
	return DOB;
}

void Account::print(){
	//inprogress
}

string Account::toString(){
	//inprogress
	return "";
}
