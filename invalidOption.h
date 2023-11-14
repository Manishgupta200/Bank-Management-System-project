#include<iostream>
#include <limits>
#include<conio.h>
using namespace std;

void invalidOption(int &userInput){
    bool validInput = false;
    while (!validInput) {
        // cout << "\t\t\t Enter option: ";
        cout << "Enter option: ";

        if (cin >> userInput) {
            // Input is successful
            validInput = true;
        } else {
            // Clear the error flag and ignore the rest of the input
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
        }
    }
    cout << "You entered: " << userInput << endl;
}

void mustBeInteger(int &userInput){
    bool validInput = false;
    while (!validInput) {
        // cout << "\t\t\t Enter option: ";
        // cout << "Enter option: ";

        if (cin >> userInput) {
            // Input is successful
            validInput = true;
        } else {
            // Clear the error flag and ignore the rest of the input
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
    }
    cout << endl << "You entered: " << userInput << endl;
}

bool isNumber(const string &s) {
    return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

bool isValidPhoneNumber(const string &number) {
    return (number.length() == 10) && isNumber(number);
}
void invoiceInput(long long &userInput){
    // -------------------------------------------------------------------
    string str = to_string(userInput);
    do {
        cin >> str;

        if (!isValidPhoneNumber(str)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an 10 digit number of type integer: ";
        }
    } while (!isValidPhoneNumber(str));
    userInput = stoll(str);
    cout << endl << "You entered: " << userInput << endl;
}

void pinType(int &userInput){
    bool validInput = false;
    while (!validInput) {
        
        if ((cin >> userInput) && (to_string(userInput).length() == 4)) {
            // Input is successful
            validInput = true;
        } else {
            // Clear the error flag and ignore the rest of the input
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an 4 digit number of type integer: ";
        }
    }
    cout << endl << "You entered: " << userInput << endl;
}