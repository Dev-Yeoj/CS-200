#include <iostream>
#include"Account.h"
#include <cstdlib>
#include <fstream>
#include"Client.h"
#include"Teller.h"
#include"Admin.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Account* accPTR[100];
int count=0;


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
	char key = 'q' //Key to be used with XOR algorithm
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
	int choice;
	int flag;
	string id, pswd;
	//decrypt and load
	
	//login & menu
	do{
		flag=1;
		cout<<"Please enter account ID and password(to exit program leave blank): ";
		cin>>id, pswd;
		for(i=0; i<count;i++){
			if(accPTR[i].getID()==id && accPTR[i].getPass()==pswd){
				do{
					choice=accPTR[i].menu();
					switch(accPTR[i].getRole()){
						case "Admin":
							swtich(choice){
								case 1: //...
							}
							break;
						case "Teller":
							swtich(choice){
								case 1: //...
							}
							break;
						case "Client":
							swtich(choice){
								case 1: //...
							}
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
