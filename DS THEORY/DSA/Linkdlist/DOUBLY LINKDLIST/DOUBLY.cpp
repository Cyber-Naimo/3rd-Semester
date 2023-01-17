#include<iostream>
using namespace std;
class Node
{
	
	public:
	int data;
	Node *next;
	Node *pre;
		Node()
		{
			data = 0;
			next = 0;
			pre = 0;
		}
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
			this->pre=NULL;
		}	
};
void Display(Node* &head)
{
	Node* cur=head;
	while(cur!=NULL)
	{
		cout<<" "<<cur->data<<" --> ";
		cur= cur->next;
	}
	cout<<"NULL"<<endl;
}

void InsertAtHead(Node* &head, int d)
{
	Node* newNode = new Node(d);
	newNode->next = head;
	head->pre = newNode;
	head = newNode;	
}
void InsertAtTail(Node* &tail, int d)
{
	Node* newNode = new Node(d);
	tail->next = newNode;
	newNode->pre = tail;
	tail = newNode;
}
void Insertation(Node*head, int d,int pos)
{
	if(pos==1)
	{
		InsertAtHead(head,d);
		return;
	}
	    Node* cur = head;

		for(int i=1;i<pos-1;i++)
		{
			cur = cur->next;
		}
		Node* newNode = new Node(d);
		/*step1:*/ newNode->next = cur->next;
		/*step2:*/ cur->next->pre = newNode;
		/*step3:*/ cur->next = newNode;
		/*step4:*/ newNode->pre = cur;	
}
void MidInsertion(Node* &head, int data)
{
	Node* slow = head;
	Node* fast = head;
	Node* new_Node = new Node(data);
	while(fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<" Mid: "<<slow->data;
	new_Node->next = slow->next;
	slow->next->pre = new_Node;
	slow->next = new_Node;
	new_Node->pre = slow;
}
void Deletion(Node* &head,int pos)

{
	Node* cur = head;
	if(pos==1)
	{
		head = head->next;
		head->pre = NULL;
		cout<<"\nDeleted by value: "<<cur->data<<endl;
		delete cur;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
		{
			cur = cur->next;
		}
			Node* store_next = cur->next;
			Node* store_prev = cur->pre;
			store_next->pre = store_prev;
			store_prev->next = store_next;
	}
}

void Swap(Node* &f, Node* &l)
		{
			int x = f->data;
			f->data = l->data;
			l->data = x;
		}
		
		// Insertion Sort using Doubly Lindlist
		void InsertionSort(Node* &head)
		{
			Node* cur_node = head;			// cur pointer like 1
			Node* pre_node = NULL;		
			while(cur_node!=NULL)
			{
				pre_node = cur_node->next;	// next pointer like 2

				// comparing nextpointers data and its previeus data
				while(pre_node!=NULL && pre_node->pre!=NULL && pre_node->data < pre_node->pre->data)
				{
					//if true then swap
					Swap(pre_node,pre_node->pre);

					// then moveback the next pointer
					pre_node = pre_node->pre;
				}
				cur_node = cur_node->next;
			}
		}
		
		Node* Concatinate(Node* &head1, Node* &head2)
		{
			Node* cur = head1;
			while(cur->next!=NULL)
			{
				cur = cur->next;
			}
			cur->next = head2;
			head2->pre = head1;
			return (head1);
		}
		// Recursive Function for Concatinating
		void Concatinate2(Node* &head1, Node* &head2)
		{
			if(head1->next==NULL)
			{
				head1->next = head2;
				head2->pre = head1;
			}
			else
			{
				Concatinate2(head1->next,head2);
			}
		}

void DeleteMid(Node* &head)
{
	Node* cur = head;
	Node* slow = head;
	Node* fast = head;
	
	while(fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<"Mid: "<<slow->data<<endl;
	Node* store_next = slow->next;
	Node* store_prev = slow->pre;
	store_next->pre = store_prev;
	store_prev->next = store_next;
	cout<<"LIST Deleted by value: "<<slow->data<<endl;
	delete slow;
	
}
	
int main()
{
	Node *node1  = new Node(1);
	Node *head = node1;
	Node* tail = node1;
	Display(head);
	InsertAtTail(tail,2);
	Display(head);

return 0;

}

