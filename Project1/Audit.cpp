//Audit.cpp
#include"Audit.h"
#include<ctime>
Audit::Audit() {
	
}
void Audit::openAccLog(Teller* tel, Client* cli) {
	
	time_t tt;																     
	time (&tt);															         
    struct tm* ti; 														     
	ti = localtime(&tt);												         
	string currentTime = asctime(ti);										     
	
	string telOpenData = tel->getRole()+": "+tel->getFullNm()+" opened client's "+cli->getFullNm()+" on "+currentTime;
	Audit::saveTellerOpenLog(telOpenData);
}			

//Run this method directly after a user logs in.
//Example: Audit::loginLog(accPTR(i).getRole, accPTR(i).getFullNm);
void Audit::loginLog(int roleInt, string fullNm) {
	
	time_t tt;																     
	time (&tt);															         
    struct tm * ti; 														     
	ti = localtime(&tt);												         
	string currentTime = asctime(ti);										     
	
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
	
	string loginData = roleString + ", " + fullNm + " logged on at " + currentTime;
	Audit::saveLoginLog(loginData);
}				

void Audit::saveLoginLog(string loginData) {
	ofstream outData;
	outData.open("loginLog.txt", ios::app);
	outData<<loginData;
	outData.close();	
}

void Audit::saveTellerOpenLog(string telOpenData) {
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
