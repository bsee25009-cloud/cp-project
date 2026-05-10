#include "functions.h"
#include<iostream>
using namespace std;
int main() {
    int length = 0;
    person * users = new person[length];
    loadUsers(users, length);
    //cout<<length<<users[0].email<<users[0].password;
    cout<<   "Main Menu"   <<endl;
    cout<<"Press 1 to login "<<endl<<"Press 2 to sign up"<<endl<<"Press 0 to exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
{
    case 1:{
    login(users,length);
    break;
    }
    case 2:{
    signUp(users, length);
    break;
    }
    case 0:{
    break;
    }
}

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



