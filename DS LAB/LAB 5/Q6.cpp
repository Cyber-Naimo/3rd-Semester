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
	void InsertatHead(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
	void updateNode(int data, int newvalue)
	{
		Node* cur = head;
		while(cur!=NULL)
		{
			if(cur->data == data)
			{
				cur->data = newvalue;
			}
			cur = cur->next;
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
	obj->InsertatHead(5);
	obj->Display();
	cout<<"\nAFTER UPDATING THE VALUE: "<<endl<<endl;
	obj->updateNode(5,20);				
	obj->Display();
}


