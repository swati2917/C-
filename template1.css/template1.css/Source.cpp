#include <iostream>
using namespace std;


template <class swati>
swati addNum(swati a, swati b)
{
	return a + b;
}

template <class raju>
raju subNum(raju c, raju d)
{
	return c - d;
}


template <class division>
division divNum( division q, division w)
{
	return q / w;
}

template <class First, class Second>
First smaller(First o, Second p)
{
	return o < p ? o : p;
}

template <class T>
class Singh{
	T fiirst, secondd;

public:
	Singh(T i, T u);
	{

	fiirst = i;
	secondd = u;
}
T bigger();
};


template <class T>
T Singh <>::T bigger()
{
	return (fiirst < secondd ? fiirst : secondd);
}






int main(){

	int x = 67, y = 89, z;
	z = addNum(x, y);
	cout << z << endl;


	double e = 78.89, f = 68.78, g;
	g = subNum(e, f);
	cout << g << endl;  

	float r = 678.88, t = 786.98, u;
	u = divNum(r, t);
	cout << u << endl;


	int k = 456;
		double l = 789.78;
		cout << smaller(l, k) << endl;








}
