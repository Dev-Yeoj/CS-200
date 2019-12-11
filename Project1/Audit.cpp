//Audit.cpp
#include"Audit.h"
#include<ctime>

Audit::Audit() {
	
}

string Audit::getSysTime() {
	time_t tt;																     
	time (&tt);															         
    struct tm* local; 														     
	local = localtime(&tt);												         
	return asctime(local);
}

//Run this method directly after a account is opened by a Teller.
//Example: Audit::openAccLog(telPTR[j], cliPTR[x]);
void Audit::logOpenCli(Teller* tel, Client* cli) {	
	string telOpenData = tel->getRole()+": "+tel->getFullNm()+" opened client's "+cli->getFullNm()+" on "+getSysTime();
	saveCliOpenLog(telOpenData);
}			

//Run this method directly after a user logs in.
//Example: Audit::loginLog(accPTR[i].getRole, accPTR[i].getFullNm);
void Audit::logLogin(int roleInt, string fullNm) {
										     
	getSysTime();
	string roleString = "";
	
	switch(roleInt) {
		case 1:
			roleString = "Admin";
			break;
		case 2:
			roleString = "Teller";
			break;
		case 3:
			roleString = "Client";
			break;
	}
	
	string loginData = roleString + ", " + fullNm + " logged on at " + getSysTime();
	saveLoginLog(loginData);
}				

//run to save any logins
void Audit::saveLoginLog(string loginData) {
	ofstream outData;
	outData.open("loginLog.txt", ios::app);
	outData<<loginData;
	outData.close();	
}

//run to save when a teller accesses a client
void Audit::saveCliOpenLog(string telOpenData) {
	ofstream outData;
	outData.open("telOpenLog.txt", ios::app);
	outData<<telOpenData;
	outData.close();
}


/*
int main() {
	cout << Audit::loginLog(1, "Bla Magee");
	return 0;
}
*/
