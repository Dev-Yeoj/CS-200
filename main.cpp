#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

struct PData {
	int id;
	int userType;
	string uname;
	string fname;
	string lname;
	string DOB;
	string password;
};

class Person 
{
	private:
	
	protected:
		PData data;
	public:
		Person();
		Person(struct PData data);
		~Person();
		void setID(int arg);
		int getID();
		int getUserType();
		void setUName(string arg);
		string getUName();
		void setFName(string arg);
		string getFName();
		void setLName(string arg);
		string getLName();
		void setDOB(string arg);
		string getDOB();
		void setPassword(string arg);
		string getPassword();
		struct PData dataPump();
		virtual void printOptions();
		virtual void actionSpooler(int);
};
Person::Person(){data.userType = 0;}
Person::Person(struct PData arg)
{
}
Person::~Person(){}
void Person::setID(int arg){data.id = arg;}
int Person::getID(){return data.id;}
int Person::getUserType() {return data.userType;}
void Person::setUName(string arg){data.uname = arg;}
string Person::getUName(){return data.uname;}
void Person::setFName(string arg){data.fname = arg;}
string Person::getFName(){return data.fname;}
void Person::setLName(string arg){data.lname = arg;}
string Person::getLName(){return data.lname;}
void Person::setDOB(string arg){data.DOB = arg;}
string Person::getDOB(){return data.DOB;}
void Person::setPassword(string arg){data.password = arg;}
string Person::getPassword(){return data.password;}
struct PData Person::dataPump(){return data;}
void Person::printOptions()
{
	cout << "\n1. Change Password.\n"
	     << "2. End Session\n";
}
void Person::actionSpooler(int arg)
{
	return;
}
/*****************************************************************************/
class Admin: public Person
{
	private:
	public:
		Admin();
		Admin(struct PData arg);
		void addUser();
		void delUser();
		void addTeller();
		void addAdmin();
		void printOptions();
		void actionSpooler(int);
};
Admin::Admin(){data.userType = 1;}
Admin::Admin(struct PData arg)
{
	data.userType = 1;
	data.id = arg.id;
	data.uname = arg.uname;
	data.fname = arg.fname;
	data.lname = arg.lname;
	data.DOB = arg.DOB;
	data.password = arg.password;
}
void Admin::printOptions()
{
	cout << "\n1. Add User (Not yet implemented)\n"
	     << "2. Delete User (Not yet implemented)\n"
	     << "3. Add Teller (Not yet implemented)\n"
	     << "4. Delete Teller (Not yet implemented)\n"
	     << "5. Add Administrator (Not yet implemented)\n"
	     << "6. Delete Administrator (Not yet implemented)\n"
	     << "7. Reset User Password (Not yet implemented)\n"
	     << "8. Audit system activity.\n"
	     << "9. Change Password (Not yet implemented)\n"
	     << "10. End Session (Not yet implemented)\n";
	     
}
void Admin::actionSpooler(int arg)
{
	switch(arg)
	{
		case 1:
			/* Call add user procedure */
			break;
		case 2:
			/* Call delete user procedure */
			break;
		case 3:
			/* Call add teller procedure */
			break;
		case 4:
			/* Call delete teller procedure */
			break;
		case 5:
			/* Call add administrator procedure */
			break;
		case 6:
			/* Call delete administrator procedure */
			break;
		case 7:
			/* Call reset user password procedure */
			break;
		case 8:
			/* Call display system audit log procedure */
			break;
		case 9:
			/* Call change password procedure */
			break;
		case 10:
			/* Proceed to close session gracefully. */
			break;
		default:
			cout << "Your selection is not supported!\n";
	}
}
/*****************************************************************************/
class Teller: public Person
{
	private:
		
