//Audit.cpp
#include"Audit.h"
#include<ctime>
Audit::Audit() {
	
}
void Audit::openAccLog(Teller* tel, Client* cli) {
	
	//This part is optional since we haven't learned how to do this yet in class.//
	time_t tt;																     //
	time (&tt);															         //
    struct tm* ti; 														     //
	ti = localtime(&tt);												         //
	string currentTime = asctime(ti);										     //
	//***************************************************************************//
	//Here is a link for where I found this info https://www.geeksforgeeks.org/c-program-print-current-day-date-time/
	
	
	
	string telOpenData = tel->getRole()+": "+tel->getFullNm()+" opened client's "+cli->getFullNm()+" on "+currentTime;
	Audit::saveTellerOpenLog(telOpenData);
}			

//Run this method directly after a user logs in.
//Example: Audit::loginLog(accPTR(i).getRole, accPTR(i).getFullNm);
void Audit::loginLog(int roleInt, string fullNm) {
	
	//This part is optional since we haven't learned how to do this yet in class.//
	time_t tt;																     //
	time (&tt);															         //
    struct tm * ti; 														     //
	ti = localtime(&tt);												         //
	string currentTime = asctime(ti);										     //
	//***************************************************************************//
	//Here is a link for where I found this info https://www.geeksforgeeks.org/c-program-print-current-day-date-time/
	
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
