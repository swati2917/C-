#include "Library.h"

int main()
{

	LibraryUser::LibraryUser (string startName, int startID)
	{


		Name = startName;
		ID = startID;
		CheckedOut = nullptr;
		ArrSize = NCheckedOut = 0; // implementation of the copy constructor


	}

	LibraryUser::~LibraryUser() // implementation of the destructor
	{

		if (CheckedOut != nullptr)
		{
			delete[] CheckedOut;
			CheckedOut = nullptr;

		}
	}

	const LibraryUser& LibraryUser :: operator = (const LibraryUser& rhs)
	{
		if (this != rhs) // check self assignment

			if (NCheckedOut > ArrSize) // Increase dynamic array size
			{
				~LibraryUser();
				ArrSize *= 2; // doubling the size of array
				CheckedOut = new string[ArrSize];
			}
		// copy static data
		Name = Name.rhs;
		ID = ID.rhs;
		ArrSize = ArrSize.rhs;
		
}
if (ArrSize >0 )
{
	CheckedOut = new string[ArrSize];   //copy dynamic data (if any)
	for (int k = 0; k < NCheckedOut; k++)
		CheckedOut[k] = rhs.CheckedOut[k];

		
	}


return *this; // return this






}

LibraryUser::LibraryUser(const LibraryUser& U) {
	CheckedOut = nullptr;
	NCheckedOut = ArrSize = 0;
	*this = U;



}
	
	
	
	
	
	










































































































































