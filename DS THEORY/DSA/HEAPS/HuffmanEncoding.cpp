#include<bits/stdc++.h>
using namespace std;

// Creating Nodes for building the Huffman Tree
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int a)
    {
        data=a;
        left=right=NULL;
    }
};
// for comparing the two nodes using operator overloading
class cmp
{
    public:
    bool operator()(Node *a,Node *b)
    {
        return a->data>b->data;
    }
};
class HuffmanTree
{
	public:
	   
	   // function for printing thenodes in the preorder format
	    void PreOrder(vector<string> &ans, string s,Node* root)
	    {
	       if(root==NULL)
		   {
		       return;
		   }
		   else
		   {
		   		// when you found the leaf node print it or push in to the array
		       if(root->left==NULL && root->right==NULL)
		       {
		           ans.push_back(s);
		           return;
		       }
		       PreOrder(ans,s+"0",root->left);
		       PreOrder(ans,s+"1",root->right);
		   }
	    }
		vector<string> huffmanCodes(string s,vector<int> f,int N)
		{
			// creating a minHeap using STL;
		  priority_queue<Node*,vector<Node*>,cmp> mh;
		  
		  // pushing All nodes in the MinHeap
		  for(int i =0;i<N;i++)
		  {
		      Node* temp = new Node(f[i]);
		      mh.push(temp);
		  }
		  
		  // Traversing till we have left only one node
		  while(mh.size() > 1)
		  {
		  	// taking left node and then pop it same goes for right node
		      Node* left = mh.top();
		      mh.pop();
		      Node* right = mh.top();
		      mh.pop();
		      
		      // In huffman the parent is the sum of leftchild ans rightchild so craeting parent node and pushing into the min heap 
		      Node* parent = new Node(left->data+right->data);
		      parent->left = left;
		      parent->right = right;
		      mh.push(parent);
		  }
		  Node* root = mh.top();
		  mh.pop();
		  // printong the codes
		  vector<string> ans;
		  PreOrder(ans,"",root);
		  return ans;
		}
};

int main()
{
	

	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    HuffmanTree ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(int i=0;i<N;i++)
		{
			cout<<" "<<ans[i];
		};
	    cout << "\n";

	return 0;
}
