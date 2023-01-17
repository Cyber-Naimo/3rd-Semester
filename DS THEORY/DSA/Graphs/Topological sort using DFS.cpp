#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    void TopSort(int node, vector<bool> &visited, stack<int> &s, vector<int> adj[])
    {
        // mark the given node true
        visited[node] = true;
        // traverse its neighbours
        for(auto i: adj[node])
        {
            // if they are not visited then visit them
	        if(!visited[i])
	        {
              TopSort(i, visited, s, adj);
	        }
	    }
	    // at last when all call are done in returning push the last returning node into stack
	    s.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        // bool array for marking the nodes visited or not;
	    vector<bool> visited(V);
        
        // for pushing the Null element 
	    stack<int> s;

        // traversing the all edges 
 	    for(int i=0; i<V; i++)
 	    {
            // if the desired node is node is not visited then visit it;
	        if(!visited[i])
	        {

	            TopSort(i, visited, s, adj);

	        }

	    }
	    vector<int> ans;
        // take element from top of the stack and push in ans array
	    while(!s.empty())
	    {

	        ans.push_back(s.top());

	        s.pop();

	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/


int main() 
{
    int T;
    cin >> T;
    while (T--) 
	{
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);
    }
    
    return 0;
}

