//the source code to process the information of manager
#include <iostream>//include the information about the standard library iostream
#include <fstream>//include the information about the standard library fstream
#include<vector>//include the information about the standard library vector
#include<algorithm>//include the information about the standard library algorithm
#include <string>//include the information about the standard library string
#include <windows.h>//include the information about the stnadard library windows.h
using namespace std;//using the standard name


#include "menu.h"//include the information about the head file "menu.h"
#include "raw material.h"//include the information about the head file "raw material.h"
#include "manager.h"//includt the information about the head file "manager.h"
#include"customer.h"//include the information about the head file "customer.h"

//the function to process the manager option
int manager::decision(){
	int choice;//define the integer choice
	int password = 123;//define the integer password and set the value to 123
	int digit;//define the integer digit
	material b;//instantiation of class material
	dish a;//instantiation of class dish
	cout << "Welcome to the system, our manager" << endl;//display to ask the manager to login
	cout << "Please login first" << endl;
	cout << "Please enter the password" << endl;
	cin >> digit;//get the input password value to varible digit
	while (digit != password||!cin)//if the input passward is in correct or no input
	{
		cout << "Wrong password, please enter again" << endl;//display to inform the wrong password input,and ask to input again
		cin.clear();//clear the input
		cin.sync();//reset the input
		cin >> digit;//get the input value to varible digit
		continue;//continue the function
	}
	if (digit == password)//if the passward is correct
	{
		cout << "You have login successfully." << endl;//display to inform write passord
		Sleep(1000);//stop for two second
		system("cls");//clear the screen
		while (2)//while the system return's value is 2
		{
			system("cls");//clear the screen
			cout << "Please choose what you want to do" << endl;//display the manager's menu
			cout << "1. Add raw material" << endl;
			cout << "2. Show raw material" << endl;
			cout << "3. Read the menu." << endl;
			cout << "4. Edit the menu." << endl;
			cout << "5. Search the menu" << endl;
			cout << "6. Read the customer" << endl;
			cout << "7. show the order list and edit" << endl;
			cout << "8. Go back to the frame" << endl;
			cin >> choice;//get the value input to varible choice
			while (choice<0 || choice>8 || !cin)//if the input is not among the option
			{
				cout << "Wrong input, please input again" << endl;//display to inform the wrong input
				cin.clear();//clear the input
				cin.sync();//reset the input
				cin >> choice;//get the new input value to the varible choice
			}
			string orderdone;
			switch (choice)//switch with the choice 
			{
			case 1://manager case one, add raw material
				system("cls");//clear the screen
				b.addmaterial();//run the addmaterial() on class material
				break;//breakout from the loop
			case 2://manager case two, show the raw material
				system("cls");//clear the screen
				b.showmaterial();//run function showmaterial() on class material
				break;//break out from the loop
			case 3://manager case three, read the menu
				system("cls");//clear the screen
				showmenu();//run function showmenu()
				break;//breakout from the loop
			case 4://manager case four, edit the menu
				system("cls");//clear the screen
				a.editmenu();//run function editmenu() on class dish
				break;//breakout from the loop
			case 5://manager case five, search the menu
				system("cls");//clear the screen
				a.searchmenu();//run function searchmenu() on class dish
				break;//breakout from the loop
			case 6://manager case six,read the customer
				for (;;){
					readcus();//do the function readcus()
					cout << "\ninput 'y' if you want to go back";//display to inform user case y to go back
					if (getchar() == 'y')//if the input value is y
					{
						break;//break out from the loop
					}
					else//no input or input value is not y
					{
						continue;//continue the loop
					}
				}
				break;//break out from the loop
			case 7://manager case seven,show the order list
				ed:	//set the point ed
				system("cls");//clear the screen
				showinfo();//run the showinfo() function
				cout << "input the name of customer whose order has been dealed with:" << endl;//display to ask the order finshied
				cin >> orderdone;//get the input value for order done
				if (editorder(orderdone) == 1)///if the order done is 1
				{
					Sleep(4000);//stop for four second
					break;//breakout from the loop

				}
				else //if the value of editorder on order done is not one
				{
					goto ed;//goto point ed
				}
				break;//breakout from the loop
			case 8://if case 8, exit to the last menu
				return 1;//return with value 1
			}
		}
	}
}

//the function use to edit the order
int editorder(string x)
{
	ofstream out;//set out the stream
	vector<string> edit;//edit the order vector
	fstream file("info.txt");//open file info.txt
	string line;
	int position;//define an integer position
	int positiona;//define an integer positiona
	while (getline(file, line)){
		edit.push_back(line);
	}
	vector<string>::iterator it = find(edit.begin(), edit.end(), string(x));//edit the order with the informatikon input
	if (it != edit.end()){
		position = distance(edit.begin(), it);
		it = find(edit.begin() + position, edit.end(), "#");
		if (it != edit.end()){
			positiona = distance(edit.begin(), it);
			it = edit.erase(edit.begin() + position, edit.begin() + positiona + 1);
		}
		out.open("info.txt", ios::out); //output each name, balance and one's order
		if (edit.size() == 0)//the size of order is 0
		{
			cout << "there are no any order remained!";
			return 0;//return with value 0
		}
		else{
			for (size_t i = 0; i <= edit.size() - 1; i++)
			{
				out << edit[i] << endl;
			}
			out.close();//close the file
			cout << "update the order list successfully!";
			return 1;//return with the value 1
		}
	}

	else//the oder edit can't find the order
	{
		cout << "your choose is not in the order list!";//display to tell invalid order search
		Sleep(2000);//stop for two second
		system("cls");//clear the screen
		return 0;//return with value 0
	}
}

//the function use to read the customer information
void readcus()
{
	system("cls");//clear the screen
	vector<string> cuss;//set vector to customer information
	fstream f("lista.txt");//open the file"lista/txt"
	string line;//string the line
	while (getline(f, line))  //read lines in info.txt
	{
		cuss.push_back(line);
	}
	for (size_t i = 0; i <= cuss.size()-1; i=i+5){
		cout << "#################"<<endl;//display the customer information
		cout << "name: "<<cuss[i]<<endl;
		cout << "balance: " << cuss[i + 2] << endl;
		if (cuss[i + 3] == "0"){
			cout << "the customer has one unfinished payment, which price is: " << cuss[i + 4]<<endl;//display the order havent been paied
		}
		else{
			cout << "the customer has no unfinished payment." << endl;// display to inform all have been paied
		}
	}
}

