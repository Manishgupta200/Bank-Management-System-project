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

class admin
{
private:
	const string username = "admin123";
	const string password = "helloworld";
public:
	admin()
	{

	}
	string getUserName() const
	{
		return username;
	}
	string getPassWord() const
	{
		return password;
	}
	bool checkCredentials(string userNm, string passWd)
	{
		if (userNm == username && passWd == password)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
