//the head file for customer .cpp
#include <string>//include the information about the standard library string
#include <vector>//include the information about the standard library vector
using namespace std;//using the standard name

class Customer//define a class customer
{
public:
	string name = "unknown";//string name
	double balance= 0;// define a double integer balance
	string password = "000000";//string a password
	double totalprice = 0; // define a double integer total price
	double lastprice = 0; ////define a doble integer total price last time
	bool ordered = false;  // whether have ordered
	bool lastcheck = true; //whether checked out last time
	bool checkedout = true;  //the state of having checked out initially 
    vector<int> dishes;       //the ID of each dish
	vector<string> nameofdish;
	vector<double> dishprice; //the set of prices of each dish

	
	void checkout(); //check out
	void order();    //order
	void recharge(); //recharge the account
};
void service();
void showinfo();
string converttostring(double d);
double convertfromstring(string str);

