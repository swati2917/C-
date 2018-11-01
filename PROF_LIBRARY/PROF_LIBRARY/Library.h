#pragma once
#include <string>
#include <iostream>

using namespace std;

class LibraryUser
{
public:

	LibraryUser(string StartName="" , int StartID=0); // Constructor
	LibraryUser(const LibraryUser & U);
	~LibraryUser(); // Destructor 
	const LibraryUser &operator = (const LibraryUser& rhs); // assignment operator
	                                                         // need getters, setters etc
	int get_n_checked_out()const
	{
		return NCheckedOut;
	}

	void check_out(const string& item);
	void check_in(const string& item);








private:
	string Name;
    int ID;
	string *CheckedOut;
	int ArrSize, NCheckedOut;





};
