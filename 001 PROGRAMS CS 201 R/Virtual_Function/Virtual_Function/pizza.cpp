#include <iostream>
#include <sstream>
#include "MenuItem.h"
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
		size = small; // As per the manual 
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
		crust = thin; // As per manaual
	}

	for (int j = 0; j <= 5; j++)
	{
		getline(in, mods[j]);
		if (mods[j] == "*")
			break;
	}
	return in.good();
}


bool  Pizza::WriteData(ostream& out) const
{
	out << "Pizza" << endl;
	out << GetName() << endl;
	out << GetDescription() << endl;

	if (GetSize() == 0)
	{
		out << "Small" << endl;
	}
	else if (GetSize() == 1)
	{
		out << "Medium" << endl;
	}
	else if (GetSize() == 2)
	{
		out << "Large" << endl;
	}
	else
	{
		out << "Family";
	}

	if (GetCrust() == 0)
	{
		out << "Thin" << endl;
	}
	else if (GetCrust() == 1)
	{
		out << "Thick" << endl;

	}
	else
	{
		out << "Stuffed" << endl;
	}

	out << GetPrice() << endl;

	for (int j = 0; j <= 5; j++)
	{
		out << mods[j] << endl;
	}

	return out.good();
}

string Pizza::WhatAmI() const
{
	return "Pizza";
}