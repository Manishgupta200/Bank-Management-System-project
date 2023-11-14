#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#include "address.h"
#pragma warning(disable : 4996)
using namespace std;

struct newAccountNode
{
	string firstName;
	string lastName;
	string accountStatus;
	long long phoneNumber;
	long long CNIC;
	long double cash;
	string emailAddress;
	address homeAddress;
	bool debitCard;
	bool chequeBook;
	int debitCardPin;
	string username;
	string password;
	long accountNumber;
	newAccountNode *next;
	newAccountNode *prev;
};

class bankAccountsDatabase
{
public:
	newAccountNode *head, *tail;

public:
	bankAccountsDatabase()
	{
		head = tail = NULL;
	}
	void insertNewAccount()
	{
		newAccountNode *temp = new newAccountNode();

		char confirmation;
		int debitCardOpt = 0;
		int chequeBookOpt = 0;
		time_t t = time(NULL);
		tm* tPtr = localtime(&t);

		cout << "\t\t\t\t Kindly write down your First Name -> ";
		cin >> temp->firstName;
		cout << "\t\t\t\t Kindly write down your Last Name -> ";
		cin >> temp->lastName;
		cout << "\t\t\t\t Kindly write down your Email Address -> ";
		cin >> temp->emailAddress;
		cout << "\t\t\t\t Kindly write down your Home Address -> " << endl;
		temp->homeAddress.setAddress();
		cout << "\t\t\t\t Kindly write down your Phone Number -> ";
		long long num = temp->phoneNumber;
        invoiceInput(num);
        temp->phoneNumber = num;
		cout << "\t\t\t\t Kindly write down your CNIC -> ";
		int num2 = temp->CNIC;
        mustBeInteger(num2);
        temp->CNIC = num2;
		cout << "\t\t\t\t Do you want to get a Debit Card: write Yes(1) or No(0)-> ";
		int num3 = debitCardOpt;
        mustBeInteger(num3);
        debitCardOpt = num3;

		if (debitCardOpt == 1)
		{
			temp->debitCard = true;
			cout << "\t\t\t\t Kindly write down your Debit Card PIN (4 Digits) -> ";
			int num4 = temp->debitCardPin;
            pinType(num4);
            temp->debitCardPin = num4;
		}
		else if (debitCardOpt == 0)
		{
			temp->debitCard = false;
			temp->debitCardPin = 0;
			cout << "\t\t\t\t Debit card is set as No(0)" << endl;
		}
		else
		{
			temp->debitCard = false;
			temp->debitCardPin = 0;
			cout << "\t\t\t\t Invalid Option entered, debit card is set as No(N)" << endl;
		}

		cout << "\t\t\t\t Do you want to get a ChequeBook: write Yes(1) or No(0)-> ";
        // cin >> chequeBookOpt;
		int num5 = chequeBookOpt;
        mustBeInteger(num5);
        chequeBookOpt = num5;
		if (chequeBookOpt == 1)
		{
			temp->chequeBook = true;
		}
		else if (chequeBookOpt == 0)
		{
			temp->chequeBook = false;
            cout << "\t\t\t\t cheque book card is set as No(0)" << endl;
		}
		else
		{
			cout << "\t\t\t\t Invalid Option entered, cheque book is set as No(N)" << endl;
		}

	TYPEAGAINUSNM:cout << "\t\t\t\t Kindly write down your desired Username(NO Space Allowed) -> ";
		// cin >> temp->username;
        cin >> temp->username;

		if (checkUsernameClash(temp->username))
		{
			cout << "\t\t\t\t Username has already been taken.!" << endl;
			goto TYPEAGAINUSNM;
		}

		cout << "\t\t\t\t Kindly write down your desired Password(NO Space Allowed) -> ";
		cin >> temp->password;

		system("cls");

		cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << " ";
		cout << "Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;

		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
		cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
		cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
		cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
		cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
		cout << "\t\t\t\t ---Address--- " << endl;
		temp->homeAddress.displayAddress();
		cout << "\t\t\t\t -------------" << endl;
		cout << "\t\t\t\tUsername: " << temp->username << endl;
		cout << "\t\t\t\tPassword: " << temp->password << endl;
		cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
		cout << "\t\t\t\tCheque Book: " << temp->chequeBook << endl;
		cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
		cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t\t\t\t ", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (head == NULL)
			{
				temp->prev = NULL;
				temp->cash = 3000;
				temp->accountStatus = "In Process";
				temp->accountNumber = 0;
				head = tail = temp;
				cout << "\t\t\t\t Account Details Completed, IN PROCESS NOW." << endl;
				cout << "\t\t\t\t Admin will verify your account, then you can able to view it." << endl;
			}
			else
			{
				temp->cash = 3000;
				temp->accountStatus = "In Process";
				temp->accountNumber = 0;
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
				cout << "\t\t\t\t Account Details Completed, IN PROCESS NOW." << endl;
				cout << "\t\t\t\t Admin will verify your account, then you can able to view it." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\t\t\t\t Account not Completed." << endl;
		}
		else
		{
			cout << "\t\t\t\t ERROR ERROR ERROR!!! Wrong input entered, account opening failed!" << endl;
			temp = NULL;
		}

		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void viewAccountsToBeProcessed()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\t\t\t\t Account Database is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;

		while (temp != NULL)
		{
			if (temp->accountStatus == "In Process")
			{
				cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
				cout << "\t\t\t\t----------" << endl;
				cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
				cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
				cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
				cout << "\t\t\t\t ---Address--- " << endl;
				temp->homeAddress.displayAddress();
				cout << "\t\t\t\t -------------" << endl;
				cout << "\t\t\t\tUsername: " << temp->username << endl;
				cout << "\t\t\t\tPassword: " << temp->password << endl;
				cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			}
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void processAccounts()
	{
		newAccountNode *temp = head;
		if (head == NULL)
		{
			cout << "\t\t\t\t Account Database is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;
		int opt;

		while (temp != NULL)
		{
			if (temp->accountStatus == "In Process")
			{
				cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
				cout << "\t\t\t\t----------" << endl;
				cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
				cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
				cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
				cout << "\t\t\t\t ---Address--- " << endl;
				temp->homeAddress.displayAddress();
				cout << "\t\t\t\t -------------" << endl;
				cout << "\t\t\t\tUsername: " << temp->username << endl;
				cout << "\t\t\t\tPassword: " << temp->password << endl;
				cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
				cout << "\t\t\t\t Do you want to process this account or not? Yes(1) No(0)" << endl;
				// cin >> opt;
                mustBeInteger(opt);

				if (opt == 1)
				{
					temp->accountStatus = "Completed";
					temp->accountNumber = generateAccountNumber();
                    cout << "\t\t\t\t Account status: Completed" << endl;
				}
				else if (opt == 0)
				{
					temp->accountStatus == "Declined";
                    // newAccountNode* nodeToDelete = temp;
                    // if(temp == head){
                    //     head = temp->next;
                    // }
                    // else{
                    //     temp->prev->next = temp->next;
                    // }
                    // if(temp->next != NULL){
                    //     temp->next->prev = temp->prev;
                    // }
                    // delete nodeToDelete;
                    cout << "\t\t\t\t Account status: Declined" << endl;
				}
				else
				{
					cout << "\t\t\t\t Wrong option entered, account not completed nor declined." << endl;
				}
			}		
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	
	int countNodes()
	{
		int count = 0;

		if (head == NULL)
		{
			return count;
		}
		else
		{
			newAccountNode *temp = head;

			while (temp != NULL)
			{
				if (temp->accountStatus == "Completed")
				{
					count++;
				}
				temp = temp->next;	
			}
			return count;
		}
	}
	long generateAccountNumber()
	{
		long accNumber = 1007750 + countNodes() ;

		return accNumber;
	}
	void deleteAccount(long accountNum)
	{
		newAccountNode *temp = head;
		newAccountNode *findAndDelete;

		if (head == NULL)
		{
			cout << "\t\t\t\tAccount Database is empty, nothing is available to delete!!!!" << endl;
		}
		else if (head->accountNumber == accountNum)
		{
			head = head->next;
			findAndDelete = temp;
			temp = NULL;
			delete findAndDelete;
			cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
		}

		int flag = 0;

		while (temp != NULL)
		{
			temp = temp->next;
			if (temp->accountNumber == accountNum)
			{
				findAndDelete = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			cout << "\t\t\t\tAccount not found in database !!!!" << endl;
		}
		else if (flag == 1)
		{
			delete findAndDelete;
			cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	newAccountNode *checkIfAccountPresent(string usernm, string paswd)
	{
		newAccountNode *temp = NULL;
		if (head == NULL)
		{
			cout << "\t\t\t\tAccount not found in Database, because database is empty." << endl;
			return temp;
		}

		temp = head;

		while (temp != NULL)
		{
			if (temp->username == usernm && temp->password == paswd && temp->accountStatus == "Completed")
			{
				cout << "\t\t\t\tAccount found in Database." << endl;
				return temp;
			}
			temp = temp->next;
		}
		cout << "\t\t\t\tAccount not found in Database." << endl;

		return temp;
	}
	bool checkATMCredentials(int pn, long accNum)
	{
		if (head == NULL)
		{
			return false;
		}

		newAccountNode *temp = head;

		while (temp != NULL)
		{
			if (temp->debitCardPin == pn && temp->accountNumber == accNum && temp->accountStatus == "Completed")
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	bool checkUsernameClash(string usernameEnt)
	{
		if (head == NULL)
		{
			return false;
		}

		newAccountNode *temp = head;

		while (temp != NULL)
		{
			if (temp->username == usernameEnt)
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	void withDrawCash(string usernm, string paswd, long double amount)
	{
		newAccountNode *withDrawAcc = checkIfAccountPresent(usernm, paswd);

		if (withDrawAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
		}
		else
		{
			if (amount > withDrawAcc->cash)
			{
				cout << "\t\t\t\tAccount does not contain this much cash, transaction failed !!!!" << endl;
				cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
				_getch();
				return;
			}

			withDrawAcc->cash = withDrawAcc->cash - amount;
			cout << "\t\t\t\tTransaction successful!" << endl;
			cout << "\t\t\t\tRemaining Balance -> " << withDrawAcc->cash << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void changeATMpin(string usernm, string paswd, int oldPin, int newPin)
	{

		newAccountNode *changePinAcc = checkIfAccountPresent(usernm, paswd);
		if (changePinAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
		}
		else
		{
			if (changePinAcc->debitCardPin != oldPin)
			{
				cout << "\t\t\t\tNew PIN is not 4 digits or you entered wrong Old PIN, process failed!!!!" << endl;
                cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
                _getch();
				return;
			}

			changePinAcc->debitCardPin = newPin;
			cout << "\t\t\t\tProcess successful!" << endl;
			cout << "\t\t\t\tPin Updated " << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void balanceEnquiry(string usernm, string paswd)
	{
		newAccountNode *balanceEnquiryAcc = checkIfAccountPresent(usernm, paswd);

		if (balanceEnquiryAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
		}
		else
		{
			cout << "\t\t\t\tAccount# -> " << balanceEnquiryAcc->accountNumber << endl;
			cout << "\t\t\t\tBalance -> " << balanceEnquiryAcc->cash << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayAccountDetails(string usernm, string paswd)
	{
		newAccountNode *accountDisplay = checkIfAccountPresent(usernm, paswd);
		if (accountDisplay == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
		}
		else
		{
			cout << "\t\t\t\t------------------------------" << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\tAccount number: " << accountDisplay->accountNumber << endl;
			cout << "\t\t\t\tAccount Status: " << accountDisplay->accountStatus << endl;
			cout << "\t\t\t\tFirst Name: " << accountDisplay->firstName << endl;
			cout << "\t\t\t\tLast Name: " << accountDisplay->lastName << endl;
			cout << "\t\t\t\tEmail Address: " << accountDisplay->emailAddress << endl;
			cout << "\t\t\t\tCNIC: " << accountDisplay->CNIC << endl;
			cout << "\t\t\t\tPhone#: " << accountDisplay->phoneNumber << endl;
			cout << "\t\t\t\tCash: " << accountDisplay->cash << endl;
			cout << "\t\t\t\t ---Address--- " << endl;
			accountDisplay->homeAddress.displayAddress();
			cout << "\t\t\t\t -------------" << endl;
			cout << "\t\t\t\tUsername: " << accountDisplay->username << endl;
			cout << "\t\t\t\tPassword: " << accountDisplay->password << endl;
			cout << "\t\t\t\tDebit Card: " << accountDisplay->debitCard << endl;
			cout << "\t\t\t\tCheque Book: " << accountDisplay->chequeBook << endl;
			cout << "\t\t\t\tDebit Card PIN: " << accountDisplay->debitCardPin << endl;
			cout << "\t\t\t\t------------------------------" << endl << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayAllAccounts()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\t\t\t\t Account Database is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\tAccount Status: " << temp->accountStatus << endl;
			cout << "\t\t\t\tAccount Number: " << temp->accountNumber << endl;
			cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
			cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
			cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
			cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
			cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
			cout << "\t\t\t\t ---Address--- " << endl;
			temp->homeAddress.displayAddress();
			cout << "\t\t\t\t -------------" << endl;
			cout << "\t\t\t\tUsername: " << temp->username << endl;
			cout << "\t\t\t\tPassword: " << temp->password << endl;
			cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
			cout << "\t\t\t\tCheque Book: " << temp->chequeBook << endl;
			cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
			cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
};
