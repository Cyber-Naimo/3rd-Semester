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
	void InsertatTail(Node* &tail,int d)
	{
		Node* temp=new Node(d);		// JO NEW NODE BNI H ME USE LAST  WALI NODE K AKHIR M RKH RHA HO USING TAIL K NEXT SA
		tail -> next = temp;
		tail = temp;
	}
	void Display(Node* &head)
	{
		Node* cur = head;
		
		while(cur!=NULL)
		{
			cout<<" "<<cur->data<<" --> ";
			cur = cur->next;
		}
		cout<<"NULL";
	}
	Node* EvenOdd(Node* &head)
 	{
 		Node* even_start=NULL;
 		Node* even_end = NULL;
 		Node* odd_start=NULL;
 		Node* odd_end = NULL;
 		Node* cur = head;
 		
 		while(cur!=NULL)
 		{
 			if(cur->data%2==0)
 			{
 				if(even_start == NULL)
 				{
 					even_start = cur;
 					even_end = cur;
				}
				else
				{
					even_end->next  = cur;
					even_end = even_end->next; 
				}	 
			}
			else
			{
				if(odd_start == NULL)
 				{
 					odd_start = cur;
 					odd_end = cur;
				}
				else
				{
					odd_end->next  = cur;
					odd_end = odd_end->next; 
				}
			}
			cur = cur->next;
		}
		if(odd_end!=NULL)
 		{
 			odd_end->next = NULL;
 			if(even_start == NULL)
 			{
 				even_start = odd_start;
			}
			else
			{
				even_end->next = odd_start; 
			}
 		
		 }
		 return even_start;
	}
int main()
{	
	Node* node = new Node(17);
	Node* head = node;
	Node* tail = node;
	int  n,numbers;
	cout<<"ENTER HOW MANY LINKDLIST YOU WANT TO ADD: ";
	cin>>n;	
	for(int i=0;i<n;i++)
	{
		cin>>numbers;
		InsertatTail(tail,numbers);
	}
	cout<<"\nLINKDLIST BEFORE SORTING:\n"<<endl;
	Display(head);
	Node* newNode = EvenOdd(head);
	cout<<"\n\n\nAFTER SORTING THE EVEN NUMBERS BEFORE ODD NUMBERS:\n\n"<<endl;
	Display(newNode);
}



