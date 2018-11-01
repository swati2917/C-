#include <iostream>
#include <fstream>

#include <sstream>
using namespace std;


int main()
{

	ofstream file1;
	file1.open("enrollment.txt");

	string line;

	if (file1.fail())
	{


		cout << "please check the file" << endl;
	}
	else
	{
		while (!file1.eof())
		{
			//getline(file1, line);
			cout << line << endl;
		}
	}
	file1.close();
}