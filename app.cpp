#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
  int choice;
  cout << "\t\t\t_____________________________________________\n\n\n";
  cout << "\t\t\t             Welcome to the login page       \n\n\n";
  cout << "\t\t\t_____________________Menu____________________\n\n\n";
  cout << "\t|Press 1 to Login               |" << endl;
  cout << "\t|Press 2 to Register            |" << endl;
  cout << "\t|Press 3 if you forgot password |" << endl;
  cout << "\t|Press 4 to Exit                |" << endl;
  cout << "\n\t\t\t Please enter your choice: ";
  cin >> choice;

  switch(choice){
    case 1:
      login();
      break;
    case 2:
      registration();
      break;
    case 3:
      forgot();
      break;
    case 4:
      cout << "\t\t\t Thank you!";
      break;
    default:
      system("cls");
      cout << "Invalid choice, please pick 1, 2, 3, 4";
      main();
  }
}

void login(){
  int count;
  string userId, password, id, pass;
  system("cls");
  cout << "\t\t\t Please enter the username and password : " << endl;
  cout << "\t\t\t USERNAME ";
  cin >> userId;
  cout << "\t\t\t PASSWORD ";
  cin >> password;

  // reads data from the files
  ifstream input("records.txt");

  while(input>>id>>pass){
    if(id==userId && pass==password){
      count = 1;
      system("cls");
    }else {
      count = 0;
      system("cls");
    }
  }
  // closes file
  input.close();

  if(count == 1){
    cout << userId << "\n Your LOGIN is successful \n Thank you for logging in";
    main();
  }else
  {
    cout << "\n LOGIN ERROR \n username and or password do not match\n";
    main();
  }
}

void registration(){
  string ruserId, rpassword, rid, rpass;
  system("cls");
  cout << "\t\t\t Enter your username: ";
  cin >> ruserId;
  cout << "\t\t\t Enter a password: ";
  cin >> rpassword;
  
  // using ofstream to write inside file
  ifstream f3("records.txt");
  while(f3>>rid){
    if(rid == ruserId){
      cout << "username already exists enter a different username \n";
      registration();
    }else{
      ofstream f1("records.txt", ios::app);
      f1 << ruserId << " " << rpassword << endl;
      system("cls");
      cout << "\n\t\t\t Registration is successful\n";
      main();
    }
  }
 
}

void forgot(){
  int option;
  system("cls");
  cout << "\t\t\t You forgot your password\n";
  cout <<  "Press 1 to search your id by username " << endl;
  cout << "Press 2 to go back to main menu " << endl;
  cout << "\t\t\t Enter your choice ";
  cin >> option;

  switch(option){
    case 1:
      {
        int count = 0;
      string suserId, sId, sPass;
      cout << "\n\t\t\tEnter your username: ";
      cin >> suserId;
      ifstream f2("records.txt");
      while(f2>>sId>>sPass){
        if(sId == suserId){
          count = 1;
        }
        f2.close();
        if(count ==1){
          cout << "\n\n Your account is found! \n";
          cout << "\n\n Your password is: " << sPass;
          main();
        }else {
          cout << "Username does not exist \n";
          main();
        }
      }
      break;
    }
    case 2:
      {
        main();
        }
    default:
      cout << "Invalid option, please choose 1 or 2\n";
      forgot();
  }
}