#include <sstream>
#include "Pizza.h"

bool Pizza::ReadData(istream& in)
{
	stringstream ss;
	string inStr;
	char type;

	getline(in, inStr);
	SetName(inStr);
	getline(in, inStr);
	SetDescription(inStr);
	getline(in, inStr);
	ss << inStr;
	ss >> type;
	switch (tolower(type))
	{
	case 's': size = small; price = 7; break;
	case 'm': size = medium; price = 8; break;
	case 'l': size = large; price = 10; break;
	case 'f': size = family; price = 12; break;
	default: cerr << "Error: Unknown pizza size: " << type << endl;
		size = small; // it has to be set to *something* 
		price = 7;
	}
	getline(in, inStr);
	ss << inStr;
	ss >> type;
	switch (tolower(type))
	{
	case 't': crust = thin; break;
	case 'k': crust = thick; break;
	case 's': crust = stuffed; price += 1; break;
	default: cerr << "Error: Unknown crust type: " << type << endl;
		crust = thin; // has to be set to SOMETHING
	}

	for (int j = 0; j <= 5; j++)
	{
		getline(in, mods[j]);
		if (mods[j] == "*")
			break;
	}
	return in.good();
}
