/*

Swati Singh
ss3m6@mail.umkc.edu
CS 201 R
Assignment 4 - student.cpp
Due 7/5/17
Description: This program  is about the online registration system; been assigned writing part of the
course-enrollment section

Inputs: various texts files.
Outputs: Various status messages, to screen.

Algorithm:
1. Initialize student class with pubic and private
2. course struct
a. use various input text files
c. tuition computation
various output files with student details 
mentioned in the description
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "student.h"
#include <iomanip>
using namespace std;



int main()
{
	ifstream fin,fin1;
	ofstream fon,fon1;
	
	int maxstudent=40;

	string iline;

	Student *S=new Student[maxstudent];

	Course c1;

	Course C[15] = { {"IT",334,1}, {"ENGL",135,3}, {"IT",306,3}, {"SOC",166,3},
	                 {"MATH",270,3}, {"POLS",101,3}, {"HIST",368,3}, {"IT",146,3},
					 { "MUS",139, 3 }, { "IT", 361, 3 }, { "ECE", 104, 4 }, { "IT",179,3 },
	{"POLS",256,3}, {"CS",181,3}, {"IT",288,3} };


	int i = 0;
	fin.open("student.txt");

	if (fin.fail())
	{
		cout << "Please check the student file";
	}
	else
	{   
		
		while (!fin.eof())
		{

			if (i < maxstudent)
			{
				bool result = S[i].read_data(fin);
				if (result == true)
				{
					maxstudent++;
					i++;
				}
				else
				{
					cout << "some problem";
				}
			}

		}
	}

	
	fin.close();

	fin1.open("schedule.txt");
	
	if (fin1.fail())
	{
		cout << "please check the schedue file";
	}
	else
	{
		
           while (!fin1.eof())
			{
				string cline;
				getline(fin1, cline);
				stringstream ss(cline);
				int sid, cnum, crd;
				string cname;
				bool result;
				if (ss >> sid >> cname >> cnum >> crd)
				{
					c1.dept = cname;
					c1.dept_num = cnum;
					c1.credit_hrs = crd;
				}

			
				for (int j = 0; j < i; j++)
				{
					//cout << S[j].get_student_id() << '\t' << sid << endl;
					if (S[j].get_student_id() == sid)
					{

					result=S[j].AddCourse(c1);
				
					}
				}
			}
		   
	 }

	fin1.close();

	

	fon.open("enrollment.txt");
	if (fon.fail())
	{
		cout << "Please check the classes file";
	}
	else
	{
		for (int s = 0; s < i; s++)
		{
			S[s].write_data(fon);
		}
	}
	fon.close();

	fon1.open("classes.txt");
		if (fon1.fail())
		{
			cout << "Please check Enrollment File";
		}
		else
		{
			bool c_result;
			for (int c = 0; c <15; c++)
			{
				fon1 << C[c] << endl;
				for (int s = 0; s < i; s++)
				{
					c_result=S[s].isEnrolled(C[c]);
					if (c_result == true)
					{
						fon1 << setw(20) <<S[s].get_student_id() << '\t' << S[s].get_student_fname() << '\t' << S[s].get_student_lname() << endl;
					}
					

				}
			}
		}

		fon1.close();

	delete[] S;
}