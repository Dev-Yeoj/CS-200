//Client.cpp
#include"Client.h"
#include<sstream>
int bal;
Client::Client(){
	this->bal=0.0;
	setRole("Client");
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
	cout<<"Client Account\n";
	Account::print();
	cout<<"Current balance: "<<this->bal<<endl;
}

string Client::toString(){
	string output;
	string balance;
	stringstream amount;
	amount>>bal;
	balance=amount.str();
	output=Account::toString()+" "+balance;
	return output;
}

int Client::menu(){//Client menu

    int choice;
    cout <<"ATM\n"
         <<"~~~~~~~~~~~~~~~~~~\n"
         <<"1. Deposit\n"
         <<"2. Withdrawl\n"
	<<"3. View Balance\n";
	<<"4. EXIT\n";
         <<"\nEnter your choice: ";
    cin >>choice;
    return choice;
}
	do
  { //choice controlled system
        system("CLS");
        option = menu();
        switch(option)
        {
                      case 1:cout << "Enter Amount";
			cin >> transaction;
			Deposit();
                           break;
                      case 2:cout << "Enter Amount";
                           cin >> transaction;
			Withdraw();
                           break;
                      case 3:viewBal();
			cout << "" <<bal<<"\n";
                           break;
                      case 4: cout <<"Goodbye";
                           break;
                      default: cout << "Invalid option!\n";
        }
        
        system("PAUSE");
    }while(option != 4);
}
