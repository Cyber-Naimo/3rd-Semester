#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* right;
	Node* left;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	
};
class AVLTrees
{
	Node* root;
	public:
		
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
				return max(left,right)+1;
			}
		}
		
		Node* LeftRotation(Node* root)
		{
			Node* x = root;
			Node* y = x->right;
			y->left = x;
			x->right = NULL;
			return y;
		}
		
		Node* RightRotation(Node* root)
		{
			Node* x = root;
			Node* y = x->left;
			y->right = x;
			x->left = NULL;
			return y;
		}
		int BalanceFactor(Node* root)
		{
			if(root == NULL)
			{
				return 0;
			}
			else
			{
				return (height(root->left) - height(root->right));
			}
		}
		Node* Insertion(Node* root, int data)
		{
			if(root == NULL)
			{
				Node* newNode = new Node(data);
				return newNode;
			}
			else if(data > root->data)
			{
				root->right = Insertion(root->right,data);
			}
			else if(data < root->data)
			{
				root->left = Insertion(root->left,data);
			}
			
				int bf = abs(BalanceFactor(root));
				//  LL
				if(bf > 1 && data > root->right->data)
				{
					return LeftRotation(root);
				}
				
				// RR
				else if(bf > 1 && data < root->left->data)
				{
					return RightRotation(root);
				}
				
				// LR
				else if(bf > 1 && data>root->left->data)
				{
					root->left = LeftRotation(root->left);
					return RightRotation(root);
				}
				// RL
				else if(bf > 1 && data < root->right->data)
				{
					root->right = RightRotation(root->right);
					return LeftRotation(root);
				}
				return root;

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
			if(root->left != NULL && root->right != NULL)
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
		
		int bf = abs(BalanceFactor(root));
				//  LL
				if(bf > 1 && data > root->right->data)
				{
					return LeftRotation(root);
				}
				
				// RR
				else if(bf > 1 && data < root->left->data)
				{
					return RightRotation(root);
				}
				
				// LR
				else if(bf > 1 && data>root->left->data)
				{
					root->left = LeftRotation(root->left);
					return RightRotation(root);
				}
				// RL
				else if(bf > 1 && data < root->right->data)
				{
					root->right = RightRotation(root->right);
					return LeftRotation(root);
				}
				return root;
		
	}
};
int main()
{
 	Node* root = NULL;
    AVLTrees objbst;
    
    root = objbst.Insertion(root, 54);
    root = objbst.Insertion(root, 11);
    root = objbst.Insertion(root, 87);
    root = objbst.Insertion(root, 23);
    root = objbst.Insertion(root, 111);
    root = objbst.Insertion(root, 120);
    objbst.LevelOrderTraversal(root);
   	cout << objbst.height(root);
   	cout<<" Value: "<<!1<<endl;
	return 0;

}

