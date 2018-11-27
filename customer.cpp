//the source code use for process customer part
#include <sstream>//include the information about the standard library sstream
#include <iostream>//include the information about the standard library ioistream
#include <fstream>//include the information about the standard library fstream
#include <string>//include the information about teh standard library string
#include <vector>//include the information about the standard library vector
#include "menu.h"//include the information about the head file "menu.h"
#include"customer.h"//include the information about the head file "customer.h"
#include <windows.h>//include the information about the standard library "windows.h"

using namespace std;//using the standard name

//the function used to recharge the customer account(add balance)
void Customer::recharge(){       
	cout << "Your Balance:	" << this->balance << endl;		//show the balance
	cout << "How much do you want to recharge?" << endl;//ask user the balance to be recharged
	double money;//define a double as money
	cin >> money;//read in the money
	this->balance += money;	//add money to the balance
	cout << "Recharge Succeeds." << endl;
	cout << "Your Balance:	" << this->balance << endl;	//show current balance
	cout << "You can input 'y' and ENTER to go on" << endl;
	while (true){//test the invalid input
		char y;
		cin >> y;
		if (y == 'y' || y == 'Y')
		{
			break;
		}
		else cout << "invalid input!";
	}
}

//the function used to order the customer
void Customer::order()	
{
	
	dish d = dish();                //instantiation of class dish
ch://set the point ch
	showmenu();  //run the function showmenu() to show the menu
	for (;;)
	{
		cout << "Please choose the Number of dish." << endl;//ask the user to input the ID of the dish
		int num;//define an integer num
		cin >> num;//get the input value to varible num
		int nums = d.menunumber();                 //check whether inputted num is over the region of number in the menu
		if (num > nums) //if value of num is bigger than value in nums
		{
			cout << "Your choice is invalid." << endl;//
			goto ch;  //show the menu and choose again
		}
		else{
			this->dishprice.push_back(d.getmoney(num));		//put price of this dish into the vector of Customer
			this->dishes.push_back(num);		            //put number of dish into the vector of Customer
			this->nameofdish.push_back(d.dishnameaaa(num)); //put name of dish into the vector of Customer
		}
		reoption://set the point reoptiong
		cout << "1-------Choose deals again			2--------Quit order" << endl;//display the menu to process after one order
		int choice;//define a integer choice
		cin>>choice;  //get the input value to varible choice
		
		if (choice ==1){	//the choice is one, order again
			continue;//continue the loop
		}
		else if (choice == 2){		//the choice is two, quit order
			break;//breakout from the loop
		}
		else//the opthion is not one nor two 
		{
			cout << "Invalid Option" << endl;//display to inform invalid input	
			goto reoption;		//start from the point reoption choose again
		}
	}

	for (size_t i = 0; i <= dishes.size()-1; i++) //add each price of dish to the total price
	{
		this->totalprice += this->dishprice[i];//add the price together
	}

	cout << "Order Finished!" << endl;//display to inform the order is finished
	cout << "Your Total Price:	" << this->totalprice << endl; //show total price of this order
}

