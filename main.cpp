/*
Name: Ateeq Rana

Bank Management System
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#include "payBillNode.h"
#include "withdrawDepositNode.h"
#include "newAccountNode.h"
#include "admin.h"
#pragma warning(disable : 4996)
using namespace std;

// 1. payBillNode(struct) -> billPaymentQueue(class)
// 2. withdrawDepositNode(struct) -> withdrawDepositQueue(class)
// 3. newAccountNode(struct)[#include "address.h" -- address(class)] -> bankAccountsDatabase(class)
// 4. admin(class)

void dateAndTime(tm* tPtr){
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << " ";
	cout << "Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;
}

void startScreen(tm* tPtr);
void endScreen(tm* tPtr);
void bankEnterScreen(tm* tPtr, int &opt);
void screenBank(tm* tPtr, int &opt);
void screenATMone(tm* tPtr, long &userCardNumber, int &userPINnumber);
void screenATMtwo(tm* tPtr, int &opt);
void screenAdminOne(tm* tPtr, string &adminUserName, string &adminPassword);
void screenAdminTwo(tm* tPtr, int &opt);
void screenAdminAccountOpenings(tm* tPtr, int &opt);
void screenAdminBillPayments(tm* tPtr, int &opt);

int main()
{
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	int bankEnterOption = 0;
	int optionInBankOne = 0;
	int optionInBankTwo = 0;
	int optionInATMone = 0;
	int optionInATMtwo = 0;
	int optionInAdmin = 0;
	int optionInAdminAccOpen = 0;
	int optionInAdminBillPaymt = 0;
	long userCardNumber = 0;
	int userCardPIN = 0;
	string accountViewUsnm = "";
	string accountViewPaswd = "";
	string adminUserName;
	string adminPassword;
	int flag = 0;
	admin administrator;
	long double withdrawCash = 0.00;
	int oldPinChange = 0;
	int newPinChange = 0;
	bankAccountsDatabase accDatabase;
	billPaymentQueue billPaymentLine;
	withdrawDepositQueue withDwDepstLine;
	string usnmATM = "";
	string pssdATM = "";

	startScreen(tPtr);
	system("cls");
	
BANKSCREEN:bankEnterScreen(tPtr, bankEnterOption);
	system("cls");
	switch (bankEnterOption)
	{
	case 1:
		INSIDEBANK:screenBank(tPtr, optionInBankOne);
		system("cls");

		dateAndTime(tPtr);

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		switch (optionInBankOne)
		{
		case 1:
			billPaymentLine.enqueue();
			system("cls");
			goto INSIDEBANK;
			break;
		case 2:
			withDwDepstLine.enqueue();
			system("cls");
			goto INSIDEBANK;
			break;
		case 3:
			accDatabase.insertNewAccount();
			system("cls");
			goto INSIDEBANK;
			break;
		case 4:
			cout << "\t\t\t Enter Username (no space allowed): ", cin >> accountViewUsnm, cout << endl;
			cout << "\t\t\t Enter Password (no space allowed): ", cin >> accountViewPaswd, cout << endl;
			accDatabase.displayAccountDetails(accountViewUsnm, accountViewPaswd);
			system("cls");
			goto INSIDEBANK;
			break;
		case 5:
			system("cls");
			goto BANKSCREEN;
			break;
		default:
			system("cls");
			dateAndTime(tPtr);

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu "<< endl;
			_getch();
			system("cls");
			goto INSIDEBANK;
			break;
		}
		break;
	case 2:
		MAINATMSCREEN:screenATMone(tPtr, userCardNumber, userCardPIN);
		system("cls");

		if (accDatabase.checkATMCredentials(userCardPIN, userCardNumber))
		{
		ATMSCREEN:screenATMtwo(tPtr, optionInATMtwo);
			system("cls");
			dateAndTime(tPtr);

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			switch (optionInATMtwo)
			{
			case 1:
				cout << "\t\t\t # Enter amount you wish to withdraw -> ", cin >> withdrawCash;
				cout << "\t\t\t # Enter your username -> ", cin >> usnmATM;
				cout << "\t\t\t # Enter your password -> ", cin >> pssdATM;
				accDatabase.withDrawCash(usnmATM, pssdATM, withdrawCash);
				system("cls");
				goto ATMSCREEN;
				break;
			case 2:
				cout << "\t\t\t # Enter your username -> ", cin >> usnmATM;
				cout << "\t\t\t # Enter your password -> ", cin >> pssdATM;
				accDatabase.balanceEnquiry(usnmATM, pssdATM);
				system("cls");
				goto ATMSCREEN;
				break;
			case 3:
				cout << "\t\t\t # Enter your username -> ", cin >> usnmATM;
				cout << "\t\t\t # Enter your password -> ", cin >> pssdATM;
				cout << "\t\t\t # Enter old pin -> ";
				pinType(oldPinChange);
				cout << "\t\t\t # Enter new pin (4 Digits) of Integer type only: -> ";
				pinType(newPinChange);
				accDatabase.changeATMpin(usnmATM, pssdATM, oldPinChange, newPinChange);
				system("cls");
				goto ATMSCREEN;
				break;
			case 4:
				system("cls");
				goto BANKSCREEN;
				break;
			default:
				system("cls");
				dateAndTime(tPtr);

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
				_getch();
				system("cls");
				goto ATMSCREEN;
				break;
			}
		}
		else
		{
			dateAndTime(tPtr);

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t # Invalid Credentials Added" << endl;
			cout << "\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			system("cls");
			goto BANKSCREEN;
		}
		break;
	case 3:
		screenAdminOne(tPtr, adminUserName, adminPassword);
		system("cls");
		if (administrator.checkCredentials(adminUserName, adminPassword))
		{
			ADMINSCREEN:screenAdminTwo(tPtr, optionInAdmin);
			system("cls");

			switch (optionInAdmin)
			{
			case 1:
				ACCOPPSCREN:screenAdminAccountOpenings(tPtr, optionInAdminAccOpen);
				system("cls");
				dateAndTime(tPtr);

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				switch (optionInAdminAccOpen)
				{
				case 1:
					accDatabase.viewAccountsToBeProcessed();
					system("cls");
					goto ACCOPPSCREN;
					break;
				case 2:
					accDatabase.processAccounts();
					system("cls");
					goto ACCOPPSCREN;
					break;
				case 3:
					accDatabase.displayAllAccounts();
					system("cls");
					goto ACCOPPSCREN;
				case 4:
					system("cls");
					goto ADMINSCREEN;
					break;
				default:
					system("cls");
					dateAndTime(tPtr);

					cout << "\t\t\t ##########################################################################################################################" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
					_getch();
					system("cls");
					goto ACCOPPSCREN;
					break;
				}
			case 2:
				BILLPAYSCREEN:screenAdminBillPayments(tPtr, optionInAdminBillPaymt);
				system("cls");
				dateAndTime(tPtr);

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				switch (optionInAdminBillPaymt)
				{
				case 1:
					billPaymentLine.displayBillPaymentQueue();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 2:
					billPaymentLine.displayFront();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 3:
					billPaymentLine.dequeueAndRecordHistory();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 4:
					billPaymentLine.displayTransactionHistory();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 5:
					system("cls");
					goto ADMINSCREEN;
					break;
				default:
					system("cls");
					dateAndTime(tPtr);

					cout << "\t\t\t ##########################################################################################################################" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
					_getch();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				}
				break;
			case 3:
				system("cls");
				goto BANKSCREEN;
				break;
			default:
				system("cls");
				dateAndTime(tPtr);

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
				_getch();
				system("cls");
				goto ADMINSCREEN;
				break;
			}
		}
		else
		{
			dateAndTime(tPtr);

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t # Invalid Credentials Added" << endl;
			cout << "\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			system("cls");
			goto BANKSCREEN;
		}
		break;
	case 4:
		system("cls");
		endScreen(tPtr);
		break;
	default:
		system("cls");
		dateAndTime(tPtr);

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
		_getch();
		system("cls");
		goto BANKSCREEN;
		break;
	}

	cout << "\t\t\t ", system("pause");
	return 0;
}

void startScreen(tm* tPtr)
{
	dateAndTime(tPtr);
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\tWelcome\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t  to\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t ",system("pause");
}

void endScreen(tm* tPtr)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\tThank you\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\tfor using\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
}

void bankEnterScreen(tm* tPtr, int &opt)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Enter Bank\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Enter ATM\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Admin Login\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	// cout << "\t\t\t Enter Option: ",cin>>opt,cout<<endl;
	invalidOption(opt);
}

void screenBank(tm* tPtr, int &opt)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to Bank\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Pay Bills\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Deposits/Cheques\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Open up Account\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) View your Account\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    5) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	// cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
	invalidOption(opt);
}

void screenATMone(tm* tPtr, long &userCardNumber, int &userPINnumber)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to ATM\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\tEnter Following Details:\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Account Number\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Debit Card PIN\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Account Number: ", cin >> userCardNumber, cout << endl;
	cout << "\t\t\t Enter Debit Card PIN: ", cin >> userPINnumber, cout << endl;
}

void screenATMtwo(tm* tPtr, int &opt)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to ATM\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Withdraw Cash\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Balance Inquiry\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Change Pin\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	// cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
	invalidOption(opt);
}

void screenAdminOne(tm* tPtr, string &adminUserName, string &adminPassword)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    Welcome to Admin\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\tEnter Following Details:\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Username\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Password\t\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Username: ", cin >> adminUserName, cout << endl;
	cout << "\t\t\t Enter Password: ", cin >> adminPassword, cout << endl;
}

void screenAdminTwo(tm* tPtr, int &opt)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    Welcome to Admin\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Process Account Openings\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Process Bill Payments\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	// cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
	invalidOption(opt);
}

void screenAdminAccountOpenings(tm* tPtr, int &opt)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\tWelcome to Account Openings\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) View Account Openings\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Process Accounts\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) View Accounts in Database\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	// cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
	invalidOption(opt);
}

void screenAdminBillPayments(tm* tPtr, int &opt)
{
	dateAndTime(tPtr);

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Dhan Lakshmi Bank Pvt Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    Welcome to Bill Payments\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) View All Bill Payments\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) View Bill Payment at Front\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Tap to directly Processed Bill Payment at Front\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) View All Transactions\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    5) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	// cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
	invalidOption(opt);
}