#include <iostream>
#include"Account.h"
#include <cstdlib>
#include <fstream>
#include"Client.h"
#include"Teller.h"
#include"Admin.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string readAndDecrypt()
{
	char key = 'q';
	//ofstream adminsFile;
	ifstream tellersFile;
	ifstream clientsFile;
	ifstream adminsFile;
	string dataIn;
	string decryptedData;
	string space = " ";
	
	
	adminsFile.open("adminList.txt");
    getline(adminsFile,dataIn);  // Get the frist line from the file, if any.
    while ( adminsFile ){  // Continue if the line was sucessfully read.
    	//processLine(dataIn);  // Process the line.
        getline(adminsFile,dataIn);   // Try to get another line.
}
	string test;
	getline(adminsFile,test);
	cout<<test<<endl;
    for (int x = 0; x < dataIn.length(); x++)
    	{
        	decryptedData += dataIn[x] ^ key;
        }
			decryptedData += space;
	
	
	
	tellersFile.open("tellerList.txt");
    getline(tellersFile,dataIn);  // Get the frist line from the file, if any.
    while ( tellersFile ){  // Continue if the line was sucessfully read.
    	//processLine(dataIn);  // Process the line.
        getline(tellersFile,dataIn);   // Try to get another line.
}

    for (int x = 0; x < dataIn.length(); x++)
    	{
        	decryptedData += dataIn[x] ^ key;
        }
			decryptedData += space;
			
			
	clientsFile.open("clientList.txt");
    getline(clientsFile,dataIn);  // Get the frist line from the file, if any.
    while ( clientsFile ){  // Continue if the line was sucessfully read.
    	//processLine(dataIn);  // Process the line.
        getline(clientsFile,dataIn);   // Try to get another line.
}

    for (int x = 0; x < dataIn.length(); x++)
    	{
        	decryptedData += dataIn[x] ^ key;
        }

                 
                 
     
	
	
	
	return decryptedData;
	}


int saveAndEncrypt()
{
	char key = 'q'; //Key to be used with XOR algorithm
	string INFO =""; //Blank initializer for string: INFO

	ofstream adminsFile;
	ofstream tellersFile;
	ofstream clientsFile;
	//variable initialization

	//adminCount  =   The number of admins that were added
	//adminPTR    =   The pointer array of admins
	//tellerCount =   The number of tellers that were added
	//tellerPTR   =   The pointer array of tellers
	//clientCount =   The number of clients that were added
	//clientPTR   =   The pointer array of clients
	//decrypt and load

	adminsFile.open("adminList.txt");
	//In this for loop the "i" represents which admin in the array of admins
	for(int i=0; i < adminCount; i++)
	{

		//In this for loop the "x" a single character in the string of adminPTR[i]
		for (int x = 0; x <adminPTR[i].toString().length(); x++)
    		{
        		INFO += adminPTR[i].toString()[x] ^ key;
        	}
        adminsFile <<INFO<<" "; 
	}
	adminsFile.close();




	tellersFile.open("tellerList.txt");
	for(int i=0; i < tellerCount; i++)
	{
		for (int x = 0; x <tellerPTR[x].toString().length(); x++)
    		{
        		INFO += tellerPTR.toString()[x] ^ key;
        	}
        tellersFile <<INFO<<" ";
	}
	tellersFile.close();




	clientsFile.open("clientList.txt");
	for(int i=0; i < clientCount; i++)
	{
		for (int x = 0; x <clientPTR[x].toString().length(); x++)
    		{
        		INFO += clientPTR.toString()[x] ^ key;
        	}
        clientsFile <<INFO<<" ";
	}
	clientsFile.close();

	return 0;
}



int main(int argc, char** argv) {
	//variable initialization
	Account* accPTR[100];
	int count=0;
	int choice;
	int flag;
	string id, pswd;
	//decrypt and load
	
	//login & menu
	do{
		flag=1;
		cout<<"Please enter account ID and password(to exit program leave blank): ";
		cin>>id, pswd;
		for(int i=0; i<count;i++){
			if(accPTR[i]->getID()==id && accPTR[i]->getPass()==pswd){
				do{
					choice=accPTR[i]->menu();
					switch(accPTR[i]->getRole()){
						case 1://Admin
							do {//choice controlled system
							    system("Case");
							    int option = accPTR[i]->menu();
							    switch(option) {
							      case 1:addClient();
							           break;
							      case 2: addTeller();
							           break;
									case 3: addAdmin();
							           break;
							      case 4:viewLog();
							           break;
							      case 4: cout <<"Goodbye";
							      flag=0;
							           break;
							      default: cout << "Invalid option!\n";
							    }
							    
							    system("PAUSE");
							}while(option != 5);
							break;
						case 2://Teller
							string id, pswd;
							
							do { //choice controlled system
						        system("Case");
						        option = menu();
						        switch(option) {
						        	case 1:cout << "Enter Amount";
										cin >> transaction;
										Deposit(transaction);
						                break;
						            case 2:cout << "Enter Amount";
						                cin >> transaction;
										Withdraw(transaction);
						                break;
						            case 3:viewBal();
										cout << "" <<Bal<<"\n";
						                break;
						            case 4: cout <<"Goodbye";
						            	flag=0;
						                break;
						            default: cout << "Invalid option!\n";
						        }
						        
						        system("PAUSE");
						    }while(option != 4);
							break;
						case 3://Client
							do { //choice controlled system
						        system("Case");
						        option = menu();
						        switch(option) {
						        case 1:cout << "Enter Amount";
									cin >> transaction;
									accPTR[i].deposit(transaction);
						            break;
						        case 2:cout << "Enter Amount";
						            cin >> transaction;
									accPTR[i].withdraw(transaction);
						            break;
						        case 3:viewBal();
									cout << "" <<Bal<<"\n";
						            break;
						        case 4: cout <<"Goodbye";
						        	flag=0;
						            break;
						        default: cout << "Invalid option!\n";
						        }
						        
						        system("PAUSE");
						    }while(option != 4);
							break;
						default: break;
					}
				sytstem("CLS");
				}while(flag==1);
				
			}
			
		}	
	}while(id!="");
	//encrypt and write
	
	return 0;
}
