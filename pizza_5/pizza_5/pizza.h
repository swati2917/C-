#pragma once 

#include "MenuItem.h"
#include <iostream>
using namespace std;

enum PizzaSizeType { small, medium, large, family };
enum PizzaCrustType { thin, thick, stuffed };

class Pizza : public MenuItem
{
public:
	Pizza() { size = small; crust = thin; Nmods = 0; price = 7; }
	// accept parent constructor for all else. Note assignment to protected variable price. 
	PizzaSizeType GetSize() const { return size; }
	void SetSize(PizzaSizeType s) { size = s; }
	PizzaCrustType GetCrust() const { return crust; }
	void SetCrust(PizzaCrustType c) { crust = c; }
	bool ReadData(istream& in);
private:
	PizzaSizeType size;
	PizzaCrustType crust;
	string mods[6];
	int Nmods;
};