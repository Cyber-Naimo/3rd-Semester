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
	
	void Insertation(int data , int pos)
	{
		Node* cur = head;
		Node* temp = new Node(data);
		if(pos==1)
		{
			Node* temp = new Node(data);
			temp->next = head;
			head = temp;
		}
		else
		{
			for(int i = 1; i<pos-1 ; i++)
			{
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next = temp; 
		}
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
	obj->Insertation(20,2);
	obj->Display();
}
