//the source code use for dish ad menu informatikon processing
#include <iostream>//include the information about the standard library iostream
#include <fstream>//include the information about the standard library fstream
#include <time.h>//include the information about the standard library time.h
#include <string>//include the information about the standard library string
#include <iomanip>//include the information about the standard library iomanip
#include "menu.h"//include the information about the head file "menu.h"
#include "raw material.h"//include the information about head file "raw material.h"
#include <windows.h>//include the information about the standard library windows.h

using namespace std;//using the standard name

const char* file = "menuk.txt";//set the file probe menuk.txt

//the function to add dish to menu
int dish::addmenu(){
	for (;;){
		char decision;//define a charctor decision
		material m;//instentiation the class material
		m.showmaterial();//run the function showmaterial() on class material to display the material left
		dish a, b;//instentiation the class dish twice with a and b
		ifstream fin;//reset the font stream
		ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
		if (!fout.is_open())//cant open the file
		{
			cout << "Can't open" << file << endl;//display to inform the problem
			exit(EXIT_FAILURE);//exit the program with value "EXIT_FAILURE"
		}
		fout.close();//close the file
		cout << "Please enter the name of the dish" << endl;///ask to enter the name dish
		flushall();//run the function flushall
		cin.get(a.dishname, 21);//get the dishname on class dish a
		flushall();
		cout << "Please enter the prcie of the dish" << endl;//get the price of the new dish
		cin >> a.price;//get the value of price of the new dish
		flushall();
		while (!cin)//if the input is invalid
		{
			cout << "Please enter numbers!" << endl;//display to inform to enter the number
			cin.clear();//clear the input
			cin.sync();//reset the input
			cin >> a.price;//get the new input to the varible price on class dish a
		}
		for (int i = 0; i < 60; i++)//get the material information
		{
			cout << "Please enter the material you want" << endl;//get the material
			cin >> a.dishmet[i];//get the input value to the varible dishmet
			cout << "Do you want to add another one(any input except q) or quit(Q)" << endl;//ask whether to quit
			cin >> decision;///get the input to the varible decision
			if (decision == 'Q' || decision == 'q')//quit from the add
			{
				break;//breakout from the loop
			}
			else//press other key to get the to add a new dish
			{
				continue;//continue the loop
			}
		}
		a.ID = 1;//set the basic ID as one
		fin.open(file, ios_base::in | ios_base::binary);//open the file for write information in
		if (fin.is_open())//open the file
		{
			while (fin.read((char *)&b, sizeof b) && strcmp(b.dishname, a.dishname))//if player name can't be matched, continue the loop, otherwise ask the user to input another name
			{
				a.ID++;//add up the ID number
				continue;//continue the loop
			}
			if (!(strcmp(b.dishname, a.dishname)))//the dish name is exit in the file
			{
				printf("this dishname exists already, please choose another one!\n");//display to inform the dish is exit in the file
				Sleep(1000);//stop for one second
			}
			else//the dish is not in the datafile
			{
				fout.open(file, ios_base::out | ios_base::app | ios_base::binary);//open the file to save the dish data
				fout.write((char*)&a, sizeof a);
				cout << "the dish order is:" << a.ID << endl;//display the dish ID
				cout << "Add successfully" << endl;//display to inform success add
				fout.close();//close the file
			}
		}
		else {//if fail to open, then tell the player to restart the game
			cout << "There was some error, please restart the programme\n";
			Sleep(1000);//stop for one second
			exit(1);//exit with value 1
		}
		fin.close();//close the file
		char choice;//define a charctor choice
		cout << "Do you want add another dish? Y or N" << endl;
		cin >> choice;//get the input value to the varible choice
		if (choice == 'Y' || choice == 'y')//user choose to add another dish
		{
			continue;//continue the loop
		}
		else//the choice is not y or Y
		{
			return 2;//return with the value 2
		}
	}
}

