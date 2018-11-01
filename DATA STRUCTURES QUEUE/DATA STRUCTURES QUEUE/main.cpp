#include <iostream>
#include <string>
using namespace std;


const int maxqueue = 7; //the maximun people that a queue can have is 7. Its constant so cant be changed

struct queuetype
{
	string name[maxqueue];// using array of maxqueue
	int front;
	int back;

};

//now writing the functions create,empty,full,enqueue,dequeue

void createqueue(queuetype &queue);
bool emptyqueue(queuetype queue);
bool fullqueue(queuetype );
void enqueue(queuetype);
void dequeue(queuetype);

int main()
{
















	return 0;
}