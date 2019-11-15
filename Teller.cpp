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
	string id, pswd;
	int choice;
	cout<<"Please enter Clients ID and password: ";
	cin>>id, pswd;
	for(i=0; i<BankingProject->count;i++){
		if(BankingProject->accPTR[i].getRole()=="Client"){
			if(BankingProject->accPTR[i].getID()==id && BankingProject->accPTR[i].getPass()==pswd){
				do{
					choice=BankingProject->accPTR[i].menu();
					switch(choice){
						case 1://...
					}
					system("CLS");
				}while(choice!=4);
				
			}
		}
	}	
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

int Teller::menu(){//teller menu

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
do
    {//choice controlled system
        system("CLS");
        option = menu();
        switch(option)
        {
                      case 1:addClient();
                           break;
                      case 2: 
			openAccount();
                           break;
                      case 3:
                           viewLog();
                           break;
                      case 4: cout <<"Goodbye";
                           break;
                      default: cout << "Invalid option!\n";
        }
        
        system("PAUSE");
    }while(option != 4);
}
