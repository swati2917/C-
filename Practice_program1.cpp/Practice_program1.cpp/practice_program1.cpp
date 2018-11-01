/*#include <iostream>
#include <cmath> 
using namespace std;

double GetXVal();
// PRE: None. 
// POST: Returns a value for X that is > 0. Loops until user enters valid value. 
// I/O: Output prompts to screen, input from keyboard. 
// INTERACTION W/ USER: See above 
// ERROR HANDLING: None. 
// RETURNS: Value of X, X > 0. 

int GetIters();
// PRE: None. 
// POST: Returns a value for iterations that is > 0 and < 100,000. 
//      Loops until user enters valid value. 
// I/O: Output prompts to screen, input from keyboard. 
// INTERACTION W/ USER: See above 
// ERROR HANDLING: None. 
// RETURNS: Value of Iters, 0 < X < 100,000. 

double BabylonianRoot(double x, int iters);
// PRE: x > 0, 0 < iters < 100,000.
// POST: Returns value computed by iters iteration of Babylonian algorithm 
//       starting with an estimate of 1.0. 
// I/O: None.  
// INTERACTION W/ USER: None. 
// ERROR HANDLING: None. 
// RETURNS: Estimate of square root. 


int main()
{
	bool Again = true;
	char ch;
	double X;
	int iters;

	while (Again)
	{
		X = GetXVal();
		iters = GetIters();
		cout << "Babylonian method with " << iters << " iterations computes value of "
			<< BabylonianRoot(X, iters) << ";\n"
			<< "Math library computes value of " << sqrt(X) << endl << endl;
		cout << "Try another [Y/N]? ";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			Again = false;
	}
	return 0;
}

double GetXVal()
{
	double X = -1.0;

	while (X <= 0)
	{
		cout << "Enter a value to find the square root of: ";
		cin >> X;
		if (X <= 0)
			cout << "Value must be > 0 to have a real square root; try again.\n";
	}
	return X;
}



int GetIters()
{
	int iters = -1;

	while (iters <= 0 || iters > 100000)
	{
		cout << "Enter a value for the number of iterations: ";
		cin >> iters;
		if (iters <= 0)
			cout << "Value must be > 0; try again.\n";
		else if (iters >= 100000)
			cout << "Value must be less than 100,000; try again.\n";
	}
	return iters;

}

double BabylonianRoot(double x, int iters)
{
	double est = 1.0;

	for (int j = 0; j < iters; j++)
	{
		if ((x / est) == est)
			return est;  // converged to machine accuracy, no point 
		else             // in continuing 
			est = (est + (x / est)) / 2.0; // otherwise try again 
	}
	return est;
}*/

#include <iostream>
#include <cmath>
using namespace std;


double GetXValue();

int GetIters();

double BabylonianRoot(double x, int iters);

int main()
{
	bool Again = true;
	char ch;
	int iters;
	double X;

	while (Again)
	{
		X = GetXValue();
		iters = GetIters();
		cout << "Babylonian method with" << iters << "iterations computes value of"
			<< BabylonianRoot(X, iters) << ";\n"
			<< "Math library computes the value of" << sqrt(X) << endl;
		cout << "Try another [Y/N]" << endl;
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			Again = false;


	}
	return 0;
}
double GetXValue()
{
	double X = -1.0;

	while (X <= 0)
	{
		cout << "Enter the value to find the sqrt of:";
		cin >> X;
		if (X <= 0)

			cout << "value must be >0 to have a real sq root;try again\n";

	}
	return X;
}
int GetIters()
{
	int iters = -1;

	while (iters <= 0 || iters >= 100000)

	{
		cout << "enter the number of iterations";
		cin >> iters;
		if (iters <= 0)
			cout << "Value must be > 0; try again.\n";
		else if (iters >= 100000)
			cout << "Value must be > 100000; try again.\n";
	}
	return iters;
}
double BabylonianRoot(double x, int iters)
{
	double est = 1.0;


	for (int j = 0; j < iters; j++)
	{
		if ((x / est) == est)
			return est;  // converged to machine accuracy, no point 
		else             // in continuing 
			est = (est + (x / est)) / 2.0; // otherwise try again 
	}
	return est;
}




 


	
	
	
	











