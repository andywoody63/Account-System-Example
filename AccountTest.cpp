#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Account.h"
using namespace std; 

//Array of objects. 
CurrentAccount curacc[20]; 
SavingsAccount savacc[20]; 
FixedTermAccount ftdacc[20]; 


////////////////////////////////WRITING TO FILE

void writeToCurrent() //Function to write from curacc array to CurrentAccount text file
{
	ofstream fout;
	fout.open("CurrentAccount.txt", ios::out);

    if (fout.is_open()) //if file is open then write to file. 
	{
		for(int i =0; i<20; i++) //loops through all whole curacc array. 
		{			
		fout << curacc[i].account_no << " ";
		fout << curacc[i].customer_fname << " ";
		fout << curacc[i].customer_lname << " ";
		fout << curacc[i].overdraft<< " ";
		fout << curacc[i].balance << endl;
		}
		fout.close();
	}
}

void writeToSavings() //Function to write from savacc array to SavingsAccount text file
{
	ofstream fout;
	fout.open("SavingsAccount.txt", ios::out);
	
	if (fout.is_open()) //if file is open then write to file. 
	{
		for(int x =0; x<20; x++) //loops through all whole savacc array. 
		{
		fout << savacc[x].account_no << " ";
		fout << savacc[x].customer_fname<< " ";
		fout << savacc[x].customer_lname << " ";
		fout << savacc[x].interestrate<< " ";
		fout << savacc[x].balance<< endl;
		}
		fout.close();
	}
}

void writeToFixedTerm() //Function to write from ftdacc array to Fixed Term text file
{
	ofstream fout;
	fout.open("FixedTermAccount.txt", ios::out);
	
	if (fout.is_open()) //if file is open then write to file. 
	{
		for(int y =0; y<20; y++) //loops through all whole ftdacc array. 
		{
		fout << ftdacc[y].account_no << " " ; 
		fout << ftdacc[y].customer_fname << " "; 
		fout << ftdacc[y].customer_lname << " ";
		fout << ftdacc[y].interestrate<< " "; 
		fout << ftdacc[y].years << " ";
		fout << ftdacc[y].balance << endl;
		}
		fout.close();
	}
}


////////////////////////////////READING FROM FILE  

void readSavingsAccount() //Function to read from Savings Account text file into savacc array
{
	int i;
	ifstream fin;

	fin.open("SavingsAccount.txt",ios::in);

	if (! fin.is_open()) //if error then display error message. 
	{ 
		cout << "Error Opening File!"; exit (1); 
	}

	while (! fin.eof() ) //if file is open then read from file. 
	{
		for(i =0; i<20;i++) 
		{
  		fin >> savacc[i].account_no >> 
			   savacc[i].customer_fname >> 
			   savacc[i].customer_lname >> 
			   savacc[i].interestrate >> 
			   savacc[i].balance; 
		}
	}
	fin.close();
}

void readCurrentAccount() //Function to read from Current Account text file into curacc array
{
	int i;
	ifstream fin;

	fin.open("CurrentAccount.txt",ios::in);

	if (! fin.is_open()) //if error then display error message. 
	{ 
		cout << "Error Opening File!"; exit (1); 
	}

	while (! fin.eof() ) //if file is open then read from file. 
	{
		for(i =0; i<20;i++)
		{
  		fin >> curacc[i].account_no >> 
			   curacc[i].customer_fname >> 
			   curacc[i].customer_lname >> 
			   curacc[i].overdraft >> 
			   curacc[i].balance; 
		}
	}
	fin.close();
}

void readFixedTermAccount() //Function to read from Fixed Term Account text file into ftdacc array
{
	int i;
	ifstream fin;

	fin.open("FixedTermAccount.txt",ios::in);

	if (! fin.is_open()) //if error then display error message. 
	{ 
		cout << "Error Opening File!"; exit (1); 
	}

	while (! fin.eof() ) //if file is open then read from file. 
	{
		for(i =0; i<20;i++) 
		{
  		fin >> ftdacc[i].account_no >> 
			   ftdacc[i].customer_fname >> 
			   ftdacc[i].customer_lname >> 
			   ftdacc[i].interestrate >> 
			   ftdacc[i].years >> 
			   ftdacc[i].balance; 
		}
	}
	fin.close();
}

///////////////////////////////////////MAIN

