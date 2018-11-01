#include <iostream>
#include <string>

using namespace std;

struct Course
{
	string	dept;
	int dept_num;
	int credit_hrs;

};

ostream &operator<<(ostream& os, const Course& C)
{

	return os << C.dept << " " << C.dept_num << " " << C.credit_hrs << '\n';
}

istream &operator>>(istream &in, Course& C)
{
	return in >> C.dept >> C.dept_num >> C.credit_hrs;
}

