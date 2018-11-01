#include <iostream>
using namespace std;

int subtraction(int a, int b)
{
	int v;
	v = a - b;
	return v;

}

void excellent()
{

	cout << "i am useless";
}

int main()
{

	int result;
	int x = 7;
	int y = 9;
	result = subtraction(66, 55);
	cout << "The resut is:" << result << endl;
	cout << "The second result is :" << subtraction(6, 3) << endl;
	cout << "third result" << subtraction(x, y) << endl;
	result = 6 + subtraction (x,y);
	cout << result << endl;
	 excellent();
}


