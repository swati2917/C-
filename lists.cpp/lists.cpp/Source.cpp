#include <iostream> 
using namespace std;

template <class T>
class List;

template <class T>
class ListNode
{
	friend class List < T >;
public:
	ListNode() { next = prev = nullptr; }
	ListNode(const T& item) {
		data = item;
		next = prev = nullptr;
	}
private:
	T data;
	ListNode<T> *next, *prev;
};

template <class T>
class List
{
public:
	List();
	List(const List<T>& other);
	const List<T>& operator=(const List<T>& rhs);
	~List();
	void push_front(const T& item);
	void push_back(const T& item);
	void push_ordered(const T& item);
	T pop_front();
	T pop_back();
	void clear();
	int size() const { return count; }
	bool is_empty() const { return count == 0 ? true : false; }
	void traverse(ostream& out);
	// void sort(); 
private:
	ListNode<T> *front, *back;
	int count;
};

class ListException
{

public:
	ListException(const string& M = "List Error");
	string what() const;

private:
	string msg;

};


template<class T>
List::List()
{
	front = back = nullptr;
	count = 0;
}

template<class T>
List<T>::List(const List<T>& other)
{
	front = back = nullptr;
	count = 0;
	*this = other;
}


template<class T>
List<T>::~List()
{
	clear(); // already have function to remove everything,  so call it. 
}

template <class T>
void List<T>::clear()
{
	ListNode<T> *tmp = front;

	while (tmp != NULL)
	{
		ListNode<T> *T2 = tmp;
		tmp = tmp->next;
		delete T2;
		count--;
	}
	front = NULL;
	back = NULL;

	// Remove first node, repeatedly, until there aren't any more. 
	// update tail, count, etc appropriately by end of function 
}

template <class T>
void List<T>::push_front(const T& item)
{
	ListNode<T> *P = new ListNode<T>();
	P->next = NULL;
	P->prev = NULL;
	P->data = item;


	if (is_empty())
	{
		// Add the first element 
		front = back = P;
	}
	else
	{
		// Prepend to the list and fix links 

		P->next = front;
		front->prev = P;
		front = P;
	}

	count++;
}



template <class T>
void List<T>::push_back(const T& item)
{
	ListNode<T> *P = new ListNode<T>();

	P->data = item;
	P->next = NULL;
	P->prev = NULL;

	if (is_empty)
	{
		front = back = P;
	}
	else
	{
		back->next = P;
		P->prev = back;
		back = P;
	}

	count++;
}

template <class T>
void List<T>::push_ordered(const T& item)
{
	// to do. Note: If list is empty, can call push_front, which 
	// already has code to handle empty list 
	// also consider when push_front or push_back can be used 
	;
}
template <class T>
T List<T>::pop_front()
{
	if (is_empty)
	{
		throw
	}

	//  Data in the front node 
	int ret = front->data;

	// Delete the front node and fix the links 
	Node* tmp = front;
	if (front->next != NULL)
	{
		front = front->next;
		front->prev = NULL;
	}
	else
	{
		front = NULL;
	}
	count--;
	delete tmp;

	return ret;
}

template <class T>
T List<T>::pop_back()
{
	if (is_empty)
	{
		throw new;
	}

	//  Data in the rear node 
	int ret = rear->data;

	// Delete the front node and fix the links 
	Node* tmp = back;
	if (back->prev != NULL)
	{
		back = back->prev;
		back->next = NULL;
	}
	else
	{
		back = NULL;
	}
	count--;
	delete tmp;

	return ret;
}

int main() {
	// your code goes here 
	return 0;
} 