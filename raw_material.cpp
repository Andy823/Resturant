//the source code to process the information about the raw materials
#include <iostream>//inclued the information about the standard library iostream
#include <fstream>//include the information about the standard library fstream
#include <time.h>//include the information about the standard library time.h
#include <iomanip>//includde the information about the standard library iomanip
#include "raw material.h"//include the informatrion about the head file "raw material .h"
#include <windows.h>//include the information about the standard library windows .h
using namespace std;//using namespace std


const char* fileA = "rawmaterial.txt";//set probe to file "rawmaterial.txt"

//the function to add material
int material::addmaterial(){
	for (;;){
		material a, b;//instentiation to class material with a and b
		ifstream fin;//reset the font stream
		ofstream fout(fileA, ios_base::out | ios_base::app | ios_base::binary);//open the file
		if (!fout.is_open())//if the file is not open
		{
			cout << "Can't open" << fileA << endl;//display to inform the file is not open
			exit(EXIT_FAILURE);//exit 
		}
		fout.close();//close the file
		cout << "Please enter the name of the material" << endl;//ask to input the name of new raw material
		cin >> a.rawmaterial;//get the row material information value to the varible rawmaterial
		a.number = 1;//set the number as one
		fin.open(fileA, ios_base::in | ios_base::binary);//open the file for write information in
		if (fin.is_open())//if the file is open
		{
			while (fin.read((char *)&b, sizeof b) && strcmp(b.rawmaterial, a.rawmaterial))//if player name can't be matched, continue the loop, otherwise ask the user to input another name
			{
				a.number++;//add the number
				continue;//continue the loop
			}
			if (!(strcmp(b.rawmaterial, a.rawmaterial)))//if the material is found in the file
			{
				printf("this material exists already, please choose another one!\n");//display to infrom the material is exit already
				Sleep(1000);//stop for one second
			}
			else//there is no same raw material
			{
				fout.open(fileA, ios_base::out | ios_base::app | ios_base::binary);//open the file 
				fout.write((char*)&a, sizeof a);
				cout << "the material order is:" << a.number << endl;//display the new material 's number
				cout << "Add successfully" << endl;
				fout.close();//close the file
			}
		}
		else {//if fail to open, then tell the player to restart the game
			cout << "There was some error, please restart the programme\n";
			Sleep(1000);//stop for one second
			exit(1);
		}
		fin.close();//close the file
		char choice;//define an charctor choice
		cout << "Do you want add another material? Y or N" << endl;
		cin >> choice;//input the choice
		if (choice == 'Y' || choice == 'y')//the user choose to add new material
		{
			continue;//continue the loop
		}
		else//the user choose to quit
		{
			return 2;//return with vallue 2
		}
	}
}

//the function to show the material
void material::showmaterial(){
	material show;//instentiation the class material
	char decision;//define a charctor decision 
	ifstream fin;//reset the font stream
	fin.open(fileA, ios_base::in | ios_base::binary);//open the file
	if (fin.is_open())//the open is success
	{
		cout << "The raw material is listed below:" << endl;
		while (fin.read((char*)&show, sizeof show))//get all the information of the raw material
		{
			cout << show.number << ": " << show.rawmaterial<< endl;//display the row material
		}
		fin.close();//close the file
	cout << "You can input 'y' and ENTER to go on" << endl;//display to ask to go on
	while (true)//the states is true
	{
		char y;//define a charctor y
		cin >> y;//get the input value to the varible y
		if (y == 'y' || y == 'Y')//if the user case y or Y to exit to the menu
		{
			break;//breakout from the loop
		}
		else cout << "invalid input!";//display to inform the invalid input
	}
	}
}

//the function to search for the function
string material::searchmaterial(int x){
	material search;//instentiation of the class material
	ifstream fin;//reset the font stream
	fin.open(fileA, ios_base::in | ios_base::binary);//open the file
	while (fin.read((char*)&search, sizeof search))//read and search the value of raw material
	{
		if (x == search.number)//if x is the number
		{
			return search.rawmaterial;//return the value
		}
		else//the row material is not found
		{
			continue;//continue the loop
		}
	}
	fin.close();//close the fiel
	return "";//return 
}