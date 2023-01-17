#include<iostream>
using namespace std;
class Node
{
		public:
		int data;
		Node* next;
		Node* pre;
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int data)
		{
			this->data = data;
			this->pre = NULL;
			this->next = NULL;
		}
		~Node()
		{
		}
};
class DC
{
	public:
	Node* head;
	Node* tail;
	DC()
	{
		head = new Node;
		tail = head;
	}
	DC(int data)
	{
		head = new Node(data);
		tail = head;
	}
	void InsertAtTail(int data)
	{
	 	Node* new_Node = new Node(data);	
		tail->next = new_Node;				// pointing the lastnext to newnode rather then head
		new_Node->pre = tail;				// newNode pre pointing to last node;
		new_Node->next = head;				// newNode next pointing to head node;
		tail = new_Node;					// updating tail
	}
	void InsertAtHead(int data)
	{
		Node* new_Node = new Node(data);
		tail->next = new_Node;				// pointing the lastnext to newnode rather then head
		new_Node->pre = tail;				// newNode pre pointing to last node;
		new_Node->next = head;				// newNode next pointing to head node;
		head = new_Node;					// updating head
	}
	void Insertion(int pos, int data)
	{
		if(pos == 1)
		{
			InsertAtHead(data);
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
			cur->next->pre = new_node;
			new_node->pre = cur;
			cur->next = new_node;
		}
	}
	void Deletion(int pos)
	{
		Node* cur = head;
		if(pos==1)
		{
			head = cur->next;
			head->pre = NULL;
			tail->next = head;
			delete cur;
		}	
		else
		{
			for(int i=1;i<pos-1;i++)
			{
				cur = cur->next;
			}
			Node* p = cur->next;
			cur->next = p->next;
			delete (p);
		}
	}

	void Display()
	{
		Node* cur = head;
		do
		{
			cout<<"  "<<cur->data<<" --> ";
			cur = cur->next;
		}while(cur!=head);
		cout<<"NULL"<<endl;
		
	}
};

int main()
{
	DC* ob = new DC(10);
	ob->InsertAtHead(20);
	ob->InsertAtTail(60);
	ob->InsertAtTail(70);
	ob->Display();
	ob->Deletion(2);
	ob->Display();
	
	return 0;

}