//the function to process the checkout procedure of cuetomer
void Customer::checkout(){   
	if (this->ordered == false) //if the order is false, the customer has not ordered the meals
	{
		cout << "You have not ordered." << endl;//display to inform the information
	}
else//customer has ordered meals
{		
op:	cout << "Total Price:	" << this->totalprice << endl; //display the total price of this order
	cout << "1. Payment by Cash\n2. Payment by Balance\n3. Recharge\n4. Inquiry Your Balance\n5. Give up paying\n "<< endl; //Options to check out 
	int n; //define an integer n
	cin >> n;//get the input value to varible n
	switch (n) //switch with the varible n
	{
	case 1:			//customer case one, pay by cash
		system("cls");//clear the screen
		cout << "Please go to the front desk to check out." << endl;//display to inform the checkout method
		Sleep(2000);//stop for two second
		cout << "Thanks for coming, welcome back!" << endl;
		this->checkedout = true; //change the state of check out
		Sleep(2000);//stop for two secod
		break;//break out from the loop
	case 2:  //cuetomer case two,pay by balance
		system("cls");//clear the screen
		if (this->balance >= this->totalprice){			//balance is enough
			this->balance -= this->totalprice;			//reduce the balance
			cout << "Spent Successfully." << endl;
			cout << "Your Remaining Balance:	" << this->balance << endl; //show the balance
			cout << "Welcome Back" << endl;
			this->checkedout = true;  //change the state of check out
			Sleep(2000);//stop for two second
		}
		else{   //balance is not enough
			cout << "Your balance is not enough, please recharge first!" << endl;//ask user to recharge the balance
			cout << "You can input 'y' and ENTER to go on" << endl;
			while (true){
				char y = cin.get();//read in the choice
				if (y == 'y' || y == 'Y')//test whether the input is valid
				{
					break;
				}
				else cout << "invalid input!";
			}
			goto op;//goto op
		}
		break;
	case 3://customer case three, recharge
		recharge();  //run function recharge() to recharge the account (add balance)
		break;//breakout from the loop
	case 4:			//customer case four, see the balance
		cout << "Your Balance:	" << this->balance << endl;  //show the balance
		cout << "Please input any Char to go back:" << endl;
		while (true){//test the input to be valid or not
			char y = cin.get();
			if (y == 'y' || y == 'Y')
			{
				break;
			}
			else cout << "invalid input!";
		}
		break;
	case 5: //customer case 5, Give up Payment
		cout << "You have one payment remained!" << endl;//display to inform the charge left
		cout << "Please input any Char to go back:" << endl;//display to inform goback
		while (true){//test the input to be valid or not
			char y = cin.get();
			if (y == 'y' || y == 'Y')
			{
				break;
			}
			else cout << "invalid input!";
		}
		break;
	default: 
		cout << "Your choice is invalid" << endl;//the choose in not in the option
		_sleep(3000);
		goto op;//start from point op
		break;//break out from the loop
    }
}
}

