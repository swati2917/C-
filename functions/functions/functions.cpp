#include <iostream>
#include <cmath>
using namespace std;

int subtraction(int a, int b)
{
	
	 
	int r = a - b;
	return r;

}

int division(int x, int y)
{

	int r = x / y;
	return r;
}


double multiplication(double c, double d)
{

	double s = c*d;
	return s;

}

int main()
{
	int z;
  z = subtraction(9, 7);
	cout << "The answer is =" << z << endl;

	int r;
	r = division(400, 200);
	cout << "The answer is =" << r << endl;


	double s;
	s = multiplication(509.77, 609.77);
	cout << "The answer is=" << s << endl;

	double s1 = 33.33;
	cout << s1; 
}

