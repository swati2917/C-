// this is a getline function program
#include <iostream>
#include <string>

using namespace std;
string name;
string mobnum;
string address;
string zipcode;


int main()
{
	cout << "enter name= " ;
	getline (cin, name);
	cout << "\n";
	cout << "enter mobnum= " ;
	getline (cin, mobnum);
	cout << "\n";
	cout << "address=";
	getline(cin, address);
	cout << "\n";
	cout << "enter zipcode=";
	getline(cin, zipcode);
	cout << "\n";
	cout << "Hello my name is " << name << endl;
	cout << " i live in " << address << endl;
	cout << "my mobile number is " << mobnum << endl;
		cout << "my zipcode is" << zipcode;



}