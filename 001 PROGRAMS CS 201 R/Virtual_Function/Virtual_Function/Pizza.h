#include <iostream>
#include <sstream>
#include "MenuItem.h"

using namespace std;

enum PizzaSizeType { small, medium, large, family };
enum PizzaCrustType { thin, thick, stuffed };

class Pizza : public MenuItem{
public:
	Pizza() 
	{
		size = small; crust = thin; Nmods = 0; price = 7;
	}
	PizzaSizeType GetSize() const
	{
		return size; 
	}
	void SetSize(PizzaSizeType s)
	{
		size = s;
	}
	PizzaCrustType GetCrust() const
	{
		return crust;
	}
	void SetCrust(PizzaCrustType c)
	{ 
		crust = c;
	}
	bool ReadData(istream& in);
	bool WriteData(ostream& out) const;
	string WhatAmI() const;

private:
	PizzaSizeType size;
	PizzaCrustType crust;
	string mods[6];
	int Nmods;
};