//the function to edit the value
int dish::editmenu(){
	dish temp;//instentiation the class dish with temp
	dish see;//instentiation the class dish with see
	char newname;//define a new charctor newname
	char choice;//define a charctor choice
	material mee;//instrntiation the class material with mee
	ifstream fin;//reset the font stream
	ofstream fout;
	long sp;//define a long integer sp
	fin.open(file, ios_base::in | ios_base::binary);//open the file
	for (;;){
		if (fin.is_open())//the file is open
		{
			cout << "Please enter the name of dish you want to change:" << endl;//input the name to change
			flushall();
			cin.get(temp.dishname, 21);//get the input value for dish name 
			flushall();
			while (fin.read((char*)&see, sizeof see) && strcmp(see.dishname, temp.dishname))//search the input name in the file
			{
				continue;//continue the loop
			}
			if (!(strcmp(see.dishname, temp.dishname)))//the dish is found in the file
			{
				sp = fin.tellg();
				cout << "******************************************************" << endl;//display the edit menu
				cout << "the information of the dish you want to edit:" << endl;
				cout << "The ID of this dish is: " << see.ID << endl;
				cout << "The price of this dish is: " << see.price << endl;
				cout << "The raw material of this dish is" << endl;
				for (int i = 0; i < 60; i++){
					temp.dishmet[i] = see.dishmet[i];//get the dish meterial
				}
				for (int i = 0; i < 60; i++){
					if (mee.searchmaterial(see.dishmet[i]) == ""){
						break;//breakout from the loop
					}
					cout << see.dishmet[i] << ". " << mee.searchmaterial(see.dishmet[i]) << endl;//display the infromtaion before edit
				}
				cout << "******************************************************" << endl;
			}
			else//the dish is not found
			{
				cout << "This dish doesn't exist" << endl;//display to inform the dish is not found
				Sleep(3000);//stop for three second
				return 0;//return with value 0
			}
		}
		fin.close();//close the file
		temp.ID = see.ID;//get the dish ID
		cout << "Do you want to change the name(n) or price(p)" << endl;//ask the item user want to change the dish
		flushall();
		cin >> choice;//get the input value to the varible choice
		if (choice == 'N' || choice == 'n')//the user choose to change name
		{
			temp.price = see.price;//put the price not change
			cout << "Please input the new name:" << endl;//display to ask to input the new name
			flushall();
			cin.get(temp.dishname, 21);//get the new name
			flushall();
			fout.open(file, fstream::binary | fstream::out | fstream::in);//open the file
			if (!fout.is_open())//if the file is not open 
			{
				cout << "There was some error, please restart the game\n";//display the problem and quit
				Sleep(1000);//stop for one second
				exit(0);//exit with the value 0
			}
			sp = sp - sizeof(temp);
			fout.seekp(sp);//look for the same variable in the file
			fout.write((char*)&temp, sizeof temp);//write data into the file
			cout << "You have changed successfully!\n";//tell the user create successfully
			fout.close();//close the file
			Sleep(6000);//stop for six second
			return 2;//return with value 2
		}
		else if (choice == 'p' || choice == 'P')//the user choose to edit the price
		{
			cout << "Please input the new price:" << endl;//ask to input the new price
			flushall();
			cin >> temp.price;//get the new price value
			fout.open(file, fstream::binary | fstream::out | fstream::in);
			if (!fout.is_open())//the file is not open
			{
				cout << "There was some error, please restart the game\n";
				Sleep(2000);//stop for two second
				exit(0);//exit the system
			}
			sp = sp - sizeof(temp);
			fout.seekp(sp);//look for the same variable in the file
			fout.write((char*)&temp, sizeof temp);//write data into the file
			cout << "You have changed successfully!\n";//tell the user create successfully
			Sleep(6000);//stop for six second
			fout.close();//close the file
			return 2;//return with the value 2
		}
	}
}


