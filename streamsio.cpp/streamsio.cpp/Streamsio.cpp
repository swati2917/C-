// this is a stream prog
#include <iostream>
#include <string>

using namespace std;
int l;
int b;
int ar;
string myname;

int main()

{
	cout << "please enter your name";
	getline(cin, myname);

	cout << myname << endl;

	cout << "please enter length" << endl;
	cin >> l ;
	cout << endl;
	cout << "please enter breath" << endl;
	cin >> b;
	ar = l*b;

	cout << ar << endl;
	


}
