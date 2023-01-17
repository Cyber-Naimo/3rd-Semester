#include<iostream>
#include <queue>
#include<stack>
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
class BinaryTree{
	public:
	Node* root;
		BinaryTree()
		{
			this->root = NULL;
		}
		
		/////  	********	PART A		**************   /////// 
		Node* Insertion(Node* root,int data)
		{
			if(root == NULL)
			{
				root = new Node(data);
				return root;
			}
			else if(data > root->data)
			{
				root->right = Insertion(root->right,data);
			}
			else 
			{
				root->left = Insertion(root->left,data);
			}
		}
		void TakeInputs()
		{
			int data[] = {15,10,20,8,12,16,25,-1};
			int i=0;
//			cout<<"ENTER DATA TO INSERT AT BST: "<<endl;
//			cin>>data;
			while(data[i]!=-1)
			{
				root = Insertion(root,data[i]);
//				cin>>data;
				i++;
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
		
		void IterativePreOrder()
		{
			// temperaray nood
			Node* temp = root;
//			storing element in the stack
			stack <Node*> s;
			s.push(root);
			// it stop when stack is empty 
			while(!s.empty() && temp!=NULL)
			{
//				take 1st element
				temp =  s.top();
				s.pop();
				// print it
				cout<<" "<<temp->data<<" ";
				// if right!= NULL then again elements
				if(temp->right!=NULL)
				{
					s.push(temp->right);
				}
				if(temp->left!=NULL)
				{
					s.push(temp->left);
				}
			}
		}
		Node* DeletionTruncate(int low, int high)
		{
		    // base case
		    if (root == NULL) {
		        return root;
		    }
		 
		    // recursively truncate the left and right subtree first
		    root->left = DeletionTruncate(root->left, low, high);
		    root->right = DeletionTruncate(root->right, low, high);
		 
		    Node* temp = root;
		 
		    // if the root's key is smaller than the minimum allowed, delete it
		    if (root->data < low)
		    {
		        root = root->right;
		        delete temp;
		    }
		    // if the root's key is larger than the maximum allowed, delete it
		    else if (root->data > high)
		    {
		        root = root->left;
		        delete temp;
		    }
		    return root;
		}
};

int maxDepth(Node * root)
{

  if (root == NULL)
    return 0;
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  return max(left,right)+1;
}

 int minDepth(Node* root) 
 {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return min(left,right)+1;
        }
    }
Node* Insertion(Node* root,int data)
{
	if(root == NULL)
	{
		root = new Node(data);
		return root;
	}
	else if(data > root->data)
	{
		root->right = Insertion(root->right,data);
	}
	else 
	{
		root->left = Insertion(root->left,data);
	}
}
void TakeInputs(Node* &root)
{
	int data;
	cout<<"ENTER DATA TO INSERT AT BST: "<<endl;
	cin>>data;
	while(data!=-1)
	{
		root = Insertion(root,data);
		cin>>data;
	}
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

void PreOrder(Node* &root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		// 1)Node print kro , 2) left me jao,  3) right m jao
		cout<<" "<<root->data<<" ";
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
//1 2 3 4 5 6 7 8 9 10 -1 -1 -1 -1 -1 -1 -1
bool Search(Node* &root,int data)
{
	Node* temp = root;
	while(temp!=NULL)
	{
		if(data == temp->data)
		{
			return true;
		}
		if(data < temp->data)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return false;
}
Node* Min(Node* &root)
{
	Node* temp = root;
	while(temp->left!=NULL)
	{
		temp = temp->left;
	}
	return temp;
}
Node* Max(Node* &root)
{
	Node* temp= root;
	while(temp->right!=NULL)
	{
		temp = temp->right;
	}
	return temp;
 } 
// preccessor and successor are homework

Node* Deletion(Node* &root,int data)
{
	if(root == NULL)
	{
		return root;
	}
	if(data == root->data)
	{
		// 0 child
		if(root->right==NULL && root->left == NULL)
		{
			delete root;
			return NULL;
		}
		
		// 1 child
		// left
		if(root->right== NULL && root->left!=NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		
		// right
		if(root->right!=NULL && root->left== NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		// 2 child
		if(root->left == NULL && root->right == NULL)
		{
			int mini = Min(root->right)->data;			// first take min value from RHS 
			root->data = mini;							// COPY THE ROOTT DATA TO MIN VALUE		
			root->right = Deletion(root->right,mini);	// NOW DELETE MIN NODE USING RECUSRION
			return root;
			
		}
	}
	
	else if (data < root->data)
	{
		root->left = Deletion(root->left,data);
		return root;
	}
	else
	{
		root->right = Deletion(root->right,data);
		return root;
	}
}
int solve(Node* &root,int min,int max)
{
	if(root==NULL)
	{
		return 10;
	}
	if(root->data<=max && root->data>=min)
	{
		int left = solve(root->left,min,root->data);
		int right = solve(root->right,root->data,max);
		return 10;
	}
	else
	{
		return 0;
	}
}
int AutoGrader(Node* root)
{
	return solve(root,INT_MIN,INT_MAX);
}
void solve(Node *root, vector<int>&ans){

        // base case

        if(root==NULL) return;
        solve(root->left,ans);

        ans.push_back(root->data);

        solve(root->right, ans);
    }
    int KthLargest(Node *root, int K)
    {
        vector<int> ans;

        solve(root,ans);

        if(K > ans.size()) return -1;

        return ans[ans.size()-K];
    }
     void solve1(Node *root, vector<int>&ans){

        // base case

        if(root==NULL) return;
	    solve(root->left,ans);

        ans.push_back(root->data);

        solve(root->right, ans);
    }

    int KthSmallestElement(Node *root, int K) {

        vector<int> ans;

        solve1(root,ans);

        if(K > ans.size()) return -1;

        return ans[K-1];

    }
int Precessor(Node* &root,int k)
{
	Node* temp = root;
	int prec = -1;
	while(temp->data!=k)
	{
		if(temp->data>k)
		{
			temp = temp->left;
			prec = temp->data;
		}
	}
	Node* leftside = temp->left;
	while(leftside!=NULL)
	{
		prec = leftside->data;
		leftside = leftside->right;		
	}
	return prec;
}
int Successor(Node* root, int k)
{
	Node* temp = root;
	int succ = -1;
	while(temp->data!=k){
		if(k > temp->data)
		{
			temp = temp->right;
			succ = temp->data;
		}
	}
	Node* rightside = temp->right;
	while(rightside!=NULL)
	{
		succ = rightside->data;
		rightside = rightside->left;
	}
	return succ;
	
}
Node* LCAinaBST(Node* root, Node* P, Node* Q)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->data > P->data && root->data > Q->data)
        {
            return LCAinaBST(root->left,P,Q);
        }
        if(root->data < P->data && root->data < Q->data)
        {
            return LCAinaBST(root->right,P,Q);
        }
    }
    return root;
	// Write your code here
}
int main()
{	
	BinaryTree b;
	b.TakeInputs();
	PreOrder(b.root);
	cout<<" \n\n\\n\n";
	b.IterativePreOrder();
	return 0;

}

