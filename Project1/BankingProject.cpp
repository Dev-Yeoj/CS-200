#include <iostream>
#include"Account.h"
#include <cstdlib>
#include <fstream>
#include"Client.h"
#include"Teller.h"
#include"Admin.h"

//WARNING CURRENTLY WE DO NOT HAVE A METHOD TO SAVE THE AMOUNT OF USERS CREATED WHICH MEANS IF YOU CREATE A NEW ADMIN ACCOUNT YOU MAY OVERWRITE THE EXISTING
//ROOT ACCOUNT AND REPLACE IT WITH THE ACCOUNT YOU JUST MADE

//also theres no way to tell what account type the accounts that are read in from files are

//GLOBAL VARIABLES
	int cliCount=0;
	int telCount=0;
	int adCount=0;
	int count=0;
	Account* accPTR[100];
	Admin* adPTR[50];
	Teller* telPTR[50];
	Client* cliPTR[50];
	
	
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
    getline(adminsFile,dataIn);     // Get the frist line from the file, if any.
    while ( adminsFile ){           // Continue if the line was sucessfully read.
    	//processLine(dataIn);      // Process the line.
        getline(adminsFile,dataIn); // Try to get another line.
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


string saveAndEncrypt()
{
	try{
	
	char key = 'q'; //Key to be used with XOR algorithm
	string INFO =""; //Blank initializer for string: INFO

	ofstream adminsFile;
	ofstream tellersFile;
	ofstream clientsFile;
	//variable initialization

	//adCount  =   The number of admins that were added
	//adPTR    =   The pointer array of admins
	//telCount =   The number of tellers that were added
	//telPTR   =   The pointer array of tellers
	//cliCount =   The number of clients that were added
	//cliPTR   =   The pointer array of clients
	//decrypt and load

	cout<<"Saving and encrypting contents. . ."<<endl;

	adminsFile.open("adminList.txt");
	//In this for loop the "i" represents which admin in the array of admins
	for(int i=0; i < adCount; i++)
	{
		//In this for loop the "x" a single character in the string of adPTR[i]
		for (int x = 0; x <adPTR[i]->toString().length(); x++)
    		{
        		INFO += adPTR[i]->toString()[x] ^ key;
        	}
        adminsFile <<INFO<<" "; 
	}
	adminsFile.close();




	tellersFile.open("tellerList.txt");
	for(int i=0; i < telCount; i++)
	{
		for (int x = 0; x <telPTR[i]->toString().length(); x++)
    		{
        		INFO += telPTR[i]->toString()[x] ^ key;
        	}
        tellersFile <<INFO<<" ";
	}
	tellersFile.close();




	clientsFile.open("clientList.txt");
	for(int i=0; i < cliCount; i++)
	{
		for (int x = 0; x <cliPTR[i]->toString().length(); x++)
    		{
        		INFO += cliPTR[i]->toString()[x] ^ key;
        	}
        clientsFile <<INFO<<" ";
	}
	clientsFile.close();
}

	catch( const std::exception & ex ){
    cerr << ex.what() << endl;
	}

	return "Contents saved and encrypted!";
}

bool doesExist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

string makeRoot(){
	adPTR[adCount]=adPTR[0]->addAdmin();
	accPTR[count]=adPTR[cliCount];
	adCount++;
	count++;
	return "\nRoot created.";
}

int main(int argc, char** argv) {
	//variable initialization
	//MOVED ARRAYS AND COUNTERS TO GLOBAL
	
	int option;
	int flag;
	string id, pswd;
	double transaction;
	string cliID; 
	string cliPSWD;
	int opt2;
	//Check for root account
	if(doesExist("adminList.txt") && doesExist("clientList.txt") && doesExist("tellerList.txt")){
		cout<<"Root account exists, moving to login page. . ."<<endl;
	}
	else{
		cout<<"Root account does not exist. Lets create one.\n"<<endl;
		//root account creation function
		cout<<makeRoot()<<endl;
		saveAndEncrypt();
		cout<<"Please restart program :)"<<endl;
		exit(0);
	}
	
	//decrypt and load
	cout<<"Read and decrypted data: "<<readAndDecrypt()<<endl;
	//login & menu
	do{
		flag=1;
		cout<<"Please enter account ID and password(to exit program leave blank): ";
		cin>>id, pswd;
		for(int i=0; i<count;i++){
			if(accPTR[i]->getID()==id && accPTR[i]->getPass()==pswd){
				do{
					switch(accPTR[i]->getRole()){
						case 1://Admin
							for(int j=0; i<adCount;i++){
							if(adPTR[j]->getID()==id && adPTR[j]->getPass()==pswd){
								do {//choice controlled system
							    	system("CLS");
							    	option = adPTR[j]->menu();
							    	switch(option) {
							    		case 1:cliPTR[cliCount]=adPTR[j]->addClient();
							    			accPTR[count]=cliPTR[cliCount];
							    			cliCount++;
							    			count++;
							           		break;
							      		case 2: telPTR[telCount]=adPTR[j]->addTeller();
							      			accPTR[count]=telPTR[telCount];
							    			telCount++;
							    			count++;
							           		break;
										case 3: adPTR[adCount]=adPTR[j]->addAdmin();
											accPTR[count]=adPTR[cliCount];
							    			adCount++;
							    			count++;
							           		break;
							      		case 4:adPTR[j]->viewLog();
							           		break;
							      		case 5: cout <<"Goodbye";
							      			flag=0;
							           		break;
							      		default: cout << "Invalid option!\n";
							      	}
							      }while(option != 5);
							    }
							    system("PAUSE");
							}
							break;
						case 2://Teller
							for(int j=0; i<telCount;i++){
							if(telPTR[j]->getID()==id && telPTR[j]->getPass()==pswd){
								do {//choice controlled system
							    	system("CLS");
							    	option = telPTR[j]->menu();
							    	switch(option) {
							    		case 1:cliPTR[cliCount]=telPTR[j]->addClient();
							    			accPTR[count]=cliPTR[cliCount];
							    			cliCount++;
							    			count++;
							           		break;
							      		case 2: //open account
											cout<<"Please enter Clients ID and password: ";
											cin>>cliID, cliPSWD;
											for(int x=0; x<cliCount;x++){
												if(cliPTR[x]->getID()==cliID && cliPTR[x]->getPass()==cliPSWD){
													do { //choice controlled system
						    		    				system("CLS");
						    		    				opt2 = cliPTR[x]->menu();
						    		    				switch(opt2) {
						    			    				case 1:cout << "Enter Amount";
																cin >> transaction;
																cliPTR[x]->deposit(transaction);
																break;
						       								case 2:cout << "Enter Amount";
						            							cin >> transaction;
																cliPTR[x]->withdraw(transaction);
						           			 					break;
						        							case 3:cliPTR[x]->getBal();
																cout << "Current Balance: " <<cliPTR[x]->getBal()<<"\n";
						            							break;
						        							case 4: cout <<"Goodbye";
						        	    						break;
						        							default: cout << "Invalid option!\n";
						        						}
						    						}while(opt2 != 4);
						    						system("PAUSE");
												}
						    				}//end of open account
							           		break;
										case 3: telPTR[j]->viewLog();
							           		break;
							      		case 4: cout <<"Goodbye";
							      			flag=0;
							           		break;
							      		default: cout << "Invalid option!\n";
							      	}
							      }while(option != 4);
							    }
							    system("PAUSE");
							}
							break;
						case 3://Client
							for(int j=0; i<cliCount;i++){
								if(cliPTR[j]->getID()==id && cliPTR[j]->getPass()==pswd){
									do { //choice controlled system
						    		    system("CLS");
						    		    option = cliPTR[j]->menu();
						    		    switch(option) {
						    			    case 1:cout << "Enter Amount";
												cin >> transaction;
												cliPTR[j]->deposit(transaction);
						    		   	    	break;
						       				case 2:cout << "Enter Amount";
						            			cin >> transaction;
												cliPTR[j]->withdraw(transaction);
						           			 	break;
						        			case 3:cliPTR[j]->getBal();
												cout << "Current Balance: " <<cliPTR[j]->getBal()<<"\n";
						            			break;
						        			case 4: cout <<"Goodbye";
						        				flag=0;
						        	    		break;
						        			default: cout << "Invalid option!\n";
						        		}
						    		}while(option != 4);
						    	system("PAUSE");
								}
						    }
							break;
						default: break;
					}
				system("CLS");
				}while(flag==1);
			}
		}	
	}while(id!="");//This is correct but the program does not exit because CIN doesn't input blank spaces.
	//encrypt and write
	
	cout<<saveAndEncrypt();
	return 0;
}
