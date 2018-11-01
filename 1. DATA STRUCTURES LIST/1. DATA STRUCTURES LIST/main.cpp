#include <iostream>
using namespace std;

struct node
{
	int number;
	node *next;

};


bool isEmpty(node *head);
char menu();
void insertAsFirstElement(node *&head , node *&last , int number);
void insert(node *&head , int number);
void remove(node *&head ,node *&last);
void showList(node *current);


bool isEmpty(node *head)
{
	if
		(head == NULL)
	return true;

	else
		return false;

}
char menu()
{


}
void insertAsFirstElement(node *&head, node *&last, int number)
{
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;


}
void insert(node *&head, int number)
{



}
void remove(node *&head, node *&last)
{


}
void showList(node *current)
{



}




int main()
{
	node *head = NULL;
	node *last = NULL;




	return 0;

}