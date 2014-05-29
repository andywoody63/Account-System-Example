#include <iostream>
#include <string>
#include "Account.h"
using namespace std; 


	//////////////////////////////////////////////////////////////////////
	Account::Account(){}
	Account::Account(int accNo, string custfname, string custlname, double accbal)
	{
		account_no = accNo; 
		customer_fname = custfname;
	    customer_lname = custlname;
	    balance = accbal; 
	}

	void Account::get_accountinfo(){}

	void Account::display_accountinfo(){}

	void Account::deposit(){}

	void Account::withdraw(){}

	double Account::view_balance()
	{
		return balance; 
	}



	//////////////////////////////////////////////////////////////////////
	CurrentAccount::CurrentAccount() : Account(){}	
	CurrentAccount::CurrentAccount(int accNo, string custfname, string custlname, double accbal, double odraft ) : Account(accNo, custfname, custlname, accbal)
	{
		overdraft = odraft; 
	}
	
	void CurrentAccount::get_accountinfo()
	{ 
		cout << "Enter Account Number : ";
		cin >> account_no;
		cout << "Enter Customer First Name : ";
		cin >> customer_fname;	
		cout << "Enter Customer Last Name : ";
		cin >> customer_lname;	
		cout << "Enter Opening Balance : "; 
		cin >> balance; 
    	cout << "Enter Overdraft Limit : "; 
		cin >> overdraft; 
		cout << endl << endl; 
	}

	void CurrentAccount::display_accountinfo()
	{
		cout << endl << "Account Number : " << account_no;
	    cout << endl << "Customer First Name : " << customer_fname;
	    cout << endl << "Customer Last Name : " << customer_lname;
		cout << endl << "Balance : " << balance; 
		cout << endl << "Overdraft Limit: " << overdraft; 
		cout << endl << endl; 
	}

	void CurrentAccount::withdraw()
	{
		cout << "How much do you to withdraw? " << endl; 
		double withdraw; 
		cin >> withdraw; 
		
		if(balance + overdraft < withdraw  )
		{
			cout << "You can not go that much overdrawn, your overdraft is: " << overdraft << endl << endl; 
		}
		else
		{
			balance = balance - withdraw; 
		}
		cout << "New Balance: " << balance << endl << endl; 
	}

	void CurrentAccount::deposit()
	{
		cout << "How much do you want to deposit? "; 
		double deposit; 
		cin >> deposit; 
		balance = balance + deposit; 
		cout << "New Balance: " << balance << endl << endl; 
	}
 
	double CurrentAccount::view_balance() 
	{
		cout << "Balance: " << balance << endl << endl;  
		return balance;
	} 

	

	//////////////////////////////////////////////////////////////////////
	SavingsAccount::SavingsAccount() : Account(){}
	SavingsAccount::SavingsAccount(int accNo, string custfname, string custlname, double accbal, double interest) : Account(accNo, custfname, custlname, accbal) 
	{
		interestrate = interest; 

	}

	void SavingsAccount::get_accountinfo() 
	{		
		cout << "Enter Account Number : ";
		cin >> account_no;
		cout << "Enter Customer First Name : ";
		cin >> customer_fname;	
		cout << "Enter Customer Last Name : ";
		cin >> customer_lname;		
		cout << "Enter Opening Balance : "; 
		cin >> balance; 
		cout << "Enter Interest rate : "; 
		cin >> interestrate; 
		cout << endl << endl; 
	}

	void SavingsAccount::display_accountinfo() 
	{
		cout << endl << "Account Number : " << account_no;
	    cout << endl << "Customer First Name : " << customer_fname;
	    cout << endl << "Customer Last Name : " << customer_lname;
		cout << endl << "Balance : " << balance;  
		cout << endl << "Interest Rate: " << interestrate; 
		cout << endl << endl; 
	}

	void SavingsAccount::withdraw() 
	{
		cout << "How much do you to withdraw? " << endl; 
		double withdraw; 
		cin >> withdraw; 
		
        if(withdraw > balance)
		{
			cout << "You have insufficent funds avaliable" << endl << endl;
		}
		else
		{
			balance = balance - withdraw; 
		}
		cout << "New Balance: " << balance << endl << endl; 
	}

	void SavingsAccount::deposit() 
	{
		double deposit, interest; 
		cout << "How much do you want to deposit? "; 
		cin >> deposit; 
		balance = balance + deposit; 
		interest = (balance*interestrate) / 100;
		balance = balance + interest;
		cout << "New Balance + interest: " << balance << endl << endl; 
	} 

	double SavingsAccount::view_balance() 
	{
		cout << "Balance: " << balance << endl << endl;  
		return balance;
	}



	//////////////////////////////////////////////////////////////////////
	FixedTermAccount::FixedTermAccount() : Account(){} 
	FixedTermAccount::FixedTermAccount(int accNo, string custfname, string custlname, double accbal, double interest, int yrs) : Account(accNo, custfname, custlname, accbal) 
	{
		interestrate = interest; 
		years = yrs; 
	}

	void FixedTermAccount::get_accountinfo() 
	{
		cout << "Enter Account Number : ";
		cin >> account_no;
		cout << "Enter Customer First Name : ";
		cin >> customer_fname;	
		cout << "Enter Customer Last Name : ";
		cin >> customer_lname;		
		cout << "Enter Opening Balance : "; 
		cin >> balance; 
		cout << "Enter Interest rate : "; 
		cin >> interestrate; 
		cout << "Enter Number of Years : "; 
		cin >> years; 
		cout << endl << endl; 
	}

	void FixedTermAccount::display_accountinfo()
	{
		cout << endl << "Account Number : " << account_no;
	    cout << endl << "Customer First Name : " << customer_fname;
	    cout << endl << "Customer Last Name : " << customer_lname;
		cout << endl << "Balance : " << balance;  
		cout << endl << "Interest Rate: " << interestrate; 
		cout << endl << "Number of Years: " << years; 
		cout << endl << endl; 
	}

	void FixedTermAccount::withdraw()
	{
		cout << "How much do you to withdraw? " << endl; 
		double withdraw; 
		cin >> withdraw; 
		
        if(withdraw > balance)
		{
			cout << "You have insufficent funds avaliable" << endl << endl;
		}
		else
		{
			balance = balance - withdraw; 
		}
		cout << "New Balance: " << balance << endl << endl; 
	}

	void FixedTermAccount::deposit()
	{
		double deposit, interest; 
		cout << "How much do you want to deposit? "; 
		cin >> deposit; 
		balance = balance + deposit; 
		interest = (balance*interestrate) / 100;
		balance = balance + interest; 
     	cout << "New Balance + interest: " << balance << endl << endl; 
	}

	double FixedTermAccount::view_balance()
	{
		cout << "Balance: " << balance << endl << endl;  
		return balance;
	}











