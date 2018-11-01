/*********************************************


Name: Swati Singh
Course:	CS 201 R
Program:	Babylonian Algorithim
Due Date:
Inputs:	int >0 and <100000.
Outputs: actual sqrt and babylonian algorithim's sqrt.


*********************************************/
#include <iostream>
#include <cmath>

using namespace std;

double sqroot()
{
	double number = 0.0;
	do
	{
		cout << "enter a number>0" << endl;
		cin >> number;
	} while (sqroot <= 0); 
	return number;
}

int round()
{
	int count = 0;
	while (count <= 0 || count >= 100000)
	{
		cout << "enter number of iteration between 0 and 100,000" << endl;
		cin >> count;
	}
	return count;
}

double calculation(double number, double guess, int count, double actualroot)
{
	double result;
	for (int i = 0; i <= count; i++);
	{
		result = (guess + (number / guess)) / 2;
		if (result == actualroot)
		{
			return result;
		}
		
	}
	return result;
}


int main()
{
	while (true)
	{
		double number = 0.0;
		int count = 0;
		double guess = 0.0;
		double actualroot = 0.0;
		double result = 0.0;
		int runagain = 0;

		number = sqroot();
		count = round();
		guess = number / 2;
		actualroot = sqrt(number);
		result = calculation(number, guess, count, actualroot);



		cout << "The square root is: " << result << endl;
		cout << "The actual square root is : " << actualroot << endl;
		cout << "Do u want it to run again : 0=N, 1=Y ";
		cin >> runagain; 
		 
		if (runagain == 0)
		{
			return 0;

		}
	}
}