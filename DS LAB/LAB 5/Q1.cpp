#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	int key;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
		key = 0;
	}
	Node(int data,int key)
	{
		this->data = data;
		this->key = key;
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
	Linkdlist(int data,int key)
	{
		head = new Node(data,key);
		tail = head;
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
	Linkdlist* obj = new Linkdlist(10,1);
	obj->Display();
}
