#include "Student.h"



istream& operator >> (istream& in, Course& C)
{
	in >> C.Dept >> C.Number >> C.Hours;
	return in;
}

ostream& operator<< (ostream& out, const Course& C)
{
	out << C.Dept << ' ' << C.Number << '\t' << C.Hours;
	return out;
}

bool operator==(const Course& C1, const Course& C2)
{
	return (C1.Dept == C2.Dept && C1.Number == C2.Number && C1.Hours == C2.Hours);
}
Student::Student()
{
	ID = ArrSize = NCourses = 0;
	courses = nullptr;
}

Student::Student(const Student& other)
{
	courses = nullptr;
	*this = other;
}

Student::~Student()
{
	if (courses != nullptr)
	{
		delete[] courses;
		courses = nullptr;
	}
}

const Student& Student::operator= (const Student& rhs)
{
	if (this != &rhs)
	{
		if (courses != nullptr)
		{
			delete[] courses;
			courses = nullptr;
		}
		ID = rhs.ID;
		First = rhs.First;
		Last = rhs.Last;
		ArrSize = rhs.ArrSize;
		NCourses = rhs.NCourses;
		if (ArrSize > 0)
		{
			courses = new Course[ArrSize];
			for (int k = 0; k < NCourses; k++)
				courses[k] = rhs.courses[k];
		}
	}
	return *this;
}

bool Student::AddCourse(const Course& C)
{
	Course* P;
	if (NCourses == ArrSize) // need to make room 
	{
		try
		{
			ArrSize = (ArrSize * 2) + 1;
			P = new Course[ArrSize];
		}
		catch (...)
		{
			cerr << "Error on trying to expand array in student object.\n";
			ArrSize /= 2; // undo as much as we can; data is still unchanged. 
			return false;
		}
		for (int k = 0; k < NCourses; k++)
			P[k] = courses[k];
		delete[] courses;
		courses = P;
	}
	// most of the time we start here 
	courses[NCourses++] = C;
	return true;
}

bool Student::RemoveCourse(const Course& C)
{
	for (int k = 0; k < NCourses; k++)
	{
		if (C == courses[k]) // found one... 
		{
			swap(courses[k], courses[--NCourses]);
			if (NCourses == 0)
			{
				delete[] courses;
				courses = nullptr;
				ArrSize = 0;
			}
			return true;
		}
	}
	// if we're here, the item to be removed was never here at all 
	return false;
}

bool Student::ReadData(istream& in)
{
	in >> ID >> First >> Last;
	if (ArrSize > 0)
	{
		delete[] courses;
		courses = nullptr;
		NCourses = ArrSize = 0;
	}
	in >> NCourses;
	if (NCourses > 0)
	{
		ArrSize = NCourses * 2;
		courses = new Course[ArrSize];
		for (int k = 0; k < NCourses; k++)
			in >> courses[k];
	}
	return in.good();
}

bool Student::WriteData(ostream& out) const
{
	char tab = '\t';
	out << ID << tab << First << tab << Last << endl
		<< NCourses << '\n';
	for (int k = 0; k < NCourses; k++)
		out << courses[k] << '\n';
	return out.good();
}

double Student::TuitionDue() const
{
	double Tuition = 0;
	int Hours = 0, EngHrs = 0;

	for (int k = 0; k < NCourses; k++)
	{
		Hours += courses[k].Hours;
		if (Surcharge(courses[k].Dept))
			EngHrs += courses[k].Hours;
	}
	// Now accumulate charges 
	Tuition += Hours * 476;  // base tuition 
	Tuition += EngHrs * 15;  // Engineering lab fee 
	Tuition += Hours * 0.75; // student union fee 
	Tuition += 10;           // library fee 
	Tuition += (Tuition * 0.0025); // chancellor's pastry fund 

	return Tuition;
}

bool Student::Surcharge(const string& Dept) const
{
	static const string Engineers[] = { "CS", "IT", "ECE", "CE", "ME" };
	for (int k = 0; k < 5; k++)
		if (Dept == Engineers[k])
			return true;
	// if we're here, it's not on the list 
	return false;
}

bool Student::isEnrolledIn(const Course& c) const
{
	for (int j = 0; j < NCourses; j++)
		if (courses[j] == c)
			return true;
	// if we're here, we never found it 
	return false;
}

istream& operator>>(istream& in, Student& C)
{
	// rather than repeat the code, we'll take advantage of what we've already done 
	C.ReadData(in);
	return in;
}
ostream& operator<<(ostream& out, const Student& C)
{
	C.WriteData(out);
	return out;
}