//the function to process customer information
void service(){        
	dish d = dish();//instantiation of class dish
	vector <string> list;	    //vector to store customer's name, password, balance, the states of last order and last checkout
	fstream file("lista.txt");	//list consists of persoanl information name, password, balance, the states of last order and last checkout
	string  l;
	while (getline(file, l))	//get each line and put it in the vector
	{
		list.push_back(l); 
	}
	int lengthoflist = list.size(); //number of elements in the vector
	Customer c = Customer();       //instantiation of class Customer 
    int newaccount = 1; //define a integer set the value to 1 to state of a new customer
start://set the point start
	string name; 
	int position;     //the index of balance in the Vector list
	cout << "1. Log In Your Account\n2.Create New Account" << endl;//display the login menu for customer
	int number;//define an integer number
	cin >> number;//get the input value to varible number
	if (number == 1)     //value of number is 1 Log in
	{
		system("cls");//clear the screen
		cout << "Please input your user name:" << endl;//ask to input the name
		cin >> name; //input name
		for (int i=0 ; i < lengthoflist; i++){  //check whether the name is in the namelist
			if (list[i] == name)
			{
				c.name = name;  //assign customer name
				newaccount = 0; //it is a regular customer
				position = i+2;
				break;//breakout from the loop
			}
		}

		if (newaccount == 1){	 // cannot find the account
			cout << "the username dose not exist, please register first!";//display to infom the account is not exit
			goto start;			//go back to rechoose
		}

		c.password = list[position-1];		//assign password
		c.balance = convertfromstring(list[position]);		//assign balance
		
		if (list[position+1] == "0"){
			c.lastcheck = false;	//assign the state of last checkout
		}	
		else{
			c.lastcheck = true;		//assign the state of last checkout
		}	 
		c.lastprice = convertfromstring(list[position+2]);		//assign last order's price
pass:   cout << "Please input your password:" << endl;  //inptut password
		string passwords;
		cin >> passwords;
		if (c.password != passwords)    //if password is not correct
		{
			cout << "Your password is incorrect." << endl;
			goto pass;//go back to the point pass
		}
		else{		                   //password is correct
			cout << "Login Succeeds." << endl;
			Sleep(2000);//stop for two seconds
			newaccount = 0;//state the states as old account
		}
	}
	    else if (number == 2)		//number is tworegister a new account for the customer
		{   
		rename: cout << "Please set your user name:" << endl;//set the point rename, ask to input the new user name
			cin >> c.name;		//input value to the varible name
		for (int i = 0; i < lengthoflist; i++){		//check whether the name is repeated
			if (list[i] == c.name)//the name is exit in the file already
			{
				cout << "The name has been registered." << endl;
				goto rename; //go back to rename, set name again
				break;//break out from the loop
			}
		}
		cout << "Please set your password:" << endl;///ask to set the password 
		cin >> c.password;		//input the value to the variblepassword
		cout << "New Account Succeeds." << endl; 
		Sleep(2000);//stop for two second
	}
	else//the choise is not in option
	{
		cout << "Your choice is invalid." << endl;//display to infrom invalid choice
		system("cls");//clear the screen
		goto start; //go back to the start
	}
	//char choose;/////////////////////////////
	if (c.lastcheck == false) //customer have not finished the last payment
	{
		
		system("cls");//clear the screen
		cout << "you have a unfinished payment last time.\n Please checkout your last order firstly." << endl;//display to inform unfinished pay ment
		cout << "Total Price:	" << c.lastprice << endl;  //show the last total price
choice:	cout << "1. Payment by Cash\n2. Payment by Balance\n3. Recharge\n4. Inquiry Your Balance" << endl;  //options on the pay ment of unfinished payment last time 
		int op;//define an integer op
		cin >> op;//input the value to varible op
		switch (op)//switch the option op
		{
		case 1:			//customer case one, pay by cash
			system("cls");//clear the screen
			cout << "Please go to the front desk to check out." << endl;//display the check out method
			Sleep(2000); //stop for two second                             
			cout << "Spent Successfully!" << endl;
			while (true){ //test the input to be valid or not
				char y = cin.get();
				if (y == 'y' || y == 'Y')
				{
					break;
				}
				else cout << "invalid input!";
			}
			break;//break out from the menu

		case 2://customer case two, pay by balance
			if (c.balance >= c.lastprice) //the balance is enough
			{
				c.balance -= c.lastprice;//reduce the balance by the value of price last time
				c.checkedout = true;//set checkout states to true
				cout << "Spent Successfully." << endl;//display to inform the success payment
				cout << "Your Remaining Balance:	" << c.balance << endl; //show the balance remained
				cout << "You can input 'y' and ENTER to go on" << endl;                    ///////////////////////////////////////
				while (true){//to test the input to be valid or not
					char y = cin.get();
					if (y == 'y' || y == 'Y')
					{
						break;
					}
					else cout << "invalid input!";
				}
			}
			else//the balance is not enough
			{
				cout << "Your balance is not enough, please recharge first!" << endl;//display to inform the balance is not enough
				cout << "You can input 'y' and ENTER to go on" << endl;
				while (true){//to test the input to be invalid or not
					char y = cin.get();
					if (y == 'y' || y == 'Y')
					{
						break;
					}
					else cout << "invalid input!";
				}
				system("cls");
				goto choice;
			}
			break;//break out from the loop
		case 3://customer case three, recharge the customer account
			c.recharge(); //run the recharge function on customer class
			_sleep(3000);
			system("cls");
			goto choice;//goto choice point directly
			break;//breakout from the loop
		case 4://customer case 4, view the balance
			cout << "Your Balance:	" << c.balance << endl;//display the balance for customer
			cout << "You can input 'y' and ENTER to go back" << endl;
			while (true){ //to test the input to be invalid or not                                                         
				char y = cin.get();
				if (y == 'y' || y == 'Y')
				{
					break;
				}
				else cout << "invalid input!";
			}
			goto choice;
			break;

		default:
			cout << "Your choice is invalid" << endl;//display to inform invalid input
			_sleep(3000);
			goto choice;//goto point choice
			break;//break out from the loop
		}
	}

option://set the point option
	int len = c.dishes.size();//int the string of customer
	string balances;
	string lastcheck;
	string lastprice;
	ofstream out;
	system("cls");//clear the screen
	char choice;//define a charctor choice
	cout << "1. Browse Menu\n2. Order\n3. Check Out\n4. Recharge the Account\n5. Exit" << endl;   //dis plancemain interface for the customer
	int n;//define an integer n
	cin >> n;//get the input value to varible n
	switch (n)//switch with the value n
	{
		
	case 1:     //case one,browser the menu
		system("cls");//clear the screen
		if (showmenu() == 2)//the return value of showmenu is 2
		{
			goto option;//goto the point option
		}
		break;//breakout from the value option
	case 2:		//case two,order meals
		c.order();			  //call the member function of customer to begin ordering
		c.ordered = true;     //change the state of order
		c.checkedout = false; //change the state of checkout
		goto option;//go to the point option
		break;//breakout from the loop
	case 3:		//check out
		c.checkout();//run the function checkout()
		goto option;//go to point option
		break;//breakout from the loop
	case 4:		//recharge the account
		c.recharge();//run the function recharge() on class cus
		goto option;//go to point option
		break;//break out from the loop
	case 5://customer case five exit from the customer part
	end : //set point end
		c.lastcheck = c.checkedout;
		c.lastprice = c.totalprice;
		balances = converttostring(c.balance);
		lastcheck = converttostring(c.lastcheck);
		lastprice = converttostring(c.lastprice);
		if (newaccount == 0){                    //save information for the old customer
			list[position] = balances;
            list[position + 1] = lastcheck;
			list[position + 2] = lastprice;
			out.open("lista.txt", ios::out);//open the file"lista.txt"
			for each  (string line in list)
			{
				out << line << endl;
			}
			out.close();//close the "lista.txt"
		}
		else{            //save information for the new customer
			out.open("lista.txt", ios::out | ios::app);//open the file"lista.txt"and save the data of customer
			out << c.name << endl;
			out << c.password << endl;
			out << balances << endl;
			out << lastcheck << endl;
			out << lastprice << endl;
			out.close();//close the file
		}

		cout << "Welcome Back" << endl;
		if (c.ordered == true){//do the loop if order return true
			out.open("info.txt", ios::out | ios::app); //output each name, balance and one's order
			out << c.name << endl;//print the name on the screen
			out << c.balance << endl;//print the balance on the screen

			for (int i = 0; i < len; i++)//do the loop when i is smaller than len
			{
				out << c.dishes[i] << "   " << c.nameofdish[i] << endl;//print the order on the screen
			}
			out << "#" << endl;
			out.close();
		}
		break;

	default:
		cout << "Your option is invalid." << endl;
		goto option;//goto point option
	    break;//breakout from the loop
	}


	
};

//function to show customer 's information
void showinfo(){    
	fstream f("info.txt");  //open the file "info.txt"
	string line;
	while (getline(f, line))  //read lines in info.txt
	{
		cout << line<<endl;
	}
}

//the file to convert string to dobuvar
double convertfromstring(string str){     //convert string to double var
	istringstream iss(str);
	double x;//define dobule x
	if (iss >> x)
		return x;
	return 0.00;
}

string converttostring(double d){         //convert double var to string
	ostringstream o;
	if (o << d)
		return o.str();
	return "invalidation";//return with incalidation value
}
