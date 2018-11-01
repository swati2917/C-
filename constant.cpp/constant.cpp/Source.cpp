// This is a constant (type 1) defining program

#include <iostream>
using namespace std;
int const l = 4; // const length for rect
int const b = 3; //constant breath for rect
#define A 5 // constant square calcultion




int main()
{
	int square; // variable for square area
	square = A * A; 
	cout<< "square="<< square << endl;


	int rectangle; // variable for rectangle area

		rectangle = l*b;
	cout << "rectangle="<< rectangle << endl;


	int perimeter; //variable for rect peri
	perimeter = 2 * (l + b);
	cout << perimeter << endl;



}