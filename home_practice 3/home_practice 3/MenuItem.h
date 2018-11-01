#include <iostream>
using namespace std;

class MenuItem
{
private:

	string name, description; 
	
	 
protected:
	float price;


public:

	//getters

	string GetName() const
	{ 
		return name; 
	}

	string GetDescription() const
	{
		return description; 
	}

	float GetPrice() const
	{
		return price;
	}
	
	//setters

	void SetName(const string& s)
	{
		name = s;
	}
	void SetDescription(const string& s)
	{
		description = s;
	}


	virtual bool ReadData(istream& in) = 0;
	virtual bool WriteData(ostream &out) = 0; //its const in your program why??? 
	virtual string WhatAmI() const = 0;






};