//the headfile for chef
#ifndef __chef__
#define __chef__

#include<iostream>//include the information about the standard library iostream
using namespace std;//using the standard name

#include"menu.h"//include the information about the head file "menu.h"
#include"raw material.h"//include the information about the head file "raw material.h"

class chef//define a class shef
{
public:
	int choice();//define a function choice()
	int searchorder();//define a function searchorder()
	void showorder();//define a function showorder()
	void deleteorder();//define a function deleteorder()
};
#endif//end of the head file
	