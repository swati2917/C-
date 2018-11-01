#include <string> 
#include <iostream> 
#include <fstream> 
#include <ctime>
#include <string>
#include "MenuItem.h"
#include "Pizza.h"
#include "Sandwich.h"
using namespace std;

float ApplyDiscountMaybe(const MenuItem& thing);
// Pre: None. 
// Post: thing is unchanged. 
// Returns: discounted price (if discount applies); original price otherwise. 
// I/O: None. 
// User interaction: None. 
// Error checking: None. 


int main()
{
	ifstream fin;
	Pizza piz;
	Sandwich sand;
	int NPiz, NSand;
	float price, disc_price, total, total_disc;
	char item_type;
	string junk;

	// srand(time(NULL)); 
	NPiz = NSand = 0;
	price = disc_price = total = total_disc = 0.0f;

	fin.open("program3data.txt");
	while (fin >> item_type)
	{
		getline(fin, junk); // read and discard \n after type
		switch (item_type)
		{
		case 'P':
			piz.ReadData(fin);
			price = piz.GetPrice();
			disc_price = ApplyDiscountMaybe(piz);
			NPiz++;
			total += price;
			total_disc += (price - disc_price);
			break;
		case 'S':
			sand.ReadData(fin);
			price = sand.GetPrice();
			disc_price = ApplyDiscountMaybe(sand);
			NSand++;
			total += price;
			total_disc += (price - disc_price);
			break;
		default:
			cerr << "Error in input: Unknown item type: " << item_type << endl;
		}
	}
	fin.close();
	cout << "Pizzas sold: " << NPiz << '\n'
		<< "Sandwiches sold: " << NSand << '\n'
		<< "Total sales: $" << total << '\n'
		<< "Less discount: $" << total_disc << '\n'
		<< "Net sales: $" << (total - total_disc) << endl;
	system("pause");
	return 0;
}


float ApplyDiscountMaybe(const MenuItem& thing)
{
	int chance;

	chance = rand() % 100;
	if (chance < 20)
		return thing.GetPrice() * 0.8;
	else
		return thing.GetPrice();
}
