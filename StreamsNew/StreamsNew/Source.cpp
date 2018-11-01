#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using std::getline;



int main(){

	ifstream inFile;
	inFile.open("data.txt");
	string line;
	string mod[100];
	int i = 0,P=0,S=0;
	void  Readdata(ifstream& fin);
	string type;
	if (inFile.fail())
	{
		
		cerr << "error opening file" << endl;
	}
	else
	{
		//while (getline(inFile, line))
		//{
			//mod[i] = line;
			//cout << mod[i]<< endl;
		//}
		//inFile >> type;
		//cout << "First line=" << type;
		//switch (type)
		//{
		//case 'P': Readdata(inFile); P++; break;
		//case 'S': Readdata(inFile); S++; break;
		//}

		while (inFile>>type)
		{ 
			
			if (type == "P")
			{
				Readdata(inFile);
			}
			else
			{
				break;
			}
		
		}
		inFile.close();
	}
}

void Readdata(ifstream& fin){
	string line;
	string sline;
	string mod;
	int i = 0;
	while (getline(fin, line)) 
	{
		if (line=="S")
		{
			
			break;
		}
		else
		{
			 mod=line;
			i++;
			cout << "line=" << line << endl;
			cout << "my Vaulues are =" << mod << endl;
			
		}

	}
	
}