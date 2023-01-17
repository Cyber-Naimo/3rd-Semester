#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	int priority;
	Node* next;
	
	Node* newNode(int d, int p)
	{
	    Node* temp = new Node;
	    temp->data = d;
	    temp->priority = p;
	    temp->next = NULL; 
	    return temp;
	}
	
	int peek(Node* head)
	{
	    return head->data;
	}
	void pop(Node* head)
	{
	    Node* temp = head;
	    head = head->next;
	    delete(temp);
	}
	
	void push(Node* head, int d, int p)
	{
	    Node* start = head;
	    Node* temp = newNode(d, p);
	    if (head->priority > p)
	    {
	        temp->next = head;
	        head = temp;
	    }
	    else
	    {
	        while (start->next != NULL && start->next->priority < p)
	        {
	            start = start->next;
	        }
	        temp->next = start->next;
	        start->next = temp;
	    }
	}
};
class Queue
{
	public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL; 
	}
	void EnQueue(int data)
	{
		Node* temp = new Node(data);
		if(rear == NULL )
		{
			front = rear = temp;
			return;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void DeQueue()
	{
		Node* temp = front;
		front = front->next;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete temp;
	}
	bool Full()
	{
		if(rear == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{

return 0;

}

