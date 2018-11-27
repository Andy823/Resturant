//the head file use to process menu.cpp
#ifndef __dish__
#define __dish__
#include<iostream>//include the information about the standard library iostream
using namespace std;//using the standard name 
class dish//difine a class dish
{
public:
	char dishname[20];//define a charctor dishname in 20 digits limit
	int ID;//define a integer ID
	int price;//define an integer price
	int dishmet[60];//define an integer dishmet in 60 digit
	int addmenu();//define the function addmenu()
	int editmenu();//define the function editmenu()
	int searchmenu();//define the function searchmenu()
	int getmoney(int x);//define the function getmoney()in x integer
	int menunumber();//fefine the function menunumber()
	string dishnameaaa(int x);//string the function dishnameaaa()
};
int showmenu();//define an function showmenu()
#endif