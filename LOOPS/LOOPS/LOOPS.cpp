#include <iostream>
using namespace std;

int add(int a =5, int b =3){

	int r;
	r = a + b;
	return r;


}


void duplicate(int& a, int& b, int& c)
{
	a *= 2;
	b *= 2;
	c *= 2;
}




int r; // global- Any avriable defined outside function




int main()
{

	int z;

	z = add(2, 4);
	cout << "Total Z=" << z << endl;

	int x = 6, y = 4;
	int z1;

	z1 = add(x, y);

	cout << z1 << endl;


	duplicate(x, y, z);

	cout << x << y << z << endl;

	int z3;
	z3 = add(3);
	cout << z3 << endl;
}