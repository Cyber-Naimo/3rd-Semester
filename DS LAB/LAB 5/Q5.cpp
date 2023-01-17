#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	
};

class Linkdlist
{
	public:
	Node* head;
	Node* tail;
	Linkdlist()
	{
		head = new Node;
		tail = head;
	}
	Linkdlist(int data)
	{
		head = new Node(data);
		tail = head;
	}
	void Insert(int d)
	{
		Node* newNode = new Node(d);
		newNode->next = head;
		head = newNode;
	}
	void LastNode()
	{
	    Node* cur = head;
		if(head == NULL)
		{
			return;
		}
		else if(head->next == NULL)
		{
			delete head;
			return;
		}
		else
		{
			while (cur->next->next != NULL)
		    {
		    	cur = cur->next;
			}
		        
		    delete (cur->next);
		    cur->next = NULL;
		}	   
	}
	
	int Delete(int pos)
	{
		Node* temp = head;
		int x;
		if(pos==1)
		{
			head = head->next;
			x = temp->data;
			temp->next = NULL;
			delete temp;
		}
		else
		{
			for(int i = 1; i<pos-1 ; i++)
			{
				temp = temp->next;
			}
			temp->next = temp->next->next;
			x = temp->data;;
		}
		return x;
	}
	void Display()
	{
		Node* cur = head;
		while(cur!=NULL)
		{
			cout<<"  "<<cur->data<<" --> ";
			cur = cur->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main()
{	
	Linkdlist* obj = new Linkdlist(10);
	obj->Insert(3);
	obj->Insert(2);
	obj->Display();
	obj->Delete(2);
	obj->LastNode();
	obj->Display();
}
