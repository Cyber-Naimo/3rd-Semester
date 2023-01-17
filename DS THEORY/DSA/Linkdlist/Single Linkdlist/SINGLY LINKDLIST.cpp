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
			next = 0;
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

Node* Concatinate(Node* &head1, Node* &head2)
{
	Node* cur = head1;
	while(cur!=NULL)
	{
		cur = cur->next;
	}
	cur->next = head2;
	return head1;
}




Node* FindMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* Merge(Node* left, Node* right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
    while(left!=NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL)
    {
        temp->next = right;
        temp  = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
Node* mergeSort(Node *head) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node* mid = FindMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* final  = Merge(left,right);
        return final;
    }
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


bool Search(Node* &head, int key)
{
	Node* cur = head;
	
	while(cur!=NULL)
	{
		if(cur->data==key)
		{
			return true;
		}
		cur=cur->next;
	}
	return false;
}
void InsertatHead(Node* &head, int data)
{
	
	Node* temp= new Node(data);      // JO NEW NODE BNI H MNE USE HEAD P POINT KRANA HA
	temp -> next = head;
	head = temp;
}
void InsertatTail(Node* &tail,int d)
{
	
	Node* temp=new Node(d);		// JO NEW NODE BNI H ME USE LAST  WALI NODE K AKHIR M RKH RHA HO USING TAIL K NEXT SA
	tail -> next = temp;
	tail = temp;
}
void InsertinSorted(Node* &head, int val)
{
	 Node* newnode = new Node(val);		// CREATING NEW NODE FOR INSERTATION
	 Node* cur = head;				// FOR CHECKING PURPOSE WE DECLARE TEMPRARAY NODE
	 
	 if(cur==NULL  || val < cur->data)	// CONDITION FOR BEGINNING
	 {
	 	newnode->next = head;	// same logic for insert at head
	 	head=newnode;
	 	return;
	 }
	 
	while(cur->next!=NULL && cur->next->data<val)					
	{
		cur= cur->next;	
	}
	
	newnode->next = cur->next;			// placng new node between the existing nodes
	cur->next = newnode;
	
}
void Insertation(Node* &head, int data, int pos)
{
	Node* new_node = new Node(data);
	Node* cur = head;
	if(pos==1)
	{
		InsertatHead(head,data);
		return;
	}

	for(int i = 1; i<pos; i++)
	{
		cur = cur->next;
	}
	new_node->next = cur->next;
	cur->next = new_node;
}
int deletion(Node* &head, int pos)
{
	Node* pre= head;
	int x;
	if(pos==1)
	{
		head  = head->next;
		x = pre->data;
		pre->next = NULL;
		delete pre;
	}
	
	else
	{
		for(int i = 1; i<pos; i++)
		{
			pre = pre->next;
		}
		
		Node* lost = pre->next;
		pre->next = pre->next->next;
		delete(lost);
		x=pre->data;
		
	}
	return x;	
}

void DeleteByValue(Node* &head, int val)
{
	Node* cur = head;
	
	while(cur->next->data!=val)
	{
		cur=cur->next;
	}
	cur->next = cur->next->next;
	delete cur;	
}
void Reverse2(Node* &head)
{
	if(head!=NULL)
	{
		Reverse2(head->next);
		cout<<" "<<head->data<<" --> ";
	}
}
void Display2(Node* &head)
{
	if(head!=NULL)
	{
		cout<<" "<<head->data<<" --> ";
		Display2(head->next);
	}
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
int ADD(Node* &head)
{
	Node* cur = head;
	int sum=0;
	
	while(cur!=NULL)
	{
		sum+=cur->data;
		cur = cur->next;
	}
	return sum;
}
bool IsSorted(Node* &head)
{
	Node* cur = head;
	int x = INT_MIN;
	
	while(cur!=NULL)
	{
		if(cur->data < x)
		{
			return false;
		}
		x  = cur->data;
		cur = cur->next;
	}
	return true;
}
int Counter(Node* &head)
{
	Node* cur = head;
	int count=0;
	
	while(cur!=NULL)
	{
		count+=1;
		cur = cur->next;
	}
	return count;
}
int Min(Node* &head)
{
	int min = INT_MAX;
	while(head!=NULL)
	{
		if(min > head->data)
		{
			min = head->data;
		}
		head = head->next;
	}
	return min;
}

int Max(Node* &head)
{
	int max = INT_MIN;
	while(head!=NULL)
	{
		if(max < head->data)
		{
			max= head->data;
		}
		head = head->next;
	}
	return max;
}
Node* Reverse(Node* &head)
{
	Node* cur = head;
	Node* pre = NULL;
	Node* forward= NULL;
	
	while(cur!=NULL)
	{
		forward = cur->next;
		cur->next= pre;
		pre=cur;
		cur = forward;
	}
	return pre;
}
Node* DetectCycle(Node* &head)
{
	Node* slow = head;
	Node* fast = head;
	while(fast->next!=NULL)
	{
		slow = slow->next;
		fast  = fast->next->next;
		
		if(slow == fast)
		{
			return slow;
		}
	}
	return NULL;
}
Node* IntersectionNode(Node* &head)
{
	Node* cycle = DetectCycle(head);
	if(cycle==NULL)
	{
		return NULL;
	}
	Node* cur =head;
	while(cur!=cycle)
	{
		cur = cur->next;
		cycle = cycle->next;
	}
	return cur;
}
void Removeloop(Node* &head)
{
	Node* start = IntersectionNode(head);
	Node* cur = start;
	while(cur->next!=start)
	{
		cur = cur->next;
	}
	cur->next = NULL;
}

void InsertMid(Node* &head, int data)
{
	Node* slow = head;
	Node* fast = head;
	Node* new_node = new Node(data);
	while(fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	new_node->next = slow->next;
	slow->next = new_node;
	cout<<" Mid element: "<<slow->data<<endl;
	
}
//bool Palindrome(Node* &head)
//{
//	
//	if(head==NULL)
//	{
//		return true;
//	}
//	
//  Node* mid = (head);
//	
//	Node* last = Reverse(mid->next);
//	
//	Node* cur = head;
//	while(last!=NULL)
//	{
//		if(last->data!=cur->data)
//		{
//			return false;
//		}
//		cur = cur->next;
//		last = last->next;
//	}
//	return true;
//}


void sorting(Node* &head)
{
            Node *temp = head;
            if (head=NULL)
			{
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                Node *current = NULL;
                
                while(temp->next!=NULL)
				{
                    current = temp->next;
                    while(current!=NULL)
					{
                        if (current->data<temp->data)
						{
                            int x = current->data;
                            current->data = temp->data;
                            temp->data = x;
                        }
                        current = current->next;
                    }
                    temp = temp->next;
                }
                
            }
}


//Node* Merge(Node* left , Node* right)
//    {
//        if(left == NULL)
//        {
//            return right;
//        }
//        else if(right == NULL)
//        {
//            return left;
//        }
//        else
//        {
//            Node* ans = new Node(-1);
//            Node* temp = ans;
//            while(left!=NULL && right!=NULL)
//            {
//                if(left->data < right->data)
//                {
//                    temp->bottom = left;
//                    temp = left;
//                    left = left->bottom;
//                }
//                else
//                {
//                    temp->bottom = right;
//                    temp = right;
//                    right = right->bottom;
//                }
//            }
//            
//            while(left!=NULL)
//            {
//                    temp->bottom = left;
//                    temp = left;
//                    left = left->bottom;
//            }
//            while(right!=NULL)
//            {
//                  temp->bottom = right;
//                    temp = right;
//                    right = right->bottom;
//            }
//            ans = ans->bottom;
//            return ans;
//        }
//    }
//    Node* flatten(Node* head) 
//	{
//        if(head == NULL || head->next==NULL)
//        {
//            return head;
//        }
//        else
//        {
//            Node* down = head;
//            Node* right = head->next;
//            down->next = NULL;
//            right = flatten(right);
//            
//            Node* ans = Merge(down,right);
//            return ans;              
//        }
//        
//    }
Node* SwapAdjacent(Node* &head)
{
	Node* cur = head;
	while(cur!=NULL)
	{
		if(cur->next!=NULL)
		{
			swap(cur->data,cur->next->data);
		}
		cur = cur->next->next;
	}
	return head;
}
Node* ReversingKthNodes(Node* &head,int k)
{
	Node* cur = head;
	Node* pre = NULL;
	Node* forward = NULL;
	int count =0;
	if(head == NULL)
	{
		return head;
	}
	while(cur!=NULL && count<k  )
	{
		forward = cur->next;
		cur->next = pre;
		pre = cur;
		cur = forward;
		count++;
	}
	if(forward!=NULL)
	{
		head->next = ReversingKthNodes(forward,k);
	}
	return pre;
}

Node* RemoveDuplicate(Node* &head)
{
	Node* cur = head;
	while(cur!=NULL)
	{
		if( (cur->next!=NULL) && cur->data==cur->next->data)
		{
		
			Node* next_next = cur->next->next;
			Node* to_delete = cur->next;
			delete(to_delete);
			cur->next=next_next;
		}
		else
		{
			cur = cur->next;	
		}
	}
	return head;
}
void swap(int x, int y, Node* &head)
{
	if(x==y)
	{
		return;
	}
	Node* prevx=NULL;
	Node* curx=head;
	while(curx!=NULL && curx->data!=x)
	{
		prevx = curx;
		curx = curx->next;
	}
	Node* prevy=NULL;
	Node* cury = head;
	while(cury!=NULL && cury->data!=NULL)
	{
		prevy = cury;
		cury = cury->next;
	}
	if(cury==NULL|| curx==NULL)
	{
		return;
	}
	if(prevx!=NULL)
	{
		prevx->next = cury;
	}
	else
	{
		head = cury;
	}
	if(prevy!=NULL)
	{
		prevy->next = curx;
	}
	else
	{
		head = curx;
	}
	
	Node* temp = cury->next;
	cury->next = curx->next;
	curx->next = temp;
}
void Dupli(Node* head)
{
	//  1 3 4 1 1 
	Node* cur = head;
	while(cur!=NULL && cur->next!=NULL)
	{
		Node* pre = cur;			// 1
		while(pre->next!=NULL)
		{
			if(cur->data == pre->next->data)
			{
				Node* next_next = pre->next;
				pre->next = pre->next->next;
				delete(next_next);
			}
			else
			{
				pre = pre->next;
			}
		}
		cur = cur->next;			// 3	
	}
}
Node* Dup(Node* &head)
{
	Node* cur = head;
	while(cur!=NULL && cur->next!=NULL)
	{
		Node* pr = cur;
		while(pr->next!=NULL)
		{
			if(cur->data == pr->next->data)
			{
				Node* next_next = pr->next;
				pr->next = pr->next->next;
				delete(next_next);
			}
			else
			{
				pr = pr->next;
			}		
		}
		cur = cur->next;
	}
	return head;
}
int main()
{
	Node* node= new Node;
	Node* head = node;
	Node* tail = node;
	int  n,numbers;
	cout<<"ENTER HOW MANY LINKDLIST YOU WANT TO ADD: ";
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		cin>>numbers;
		InsertatTail(tail,numbers);
	}
//	Display(head);
	Dupli(head);
//	1 1 3 3 3 3 5 9 9 12 15 15 15 15 15 15 17
	Display(head);


	return 0;

}

