#include "functions.h"
#include<iostream>
using namespace std;
int main() {
    int length = 0;
    person * users = new person[length];
    signUp(users, length);

    int choice;
do{
    cout <<"\n CONNECTPLUS ADMIN \n";
    cout << "1. Report \n";
    cout << "2. Application \n";
    cout << "0. Exit\n";
    cin >> choice;

    if(choice==1) 
    reportMenu();
    else if(choice==2)
    marketingMenu();
        
} while (choice!=0);

delete[] users;

return 0;
}