//the function to search for the dish information
int dish::searchmenu(){
	dish seek;//instentiation the class dish
	char dname[20];//define a charctor dname with 20 digit limit
	char decision;//define a charctor decision
	material mw;//instentiation the class material
	ifstream fin;
	ifstream fin1;
	int num;//define a new integer num
	fin.open(file, ios_base::in | ios_base::binary);//open the file
	for (;;){
		cout << "Please enter the dish name you want to look for" << endl;//display to ask for the dish name
		flushall();//run the function flushall()
		cin.get(dname, 21);//get the dish name
		flushall();//run the function flushall()
		if (fin.is_open())//open the file
		{
			while (fin.read((char*)&seek, sizeof seek) && strcmp(seek.dishname, dname))//read the dish file for the dish name
			{
				continue;//continue the loop
			}
			if (!(strcmp(seek.dishname, dname)))//displayt the dish information except the material
			{
				cout << "The ID of this dish is: " << seek.ID << endl;
				cout << "The name of this dish is: " << seek.dishname << endl;
				cout << "The price of this dish is: " << seek.price << endl;
				fin.close();
				for (int i = 0; i < 60; i++){
					if (mw.searchmaterial(seek.dishmet[i]) == "")//get the dish material information
					{
						break;//break out from the loop
					}
					cout << seek.dishmet[i] << ". " << mw.searchmaterial(seek.dishmet[i]) << endl;//display the dish material information
				}
				cout << "Do you want to go back to the frame? (input 'y' to go back)" << endl;//ask the user to go back
				cin >> decision;//get the input value of goback to last menu
				flushall();
				if (decision == 'Y' || decision == 'y')//the decision to go back
				{
					return 2;//return with the value 2
				}
			}
			else//the dish is not found
			{
				cout << "This dish doesn't exist" << endl;//display the dish is not found
				_sleep(2000);//stop for two second
				fin.close();//close the file
				return 2;//return with the value 2
			}
		}
		else//the file of the menu cant be open properly
		{
			cout << "There was some error, please restart the programme\n";
			Sleep(1000);//stop for one second
			exit(0);//exit to the system with value 0
		}
		fin.close();//close the file
	}
}

//the function to display the menu
int showmenu()
{
	dish show;//instantiation the dish
	ifstream fin;//reset the font stream
	char decision;//define a new charctor decision
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())//opoen the dish file
	{
		cout << "The menu is listed below:" << endl;//display the dish
		while (fin.read((char*)&show, sizeof show))//get the information of the certain dish
		{
			cout << show.ID << ": " << show.dishname <<setw(12)<<"price: "<<show.price<<endl;//display the price of the dish
		}
		fin.close();//close the file
	}
	cout << "input 'y' to go back to the frame or other keys to continue" << endl;//display to ask user to goback
	cin >> decision;//get the input decision to the varivle decision
	if (decision == 'Y' || decision == 'y')//if the value of decision is Y or y
	{
		return 2;//return with the value 2
	}
}

//the function use to get and return the price gor the certain dish
int dish::getmoney(int x)
{
	dish expense;//instentiation the class dish
	ifstream fin;//reset the font stream
	fin.open(file,ios_base::in | ios_base::binary);//open the file
	while (fin.read((char*)&expense, sizeof expense))//red the information in the file for the cretain dish
	{
		if (expense.ID == x)//get the dish ID
		{
			return expense.price;//return with the price of dish 
		}
	}
	fin.close();//close the file of dish information
}

//the functioln to calculate the total dish number in the menu
int dish::menunumber()
{
	dish n;//instentiation the class dish
	int num=0;//define an integer num and set its value to 0
	ifstream fin;//reset the font stream
	fin.open(file, ios_base::in | ios_base::binary);//open the file
	while (fin.read((char*)&n, sizeof n))//the dish inofmation is found
	{
		num++;//add up the number of dish 
	}
	return num;//return with the value of num
}

string dish::dishnameaaa(int x){
	dish expense;//instentiation the class dish
	ifstream fin;//reset the font stream
	fin.open(file, ios_base::in | ios_base::binary);//open the file
	while (fin.read((char*)&expense, sizeof expense))//read the expence value in the menu
	{
		if (expense.ID == x){
			return expense.dishname;//return with the dishname on expence value 
		}
	}
	fin.close();//close the file 
}

