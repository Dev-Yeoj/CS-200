//Account.cpp
#include"Account.h"

Account::Account(){
	setID("");
	setFullNm("","");
	setDOB("");
	setRole(0);
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

void Account::setRole(int role){
	this->role=role;
}

int Account::getRole(){
	return this->role;
}

string Account::getID(){
	return userID;
}

string Account::getPass(){
	return password;
}

string Account::getFullNm(){
	return firstName+" "+lastName;
}

string Account::getDOB(){
	return DOB;
}

void Account::print(){//does not print password
	cout<<"Account ID: "<<this->userID<<"\n"
		<<"Account holder: "<<this->firstName<<" "<<this->lastName<<" "
		<<"DOB: "<<this->DOB<<endl;
}

string Account::toString(){
	string output;
	output= this->userID+" "+this->password+" "+this->firstName+" "+this->lastName+" "+this->DOB;
	return output;
}
int menu(){
	return 0;
}
