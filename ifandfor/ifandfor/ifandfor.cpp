//this is if and for practice program

#include <iostream>
using namespace std;

int main()
{

	int marks;

	int amount;


	int vamount = amount % 10;

	if (vamount == 0){

		cout << "Dispense the money" << endl;
	}
	else {
		cout << "Sorry enter in multiple of 10 only" << endl;
	}
	cout << "Please enter yor marks ";
	cin >> marks;

	if (marks > 90)
	{
		cout << "Congrats you got 100% scholarship" << endl;

	}
	else if (marks >=80 && marks <= 90 )
	{
		cout << "You will get 90 % scholarship" << endl;
	}
	else if (marks >= 70 && marks < 80)
	{
		cout << "You will get 70% scholarshio" << endl;
	}
	else {

		cout << "Not Eligible for Scholarship" << endl;
	}



}