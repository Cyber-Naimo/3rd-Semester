#include <iostream>
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
	~Node()
		{
		}
};
class linkList
{
	
	public:
		Node* head;
		Node* tail;
		linkList()
		{
			head = new Node();
			tail = head;
		}
		linkList(int h){
			head = new Node(h);
			tail = head;
		}
		void InsertAtHead(int h)
		{
			Node* naya1 = new Node(h);
			
			if(head == NULL)
			{
				head = tail = naya1;
				head->next = naya1;
			}
			else
			{
				tail->next = naya1;
				naya1->next = head;
				head = naya1;	
			}
		}
		void InsertAtTail(int h)
		{
			Node* naya1 = new Node(h);
			tail->next = naya1;
			naya1->next = head;
			tail = naya1;
		}
		
		void InsertMid(int data)
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
		
		
		void Insertion(int pos, int h)
		{
				Node* naya1 = new Node(h);
				Node* cur = head;
				if(pos==1)
				{
					InsertAtHead(h);
				}
				else
				{
					for(int i = 1;i<pos-1;i++)
					{
						cur = cur->next;
					}
					naya1->next = cur->next;
					cur->next = naya1;
				}
		}
		void Deletion(int pos)
		{
			Node* cur = head;
			
			if(pos==1)
			{
				head = cur->next;
				tail->next = cur->next;
				delete cur;
			}
			else
			{
					for(int i = 1;i<pos-1;i++)
					{
						cur = cur->next;
					}
					Node* p = cur->next;
					cur->next = p->next;
					delete p;
			}
		}
		void printlist()
		{
			Node* temp = head;
			do
			{
				cout << temp->data << " --> ";	
				temp = temp->next;
			}while(temp!=head);
			cout<<" NULL "<<endl;
		}
};


int main(){
	


	linkList* ob1 = new linkList(10);

	ob1->InsertAtHead(20);
	ob1->InsertAtTail(30);
	ob1->InsertAtTail(230);
	ob1->Insertion(2,100);
	ob1->Insertion(4,140);
	ob1->printlist();
	ob1->Deletion(3);
	ob1->printlist();

}
