//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}



class Compare{
    public:
    bool operator ()(Node*a,Node*b)
    {
        return (a->data > b->data);
    }
};
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
         priority_queue<Node*,vector<Node*>, Compare> min;
         
         if(k==0)
         {
             return NULL;
         }
         for(int i=0;i<k;i++)
         {
            if(arr[i]!=NULL)
            {
                 min.push(arr[i]);
            }
         }
         
         Node* head = NULL;
         Node* tail = NULL;
         while(!min.empty())
         {
            
             Node* newNode = min.top();
             min.pop();
             
             if(newNode->next!=NULL)
             {
                 min.push(newNode->next);
             }
             
             if(head == NULL)
             {
                 head = tail = newNode;
             }
             else
             {
                 tail->next = newNode;
                 tail = newNode;
             }
         }
         return head;   
         
    }
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

