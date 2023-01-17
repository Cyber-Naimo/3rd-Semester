#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
class Stack
{
	Node* head;
	public:
		Stack()
		{
			head = NULL;			
		}
		void push(int data)
		{
			Node* new_Node = new Node;
			if(new_Node == NULL)
			{
				cout<<"Stack OverFlow "<<endl;
			}
			else
			{
				
				new_Node->data = data;
				new_Node->next = head;
				head = new_Node;			
			}	
		}
		int  pop()
		{
				if(head == NULL)
				{
					cout<<"Stack UnderFlow "<<endl;
					return -1;
				}
				else
				{
//					head = head->next;
					Node* pre= head;
					int x  = -1;
					head  = head->next;
					x = pre->data;
					delete pre;
					return x;
				}
		}
		void peek()
		{
			
			Node* cur = head;
			while(cur!=NULL)
			{
				cout<<" "<<cur->data<<" --> ";
				cur = cur->next;
			}
			cout<<"NULL"<<endl;
		}
};
int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.peek();
	s.pop();
	s.peek();
	s.push(10);
	s.push(20);
	s.push(30);
	s.peek();


	return 0;

}

