#include<iostream>
using namespace std;
class Node
{
	
	public:
	int data;
	Node *next;
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
		
		~Node()
		{
		}
	
};
void InsertAtHead(Node* &head, int data)
{
	Node* new_Node = new Node(data);

	if(head == NULL)
	{
		head = new_Node;
		head->next = new_Node;
	}
	else
	{
		Node* cur;
		while(cur!=head)
		{
			cur = cur->next;
		}
		cur->next = new_Node;
		new_Node->next = head;
		head = new_Node;
	}
}
void InsertAtTail(Node* &head, int data)
{
	Node* new_Node = new Node(data);
	Node* cur = head;
	while(cur->next!=head)
	{
		cur = cur->next;
	}
	new_Node->next = cur->next;
	cur->next = new_Node;
}
void Insertion(Node* &head, int pos, int data)
{
	if(pos == 1)
	{
		InsertAtHead(head,data);
	}
	else
	{
			Node* new_node = new Node(data);
			Node* cur = head;
			for(int i=1; i<pos-1;i++)
			{
				cur = cur->next;
			}
			new_node->next = cur->next;
			cur->next = new_node;
	}
}

void InsertMid(Node* &head, int data)
{
	Node* slow = head;
	Node* fast = head;
	Node* new_node = new Node(data);
	while(fast->next->next!=head )
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	new_node->next = slow->next;
	slow->next = new_node;
}
int Deletion(Node* &head, int pos)
{
	Node* cur,*q;
	int x;
	if(pos == 1)
	{
		while(cur->next!=head)
		{
			cur = cur->next;
		}
		x = head->data;
		if(head == cur)
		{
			delete head;
			head = NULL;
		}
		else
		{
			cur->next = head->next;
			delete (head);	
			head = cur->next;		
		}	
	}
	else
	{
		for(int i = 1; i<pos-1;i++)
		{
			cur = cur->next;	
		}
		q = cur->next;
		cur->next = q->next;
		x = q->data;
		delete (q);	
	}
	return x;
}

void Display(Node* &head)
{
	Node* cur = head;
	do
	{
		cout<<"  "<<cur->data<<" --> ";
		cur = cur->next;
	}while(cur!=head);
	cout<<"NULL"<<endl;
	
}


int main()
{
	Node* node = NULL;
	Node* head = node;
	Node* tail = node;
	InsertAtHead(head,10);
//	InsertAtHead(head,40);
//	InsertAtHead(head,30);
//	InsertAtHead(head,70);
//	Insertion(head,2,20);
//	Insertion(head,3,30);
//	Insertion(head,4,40);
//	InsertAtTail(head,50);
	InsertAtTail(head,530);
	InsertAtTail(head,25);
//	InsertAtHead(head,70);
	Display(head);
//	Deletion(head,4);
//	Display(head);
	return 0;

}

