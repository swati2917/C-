#include <string>
#include <sstream> 
#include "MenuItem.h"
#include "Sandwich.h"


bool Sandwich::ReadData(istream& in)
{
	stringstream ss;
	string tmpStr;

	getline(in, tmpStr);
	SetName(tmpStr);
	getline(in, tmpStr);
	SetDescription(tmpStr);
	getline(in, tmpStr);
	SetSide(tmpStr);
	price = 8;
	return in.good();
}

string Sandwich::WhatAmI() const
{
	return "Sandwich";
}

bool Sandwich::WriteData(ostream& out) const
{
	out << "Sandwich" << endl;
	out << GetName() << endl;
	out << GetDescription() << endl;
	out << GetSide() << endl;
	out << price;

	return out.good();
}