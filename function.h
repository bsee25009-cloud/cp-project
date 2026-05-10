#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include<iostream>
using namespace std;
#include <vector>
#include<fstream>
#include <sstream>

struct person{
    string name;
    string email;
    string password;
    string country;
};


void resize(person*&  users, int & length, int increment = 1);
void listUsers(person*, int length);
bool validateUser(person, person*, int length);
bool emailExists(string,person*, int length);
void signUp(person*&, int & length);
void login(person*, int length);
void loadUsers(person*&, int & length);








#endif
