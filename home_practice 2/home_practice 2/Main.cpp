#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "Student.h"
#include "SAddress.h"
using namespace std;



int main()
{

	ifstream fin;
	ofstream fout;

	 const int MAX = 15;
	  
	 Student* S[MAX];

	 for (int k = 0; k < MAX; k++)
	 {
		 S[k] = nullptr;
	 }
	 int NStudent = 0;
	 fin.open("student.txt");
	
	

	 if (fin.fail())
	 {

		 cout << "please check the file" << endl;
	 }
	 else
	 {

		 {
			 while (!fin.eof())
			 {
				 S[NStudent] = new SAddress;
				 S[NStudent]->read_data(fin);
				
				 NStudent++;

			 }
			 fin.close();
		 }


		 fout.open("output.txt");

			 if (fout.fail())
			 {

				 cout << "please check the file" << endl;
			 }
			 else
			 {
				 for (int k = 0; k < NStudent; k++)
				 {
					 S[k]->write_data(fout);
					 cout << endl;

				 }
					 

			 }



		 for (int k = 0; k < NStudent; k++) // deletion of dynamic allocation
		 {
			 delete S[k];
		 }

	
		

		 
		 cout << NStudent << endl;


	 }
















}