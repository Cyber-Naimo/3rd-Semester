
#include<bits/stdc++.h>
#define N 105
using namespace std;
/*
	Input:
	K = 4
	arr[][]={{1,2,3,4}{2,2,3,4},
	         {5,5,6,6},{7,8,9,9}}
	Output:
	1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
	Explanation: Above test case has 4 sorted
	arrays of size 4, 4, 4, 4
	arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
	[5, 5, 6, 6]  [7, 8, 9, 9 ]]
	The merged list will be 
	[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
	6, 6, 7, 8, 9, 9 ]
*/
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

// creatinng our own data for help
class Node
{
  public:
  int j;
  int i;
  int data;
  Node(int data,int i,int j)
  {
      this->data = data;
      this->i = i;
      this->j = j;
  }
};
class Compare
{
  public:
  // using our own condition for the minHeap
  bool operator()(Node *a,Node *b)
  {
      return (a->data > b->data);
  }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int> > arr, int K)
    {
        priority_queue<Node*,vector<Node*>,Compare> min;
        
        //step1: sarey 1st element push kradie min heap har Array k;
        for(int i=0;i<K;i++)
        {
            Node* newNode = new Node(arr[i][0],i,0);
            min.push(newNode);
        }
        vector<int> ans;
        // step2:
        // jb tk min heap empty na ho jo bh minimum elemnt ho use ans
        // wale array m push krdo then us element ko hatado then phr usi row ka 
        // j+1 element access krke use min heap me push krdo isi tarah sarey kro
        while(!min.empty())
        {
            Node* temp = min.top();
            ans.push_back(temp->data);
            min.pop();
            int i = temp->i;
            int j = temp->j;
            if(j+1<arr[i].size())
            {
                Node* nod = new Node(arr[i][j+1],i,j+1);
                min.push(nod);
            }
        }
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int> > arr(k,vector<int>(k,0));
	   
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}