	public:
		Teller();
		Teller(struct PData arg);
		~Teller();
		void printOptions();
		void actionSpooler(int);
		void addUser();
		void openAccount();
};
Teller::Teller(){data.userType = 2;}
Teller::Teller(struct PData arg)
{
	data.userType = 2;
	data.id = arg.id;
	data.uname = arg.uname;
	data.fname = arg.fname;
	data.lname = arg.lname;
	data.DOB = arg.DOB;
	data.password = arg.password;
}
void Teller::printOptions()
{
	cout << "\n1. Add Customer (Not yet implemented)\n"
	     << "2. Open new bank account for user (Not yet implemented)\n"
	     << "3. Close user bank account (Not yet implemented)\n"
	     << "4. View system activity (Not yet implemented)\n"
	     << "5. Change Password (Not yet implemented)\n"
	     << "6. End Session (Not yet implemented)\n";
}
void Teller::actionSpooler(int arg)
{
	switch(arg)
	{
		case 1:
			/* Call add user procedure */
			break;
		case 2:
			/* Call Open Bank account procedure */
			break;
		case 3:
			/* Call Close Bank Account procedure */ 
			break;
		case 4:
			/* Call View system audit log procedure */
			break;
		case 5:
			/* Call change password procedure */
			break;
		case 6:
			/* Proceed to end session gracefully */
			break;
		case 7:
			//break;
		case 8:
			//break;
		case 9:
			//break;
		case 10:
			//break;
		default:
			cout << "Your selection is not supported!\n";
	}
}
/*****************************************************************************/
class Customer: public Person
{
	private:
		int account[10];
	public:
		Customer();
		Customer(struct PData arg);
		~Customer();
		void viewAcctStatement();
		void makeAcctTransaction();
		void printOptions();
		void actionSpooler(int);
};
Customer::Customer(){data.userType = 3;}
Customer::Customer(struct PData arg)
{
	data.userType = 3;
	data.id = arg.id;
	data.uname = arg.uname;
	data.fname = arg.fname;
	data.lname = arg.lname;
	data.DOB = arg.DOB;
	data.password = arg.password;
}
void Customer::printOptions()
{
	cout << "\n1. Make Transaction (Not yet implemented)\n" 
	     << "2. View balances (Not yet implemented)\n"
	     << "3. Change Password (Not yet implemented)\n"
	     << "4. End Session (Not yet implemented)\n";
}
void Customer::actionSpooler(int arg)
{
	switch(arg)
	{
		case 1:
			/* Call select account menu */
			break;
		case 2:
			/* Call display balances procedure */
			break;
		case 3:
			/* Call change password procedure */
			break;
		case 4:
			/* Proceed to gracefully shut'er down */
			break;
		case 5:
			//break;
		case 6:
			//break;
		case 7:
			//break;
		case 8:
			//break;
		case 9:
			//break;
		case 10:
			//break;
		default:
			cout << "Your selection is not supported!\n";
	}
}
/*****************************************************************************/
class UserDB 
{
	private:
		fstream fs;
		string itos(int);
	public:
		UserDB(string Filename);
		~UserDB();
		string encryptData(string data);
		string decryptData(string data);
		streampos searchID(int uid);
		struct PData getUser(int uid);
		void putUser(struct PData data);
		void delUser();
};
string UserDB::itos(int arg){
	stringstream s;
	s << arg;
	return s.str();
}
UserDB::UserDB(string Filename)
{
	fs.open(Filename.c_str(), ios::in | ios::out | ios::binary);
	if(fs.fail())
	{
		cerr << "User database does not exist.  Generating new DB.\n";
		fs.close();
		fs.open(Filename.c_str(), ios::out);
		fs.close();
		fs.open(Filename.c_str(), ios::in | ios::out | ios::binary);
		fs << "USER_DB\n";
	}
	if(fs.fail())
	{
		cerr << "Failed to load user DB.\n";
	}
	else
	{
		cout << "User database loaded successfully.\n";
	}
}
UserDB::~UserDB(){fs.close();}
string UserDB::encryptData(string adata)
{
	// Add encryption cipher
	return adata;
}
string UserDB::decryptData(string adata)
{
	// Remove cipher.... decipher
	return adata;
}
streampos UserDB::searchID(int uid)
{
	fs.seekg(0, ios::beg);
	string tmp;
	stringstream suid;
	suid << uid;
	streampos idStart = streampos(0);
	bool idFound = false;
	while(!fs.eof()){
		idStart = fs.tellg();
		fs >> tmp;
		//cerr << "tmp: " << tmp << "\n";
		if(tmp == suid.str()){
			idFound = true;
			break;
		}
		else{
			fs.ignore(4000, '\n');
		}
	}
	if(idFound)
	{
		return idStart;
	}
	else{
		fs.clear();
		return -1;
	}
}
struct PData UserDB::getUser(int argId)
{
	struct PData x; 
	int id;
	streampos idPos = searchID(argId);
	if(idPos != -1)
	{
		fs.seekg(idPos, ios::beg);
	}
	else {
		x.id = -1;
		return x;
	}
	if(fs.fail())
	{
		cerr << "getUser reports Filestream is in error state.\n";
	}
	fs >> x.id
	   >> x.userType
	   >> x.uname
	   >> x.fname
	   >> x.lname
	   >> x.DOB
	   >> x.password;
	   
