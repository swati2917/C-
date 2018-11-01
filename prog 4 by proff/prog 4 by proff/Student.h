#pragma once 

#include <iostream> 
#include <string> 
using namespace std;

struct Course
{
	string Dept;
	int Number;
	int Hours;
};

class Student
{
public:
	Student();
	Student(const Student& other);
	~Student();
	const Student& operator= (const Student& rhs);
	void SetFirstName(const string& F) { First = F; }
	void SetLastName(const string& L) { Last = L; }
	void SetIDNumber(int N) { if (N > 0) ID = N; }
	string GetFirstName() const { return First; }
	string GetLastName() const { return Last; }
	int GetIDNumber() const { return ID; }
	bool isEnrolledIn(const Course& c) const; 
	bool AddCourse(const Course& C);
	bool RemoveCourse(const Course& C);
	bool ReadData(istream& in);
	bool WriteData(ostream& out) const;
	double TuitionDue() const;
private:
	string First, Last;
	int ID;
	Course* courses;
	int ArrSize, NCourses;
	bool Surcharge(const string& Dept) const;
};

istream& operator>>(istream& in, Course& C);
ostream& operator<<(ostream& out, const Course& C);
bool operator==(const Course& C1, const Course& C2);

// extra credit: 
istream& operator>>(istream& in, Student& C);
ostream& operator<<(ostream& out, const Student& C);