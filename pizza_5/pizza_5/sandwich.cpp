#include "Sandwich.h"
#include <sstream>

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