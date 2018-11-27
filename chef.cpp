//the source code use to process chef information
#include <iostream>//include the information about the standard library iostream
#include <fstream>//include the information about the standard library fstream
#include <time.h>//include the information about the standard library time.h
#include <iomanip>//include the information about the standard library iomainp
#include <windows.h>//include the information about the standard library windows.h
#include"menu.h"//include the information about the headfile "menu.h"
#include"raw material.h"//include the information about the headfile "raw material.h"
#include"chef.h"//include the information about the headfile "chef.h"
#include"customer.h"//include the information about the headfile "customer.h"
using namespace std;//using standard name

////the function let the chef to choose the function
int chef::choice()
{
	int choice;//define an integer choice
	int password = 13579;//define an integer password and set the value to 13579
	int digit;//define an integer digit
	dish a;//instantiation of class dish
	material b;//instantiation of class material
	cout << "Welcome to the system, chef" << endl;//enter the intersurface of login to chef
	cout << "Please login" << endl;
	cout << "Please enter the password" << endl;
	cin >> digit;//get the value input to varible digit
	while (!cin|| digit != password)//if value in digit is not equal to value of passward or no value in digit
	{
		cout << "Wrong input, please enter again" << endl;//display to inform the incorrect passward and ask to input passward again
		cin.clear();//clear the input
		cin.sync();//reset the input
		cin >> digit;//get the new input to the varible digit
		continue;//continue the function
	}
	if (digit == password)//if value in digit is equal to value in password
	{
		cout << "You have login successfully." << endl;//display to inform correct password
	}
	Sleep(1000);//stop for two second
	system("cls");//clear the screen
	while (2)//while the system value is 2
	{
		system("cls");//clear the screen
		cout << "Please choose what you want to do" << endl;//display the chef menu
		cout << "1. Add the menu." << endl;
		cout << "2. Read the menu." << endl;
		cout << "3. Edit the menu." << endl;
		cout << "4. Search the menu" << endl;
		cout << "5. Add the raw material" << endl;
		cout << "6. Go back to the main frame" << endl;
		cin >> choice;//get the input choice to varible choice
		while (choice<1 || choice>6 || !cin)//the input value is not an option
		{
			cout << "Wrong input, please enter again" << endl;//inform the invalid input and ask to input again
			cin.clear();//clear the input
			cin.sync();//reset the input
			cin >> choice;//get the new value to varible choice
			continue;//continue the function
		}
		switch (choice)//switch the value of choice
		{
		case 1://case one ,add menu
			system("cls");//clear the screen
			a.addmenu();//run function addmenu() on class dish
			break;//breakout from the loop
		case 2://case two read menu
			system("cls");//clear the screen
			showmenu();//run function showmenu()
			break;//breakout from the loop
		case 3://case three, edit menu
			system("cls");//clear the screen
			a.editmenu();//run function editmenu() on class dish 
			break;//breakout from the loop
		case 4://case four, search menu
			system("cls");//clear the screen
			a.searchmenu();//runfunction searchmenu() on class dish
			break;//breakout from the loop
		case 5://case five, add raw material
			system("cls");//clear the screen
			b.addmaterial();//run function addmaterial() on class raw material
			break;//breakout from the loop
		case 6://case six, return to main menu
			return 1;//return with one
		}
	}
}