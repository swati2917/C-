#pragma once
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;


class PolynomialError

{
public:
	PolynomialError(const string& m) //costructor
	{
		msg = m;
	}

	~PolynomialError(); // destructor


	string what() const
	{

		return msg;
	}

private:

	string msg;

};


class Polynomial
{

public:
	Polynomial();  // default constructor
	Polynomial(const Polynomial& other); // copy constructor
	~Polynomial(); // destructor
	const Polynomial& operator = (const Polynomial& rhs); // assignment operator
	const Polynomial& operator + (const Polynomial& rhs)const; //operator overloading

	friend istream& operator>>(istream& in ,Polynomial& P);
	friend ostream& operator<<(ostream& out, const  Polynomial& P);


private :
	int ArrSize;
	double *Coeffs;




};