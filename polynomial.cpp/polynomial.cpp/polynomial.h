
#include <iostream>
#include <fstream>
#include <algorithm>




using namespace std;


public:
	Polynomial();
	Polynomial(const Polynomial& other);
	const Polynomial& operator=(const Polynomial& rhs);
	~Polynomial();
	const Polynomial& operator = (const Polynomial rhs);
	const Polynomial operator + (const Polynomial& rhs) const;
	friend istream& operator>> (istream& in; Polynomial& P);
	friend ostream& operator << (ostream& out, const Polynomial &P);
private:
	double *coeffs;
	int array_size;
};