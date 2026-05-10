#include "functions.h"
#include <fstream>
#include <string>

using namespace std;


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

    return 0;
}

    void reportMenu() {
    int choice;
    do{
        cout << "\n REPORT MANAGEMENT\n";
        cout << "1. Total Users\n";
        cout << "2. Total Posts\n";
        cout << "3. Most Active User\n";
        cout << "4. Export Report\n";
        cout << "0. Back\n";
        cin >> choice;

        if(choice==1) cout << "Total Users: " <<countUsers() << endl;
        else if(choice==2)
        cout<<"Total Posts: "<<countPosts() << endl;
        else if(choice==3)
        mostActiveUser();
        else if(choice==4)
        exportReport();
    }while(choice!=0);
}
        
int countUsers() {
    ifstream file("users.txt");
    string line;
    int count = 0;

    while(getline(file,line))
    count++;

return count;
}

int countPosts() {
    ifstream file("posts.txt");
    string line;
    int count = 0;

    while(getline(file,line))
    count++;

return count;
}

void mostActiveUser() {

    ifstream file("posts.txt");
    string username;
    string users[100];
    int posts[100]={0};
    int size = 0;

    while (file >> username)
    {
        bool found = false;

        for(int i = 0; i < size; i++) {
            if(users[i]==username) {
                posts[i]++;
                found = true;
                break;

            }
        }

    if(!found) {
        users[size] = username;
        posts[size] = 1;
        size++;
    }

    string rest;
    getline(file, rest);
    }

    if(size==0){
        cout<<"No posts available\n";
        return;
    }

int maxIndex=0;

for(int i =1; i < size; i++)
if(posts[i]>posts[maxIndex])
maxIndex=i;

cout << "Most Active User: "<< users[maxIndex]<<" ("<<posts[maxIndex]<<"posts)\n";
}

void exportReport() {
    ofstream file("report.txt");
    file <<"Total Users: "<<countUsers() << endl;
    file << "Total Posts: "<<countPosts() << endl;
    cout <<"Report saved!\n";
}

void marketingMenu() {
    int choice;
    do{
        cout << "\n  MARKETING\n";
        cout << "1. Add Announcement\n";
        cout << "2. View Announcement\n";
        cout << "3. Record  Visit\n";
        cout << "4. Marketing Report\n";
        cout << "0. Back\n";
        cin >> choice;
        cin.ignore();

        if(choice==1) addAnnouncement();
        else if(choice==2) viewAnnouncements();
        else if(choice==3) recordVisit();
        else if(choice==4) marketingReport();
        
    }while(choice!=0);
}

void addAnnouncement() {
    ofstream file("announcements.txt",ios::app);
    string msg;
    
    cout << "Enter Announcement: ";
    getline(cin,msg);

    file<<msg<<endl;
}

void viewAnnouncements() {
    ifstream file("announcements.txt");
    string msg;

    while(getline(file,msg))
    cout<<msg<<endl;
}

void recordVisit() {
    int visits = 0;
    ifstream read ("visits.txt");

    if (read.is_open()) read >> visits;

    read.close();

    visits++;

    ofstream write("visits.txt");
    write<<visits;
}

void marketingReport() {
    int visits = 0;
    ifstream file("visits.txt");

    if (file.is_open()) file >> visits;

    cout << "Total App Visits: " << visits << endl;
}
