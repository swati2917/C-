#include <iostream>
#include <string>
#include "course.h"
using namespace std;

class Student
{

	int student_id;
	string student_fname;
	string student_lname;
	int course_count;
	Course *course_detail;

public:

	//Default Constructor

	Student();

	//Copy Constructor

	Student(const Student &obj);

	//Deconstructor

	~Student();

	//Setters

	void set_student_id(int id);

	void set_student_fname(string fname);

	void set_student_lname(string lname);

	void set_student_ccount(int count);

	//Getters

	int get_student_id();

	string get_student_fname();

	string get_student_lname();

	int get_sc_count();
	//Add Course

	bool AddCourse(const Course&);

	// Remove Course

	bool RemoveCourse(const Course&);

	//Course Enrollment

	bool isEnrolled(const Course&);

	//Read Data

	bool read_data(istream& in);

	// Write Data

	bool write_data(ostream& out);

	//Tution 

	double TutionDue() const;

	// Assigenment operator overloading

	void operator=(const Student &S);

	// Extraction operator overloading
	
	friend ostream &operator<<(ostream &output, const Student &S)
	{

		output << S.student_id << S.student_fname << S.student_lname << S.course_count ;
	}
	// Inertion Operator overloading

	friend istream &operator>>(istream &input, Student &S)
	{
		input >> S.student_id >> S.student_fname >> S.student_lname >> S.course_count;
	}
};

Student::Student()
{

	student_id = 0;
	student_lname = " ";
	student_fname = " ";
	course_count = 0;
	int maxsize = 100;
	course_detail = new Course[maxsize];


}

Student::~Student()
{

	if (course_detail != nullptr)
	{
		delete[] course_detail;
		course_detail = nullptr;
	}
}



void Student::set_student_id(int id)
{

	student_id = id;

}

void Student::set_student_fname(string fname)
{

	student_fname = fname;
}


void Student::set_student_lname(string lname)
{

	student_lname = lname;
}

void Student::set_student_ccount(int count)
{

	course_count = count;

}
string Student::get_student_fname()
{
	return student_fname;
}

string Student::get_student_lname()
{

	return student_lname;
}

int Student::get_student_id()
{
	return student_id;
}

int Student::get_sc_count()
{
	return course_count;
}

bool Student::read_data(istream& in)
{
	string line;

	getline(in, line);

	stringstream ss(line);

	int a=0, c=0;
	string f, l;
	
	if (ss >> a >> f >> l >> c)
	{
		
		set_student_id(a);
		set_student_fname(f);
		set_student_lname(l);
		set_student_ccount(c);
		
   
		 return true;
	}
	else
	{
		return false;
	}
}

bool Student::AddCourse(const Course& C1)
{
	
		course_detail[course_count] = C1;
		course_count++;
		return true;

}

bool Student::write_data(ostream& out)
{

	out << get_student_id() << '\t' << get_student_fname() << '\t' << get_student_lname() << endl;
	out << course_count << endl;
	for (int c = 0; c < course_count; c++)
	{
		out << course_detail[c];
	}
	out << '$'<< TutionDue() << endl;

	return true;
}

void Student :: operator = (const Student &S)
{
	if (this != &S)
	{

		student_id = S.student_id;
		student_fname = S.student_fname;
		student_lname = S.student_lname;
		course_count = S.course_count;
		
	}

}

double Student::TutionDue() const
{
	double course_cost,total_course_cost;
	int total_credit_hrs=0;
	int credit_hr_srch = 0;
	int library_flat_fee = 10;
	double pastry_fund_perc = 0.0025;


	for (int c = 0; c < course_count; c++)
	{
		total_credit_hrs=total_credit_hrs + course_detail[c].credit_hrs;
		if ( (course_detail[c].dept == "CS") || (course_detail[c].dept == "IT") || (course_detail[c].dept == "ECE")
			|| (course_detail[c].dept == "CE") || (course_detail[c].dept == "ME") )
		{
			credit_hr_srch = credit_hr_srch + course_detail[c].credit_hrs;
		}
	}

	course_cost = total_credit_hrs * 476 + credit_hr_srch * 15 + library_flat_fee + total_credit_hrs * 0.75;
	total_course_cost = course_cost + course_cost * pastry_fund_perc;


	return total_course_cost;
}

bool Student::isEnrolled(const Course &C)
{
	bool match;
	for (int c = 0; c < course_count; c++)
	{
		
		if ((course_detail[c].dept == C.dept) && (course_detail[c].dept_num == C.dept_num))
		{
			match = true;
			break;
		}
		else
		{
			match = false;
		}
	}

	return match;

}




