#include <iostream>
using namespace std;



double liters_per_gallon = 0.264179;


//double NumberOfMilesPerGallon ( double liters, double milesTravelled ;


int main()
{
	double liters = 0;
	double milesTravelled = 0;
	double  milesPerGallon = milesTravelled / (liters*liters_per_gallon);


	do
	{
		cout << "How many liters of gas was used:" << endl;
		cin >> liters;

		cout << "How many miles did it travel :" << endl;
		cin >> milesTravelled;


		cout << "this car delivers the average of :" << milesPerGallon << endl;

		cout << "Would you like to enter information for another car? Y/N: " << endl;


	}


	while (liters >-1);

	return 0;
}
