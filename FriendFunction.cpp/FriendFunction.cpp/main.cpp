#include <iostream>
using namespace std;

class Animals
{
public: Animals() 
{
	cats = 0; 
}
private:

	int cats;

	friend void AnimalsFriend(Animals &ao);

};


void AnimalsFriend(Animals &ao)
{
	ao.cats = 78;
	cout << ao.cats << endl;
}






int main()


{
	Animals blackie;
	AnimalsFriend(blackie);
	 







}