void main() 
{

	//read in from file..
	readSavingsAccount(); 
	readCurrentAccount();
	readFixedTermAccount();

		int ch, ch2, ch3, ch4, accType, accNum, counter, counter2, counter3; 
	
///////////////////////////////////////////////////////////MAIN MENU
	    cout << endl; 
        cout << "UMAI Customer Accouts System" << endl; 
        cout << "----------------------------" << endl; 
		cout << "1 - UMAI Employee" << endl; 
		cout << "2 - Customer" << endl; 

		cin >> ch;


//////////////////////////////////////////////////////////////////////EMPLOYEE MENU
		if(ch == 1)
		{
			system("CLS");
			cout << "1 - New Customer" << endl; 
			cout << "2 - Exisiting Customer";

			cin >> ch2; 

//////////////////////////////NEW CUSTOMER
			if(ch2 == 1)
			{
				system("CLS");
				cout << "Select account type.." << endl; 
				cout << "1 - Current account" << endl; 
				cout << "2 - Savings account" << endl; 
				cout << "3 - Fixed term deposit account" << endl;

				cin >> accType; 
				counter = 0; counter2 = 0; counter3 = 0; 

				if (accType == 1)									//if account type is 1(Current), then...
				{
					for (counter = 0; counter<20; counter++)
					{
						if(curacc[counter].account_no ==0)			//find next position in array which is free
						{
							curacc[counter].get_accountinfo();		//get account information for curracc array of type object. 
							break;									//break if statment, where position containing 0 is 
						}
					}
				}


				if (accType == 2)									//if account type is 2(Savings), then...
				{
					for (counter2 = 0; counter2<20; counter2++)
					{
						if(savacc[counter2].account_no ==0)			//find next position in array which is free
						{
							savacc[counter2].get_accountinfo();		//get account information for savracc array of type object. 
							break;									//break if statment, where position containing 0 is  
						}
					}
				}

				if (accType == 3)									//if account type is 3(Fixed Term), then...  
				{
					for (counter3 = 0; counter3<20; counter3++)
					{
						if(ftdacc[counter3].account_no ==0)		    //find next position in array which is free
						{
							ftdacc[counter3].get_accountinfo();		//get account information for ftdacc array of type object. 
							break;									//break if statment, where position containing 0 is  
						}
					}
				}
			}
			else
			{
//////////////////////////////EXSISTING CUSTOMER

				system("CLS");
				cout << "What is your Account Type?" << endl; 
				cout << "1 - Current account" << endl; 
				cout << "2 - Savings account" << endl; 
				cout << "3 - Fixed term deposit account" << endl;

				cin >> accType; 

				if (accType == 1)   
				{
					system("CLS");
					cout << "What is your account number? "; 
					cin >> accNum; 
				
					for(int x=0; x<20; x++) //for loop to loop through curacc to search for accNum 
					{
						if(curacc[x].account_no == accNum)
						{
							cout << "Account Found!" << endl << endl; 
							counter = x; 
						}
					}
				}
				if (accType == 2)   
				{
					system("CLS");
					cout << "What is your account number? "; 
					cin >> accNum; 
				
					for(int x=0; x<20; x++) //for loop to loop through savacc to search for accNum 
					{
						if(savacc[x].account_no == accNum)
						{
							cout << "Account Found!" << endl << endl; 
							counter2 = x; 
						}
					}
				}
				if (accType == 3)
				{
					system("CLS");
					cout << "What is your account number? "; 
					cin >> accNum; 
				
					for(int x=0; x<20; x++) //for loop to loop through ftdacc to search for accNum 
					{
						if(ftdacc[x].account_no == accNum)
						{
							cout << "Account Found!" << endl << endl; 
							counter3 = x; 
						}
					}	
				} 
			}
			

///////////////////REPEAT EMPLOYEE MENU TILL EXIT
			do 
			{
				cout << "Employee Menu" << endl; 
				cout << "-------------------------------------" << endl; 
				cout << "1 - View Account Details" << endl; 
				cout << "2 - Current Balance" << endl; 
				cout << "3 - Make Deposit" << endl; 
				cout << "4 - Make Withdrawal" << endl;
				cout << "5 - Exit" << endl; 

				cin >> ch3; 

				switch(ch3)
				{
				case 1: 
					system("CLS");
					if (accType == 1){ curacc[counter].display_accountinfo();  } 
					if (accType == 2){ savacc[counter2].display_accountinfo();  } 
					if (accType == 3){ ftdacc[counter3].display_accountinfo();  } 
					break; 

				case 2: 
					system("CLS");
					if (accType == 1){ curacc[counter].view_balance();  } 
					if (accType == 2){ savacc[counter2].view_balance();  } 
					if (accType == 3){ ftdacc[counter3].view_balance();  } 
					break; 

				case 3:
					system("CLS");
					if (accType == 1){ curacc[counter].deposit(); } 
					if (accType == 2){ savacc[counter2].deposit(); } 
					if (accType == 3){ ftdacc[counter3].deposit(); } 
					break; 

				case 4: 
					system("CLS");
					if (accType == 1){ curacc[counter].withdraw(); } 
					if (accType == 2){ savacc[counter2].withdraw(); } 
					if (accType == 3){ ftdacc[counter3].withdraw(); }
					break; 
				}
			}while(ch3 < 5);

//////////////////////////////////////////////////////////////////////CUSTOMER MENU
		}
		if (ch == 2)
		{
				system("CLS");
				cout << "What is your Account Type?" << endl; 
				cout << "1 - Current account" << endl; 
				cout << "2 - Savings account" << endl; 
				cout << "3 - Fixed term deposit account" << endl;

				cin >> accType; 
			
				if (accType == 1)   
				{
					system("CLS");
					cout << "What is your account number? "; 
					cin >> accNum; 
				
					for(int x=0; x<20; x++) //for loop to loop through curacc to search for accNum 
					{
						if(curacc[x].account_no == accNum)
						{
							cout << "Account Found!" << endl << endl; 
							counter = x; 
						}
					}
				}
				if (accType == 2)   
				{
					system("CLS");
					cout << "What is your account number? "; 
					cin >> accNum; 
				
					for(int x=0; x<20; x++) //for loop to loop through savacc to search for accNum 
					{
						if(savacc[x].account_no == accNum)
						{
							cout << "Account Found!" << endl << endl; 
							counter2 = x; 
						}
					}
				}
				if (accType == 3)
				{
					system("CLS");
					cout << "What is your account number? "; 
					cin >> accNum; 
				
					for(int x=0; x<20; x++) //for loop to loop through ftdacc to search for accNum 
					{
						if(ftdacc[x].account_no == accNum)
						{
							cout << "Account Found!" << endl << endl; 
							counter3 = x; 
						}
					}	
				} 
			
/////////////////////////////////////////////REPEAT CUSTOMER MENU UNTIL CLOSE	
			do
			{
				cout << "Customer Menu" << endl; 
				cout << "---------------------------" << endl; 
				cout << "1 - View Account Details" << endl;
				cout << "2 - Current Balance" << endl; 
				cout << "3 - Make Deposit" << endl; 
				cout << "4 - Make Withdrawal" << endl;
				cout << "5 - Exit" << endl; 

				cin >> ch4; 

				switch(ch4)
				{
				case 1: 
					system("CLS");
					if (accType == 1){ curacc[counter].display_accountinfo();  } 
					if (accType == 2){ savacc[counter2].display_accountinfo();  } 
					if (accType == 3){ ftdacc[counter3].display_accountinfo();  } 
					break; 

				case 2: 
					system("CLS");
					if (accType == 1){ curacc[counter].view_balance();  } 
					if (accType == 2){ savacc[counter2].view_balance();  } 
					if (accType == 3){ ftdacc[counter3].view_balance();  } 
					break; 

				case 3: 
					system("CLS");
					if (accType == 1){ curacc[counter].deposit(); } 
					if (accType == 2){ savacc[counter2].deposit(); } 
					if (accType == 3){ ftdacc[counter3].deposit(); } 
					break; 


				case 4: 
					system("CLS");
					if (accType == 1){ curacc[counter].withdraw(); } 
					if (accType == 2){ savacc[counter2].withdraw(); } 
					if (accType == 3){ ftdacc[counter3].withdraw(); }
					break; 
				}
			}while(ch4 < 5); //repeat do while until 5 is pressed, 5 = exit. 
		}	
	
//Write to File..
writeToCurrent();
writeToSavings();
writeToFixedTerm(); 

}