#include <iostream>
#include <string>
#include "Student.h"
using namespace std;


class SAddress :public Student
{

	string Student_address;


public:
	 
	SAddress()
	{
	
		Student_address = "";
	
	
	
	} // default constructor

	//~SAddress(); // destructor

	void set_Student_address( const string& A)//setter
	{
		Student_address = A;
	}
	string get_Student_address() const // getter
	{
		return Student_address;


	}

	
	bool read_data(istream& in);
	bool write_data(ostream& out);
};



bool SAddress::read_data(istream& in)
{
	stringstream ss;
	string line;
	int student_id, student_ccount;
	string student_fname, student_lname, student_address;

	getline(in, line);
	ss << line;
	ss >> student_id >> student_fname >> student_lname >> student_ccount >> student_address;
	set_student_id(student_id);
	set_student_fname(student_fname);
	set_student_lname(student_lname);
	set_student_ccount(student_ccount);
	set_Student_address(Student_address);

	return in.good();

}

bool SAddress::write_data(ostream& out)
{

	out << get_student_id() << '\t' << get_student_fname() << '\t' << get_student_lname() << '\t' << get_Student_address() << endl;
	return out.good();

}