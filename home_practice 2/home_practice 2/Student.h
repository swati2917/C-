#pragma once
#include <iostream>
#include <string>

using namespace std; 
class Student
{
private:
	int student_id;
	string student_fname;
	string  student_lname;
	int student_ccount;

public:

	Student()
	{
		student_id = 0;
		student_ccount = 0;
		student_fname = "";
		student_lname = "";
		
	}//constructor
	//Student(const Student& other); //
	//~Student();destructor

	//SETTERS
	void set_student_id(int I)
	{
		student_id = I;
	}
	void set_student_fname(const string& F)
	{
		student_fname = F;
	}
	void set_student_lname(const string& L)
	{

		student_lname = L;
	}
	void set_student_ccount(int C)
	{

		student_ccount = C;
	}
	// GETTERS
	int get_student_id() const 
	{
		return student_id;
	}
		
	
	
	string get_student_fname() const
	{

		return student_fname;
	}
	
	
	string get_student_lname() const

	{

		return student_lname;
	}




	int get_student_ccount()
	{


		return student_ccount;
	}

	virtual bool read_data(istream& in) = 0;
	virtual bool write_data(ostream& out) = 0;



};






