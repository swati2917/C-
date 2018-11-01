#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using std::getline;

class MenuItem
{
private:
	string name;
	string description;
protected:
	float price;
public:


	// Default Constructor
	MenuItem();

	//Setters

	void set_name(string n);
	void set_desc(string s);

	//Getters

	string get_name();
	string get_desc();
	float get_price();

};


//Default Constructor Description
MenuItem::MenuItem()
{


	name = "";
	description = "";

}

//Description of set name setter method
void MenuItem::set_name(string n)
{

	name = n;
}
void MenuItem::set_desc(string s)
{

	description = s;
}
// Desciprtion of get name getter method

string MenuItem::get_name()
{
	return name;
}
string MenuItem::get_desc()
{
	return description;

}
float MenuItem::get_price()
{
	return price;
}



class Pizza : public MenuItem
{
private:

	enum Size  { small, medium, large, family };
	enum Crust_Type { thin, thick, stuffed };
	string mod[5];
	Size psize;
	Crust_Type pcrust_type;

public:

	Pizza();
	bool	ReadData(ifstream& fin);


};

Pizza::Pizza()
{
	psize = small;
	pcrust_type = thin;
}

bool Pizza::ReadData(ifstream& fin)
{
	string line;
	char charvariable;
	int i = 0;

	getline(fin, line);
	set_name(line);

	getline(fin, line);
	set_desc(line);

	getline(fin, line);
	fin >> charvariable;

	switch (charvariable)
	{
	case 's': psize = small; price = 7;
	case 'm': psize = medium; price = 8;
	case 'l': psize = large; price = 10;
	case 'f': psize = family; price = 12;
	default: psize = small; price = 7;
	}

	getline(fin, line);
	fin >> charvariable;

	switch (charvariable)
	{
	case 't': pcrust_type = thin;
	case 's': pcrust_type = stuffed;
	case 'k': pcrust_type = thick;
	}

	getline(fin, line);

	while (line != "*")
	{
		mod[i] = line;
		getline(fin, line);
		i++;

	}

	return true;
}

class Sandwich : public MenuItem
{
private:
	string Side_Item;
	int cost = 8;
public:

	void set_sideitems(string s);

	bool read_data(ifstream& fin);

	int get_cost();
};

bool Sandwich::read_data(ifstream& fin)
{
	string line;

	getline(fin, line);
	set_name(line);

	getline(fin, line);
	set_desc(line);

	getline(fin, line);
	set_sideitems(line);

	return true;

}

void Sandwich::set_sideitems(string s)
{
	Side_Item = s;

}

int Sandwich::get_cost()
{
	return cost;
}



int main()
{
	ifstream fin;
	fin.open("data.txt");

	char charvar;
	Pizza P;
	Sandwich S;
	int pcount = 0, scount = 0;
	float total_cost=0;
	while (fin >> charvar)
	{
		if (charvar == 'P')
		{
			P.ReadData(fin);
			pcount++;
			total_cost+=P.get_price();
		}
		else if (charvar == 'S')
		{
			S.read_data(fin);
			scount++;
			total_cost += S.get_cost();
		}

	}

	cout << "Pizza sold" << pcount << endl;
	cout << "Sandwich Sold" << scount << endl;
	cout << "Total Sale" << total_cost << endl;

}