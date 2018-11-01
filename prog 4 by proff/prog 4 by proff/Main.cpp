#include <iostream>
#include <fstream> 
#include <vector>
#include <iomanip>
#include "Student.h"
using namespace std;

int SearchForStudentID(const Student pupils[], int Npupils, int TargetID);
// PRE: Array is full in at least the first Npupils locations 
// POST: Array is unchanged. 
// RETURNS: index of student with TargetID, or -1 if no such student is found. 
// ERROR HANDLING: Assumes that student ID numbers are unique. If multiple 
//    students with same ID are present, returns location of first one. 
// I/O: None. 
// USER INTERACTION: None. 


void AddCourseWithoutDuplicate(vector <Course>& C, Course newcourse);
// PRE: None. 
// POST: newcourse is added to vector iff it is not already present
// RETURNS: None. 
// ERROR HANDLING: None 
// I/O: None. 
// USER INTERACTION: None. 

int main()
{
	Student S, *Roster;
	ifstream fin("students.txt");
	ofstream fout("enrollments.txt");
	int Student_ID, ArrSize, NStudents, idx;
	Course c;
	vector<Course> courselist;

	ArrSize = 5;
	NStudents = 0;
	Roster = new Student[5];
	while (fin >> S)
	{
		if (ArrSize == NStudents) // array is full! 
		{
			Student *tmp;
			ArrSize = (ArrSize * 2) + 1;
			tmp = new Student[ArrSize];
			for (int k = 0; k < NStudents; k++)
				tmp[k] = Roster[k];
			delete[] Roster;
			Roster = tmp;
		}
		// most of the time we start here 
		Roster[NStudents++] = S;
	}
	fin.close();
	fin.clear();
	fin.open("schedules.txt");

	while (fin >> Student_ID >> c)
	{
		idx = SearchForStudentID(Roster, NStudents, Student_ID);
		if (idx >= 0)
		{
			Roster[idx].AddCourse(c);
		}
		else
			cerr << "Error: No student with ID " << Student_ID << endl;
		AddCourseWithoutDuplicate(courselist, c);
	}
	fin.close();
	fout << fixed << showpoint << setprecision(2);
	for (int j = 0; j < NStudents; j++)
	{
		fout << Roster[j] << '\n';
		fout << '$' << Roster[j].TuitionDue() << "\n\n";
	}
	fout.close();
	fout.clear();
	fout.open("classes.txt");
	for (int j = 0; j < courselist.size(); j++)
	{
		fout << courselist.at(j) << '\n';
		for (int k = 0; k < NStudents; k++)
		{
			if (Roster[k].isEnrolledIn(courselist.at(j)))
				fout << '\t' << Roster[k].GetIDNumber() << '\t'
				<< Roster[k].GetFirstName() << '\t'
				<< Roster[k].GetLastName() << '\n';
		}
		fout << endl;
	}
	fout.close();
	// cleanup 
	delete[] Roster;
	courselist.clear();
	return 0;
}

int SearchForStudentID(const Student pupils[], int Npupils, int TargetID)
{
	for (int j = 0; j < Npupils; j++)
	{
		if (pupils[j].GetIDNumber() == TargetID)
			return j;
	}
	// if we're here, no pupil had that ID number 
	return -1;
}

void AddCourseWithoutDuplicate(vector <Course>& C, Course newcourse)
{
	for (int j = 0; j < C.size(); j++)
	{
		if (C.at(j) == newcourse)
			return; // already listed, don't need it again 
	}
	// if we're here, it isn't present 
	C.push_back(newcourse); // so add it
}