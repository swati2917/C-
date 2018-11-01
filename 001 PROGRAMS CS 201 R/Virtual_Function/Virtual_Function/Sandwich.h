#include <string>
#include <sstream> 
#include "MenuItem.h"

class Sandwich : public MenuItem
{
public:
	Sandwich() { ; } // parent's constructor takes care of things 
	void SetSide(const string& s) 
	{ 
		side = s; 
	}
	string GetSide() const 
	{
		return side;
	}
	
	bool ReadData(istream& in);

	bool WriteData(ostream& out) const;

	string WhatAmI() const;

private:
	string side;
};

