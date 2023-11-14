#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
// #include "invalidOption.h"
#pragma warning(disable : 4996)
using namespace std;

struct withdrawDepositNode
{
	long accountNumber;
	long double cashAmount;
	bool withdrawCash;
	bool depositCash;
	withdrawDepositNode *next;
	withdrawDepositNode *prev;
};

class withdrawDepositQueue
{
private:
	withdrawDepositNode *front;
	withdrawDepositNode *rear;
public:
	withdrawDepositQueue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue()
	{
		withdrawDepositNode *temp = new withdrawDepositNode();

		int opt = 0;
		string flag = "";

		cout << "\t\t\t\t Kindly choose from the following two options: 1) Withdraw Cash (cheque) or 2) Deposit Cash -> ";
		// cin >> opt;
        int num = opt;
        invalidOption(num);
        opt = num;

		if (opt == 1)
		{
			temp->withdrawCash = true;
			temp->depositCash = false;
			flag = "Withdraw Cash";
		}
		else if (opt == 2)
		{
			temp->depositCash = true;
			temp->withdrawCash = false;
			flag = "Deposit Cash";
		}
		else
		{
			cout << "\t\t\t\t Wrong option entered, press any key to return to menu." << endl;
			_getch();
			return;
		}

		char confirmation;

		cout << "\t\t\t\t Kindly write down your Account Number -> ";
		// cin >> temp->accountNumber;
        int num2 = temp->accountNumber;
        mustBeInteger(num2);
        temp->accountNumber = num2;
		cout << "\t\t\t\t Kindly write down the cash amount -> ";
		// cin >> temp->cashAmount;
        int num3 = temp->cashAmount;
        mustBeInteger(num3);
        temp->cashAmount = num3;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tAccount#: " << temp->accountNumber << endl;
		cout << "\t\t\t\tCash: " << temp->cashAmount << endl;
		cout << "\t\t\t\tTransaction Type: " << flag << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t\t\t\t ", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (isEmpty())
			{
				temp->prev = NULL;
				front = rear = temp;
				cout << "\t\t\t\t Transaction Completed." << endl;
			}
			else
			{
				temp->prev = rear;
				rear->next = temp;
				rear = temp;
				cout << "\t\t\t\t Transaction Completed." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\t\t\t\t Transaction not Completed." << endl;
		}
		else
		{
			cout << "\t\t\t\t ERROR ERROR ERROR!!! Wrong input entered, transaction failed!" << endl;
			temp = NULL;
		}

		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();

	}
	void dequeue()
	{
		withdrawDepositNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Withdraw/Deposit Queue is empty, nothing left to process" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}
		else if (front == rear)
		{
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t " << temp->accountNumber << endl;
			cout << "\t\t\t\t " << temp->cashAmount << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t Transaction has been done." << endl;
			front = rear = NULL;
		}
		else
		{
			front = front->next;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t " << temp->accountNumber << endl;
			cout << "\t\t\t\t " << temp->cashAmount << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t Transaction has been done." << endl;
		}
		delete temp;
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayWithdrawDepositQueue()
	{
		withdrawDepositNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Withdraw/Deposit Payment Queue is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 0;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
			cout << "\t\t\t\t " << temp->accountNumber << endl;
			cout << "\t\t\t\t " << temp->cashAmount << endl;
			cout << "\t\t\t\t Withdraw =" << temp->withdrawCash << endl;
			cout << "\t\t\t\t Deposit =" << temp->depositCash << endl;
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
};
