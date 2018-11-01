#pragma once 

#include <iostream>
#include <string> 
using namespace std;

class MenuItem
{
public:
	MenuItem() { price = 0.0f; }
	string GetName() const { return name; }
	void SetName(const string& s) { name = s; }
	string GetDescription() const { return desc; }
	void SetDescription(const string& s) { desc = s; }
	float GetPrice() const { return price; }
private:
	string name, desc;

protected:
	float price;
};