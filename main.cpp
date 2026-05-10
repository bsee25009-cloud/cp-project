#include "function.h"
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
    return 0;
}



