#ifndef ACCOUNT_H 
#define ACCOUNT_H
#include <string>
using namespace std; 

//SUPERCLASS ACCOUNT
class Account
{

public: 
	//Should be private but dont work. 

	int  account_no;
	string customer_fname;
	string customer_lname;
	double balance; 

public:

	Account(); 
    Account(int accNo, string custfname, string custlname, double accbal); 

	virtual void display_accountinfo();
	virtual void deposit();
	virtual void withdraw(); 
	void get_accountinfo();
	double view_balance(); 
};



//SUBCLASS CURRENT ACCOUNT
class CurrentAccount : public Account
{

public: 
	//Should be private but dont work. 

	int  account_no;
	string customer_fname;
	string customer_lname;
	double balance; 
	double overdraft; 

public:

	CurrentAccount(); 
    CurrentAccount(int accNo, string custfname, string custlname, double accbal, double odraft); 

	void get_accountinfo();
	void display_accountinfo();
	void deposit();
	void withdraw();  
	double view_balance(); 
};



//SUBCLASS SAVINGS ACCOUNT
class SavingsAccount : public Account
{

public: 
	//Should be private but dont work. 

	int  account_no;
	string customer_fname;
	string customer_lname;
	double balance; 
	double interestrate; 
 

public:

	SavingsAccount(); 
    SavingsAccount(int accNo, string custfname, string custlname, double accbal, double interest); 

	void get_accountinfo();
	void display_accountinfo();
	void withdraw();
	void deposit(); 
	double view_balance();

};



//SUBCLASS FIXED TERM DEPOSIT ACCOUNT
class FixedTermAccount : public Account
{

public: 
	//Should be private but dont work. 

	int  account_no;
	string customer_fname;
	string customer_lname;
	double balance; 
	double interestrate; 
	int years; 
 

public:

	FixedTermAccount(); 
    FixedTermAccount(int accNo, string custfname, string custlname, double accbal, double interest, int yrs); 

	void get_accountinfo();
	void display_accountinfo();
	void withdraw();  
	void deposit(); 
	double view_balance();

};


#endif


