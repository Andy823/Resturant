//the source code to run the whole function
#include<iostream>//include the information about the standard library iostream
#include "chef.h"//include the information about the head file chef.h
#include "manager.h"//include the information about the headfile manager.h
#include "customer.h"//include the information about the head file customer.h

using namespace std;//using the standard name
//the main function of the system
int main(){
	while (1)//the return value of system is 1
	{
		system("cls");//clear the screen
		int decision;//define the integer decision
		manager m; // instantiation of class manager
		chef c; // instantiation of class chef
		Customer cu; // instantiation of class customer
		cout << "******************************************" << endl;//display the main menu of the restaraunt system
		cout << "Welcome to the resturant management system" << endl;
		cout << "******************************************" << endl;
		cout << "Please choose your character" << endl;
		cout << "1. Manager" << endl;
		cout << "2. Chef" << endl;
		cout << "3. Customer" << endl;
		cout << "4. Exit" << endl;
		cin >> decision;//get the input option to varible decision
		if (decision<0 || decision>4 || !cin)//invalid input
		{
			cout << "Wrong input, please enter again" << endl;//inform the invalid input and ask to input again
			cin.clear();//clear the input
			cin.sync();//rest the input
			cin >> decision;//get the new input value
			continue;//continue the loop
		}
		switch (decision)//switch the value of decision
		{
		case 1://user case one, a manager
			system("cls");//clear the screen
			m.decision();//run function decision on class manger
			break;//breakout from the menu
		case 2://user casee two, a chef
			system("cls");//clear the screen
			c.choice();//run function choice() on class chef
			break;//breakout from the loop
		case 3: //user case three, a customer
			system("cls");//clear the screen
			service();//runf function service()
			break;//breakout from the loop
		case 4:
			cout << "Goodbye" << endl;//display goodbye
			return 0;//return to the OS
		}
	}
}