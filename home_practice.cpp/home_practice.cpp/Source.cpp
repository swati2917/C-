#include <iostream>
# include <sstream>
#include <fstream>
using namespace std;


int main()
{

	ifstream f1;
	f1.open("data.txt");

	ifstream f2;
	f2.open("student.txt");

	string line;

	if (f1.fail())
	{
		cout << "please check the file" << endl;
	}
	
	else
	{
		while (!f1.eof())
		{
			//f1 >> line;
			getline(f1, line);
			cout << line << endl;
		}
		
	}
	f1.close();

	//system.wait();


	string line2;
	int id, count;
	string fname, lname;
	
	stringstream ss;

	if (f2.fail())
	{

		cout << "please check the file" << endl;
	}
	else

	{
		while (!f2.eof())
		{
			getline(f2, line2);
				ss << line2;
				ss >> id >> fname >> lname >> count;
				cout << id << '\t' << fname<< '\t' << lname<< '\t' << count << endl;
				

		} 
		f2.close();
	}


}