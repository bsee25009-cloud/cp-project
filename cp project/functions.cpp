#include "function.h"


void resize(person*& users, int & length, int increment){
    
    person * newarr=new person[length+increment];
    for(int i=0;i<length;i++){
        newarr[i] = users[i];
    }
    
    delete[] users;
    users=newarr;
    length += increment;
}


void signUp(person*& users, int & length){
    resize(users, length);
    person& newperson = users[length - 1];
    bool validUser = true;
    do {
        cout<<"Enter Name: "<<endl;
        getline(cin,newperson.name);
        cout<<"Enter Email: "<<endl;
        getline(cin,newperson.email);
        cout<<"Enter Password:" <<endl;
        getline(cin,newperson.password);
        cout<<"Enter Country: " <<endl;
        getline(cin,newperson.country);
        validUser = validateUser(newperson, users, length);
        if (validUser == false) {
            cout<<"User details not valid. Please enter again"<<endl;
        }
    } while (validUser == false);
    
    ofstream f("users.txt", ios::app);
    f << newperson.name << "," << newperson.email << "," <<newperson.password << "," << newperson.country << "\n";
    
    cout << "\nAccount created! (" << newperson.name << ", " << newperson.country << ")\n";
    
}

bool validateUser(person newuser, person * users, int length) {
    // TODO: add email unique check
    if (newuser.name.length() == 0) {
        cout<<"Name cannot be empty"<<endl;
        return false;
    }

    if (newuser.email.length() == 0) {
        cout<<"Email cannot be empty"<<endl;
        return false;
    }

    bool containsAt = false;
    bool containsDot = false;
    
    for (int i=0; i<newuser.email.length(); i++) {
        if (newuser.email[i] == '@') {
            containsAt = true;
        }
        else if (newuser.email[i] == '.') {
            containsDot = true;
        }
    }

    if (containsAt == false || containsDot == false) {
        cout<<"Email is not valid"<<endl;
        return false;
    }

    if (newuser.password.length() < 8) {
        cout<<"Password must be atleast 8 characters"<<endl;
        return false;
    }

    if (newuser.country.length() == 0) {
        cout<<"Country cannot be empty"<<endl;
        return false;
    }
   

    return true;
}