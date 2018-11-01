#include <string> 
#include <iostream> 
#include <fstream> 
#include <ctime>
#include <string>
#include "MenuItem.h"
#include "Pizza.h"
#include "Sandwich.h"
using namespace std;

float DiscountToBe(const MenuItem& thing);


int main()
{
	ifstream fin;
	ofstream fon;

	const int MAX = 100;

	MenuItem* M[MAX];

	for (int k = 0; k < MAX; k++)
	{
		M[k] = nullptr;
	}

	
	int NMenu=0;
	float price, disc_price, total, total_disc;
	char item_type;
	string junk;

	// srand(time(NULL)); 
	int NumPizza = 0;
		int NumSand = 0;
	price = disc_price = total = total_disc = 0.0f;

	fin.open("program5data.txt");
	while (fin >> item_type)
	{
		getline(fin, junk); // read and discard \n after type
		switch (item_type)
		{
		case 'P':
			M[NMenu] = new Pizza;
			M[NMenu] -> ReadData(fin);
			price = M[NMenu] -> GetPrice();
			disc_price = DiscountToBe(*M[NMenu]);
			total += price;
			total_disc += (price - disc_price);
			NMenu++;
			NumPizza++;
			break;
		case 'S':
			M[NMenu] = new Sandwich;
			M[NMenu] -> ReadData(fin);
			price = M[NMenu] -> GetPrice();
			disc_price = DiscountToBe(*M[NMenu]);
			total += price;
			total_disc += (price - disc_price);
			NMenu++;
			NumSand++;
			break;
		default:
			cerr << "Please Check Item " << item_type << endl;
		}
	}
	fin.close();

	fon.open("program5output.txt");

	if (fon.fail())
	{
		cout << "please check the classes file";
	}
	else
	{
		for (int s = 0; s < NMenu; s++)
		{
			if (M[s]->WhatAmI() == "Pizza")
				M[s]->WriteData(fon);
		}

		for (int a = 0; a <NMenu; a++)
		{
			if (M[a]->WhatAmI() == "Sandwich")
				M[a]->WriteData(fon);
		}
	}
	fon.close();


	cout << "Pizzas sold: " << NumPizza << '\n'
		<< "Sandwiches sold: " << NumSand << '\n'
		<< "Total sales: $" << total << '\n'
		<< "Less discount: $" << total_disc << '\n'
		<< "Net sales: $" << (total - total_disc) << endl;
	system("pause");

	for (int j = 0; j < NMenu; j++)
		delete M[j];

	delete [] M ;
	return 0;
}


float DiscountToBe(const MenuItem& thing)
{
	int prob;

	prob = rand() % 100;
	if (prob < 20)
		return thing.GetPrice() * 0.8;
	else
		return thing.GetPrice();
}
