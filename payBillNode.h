#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#include "invalidOption.h"
#pragma warning(disable : 4996)
using namespace std;


struct payBillNode
{
	string billType;
	long long billInvoiceNumber;
	long double billAmount;
	payBillNode *next;
	payBillNode *prev;
};

class billPaymentQueue
{
private:
	payBillNode *front;
	payBillNode *rear;
	payBillNode *transactionHistoryFront; // New linked list for transaction history
    payBillNode *transactionHistoryRear;
public:
	billPaymentQueue()
	{
		front = rear = NULL;
		transactionHistoryFront = transactionHistoryRear = NULL;
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
		payBillNode *temp = new payBillNode();
		char confirmation;
		cout << "\t\t\t\t---------------------------------------------MANUAL PAYMENT METHOD-----------------------------------------" << endl << endl;
		cout << "\t\t\t   In this transaction method, Balance cannot be deducted from your main balance!!! (Admin will record this transaction)" << endl << endl;
		cout << "\t\t\t\t Kindly write down your bill type from the following: Electricity, Gas, Internet -> ";
		cin >> temp->billType;
		cout << "\t\t\t\t Kindly write down the 10 digit Invoice Number -> ";
		// cin >> temp->billInvoiceNumber;
        long long num = temp->billInvoiceNumber;
        invoiceInput(num);
        temp->billInvoiceNumber = num;
		cout << "\t\t\t\t Kindly write down the bill amount -> ";
		// cin >> temp->billAmount;
        int num2 = temp->billAmount;
        mustBeInteger(num2);
        temp->billAmount = num2;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tBill Type : " << temp->billType << endl;
		cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
		cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
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
				cout << "\t\t\t\t Transaction Completed, Bill payment in process." << endl;
			}
			else
			{
				temp->prev = rear;
				rear->next = temp;
				rear = temp;
				cout << "\t\t\t\t Transaction Completed, Bill payment in process." << endl;
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
	// void dequeue()
	// {
	// 	payBillNode *temp = front;

		// if (isEmpty())
		// {
		// 	cout << "\t\t\t\t Bill Payment Queue is empty, nothing left to process" << endl;
		// 	cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		// 	_getch();
		// 	return;
		// }
	// 	else if (front == rear)
	// 	{
	// 		cout <<"\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid" << endl;
	// 		front = rear = NULL;
	// 	}
	// 	else
	// 	{
	// 		front = front->next;
	// 		cout << "\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid." << endl;
	// 	}
	// 	delete temp;
	// 	cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
	// 	_getch();
	// }
	void dequeueAndRecordHistory()
    {
        payBillNode *temp = front;

        if (isEmpty())
        {
            cout << "\t\t\t\t Bill Payment Queue is empty, nothing left to process" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }
        else if (front == rear)
        {
            cout << "\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid" << endl;
			cout << "\t\t\t\t Bill type: " << temp->billType << endl;
            // Insert the node into the transaction history list
            if (transactionHistoryRear == NULL)
            {
                temp->prev = NULL;
                transactionHistoryFront = transactionHistoryRear = temp;
            }
            else
            {
                temp->prev = transactionHistoryRear;
                transactionHistoryRear->next = temp;
                transactionHistoryRear = temp;
            }
			temp->next = NULL;
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            cout << "\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid." << endl;
			cout << "\t\t\t\t Bill type: " << temp->billType << endl;
            // Insert the node into the transaction history list
            if (transactionHistoryRear == NULL)
            {
                temp->prev = NULL;
                transactionHistoryFront = transactionHistoryRear = temp;
            }
            else
            {
                temp->prev = transactionHistoryRear;
                transactionHistoryRear->next = temp;
                transactionHistoryRear = temp;
            }
			temp->next = NULL;
		}

        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }
	void displayBillPaymentQueue()
	{
		payBillNode *temp = front;
		
		if (isEmpty())
		{
			cout << "\t\t\t\t Bill Payment Queue is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 0;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << ++count <<" ---------------"<< endl;
			cout << "\t\t\t\tBill Type : " << temp->billType << endl;
			cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
			cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
			cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayFront()
	{
		payBillNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Bill Payment Queue is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		cout << "\t\t\t\t------------------------------" << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tBill Amount: " << temp->billAmount << endl;
		cout << "\t\t\t\tBill Invoice#: " << temp->billInvoiceNumber << endl;
		cout << "\t\t\t\tBill Type: " << temp->billType << endl;
		cout << "\t\t\t\t------------------------------" << endl << endl;
		// temp = temp->next;
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayTransactionHistory()
    {
        payBillNode *temp = transactionHistoryFront;

        if (transactionHistoryFront == NULL)
        {
            cout << "\t\t\t\t Not any bill payment is done till now. Transaction History is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        int count = 0;

        while (temp != NULL)
        {
            cout << "\t\t\t\t--------------- Transaction #" << ++count << " ---------------" << endl;
            cout << "\t\t\t\tBill Type: " << temp->billType << endl;
            cout << "\t\t\t\tBill Invoice#: " << temp->billInvoiceNumber << endl;
            cout << "\t\t\t\tBill Amount: " << temp->billAmount << endl;
            cout << "\t\t\t\t--------------- Transaction #" << count << " ---------------" << endl
                 << endl;
            temp = temp->next;
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }
};
