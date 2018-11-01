#include <iostream>
using namespace std;


void printmessage(){

	cout << "i am a void function"<<endl;
	cout << " i dont return anything" << endl;
}

void copy(int& a, int& b, int& c)
{
	a *= 2;
	b *= 2;
	c *= 2;
}

void duplicate(double& d, double& e, double& f )
{


	d /= 2;
	e *= 5;
	f += 7;
}

void odd(int s);
void even(int s);
	
int main()
{

	printmessage();
	int x = 1, y = 3, z = 7;
	copy(x, y, z);
	cout << "x=" << x << ", y=" << y << ", z=" << z<< endl;
	
	

	double g = 3.45, h = 6.67, i = 8.99;
	duplicate(g, h, i);
	cout << "g=" << g << ",  h= " << h <<", i=" << i << endl;
	


	int m;
	do
	   {
		   cout << "please enter a number" << endl;
		   cin >> m;
		   odd(m);
	} while
		(m!= 0);
	return 0;
}
void odd(int s)
{
	if ((s % 2) != 0) cout << "It is odd."<< endl;
	else even(s);
}

void even(int s)
{
	if ((s % 2) == 0) cout << "It is even." << endl;
	else odd(s);
}