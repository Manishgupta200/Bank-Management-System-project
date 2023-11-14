#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;

class address
{
public:
	int houseNumber;
	string townName;
	int streetNumber;
	string city;

	address(int hN = 0,string tN = "",int sN = 0,string c = "")
	{
		houseNumber = hN;
		townName = tN;
		streetNumber = sN;
		city = c;
	}
	void setAddress()
	{
		cout << "\t\t\t\t House Number = ";
        int num = houseNumber;
        mustBeInteger(num);
        houseNumber = num;
		cout << "\t\t\t\t Town Name = ", cin >> townName;
		cout << "\t\t\t\t Street Number = ";
        int num2 = streetNumber;
        mustBeInteger(num2);
        streetNumber = num2;
		cout << "\t\t\t\t City = ", cin >> city;
	}
	int getHouseNumber()
	{
		return houseNumber;
	}
	int getStreetNumber()
	{
		return houseNumber;
	}
	string getCity()
	{
		return city;
	}
	string getTownName()
	{
		return townName;
	}
	void displayAddress()
	{
		cout << "\t\t\t\t House number = "<< houseNumber <<endl;
		cout << "\t\t\t\t Town Name = " << townName << endl;
		cout << "\t\t\t\t Street number = " << streetNumber << endl;
		cout << "\t\t\t\t City = "<< city << endl;
	}
	
};