	/*cerr << x.id << "\n"
	   << x.userType << "\n"
	   << x.uname << "\n"
	   << x.fname << "\n"
	   << x.lname << "\n"
	   << x.DOB << "\n"
	   << x.password << "\n";
	*/   
	return x;
}
void UserDB::putUser(struct PData d)
{
	if(fs.fail())
	{
		cerr << "putUser reports Filestream is in error state.\n";
	}
	fs.seekg(0, ios::end);
	fs << d.id << "\t"
	   << encryptData(itos(d.userType)) << "\t"
	   << encryptData(d.uname) << "\t"
	   << encryptData(d.fname) << "\t"
	   << encryptData(d.lname) << "\t"
	   << encryptData(d.DOB) << "\t"
	   << encryptData(d.password)
	   << "\n";
}

/*****************************************************************************/
struct AData
{
	int id;
	string accttype;
	string acctnum;
	double balance; 
};
class Account
{
	private:
	
	public:
};
/*****************************************************************************/
class CheckingAcct: public Account
{
	private:
	
	public:
};
/*****************************************************************************/
class SavingsAcct: public Account
{
	private:
		
	public:
};
/*****************************************************************************/
class CreditAcct: public Account
{
	private:
		
	public:
};
/*****************************************************************************/
class AcctDB
{
	private:
		
	public:
		string encryptData();
		string decryptData();
		void getAcct();
		void putAcct();
		void delAcct();
};
/*****************************************************************************/

Person* activeUser;

string getKey(string uname, Person* uc[], int size)
{
	string key;
	bool userFound = false;
	for(int i = 0; i < size; i++)
	{
		//cerr << "uname: " << uc[i]->getUName() << "\n";
		if(uname == uc[i]->getUName())
		{
			userFound = true;
			activeUser = uc[i];
			key = uc[i]->getPassword();
			break;
		}
	}
	if(userFound)
	{
		return key;
	}
	else
	{
		return string("");
	}
}

// Subroutine function
void performLogin(Person* uC[], int userCount)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	string key = "";
	string inputName = "";
	string inputPasswd = "";
	system("cls");
	cout << "Welcome to ABC banking system.\n";
	while(1)
	{
		cout <<"\nlogin: ";
		cin >> inputName;
		cout <<"password: ";
		SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
		cin >> inputPasswd;
		key = getKey(inputName, uC, userCount);
		SetConsoleMode(hStdin, mode);
		if(key == "")
		{
			/* TODO:  GENERATE INVALID LOGIN AUDIT LOG ENTRY */
			cout << "\nInvalid login!\n";
			continue;		
		}
		if( inputPasswd == key)
		{
			break;
		}
		cout << "\nInvalid login!\n";
		/* TODO:  GENERATE INVALID LOGIN AUDIT LOG ENTRY */
	}
	cout << endl;
	return ;
}

int main(int argc, char** argv) 
{
	const int userLimit = 100;
	UserDB userDB("uDB.txt");
	Person* userCache[userLimit];
	int userCount = 0;
	string opt;
	int optInt;
	
	PData adminAudit = userDB.getUser(0);
	if(adminAudit.userType != 1)
	{
		Admin defaultAdmin;
		defaultAdmin.setID(0);
		defaultAdmin.setUName("root");
		defaultAdmin.setFName("root");
		defaultAdmin.setLName("root");
		defaultAdmin.setDOB("01/01/1970");
		defaultAdmin.setPassword("password");
		userDB.putUser(defaultAdmin.dataPump());
		cout << "Creating Default Administrator\n"
		     << "username: root\n"
		     << "password: password\n"
			 << "Please change this immediately.";
	}
	
	// Load userCache
	for(int i = 0; i < userLimit; i++)
	{
		if(userDB.searchID(i) == streampos(-1))
		{
			userCount = i;
			break;
		}
		PData tmp = userDB.getUser(i);
		switch (tmp.userType){
			case 1: //Admin
				userCache[i] = new Admin(tmp);
				break;
			case 2: // Teller
				userCache[i] = new Teller(tmp);
				break;
			case 3: // Customer
				userCache[i] = new Customer(tmp);
				break;
		}
		userCount++;
	}
	
	performLogin(userCache, userCount);
	
	//Personalize Welcome
	system("cls");
	cout << "Hello " << activeUser->getFName()
	     << ", welcome to automatic tellin0g with ABC Bank.\n";
	
	cout << "\nThe following services can be provided by this terminal:\n";
	activeUser->printOptions();
	
	cout << "\nPlease select your desired option: ";
	cin >> opt;
	optInt = atoi(opt.c_str());
	activeUser->actionSpooler(optInt); // Person class is driving now.
	
	return 0;
}
