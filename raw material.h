//the head file use for raw material cpp
#ifndef __material__
#define __material__
#include <iostream>//include the information about the standard library iostream
using namespace std;//using the standard name
#include "menu.h"//incllude the informatikon about the head file "menu.h"

class material:public dish//define a class material under dish 
{
public:
	char rawmaterial[20];//define a charctor rawmaterial in 20 digits limits
	int number;//difine an integer number
	int addmaterial();//define an function addmaterial ()
	void showmaterial();//define an function showmaterial()
	string searchmaterial(int x);
};
#endif