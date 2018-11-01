#include "Vehicle.h"

Polynomial::Polynomial()
{
	ArrSize = 0;
	Coeffs = nullptr;
}

Polynomial::Polynomial(const Polynomial& other) {
	Coeffs = nullptr;
	*this = other;
}

Polynomial::~Polynomial() {
	if (Coeffs != nullptr) {
		delete[] Coeffs;
		Coeffs = nullptr; // not strictly needed but doesn't hurt. 
		ArrSize = 0;
	}
}

const Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this != &rhs)  {  // 1. avoid self-assignment A = A 
		if (Coeffs != nullptr) {  // 2. delete dynamic data if any 
			delete[] Coeffs;
			Coeffs = nullptr;
			ArrSize = 0;
		}
		ArrSize = rhs.ArrSize; // 3. copy static data (only 1 item here) 
		if (ArrSize > 0) {     // 4. copy dynamic data (if any) 
			Coeffs = new double[ArrSize];
			for (int k = 0; k < ArrSize; k++)
				Coeffs[k] = rhs.Coeffs[k];
		}
	}
	return *this;    // 5. return *this
}


istream& operator>>(istream& in, Polynomial& P)
{
	P.~Polynomial();
	in >> P.ArrSize;
	if (P.ArrSize > 0)
	{
		P.Coeffs = new double[P.ArrSize];
		for (int k = 0; k < P.ArrSize; k++)
			in >> P.Coeffs[k];
	}
	if (in.fail()) // something went wrong 
		throw PolynomialError("error on input");
	return in;
}
ostream& operator<<(ostream& out, const Polynomial& P)
{
	out << P.ArrSize << ' ';
	if (P.ArrSize > 0)
	{
		for (int k = 0; k < P.ArrSize; k++)
		{
			out << P.Coeffs[k] << ' ';
		}
	}
	return out;
}


const Polynomial Polynomial::operator+(const Polynomial& rhs) const {
	Polynomial result;

	result.ArrSize = max(ArrSize, rhs.ArrSize);
	if (result.ArrSize > 0)
	{
		result.Coeffs = new double[result.ArrSize];
		for (int j = 0; j < result.ArrSize; j++)
			result.Coeffs = 0;
		for (int j = 0; j < ArrSize; j++)
			result.Coeffs[j] = Coeffs[j];
		for (int j = 0; j < rhs.ArrSize; j++)
			result.Coeffs[j] += rhs.Coeffs[j];
	}
	return result;
}
