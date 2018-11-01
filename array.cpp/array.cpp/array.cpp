//question 2 program
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int y1, y2; // 

	for (int n = 0; n <= 100; n = n + 10){

		y1 = 100 * n + 10;
		y2 = 5 * n * n + 2;

		cout << "The Value of Y1=" << y1 << endl;
		cout << "The value of Y2=" << y2 << endl;
	}
		if (y1 > y2)
		{
			cout << "Y1 is greater" <<y1 << endl;
		}
		else
		{
			cout << y2 << endl;
			
		}
		