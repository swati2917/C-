#include <iostream>
using namespace std;

struct Node
{
	int number;
	Node *next;

};

bool isEmpty(Node *head);
char Menu();
void insertAsFirstelement(Node *&head ,Node *&last, int number);
void insert(Node *&head, Node *&last , int number);
void remove(Node *&head, Node *&last);
void ShowList(Node *current);




int main()
{

	Node *head = NULL;
	Node *last = NULL;





	return 0;
}