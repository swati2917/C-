#pragma once 

#include "MenuItem.h"
#include <string>
#include <sstream> 


class Sandwich : public MenuItem
{
public:
	Sandwich() { ; } // parent's constructor takes care of things 
	void SetSide(const string& s) { side = s; }
	string GetSide() const { return side; }
	bool ReadData(istream& in);
private:
	string side;
};