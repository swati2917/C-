#pragma once
#include <iostream>
#include <string> 
using namespace std;

class MenuItem
{
public:
	MenuItem() 
	{
		name = "";
		price = 0.0f;
		desc = "";

	}
	string GetName() const
	{ 
		return name;
	}
	void SetName(const string& s) 
	{
		name = s;
	}
	string GetDescription() const 
	{
		return desc;
	}
	void SetDescription(const string& s)
	{ 
		desc = s;
	}
	float GetPrice() const 
	{ 
		return price;
	}

	virtual bool ReadData(istream& in) = 0;

	virtual bool WriteData(ostream& out) const = 0;

	virtual string WhatAmI() const = 0;
private:
	string name, desc;

protected:
	float price;
};