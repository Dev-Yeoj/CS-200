//Teller.cpp
#include"Teller.h"

Teller::Teller(){
	setRole(2);
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

void Teller::viewLog(){
	ifstream inData;
	string data;
    inData.open("loginLog.txt");
    system("CLS");
	while (!inData.eof()) {
		getline(inData, data);
		cout<<data<<endl;
	}
	inData.open("telOpenLog.txt");
	while (!inData.eof()) {
		getline(inData, data);
		cout<<data<<endl;
	}
	system("PAUSE");
	inData.close();
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

    int choice;
    cout <<"ATM\n"
         <<"~~~~~~~~~~~~~~~~~~\n"
         <<"1. Add client\n"
         <<"2. Open Account\n" //turns to client menu
         <<"3. View log\n" //Audit
         <<"4. EXIT\n"
         <<"\nEnter your choice: ";
    cin >>choice;
    return choice;
}
