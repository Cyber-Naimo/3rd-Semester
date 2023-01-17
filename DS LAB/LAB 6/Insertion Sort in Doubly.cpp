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
};
		void InsertatStart(Node* &head, int data)
		{
			Node* new_Node = new Node(data);
			new_Node->next = head;
			head->pre = new_Node;
			head = new_Node;
		}
		void InsertatEnd(Node* &head, int data)
		{
			Node* new_Node = new Node(data);
			head->next = new_Node;
			new_Node->pre = head;
			head = new_Node;
		}
		void Insertion(Node* &head, int data,int pos)
		{
			Node* cur = head;
			Node* new_Node = new Node(data);
			if(pos == 1)
			{
				InsertatStart(head,data);
			}
			else
			{
			for(int i = 1; i<pos-1 ; i++ )
			{
				cur = cur->next;
			}
				new_Node->next = cur->next;
				cur->next->pre = new_Node;
				cur->next = new_Node;
				new_Node->pre = cur;
			}
		}
		void Deletion(Node* &head,int pos)
		{
			Node* cur = head;
			if(pos==1)
			{
				head = cur->next;
				head->pre = NULL;
				delete cur;
			}
			else
			{
			for(int i = 1; i<pos; i++ )
			{
				cur = cur->next;
			}
				Node*  next_cur = cur->next;
				Node* pre_cur = cur->pre;
				next_cur->pre = pre_cur;
				pre_cur->next = next_cur;
				delete cur;
			}
		}
		void Display(Node* &head)
		{
			Node* cur = head;
			while(cur!=NULL)
			{
			cout<<"  "<<cur->data<<" --> ";
			cur = cur->next;
			}
			cout<<"NULL"<<endl<<endl;
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
int main()
{
	int n,x;
	Node* node = new Node();			// initially it has zero store;
	Node* node1 =  new Node();			// initially it has zero store;
	
	cout<<"ENTER THE SIZE OF THE LINKDLIST: ";
	cin>>n;
	cout<<"\n\n\nENTER 1ST NODES ELEMENTS:\n";
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		Insertion(node,x,i);
	}
	cout<<"\n\n\nENTER 2ND NODES ELEMENTS:\n";
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		Insertion(node1,x,i);
	}
	
	cout<<"\n1ST NODES ELEMENTS: \n";
	Display(node);
	
	cout<<"\n\n";
	
	cout<<"2ND NODES ELEMENTS: \n";
	Display(node1);
	
	
	cout<<"\n\nAFTER CONCATINATING TWO LINKDLIST : "<<endl;
	Concatinate2(node,node1);
	Display(node);
	
	
	cout<<"\n\nSORTED CONCATINATED LINKDLIST: "<<endl;
	InsertionSort(node); 
	Display(node);


}
