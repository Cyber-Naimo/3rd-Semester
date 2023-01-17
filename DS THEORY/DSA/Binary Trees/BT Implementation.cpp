#include<iostream>
#include <queue>
#include<stack>
#include<math.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int data)
		{
			this->data = data;
			this->right = NULL;
			this->left = NULL;
		}
};
Node* Insertion(Node* &root)
{
	int d;
	cout<<"ENTER NODES DATA TO INSERT: ";
	cin>>d;
	root = new Node(d);
	
	if(d == -1)					// condition for returning
	{
		return NULL;
	}
	
	cout<<"ENTER DATA FOR INSERTING IN LEFT OF: "<<d<<endl;
	root->left = Insertion(root->left);
	cout<<"ENTER DATA FOR INSERTING IN RIGHT OF: "<<d<<endl;
	root->right = Insertion(root->right); 
	return root;
}
	//reverse level order traversal khd krna ha
	void ReverseOrderTraversal(Node* root)
	{
		stack<Node*> s;
		queue<Node*> q;
		q.push(root);
		while(!q.empty())
		{
			root = q.front();
			q.pop();
			s.push(root);
				if(root->left)
				{
					q.push(root->left);
				}
				if(root->right)
				{
					q.push(root->right);
				}
		}
		while(!s.empty())
		{
			root= s.top();
			cout<<" "<<root->data;
			s.pop();
		}
	}
	
	
/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
   void solve(Node* root, int &count)
   {
        if(root == NULL)
        {
            return;
        }
       if(root->right == NULL && root->left==NULL)
        {
            count++;
        }
        solve(root->right,count);
        solve(root->left,count);
   }
	int countLeaves(Node* root)
	{
	    int count=0;
	    solve(root,count);
	    return count;
	        
	}
	
	// gave the heoght of the tree
	int height(Node* root)
	{
		if(root == NULL)
		{
			return 0;
		}
		else
		{
			int left = height(root->left);
			int right = height(root->right);
			int ans = max(left,right)+1;
			return ans;
		}
	}
	
	// gave the diameter of the tree
	int diameter(Node* root) 
	{
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int op1 = diameter(root->left);
            int op2 = diameter (root->right);
            int op3 = height(root->right)+height(root->left)+1;
            int ans = max(op1,max(op2,op3));
            return ans;
        }
    }
	//Function to check whether a binary tree is balanced or not.
	/*
	Given a binary tree, find if it is height balanced or not. 
	A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
	
	A height balanced tree
	        1
	     /     \
	   10      39
	  /
	5
	
	An unbalanced tree
	        1
	     /    
	   10   
	  /
	5*/
    bool isBalanced(Node *root)
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            bool left = isBalanced(root->left);
            bool right = isBalanced(root->right);
            bool diff = abs(height(root->left) - height(root->right))<=1;
            if(left && right && diff)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
    
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2== NULL)
        {
            return true;
        }
        if(r1!=NULL && r2==NULL)
        {
            return false;
        }
        if(r1==NULL && r2!=NULL)
        {
            return false;
        }
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        bool value = r1->data == r2->data;
        if(left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    
    // Should return true if tree is Sum Tree, else false
    /*
    Input:

          10
        /    \
      20      30
    /   \ 
   10    10

	Output: 0
	Explanation:
	The given tree is not a sum tree.
	For the root node, sum of elements
	in left subtree is 40 and sum of elements
	in right subtree is 30. Root element = 10
	which is not equal to 30+40.*/
    int sum(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            return sum(root->right)+sum(root->left) + root->data;
        }
    }
    bool isSumTree(Node* root)
    {
         if(root == NULL)
         {
            return true;
         }
         if(root->left== NULL && root->right==NULL)
         {
             return root->data;
         }
         int left = isSumTree(root->left);
         int right =isSumTree(root->right);
         int ans = sum(root->right)+sum(root->left) == root->data;
         
         if(ans && left && right)
         {
             return true;
         }
         else
         {
             return false;
         }
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    /* 		  10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0
     */
    int solve(Node* &root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int left  = solve(root->left);
            int right = solve(root->right);
            int m = root->data;
            root->data = left+right;
            return root->data+m;
        }
    }
    
    void toSumTree(Node *root)
    {
        solve(root);
    }
    /*
    Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and
	 returns the root node to the tree constructed. 
	You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)
	Input:
	N = 6
	inorder[] = {3 1 4 0 5 2}
	preorder[] = {0 1 3 4 2 5}
	Output: 3 4 1 5 2 0
	Explanation: The tree will look like
	       0
	    /     \
	   1       2
	 /   \    /
	3    4   5
	*/
 int findPosition(int in[],int n,int ele)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==ele)
            {
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &preorderindex,int inorderstart, int inorderend,int n)
    {
        if(preorderindex>=n || inorderstart>inorderend)
        {
            return NULL;
        }
        else
        {
            int ele = pre[preorderindex++];
            Node* root = new Node(ele);
            int pos = findPosition(in,n,ele);
            root->left = solve(in,pre,preorderindex,inorderstart,pos-1,n);
            root->right = solve(in,pre,preorderindex,pos+1,inorderend,n);
            return root;
            
        }
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex = 0;
        Node* ans = solve(in,pre,preorderindex,0,n-1,n);
        return ans;
    }
    
    // array to BST
	void solve(vector<int>& nums,int start,int end,vector<int>& arr)
	{
	    if(start>end)
	    {
	        return;
	    }
	    int mid = start+(end-start)/2;
	    arr.push_back(nums[mid]);
	    solve(nums,start,mid-1,arr);
	    solve(nums,mid+1,end,arr);
	    
	}
    vector<int> sortedArrayToBST(vector<int>& nums) 
	{
        vector<int> arr;
        int left  = 0;
        int right = nums.size()-1;
        solve(nums,right,left,arr);
        return arr;
    }

void LevelOrderTraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);				// initially NULL for line breaking
	
	while(!q.empty())			// jb tk queue empty nhi hoti
	{
		Node* temp = q.front();
		q.pop();
		if(temp == NULL)		// level changing
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);		// again making it NULL for next level changing
			}
		}
		else
		{
			cout<<" "<<temp->data;
			if(temp->left)
			{
				q.push(temp->left);
			}
			 if(temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}
void InOrder(Node* &root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		// 1)left me jao, 2) Node print kro,  3) right m jao
		InOrder(root->left);
		cout<<" "<<root->data;
		InOrder(root->right);
	}
}
void PreOrder(Node* &root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		// 1)Node print kro , 2) left me jao,  3) right m jao
	
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(Node* &root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		//  1) left me jao,  2) right m jao, 3)Node print kro
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<" "<<root->data;	
	}
}
void BuildFromLevelOrder(Node* &root)
{
	queue<Node*> q;
	cout<<"ENTER ROOTS DATA TO INSERT: "<<endl;
	int data;
	cin>>data;
	root = new Node(data);
	q.push(root);
	
	while(!q.empty())
	{
	
		Node* temp = q.front();
		q.pop();
		cout<<"ENTER DATA TO INSERT AT LEFT OF: "<<temp->data<<endl;
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			temp->left = new Node(leftdata);
			q.push(temp->left);
		}
		
		cout<<"ENTER DATA TO INSERT AT RIGHT OF: "<<temp->data<<endl;
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			temp->right = new Node(rightdata);
			q.push(temp->right);
		}
	} 
}

 // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    /* Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST()
 which takes the root of the Binary tree as input and returns the root of the BST.
The driver code will print inorder traversal of the converted BST.*/

    void inorder(Node* root,vector<int>&v)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            inorder(root->left,v);
            v.push_back(root->data);
            inorder(root->right,v);
        }
    }
    Node* convertintoBST(vector<int> &v,int s ,int e)
    {
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            Node* newNode = new Node(v[mid]);
            newNode->left = convertintoBST(v,s,mid-1);
            newNode->right = convertintoBST(v,mid+1,e);
            return newNode;
        }
        return NULL;
    }
    Node *binaryTreeToBST (Node *root)
    {
       
           vector<int> v;
           inorder(root,v);
//           sort(v.begin(),v.end());
           return convertintoBST(v,0,v.size()-1);
       
    }
	
	/* Computes the number of nodes in a tree. */
	int getSize(Node* root)
	{
	   if(root == 0)
	   {
	       return 0;
	   }
	   else
	   {
	       return getSize(root->right)+getSize(root->left)+1;
	   }
	}
//	mergetoBST()
//	{
//		approach:
//		2 vector<int> a1,a2;
//		call inorderfunction which takes a1,root1, and a2, and root2 2 barcall hoga function
//		merge krdena dono ko a1,a2;
//		then arrays to BST WALA FUNCTION LIKHLENA USING MID WALI LOGIC JO UPER KI HA
//		
//	}
int main()
{
	Node* root = NULL;
	BuildFromLevelOrder(root);
	InOrder(root);
//	LevelOrderTraversal(root);
//	ReverseOrderTraversal(root);
//	1 2 3 4 5 -1 -1 -1 -1 -1 -1 
	/*
	root = Insertion(root);
	LevelOrderTraversal(root);
	cout<<"\nPRE ORDER TRAVERSAL: "<<endl;
	PreOrder(root);
	cout<<"\nIN ORDER TRAVERSAL: "<<endl;
	InOrder(root);
	cout<<"\nPOST ORDER TRAVERSAL: "<<endl;
	PostOrder(root);
	*/
	return 0;

}

