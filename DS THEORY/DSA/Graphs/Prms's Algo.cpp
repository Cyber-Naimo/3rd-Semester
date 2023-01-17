//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int spanningTree(int V, vector<vector < int>> adj[])
    {
     // prims algo to find MST for a graph using Minimum PriorityQueue and visited data structure.
     vector<int> vis(V);
     
     priority_queue<pair<int, int>,vector< pair<int, int>>, greater<pair<int, int>>> pq;

    //  {weight, node } would include parent too, if need to find the whole MST
     pq.push({ 0, 0 });
     int ans = 0;
     
     while (!pq.empty())
     {
         // initially storing the minimum weight of heaps
         int weight = pq.top().first;
         int node = pq.top().second;
         // then popping the heap element
         pq.pop();
         
         // if a visited array is false then go and add the weight and marks the visited array true
         if (!vis[node])
         {
             // if node is not visited add the node weight to answer.
             ans += weight;
             vis[node] = true;
             
             // now check for its neighbours one by one and push into the heaps
             for (auto x: adj[node])
             {
                //  similiarly do for all neighbours
                 if (!vis[x[0]])
                 {
                     pq.push({ x[1], x[0] });
                 }
             }
             
             // since we are using a PQ the sum will automatically 
            //  be always the minimum.
         }
     }
     return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
