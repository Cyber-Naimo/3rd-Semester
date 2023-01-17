#include<bits\stdc++.h>
#define MAX 6
using namespace std;

class Priority
{
	public:
	int count=0;
	int arr[MAX];
	
		bool empty()
		{
			if(count==0)
			{
				return true;
			}
			return false;
		}
		bool full()
		{
			if(count==MAX)
			{
				return true;
			}
			return false;
		}
		int top()
		{
			return arr[count-1];
		}
		
		void enquue(int d)
		{
			int i = 0;
			// first check space
			if(!full())
			{
				if(count == 0 )
				{
					arr[count++] = d;
				}
				else
				{
					for(i= count-1;i>=0;i--)
					{
						// 0 index wale value agey dal rahe ho mean 1st index pe
						if(d < arr[i])
						{
							arr[i+1] = arr[i];
						}
						else
						{
							break;
						}
					}
					
				}
				arr[i+1] = d;
				count++;
			}
		}
		
		
		void DeQueue()
		{
			--count;	 
		}
};
int kthlargest(int ptr[],int k,int n)
{
	Priority p;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=ptr[j];
			cout<<" "<<sum<<endl;
			p.enquue(sum);
		}
	 } 
	 int ans = 0;
	 cout<<"PRIORITY QUEUE: "<<endl;
	 for(int i=0;i<k;i++)
	 {
	 	 ans = p.top();
	 	 cout<<" "<<ans<<endl;
	 	 p.DeQueue();
	 }
	 return ans;
}
int main()
{
	int arr[] = {3,2,1};
	cout<<" Kth Largest: "<<kthlargest(arr,2,3)<<endl;	
	Priority p;
	p.enquue(3);
	p.enquue(100);
	p.enquue(2);
	p.enquue(6);
	cout<<" "<<p.top();
//	
 return 0;
}

	/*
	There are given N ropes of different lengths, we need to connect these ropes into one rope.
	The cost to connect two ropes is equal to sum of their lengths.
	The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.
	Input:
	n = 5
	arr[] = {4, 2, 7, 6, 9}
	Output: 
	62 
	Explanation:
	First, connect ropes 4 and 2, which makes
	the array {6,7,6,9}. Cost of
	this operation 4+2 = 6. Next, add ropes 
	6 and 6, which results in {12,7,9}. 
	Cost of this operation 6+6 = 12.
	Then, add 7 and 9, which makes the array {12,16}. 
	Cost of this operation 7+9 = 16. And
	finally, add these two which gives {28}.
	Hence, the total cost is 6 + 12 + 16 + 
	28 = 62.
	*/
	//Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Min HEAP
       priority_queue<long long, vector<long long>, greater<long long>>minH;
       // PUSHING ALL THE ELEMENTS
        for(long long i=0;i<n;i++)
        {
            minH.push(arr[i]);  
        }
          
        long long minCost = 0;
        while(minH.size() > 1)
        {
            // taking 1st and 2nd small element now
            long long first = minH.top();
            minH.pop();
            long long second = minH.top();
            minH.pop();
            // summing both 
            int sum = first + second;
            //stroring the ans
            minCost += sum;
            // now again back subsituting the sum in the Min Heap for next iteration
            minH.push(sum);
        }
        return minCost;
    }
	/*
	Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that
	all the values in the left subtree of a node should be less than all the values in the right subtree of the node.
	This condition is applied to all the nodes, in the resultant converted Min Heap.
	 Input:       4
                /   \
              2     6
            /  \   /  \
          1   3  5    7  
		Output:  1
               /   \
             2     5
           /  \   /  \
         3   4  6    7 
Explanation: The given BST has been transformed into a Min Heap. All the nodes in the Min Heap satisfies the given condition,
			that is, values in the left subtree of a node should be less than the values in the right subtree of the node. 
	*/
	void inOrder(BinaryTreeNode* root, vector<int> &in)
	{
	    if(root == NULL)
	    {
	        return;
	    }
	    inOrder(root -> left, in);
	    in.push_back(root -> data);
	    inOrder(root -> right, in);
	}
	
	void fillPreOrder(BinaryTreeNode* root, vector<int> &inOrder, int &index)
	{
	    if(root == NULL)
	    {
	        return;
	    }
	    root -> data =inOrder[index++];
	    fillPreOrder(root -> left, inOrder, index);
	    fillPreOrder(root -> right, inOrder, index);
	}
	BinaryTreeNode* convertBST(BinaryTreeNode* root)
	{
		vector<int> v;
	    int index = 0;
	    inOrder(root, v);
	    
	    fillPreOrder(root, v, index);
	    
	    return root;
	    
	}
	/* IS BINARY TREE HEAP
		Input:
	      5
	    /  \
	   2    3
	Output: 1
	Explanation: The given tree follows max-heap property since 5,
	is root and it is greater than both its children.
	
		Input:
	       10
	     /   \
	    20   30 
	  /   \
	 40   60
	Output: 0
	*/
   int Count(struct Node* root)
  {
      if(root == NULL )
      {
        return 0;
      }
      else
      {
          int ans =  1+Count(root->left)+Count(root->right);
          return ans;
      }
  }
    bool isCBT(struct Node* root,int i, int total)
	{
	      if(root == NULL)
	      {
	          return true;
	      }
	          if(i>=total)
	          {
	              return false;
	          }
	          else
	          {
	              bool left = isCBT(root->left,2*i+1,total);
	              bool right = isCBT(root->right,2*i+2,total);
	              return (left && right); 
	          }
	}
	bool isMaxHeap(struct Node* root)
	{
	      //leaf node
	      if(root->left==NULL && root->right==NULL)
	      {
	          return true;
	      }
	      if(root->right==NULL)
	      {
	          return (root->data > root->left->data);
	      }
	      else
	      {
	          bool left = isMaxHeap(root->left);
	          bool right = isMaxHeap(root->right);	          
	          return (left && right && (root->data > root->left->data) && (root->data > root->right->data));	        
	      }
	}
    bool isHeap(struct Node* tree)
	{
       int i = 0;
       int cnt = Count(tree);
       if(isCBT(tree,i,cnt) && isMaxHeap(tree))
       {
           return true;
       }
       else
       {
           return false;
       }
    }

		
	/*	Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
		n = 4 m = 3
		a[] = {10, 5, 6, 2}, 
		b[] = {12, 7, 9}
		Output : {12, 10, 9, 2, 5, 7, 6}
	*/
 
	vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       
       vector<int> v;

       vector<int> ans;     

       priority_queue<int> pq;  // max heap
       // step 1 : merge two arrays
        // pushing all elements of array 1 in new array;
       for(int i=0; i<n; i++)
       {
           v.push_back(a[i]);
       }
       //pushing all elements of array 1 in new array;
       for(int i=0; i<m; i++)
       {
           v.push_back(b[i]);
       }
        //step 2: creating a Max Heap
       for(int i=0; i<n+m; i++)
       {
           pq.push(v[i]);
       }
        // now again creating a Max HEAP ARRAY
       while(!pq.empty())
       {
           ans.push_back(pq.top());
           pq.pop();
       }

       return ans;
    }

	
 	// arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
 	int kthSmallest(int arr[], int l, int r, int k) 
    {
    	// MAX HEAP IS USED FOR KTH SMALLEST
        priority_queue<int> p;
        // step 1
        for(int i=0;i<k;i++)
        {
            p.push(arr[i]);
        }
        // step 2:
        for(int i = k;i<=r;i++)
        {
            if(arr[i] < p.top())
            {
                p.pop();
                p.push(arr[i]);
            }	
        }
        int ans = p.top();
        return ans;
        
    }
int main()
{

return 0;

}

